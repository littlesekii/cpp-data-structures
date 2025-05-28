#ifndef QUEUE_TEST_HPP
#define QUEUE_TEST_HPP

#include "../Linear/Queue/static_queue.hpp"

class QueueTest
{
public:
	static void staticQueueTest();

private:
	static void showStaticQueueProperties(StaticQueue<int>* stack);
};

#endif // !QUEUE_TEST_HPP