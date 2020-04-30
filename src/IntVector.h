/*
 * IntIntVector.h
 *
 *  Created on: Sep 4, 2019
 *      Author: triforce
 */

#ifndef INTIntVector_H_
#define INTIntVector_H_
#include <iostream>
class Vector;
class IntVector {
public:
	IntVector(int x, int y);
	explicit IntVector(Vector v);
	virtual ~IntVector();
	int x, y;
};

IntVector operator+ (IntVector, IntVector);
IntVector operator- (IntVector, IntVector);
float operator* (IntVector, IntVector);
IntVector operator* (IntVector, float);
IntVector operator/ (IntVector, float);
std::ostream& operator<<(std::ostream&, IntVector);


#endif /* INTIntVector_H_ */
