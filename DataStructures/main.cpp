#include "Tests/stack_test.hpp"
#include "Tests/queue_test.hpp"
#include "Tests/linked_list_test.hpp"

int main()
{
	//StackTest::staticStackTest();
	//QueueTest::staticQueueTest();
	//QueueTest::staticCircularQueueTest();
	//QueueTest::queuesPerformanceTest();

	LinkedListTest::linkedListTest();
	return 0;
}