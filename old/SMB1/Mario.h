#include "../Player.h"
#include "../BlankTexture.h"
#include "../CentralManager.h"
namespace SMB1 {
class Mario: public Player {
public:
	Mario() {
		texture=new BlankTexture(16, 16);
		body=new AttachedHandle(new AABB(8, 8), this, GROUND, 0);
	}
	bool IsRunning() {
		InputState b = manager->InputB(playerNo);
		return b==PRESSED || b==ON;
	}
	virtual float TOIModified(CollisionResult ground) {
		float gNorm = std::abs(ground.normal.x/ground.normal.y);

		return ground.toi+(body->shape->ContainBox().w/2)*gNorm;
	}

	virtual float TopSpeed() {
		return IsRunning()?153.75:93.75;
	}
	virtual float AirAccel() {
		return (velocity.x<93.75)?133.59:200.39;
	}
	virtual float AirDecel() {
		return (velocity.x<93.75)?((std::abs(gsp)<60)?133.59:182.81):200.39;
	}
	virtual float Accel() {
		if (gsp==0) return 4.4531/manager->DT();
		else return IsRunning()?133.59:200.39;
	}
	virtual float Decel() {
		if (std::abs(gsp)<33.75) return std::abs(gsp)/manager->DT();
		else return 365.63;
	}
	virtual float Friction() {
		return 168.75;
	}
	virtual float MinJump() {
		return 60000;
	}
	virtual float Gravity() {
		//return 0;
		if (manager->InputA(playerNo)==ON && (velocity.y<0) && !bounced) {
			if (std::abs(gsp)<1) return 450;
			if (std::abs(gsp)<2.5) return 421.875;
			else return 562.5;
		}
		else {
			if (std::abs(gsp)<1) return 1575;
			if (std::abs(gsp)<2.5) return 1350;
			else return 2025;
		}
	}
	virtual float TerminalVel() {
		return 270;
	}

	virtual Vector LostGround() {
		Vector along = Vector(mode.y, -mode.x);
		if (along.x<0) along=along*-1;
		return along*gsp;
	}
	float JumpVelocity() {
		if (std::abs(gsp)<1) return 240;
		if (std::abs(gsp)<2.5) return 240;
		else return 300;
	}
	virtual Vector Jumped() {
		Vector along = Vector(mode.y, -mode.x);
		if (along.x<0) along=along*-1;
		return along*gsp-mode*JumpVelocity();
	}
	virtual float GainedGround() {
		return velocity.x;
	}
	/*
	virtual float JumpVelocity() {
		if (std::abs(gsp)<1) return 4;
		if (std::abs(gsp)<2.5) return 4;
		else return 5;
	}
	virtual float TerminalVel() {
		return 4.5;
	}
	virtual float Gravity() {
		if (InputA()==ON && (velocity.y>0) && !bounced) {
			if (std::abs(gsp)<1) return 0.125;
			if (std::abs(gsp)<2.5) return 0.1171875;
			else return 0.15625;
		}
		else {
			if (std::abs(gsp)<1) return 0.4375;
			if (std::abs(gsp)<2.5) return 0.375;
			else return 0.5625;
		}
	}*/
};
}
