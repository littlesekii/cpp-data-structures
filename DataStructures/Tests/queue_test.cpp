#include "queue_test.hpp"

#include <iostream>
#include <stdexcept>
#include <chrono>

#include "../Linear/Queue/static_queue.hpp"
#include "../Linear/Queue/static_circular_queue.hpp"

void QueueTest::staticQueueTest()
{
	const size_t MAX_CAP = 5;

	StaticQueue<int>* queue = new StaticQueue<int>(MAX_CAP);

	showQueueProperties(queue);

	std::cout << "Filling queue...\n";
	int i = 0;
	while (!queue->isFull())
	{
		try {
			queue->push(++i);
			std::cout << i << '\n';
		}
		catch (QueueOverflowException e) {
			std::cout << e.what() << '\n';
		}

	}

	std::cout << "----------------------------\n";

	showQueueProperties(queue);

	std::cout << "Emptying queue...\n";
	while (!queue->isEmpty()) {
		try {
			std::cout << queue->shift() << '\n';
		}
		catch (QueueUnderflowException e) {
			std::cout << e.what() << '\n';
		}
	}

	delete queue;
}

void QueueTest::staticCircularQueueTest()
{
	const size_t MAX_CAP = 5;

	StaticCircularQueue<int>* queue = new StaticCircularQueue<int>(MAX_CAP);

	showQueueProperties(queue);

	std::cout << "Filling queue...\n";
	int i = 0;
	while (!queue->isFull())
	{
		try {
			queue->push(++i);
			std::cout << i << '\n';

			if (i == 4 || i == 2) {
				std::cout << "VALUE \"" << queue->shift() << "\" REMOVED\n";
			}
		}
		catch (QueueOverflowException e) {
			std::cout << e.what() << '\n';
		}

	}

	std::cout << "----------------------------\n";

	showQueueProperties(queue);

	std::cout << "Emptying queue...\n";
	while (!queue->isEmpty()) {
		try {
			std::cout << queue->shift() << '\n';	
		}
		catch (QueueUnderflowException e) {
			std::cout << e.what() << '\n';
		}
	}

	delete queue;
}

void QueueTest::queuesPerformanceTest()
{

	int amount = 100000;
	std::cout << "Performance test with " << amount << " items\n\n";

	std::cout << "         STATIC QUEUE\n";
	std::cout << "===============================\n";
	auto start = std::chrono::steady_clock::now();

	StaticQueue<int>* queue1 = new StaticQueue<int>(amount);

	for (size_t i = 0; !queue1->isFull(); i++)
		queue1->push(i);
	while (!queue1->isEmpty())
		queue1->shift();

	delete queue1;

	auto end = std::chrono::steady_clock::now();
	std::cout << "Elapsed Time: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0f
		<< "s\n";

	std::cout << "\n";
	std::cout << "     STATIC CIRCULAR QUEUE\n";
	std::cout << "===============================\n";
	start = std::chrono::steady_clock::now();

	StaticCircularQueue<int>* queue2 = new StaticCircularQueue<int>(amount);

	for (size_t i = 0; !queue2->isFull(); i++)
		queue2->push(i);
	while (!queue2->isEmpty())
		queue2->shift();

	delete queue2;

	end = std::chrono::steady_clock::now();
	std::cout << "Elapsed Time: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0f
		<< "s\n";
}

void QueueTest::showQueueProperties(IQueue<int>* queue) {

	if (queue->isEmpty())
		std::cout << "Queue is empty!\n";
	else
		std::cout << "Queue is not empty!\n";

	if (queue->isFull())
		std::cout << "Queue is full!\n";
	else
		std::cout << "Queue is not full!\n";
	std::cout << std::endl;

	std::cout << "Queue capacity: " << queue->capacity() << '\n';
	std::cout << "Queue size: " << queue->size() << '\n';
	try {
		std::cout << "Current value from front: " << queue->peek() << '\n';
	}
	catch (QueueUnderflowException e) {
		std::cout << "Current value from front: NULL\n";
	}
	std::cout << std::endl;
}