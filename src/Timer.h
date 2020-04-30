/* Timer.h - created on Apr 30, 2020
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <chrono>
class Timer {
public:
	Timer();
float Mark();
protected:
	std::chrono::high_resolution_clock::time_point t0;
	std::chrono::high_resolution_clock::time_point t1;
};

#endif /* TIMER_H_ */
