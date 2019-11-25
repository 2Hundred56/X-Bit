/*
 * CentralManager.h
 *
 *  Created on: Sep 2, 2019
 *      Author: triforce
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_
#include "Time.h"
#include "Rect.h"
class CentralManager {
public:
	CentralManager();
	virtual ~CentralManager();
	TimeDelta deltaTime();
protected:
	Rect camera;
};

#endif /* CENTRALMANAGER_H_ */
