#include "Timer.hpp"

Timer::Timer() :_execute(false)
{
}

void Timer::start(int interval, std::function<void(void)> func)
{
	_execute = true;
	std::thread([=]()
	{
		while (_execute) 
		{
			func();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}
	}).detach();
}
void Timer::stop()
{
	_execute = false;
}
