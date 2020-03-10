/*
 * TestObject.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: triforce
 */

#include "TestObject.h"
#include "BlankTexture.h"
#include "CentralManager.h"
TestObject::TestObject(int size, Vector pos) : position(pos) {
	texture = new BlankTexture(size, size);
}

void TestObject::Render() {
	manager->RenderTexture(texture, position);
}
