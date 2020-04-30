/*
 * CentralManager.h
 *
 *  Created on: Apr 28, 2020
 *      Author: triforce
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_
#include <vector>
#include <chrono>
class Camera;
class Timer;
class RenderLayer;
class CentralManager {
public:
CentralManager();
float PixelsPerUnit();
bool Update();
void Initialize();
void End();
std::vector<RenderLayer*> RenderLayers();
protected:
std::vector<RenderLayer*> renderLayers;
std::vector<Camera*> cameras;
Timer* timer;
float overflow;
};

#endif /* CENTRALMANAGER_H_ */
