/*
 * Player.h
 *
 *  Created on: Mar 9, 2020
 *      Author: triforce
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"
#include "CollisionTerms.h"
enum InputState {
	PRESSED, ON, RELEASED, OFF
};
enum PlayerState {
	 GROUND, AIR
};
class Texture;
class Player: public GameObject {
public:
	float InputX() {return x;}
	float InputY() {return y;}
	InputState InputA() {return A;}
	InputState InputB() {return B;}
	InputState InputC() {return C;}
	InputState InputD() {return D;}
	virtual float Friction() = 0;
	virtual float Accel() = 0;
	virtual float Decel() = 0;
	virtual float MinWalk() = 0;
	virtual float TopSpeed() = 0;
	virtual float AirAccel() = 0;
	virtual float AirDecel() = 0;
	virtual float JumpVelocity() = 0;
	virtual float TerminalVel() = 0;
	virtual float Gravity() = 0;
	virtual void InitialUpdate();
	virtual void ResolveMovement();
	virtual void Update();
	virtual PlayerState ChooseState();
	virtual void ChangeState(PlayerState state);
	virtual void ExecuteState();
	virtual void Render();

protected:
	float gsp = 0;
	char facing;
	bool grounded = false;
	bool bounced = false;
	Vector velocity;
	CollisionResult platform;
	AttachedHandle* body;
	PlayerState state;
	Texture* texture;
private:
	InputState A = OFF, B = OFF, C = OFF, D = OFF;
	float x = 0;
	float y = 0;
};

#endif /* PLAYER_H_ */
