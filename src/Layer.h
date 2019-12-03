/*
 * Layer.h
 *
 *  Created on: Dec 1, 2019
 *      Author: triforce
 */

#ifndef LAYER_H_
#define LAYER_H_

class CentralManager;
class Layer {
public:
	Layer(CentralManager* manager) : manager(manager) {

	}
	virtual ~Layer() {

	}
	virtual void Render() = 0;
protected:
	CentralManager* manager;
};



#endif /* LAYER_H_ */
