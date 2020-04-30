/* main.cpp - created on Apr 29, 2020
 */
#include "CentralManager.h"
int main (int argc, char* args[]) {
	CentralManager* manager = new CentralManager();
	manager->Initialize();
	while (manager->Update());
	manager->End();
}


