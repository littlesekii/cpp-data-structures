#include "queue_test.hpp"

#include <iostream>
#include <stdexcept>

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
/// <summary>
/// 
/// </summary>

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