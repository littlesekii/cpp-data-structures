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
	type peek() const;

	size_t size() const;
	size_t capacity() const;
	bool isEmpty() const;
	bool isFull() const;

private:
	type* items;
	size_t currentSize;
	size_t maxSize;

};

template <typename type>
StaticQueue<type>::StaticQueue(): 
	maxSize(100), 
	currentSize(0), 
	items(new type[maxSize]) 
{}

template <typename type>
StaticQueue<type>::StaticQueue(size_t capacity) :
	maxSize(capacity > 0 ? capacity : throw std::invalid_argument("Capacity must be > 0")),
	currentSize(0),
	items(new type[capacity])
{}

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
type StaticQueue<type>::peek() const
{
	if (isEmpty())
		throw QueueUnderflowException("Queue is empty");

	return items[0];
}

template <typename type>
size_t StaticQueue<type>::size() const { return currentSize; }

template <typename type>
size_t StaticQueue<type>::capacity() const { return maxSize; }

template <typename type>
bool StaticQueue<type>::isEmpty() const { return currentSize == 0; }

template <typename type>
bool StaticQueue<type>::isFull() const { return currentSize == maxSize; }

#endif // !STATIC_QUEUE_HPP