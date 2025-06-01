#ifndef QUEUE_TEST_HPP
#define QUEUE_TEST_HPP

#include "../Linear/Queue/static_queue.hpp"
#include "../Linear/Queue/static_circular_queue.hpp"

class QueueTest
{
public:
	static void staticQueueTest();
	static void staticCircularQueueTest();

	static void queuesPerformanceTest();

private:
	static void showQueueProperties(IQueue<int>* queue);
};

#endif // !QUEUE_TEST_HPP