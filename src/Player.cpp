/*
 * Player.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: triforce
 */

#include "Player.h"
#include <cmath>
#include "CollisionManager.h"
#include "CentralManager.h"
#include "SDL2/SDL.h"
#include <iostream>
int sign(float x) {
	if (x>0) return 1;
	else if (x<0) return -1;
	else return 0;
}

void Player::InitialUpdate() {
	if (grounded) {

		Vector along = Vector(platform.normal.y, -platform.normal.x);
		if (along.x<0) along*=-1;
		velocity=along*gsp;
	}
	else {
		velocity.x=gsp;
	}
}

void Player::Update() {
	PlayerState ps = ChooseState();
	if (ps!=state) ChangeState(ps);
	ExecuteState();
}

void Player::ResolveMovement() {

	manager->collision->RemoveHandle(body);
	float TOI = 1;
	std::vector<CollisionResult> wallCheck = manager->collision->CheckCollisionsSweep(body, velocity);
	for (auto it = wallCheck.begin(); it<wallCheck.end(); it++) {
		if ((*it).normal.x==0 || (*it).other->typeFlag<=0) continue;
		if ((*it).toi<TOI) TOI=(*it).toi;
	}
	position+=velocity*TOI;
	std::vector<CollisionResult> groundCheck = manager->collision->CheckCollisionsSweep(body, Vector(0, body->GetShape()->ContainBox().h/2));
	grounded = false;
	for (auto it = groundCheck.begin(); it<groundCheck.end(); it++) {
		if ((*it).normal.y==0 || (*it).other->typeFlag<=0) continue;
		if (!grounded && projection(velocity, (*it).normal)>0) continue;
		grounded = true;
		bounced = false;
		platform = (*it);
		position.y+=(*it).toi*body->GetShape()->ContainBox().h/2;
	}
	manager->collision->RegisterHandle(body);

}

PlayerState Player::ChooseState() {
	if (grounded) return GROUND;
	else return AIR;
}

void Player::ChangeState(PlayerState choice) {
	state=choice;
}

void Player::ExecuteState() {
	SDL_PumpEvents();
	const unsigned char* kstate = SDL_GetKeyboardState(NULL);
	bool a = kstate[SDL_SCANCODE_SPACE];
	bool b = kstate[SDL_SCANCODE_F];
	bool c = kstate[SDL_SCANCODE_LSHIFT];
	bool d = kstate[SDL_SCANCODE_G];
	bool negX = kstate[SDL_SCANCODE_A];
	bool negY = kstate[SDL_SCANCODE_W];
	bool posX = kstate[SDL_SCANCODE_D];
	bool posY = kstate[SDL_SCANCODE_S];
	if (A==PRESSED || A==ON) A = a?ON:RELEASED;
	if (A==RELEASED || A==OFF) A = a?PRESSED:OFF;
	if (B==PRESSED || B==ON) B = b?ON:RELEASED;
	if (B==RELEASED || B==OFF) B = b?PRESSED:OFF;
	if (C==PRESSED || C==ON) C = c?ON:RELEASED;
	if (C==RELEASED || C==OFF) C = c?PRESSED:OFF;
	if (D==PRESSED || D==ON) D = d?ON:RELEASED;
	if (D==RELEASED || D==OFF) D = d?PRESSED:OFF;
	x=(posX?1:0)-(negX?1:0);
	y=(posY?1:0)-(negY?1:0);
	float X = InputX();
	std::cout<<x<<" "<<X<<" "<<(int) A<<"\n"<<std::flush;
	int s = sign(X*gsp);
	if (state==GROUND) {
		if (s==0) {
			if (std::abs(gsp)<Friction()) gsp = 0;
			else gsp -= sign(gsp)*Friction();
		}
		else if (s<0) gsp += X*Decel();
		else {
			if (gsp==0) gsp=X*MinWalk();
			else if (std::abs(gsp)<TopSpeed()) {
				gsp+=X*Accel();
				if (std::abs(gsp)>TopSpeed()) {
					gsp=sign(gsp)*TopSpeed();
				}

			}

		}
		if (InputA()==PRESSED) {
			velocity.y= - JumpVelocity();
			grounded = false;
		}
	}
	if (state==AIR) {
		if (X!=0&&s>=0) {
			if (std::abs(gsp)<TopSpeed()) {
				gsp+=X*AirAccel();
				if (std::abs(gsp)>TopSpeed()) {
					gsp=sign(gsp)*TopSpeed();
				}

			}
		}
		else if (gsp!=0&&s<0) {
			gsp+=X*AirDecel();
		}
		velocity.y+=Gravity();
	}
}

void Player::Render() {
	manager->RenderTexture(texture, position);
}

