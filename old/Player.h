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

enum PlayerState {
	 STDGROUND, STDAIR
};
class Texture;
class Player: public GameObject {
public:
	virtual void InitialUpdate();
	virtual void ResolveMovement();
	virtual void Update();
	virtual PlayerState ChooseState();
	virtual void ChangeState(PlayerState state);
	virtual void ExecuteState();
	virtual void Render();

	virtual float SlopeFactor(float ax) {return 1;}
	virtual float TOIModified(CollisionResult ground);

	virtual float TopSpeed() = 0;
	virtual float AirAccel() = 0;
	virtual float AirDecel() = 0;
	virtual float Accel() = 0;
	virtual float Decel() = 0;
	virtual float Friction() = 0;
	virtual float MinJump() = 0;
	virtual float Gravity() = 0;
	virtual float TerminalVel() = 0;

	virtual Vector LostGround() = 0;
	virtual Vector Jumped() = 0;
	virtual float GainedGround() = 0;
protected:
	float gsp = 0;
	char facing = 1;
	Vector mode = Vector(0,1);
	bool grounded = false;
	bool bounced = false;
	Vector velocity;
	CollisionResult platform;
	AttachedHandle* body;
	PlayerState state;
	Texture* texture;
	bool freeze = false;
	unsigned char playerNo = 0;
};

#endif /* PLAYER_H_ */
