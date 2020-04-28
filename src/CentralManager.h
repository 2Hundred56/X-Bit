/*
 * CentralManager.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_
#include <vector>
class RenderLayer;
class CentralManager {
public:
float PixelsPerUnit();
std::vector<RenderLayer*> RenderLayers();
};

#endif /* CENTRALMANAGER_H_ */
