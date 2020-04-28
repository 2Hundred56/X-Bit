/*
 * Player.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: triforce
 */

#include "Player.h"
#include <cmath>
#include <algorithm>
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
	std::cout<<"----\n"<<std::flush;
	std::cout<<"START OF INITIAL UPDATE: "<<position<<velocity<<gsp<<"\n";
	if (freeze) return;
	if (grounded) {
		Vector along = Vector(platform.normal.y, -platform.normal.x);
		if (along.x<0) along*=-1;
		float xspd = gsp * SlopeFactor(along.x);

		velocity = Vector(1, along.y/along.x) * xspd;
	}
}

void Player::Update() {
	PlayerState ps = ChooseState();
	if (ps!=state) ChangeState(ps);
	ExecuteState();
}

PlayerState Player::ChooseState() {
	if (grounded) return STDGROUND;
	else return STDAIR;
}

void Player::ChangeState(PlayerState choice) {
	state=choice;
}

void Player::ExecuteState() {
	std::cout<<"START OF EXECUTE STATE: "<<(int) grounded<<position<<velocity<<gsp<<"\n";
	if (freeze) return;
	Vector amode = Vector(mode.y, -mode.x);
	if (amode.x<0) amode*=-1;
	float xIn = manager->InputX(playerNo);
	if (xIn!=0) facing = sign(xIn);
	if (state==STDGROUND) {
		if (xIn==0 && gsp!=0) {
			std::cout<<"SLIDING\n";
			gsp=sign(gsp)*std::max(std::abs(gsp)-Friction()*manager->DT(), 0.0f);
		}
		else if ((xIn!=0) && (xIn*gsp)>=0 && std::abs(gsp)<TopSpeed()) {
			std::cout<<"ACCELERATING\n";
			gsp+=xIn*Accel()*manager->DT();
			if (std::abs(gsp)>TopSpeed()) {
				gsp = TopSpeed()*sign(gsp);
			}
		}
		else if ((xIn*gsp)<0) {
			std::cout<<"DECELERATING\n";
			gsp+=xIn*Decel()*manager->DT();
		}
		if (manager->InputA(playerNo)==PRESSED) {
			std::cout<<"JUMPING\n";
			velocity=Jumped();
			grounded=false;
		}
	}
	if (state == STDAIR) {
		float current = velocity * amode;
		float other = velocity * mode;
		if ((xIn*current)>=0 && std::abs(current)<TopSpeed()) {
			current+=xIn*AirAccel()*manager->DT();
			if (std::abs(current)>TopSpeed()) {
				current = TopSpeed()*sign(current);
			}
		}
		else if ((xIn*current)<0) {
			current+=xIn*AirDecel()*manager->DT();
		}
		if (!bounced && other<-MinJump() && (manager->InputA(playerNo)==RELEASED || manager->InputA(playerNo)==OFF)) {
			other=-MinJump();
		}
		other+=Gravity() * manager->DT();
		if (other>TerminalVel()) {
			other=TerminalVel();
		}
		velocity = amode * current + mode * (other + Gravity() * manager->DT());
	}
	std::cout<<"END: "<<(int) grounded<<position<<velocity<<gsp<<"\n";
}

void Player::ResolveMovement() {
	std::cout<<"START OF RESOLVE MOVEMENT: "<<(int) grounded<<position<<velocity<<gsp<<"\n";
	if (freeze) return;
	float TOI = 1;
	Vector wallNormal;
	std::vector<CollisionResult> wallCheck = manager->collision->CheckCollisionsSweep(body, velocity*manager->DT());
	for (auto it = wallCheck.begin(); it!=wallCheck.end(); it++) {
		if ((!((*it).other->GetTypeFlag()&SOLID))||((*it).normal*mode)!=0 || (*it).toi<-16) continue;
		if ((*it).toi<TOI) {
			TOI=(*it).toi;
			wallNormal=(*it).normal;
		}
	}
	position+=velocity*TOI*manager->DT();
	if (TOI<1) {
		velocity = velocity - wallNormal*projection(velocity, wallNormal);
	}
	std::cout<<"WALL CHECK RESOLVED: "<<(int) grounded<<position<<velocity<<gsp<<"\n";
	if (grounded) {
		std::vector<CollisionResult> groundCheck = manager->collision->CheckCollisionsSweep(body, mode*body->shape->ContainBox().h/2);
		grounded=false;
		for (auto it = groundCheck.begin(); it!=groundCheck.end(); it++) {
			if ((!((*it).other->GetTypeFlag()&SOLID))||((*it).normal*mode)==0) continue;
			position+=-mode*TOIModified(*it)*body->shape->ContainBox().h/2;
			grounded=true;
			platform=(*it);
			bounced=false;
			break;
		}
		if (!grounded) {
			velocity=LostGround();
		}
	}
	else {
		if (velocity*mode>=0) {
			std::vector<CollisionResult> groundCheck = manager->collision->CheckCollisionsSweep(body, mode);
			for (auto it = groundCheck.begin(); it!=groundCheck.end(); it++) {
				if ((!((*it).other->GetTypeFlag()&SOLID))||((*it).normal*mode)==0) continue;
				float toi = TOIModified(*it);
				if (toi>0) continue;
				position+=mode*toi;
				grounded=true;
				platform=(*it);
				bounced=false;
				break;
			}
			if (grounded) {
				gsp=GainedGround();
			}
		}
	}
	std::cout<<"GROUND CHECK RESOLVED: "<<(int) grounded<<position<<velocity<<gsp<<"\n";

}

void Player::Render() {
	manager->RenderTexture(texture, position);
}

float Player::TOIModified(CollisionResult ground) {
	return ground.toi;
}
