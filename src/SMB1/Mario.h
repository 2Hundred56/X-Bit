#include "../Player.h"
#include "../BlankTexture.h"
namespace SMB1 {
class Mario: public Player {
public:
	Mario() {
		texture=new BlankTexture(16, 16);
		body=new AttachedHandle(new AABB(8, 8), this, 0);
	}
	bool IsRunning() {
		InputState b = InputB();
		return b==PRESSED || b==ON;
	}
	virtual float Friction() {
		return 0.046875;
	}
	virtual float Accel() {
		return IsRunning()?0.054745:0.035278;
	}
	virtual float Decel() {
		return 0.101563;
	}
	virtual float TopSpeed() {
		return IsRunning()?2.5625:1.5625;
	}
	float AirAccel() {
		return IsRunning()?0.0508422:0.0352783;
	}
	float AirDecel() {
		return IsRunning()?0.0508422:0.0352783;
	}
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
	}
	virtual float MinWalk() {
		return 1.1875;
	}
};
}
