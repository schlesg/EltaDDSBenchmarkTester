
#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

class Timer
{
public:
	Timer();
	void start(int interval, std::function<void(void)> func);
	void stop();

private:
	bool  _execute;
};