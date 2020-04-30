/* Timer.cpp - created on Apr 30, 2020
 */

#include "Timer.h"

Timer::Timer() {
	t0 = std::chrono::high_resolution_clock::now();
	t1 = std::chrono::high_resolution_clock::now();
}

float Timer::Mark() {
	t0 = t1;
	t1 = std::chrono::high_resolution_clock::now();
	return ((std::chrono::duration<float>) (t1 - t0)).count();
}
