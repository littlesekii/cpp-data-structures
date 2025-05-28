#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <optional>
#include "queue_exception.hpp"

template <typename type>
class StaticQueue
{
public:

	StaticQueue();
	StaticQueue(size_t size);

	~StaticQueue();

	void push(type item);
	type shift();
	type peek();

	size_t size();
	size_t capacity();
	bool isEmpty();
	bool isFull();

private:
	type* items;
	size_t currentSize;
	size_t maxSize;

};

template <typename type>
StaticQueue<type>::StaticQueue()
{
	maxSize = 100;
	currentSize = 0;
	items = new type[maxSize];
}

template <typename type>
StaticQueue<type>::StaticQueue(size_t capacity)
{
	this->maxSize = capacity;
	currentSize = 0;
	items = new type[this->maxSize];
}

template <typename type>
StaticQueue<type>::~StaticQueue()
{
	delete[] items;
}

template <typename type>
void StaticQueue<type>::push(type item)
{
	if (isFull())
		throw QueueOverflowException("Queue is full");

	items[currentSize++] = item;
}

template <typename type>
type StaticQueue<type>::shift()
{
	if (isEmpty())
		throw QueueUnderflowException("Queue is empty");

	type nextItem = items[0];

	for (size_t i = 0; i < currentSize; i++)
	{
		if (i < currentSize - 1)
			items[i] = items[i + 1];	
	}
	--currentSize;

	return nextItem;
}

template<typename type>
type StaticQueue<type>::peek()
{
	if (isEmpty())
		throw QueueUnderflowException("Queue is empty");

	return items[0];
}

template <typename type>
size_t StaticQueue<type>::size() { return currentSize; }

template <typename type>
size_t StaticQueue<type>::capacity() { return maxSize; }

template <typename type>
bool StaticQueue<type>::isEmpty() { return currentSize == 0; }

template <typename type>
bool StaticQueue<type>::isFull() { return currentSize == maxSize; }

#endif // !STATIC_QUEUE_HPP