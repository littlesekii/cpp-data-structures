#include "Tests/stack_test.hpp"
#include "Tests/queue_test.hpp"

int main()
{
	//StackTest::staticStackTest();
	//QueueTest::staticQueueTest();
	//QueueTest::staticCircularQueueTest();
	QueueTest::queuesPerformanceTest();
	return 0;
}