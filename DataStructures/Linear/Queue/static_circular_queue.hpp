#ifndef STATIC_CIRCULAR_QUEUE_HPP
#define STATIC_CIRCULAR_QUEUE_HPP

#include <optional>
#include "queue_exception.hpp"
#include "i_queue.hpp"

template <typename type>
class StaticCircularQueue : public IQueue<type>
{
public:

	StaticCircularQueue();
	StaticCircularQueue(size_t size);

	~StaticCircularQueue();

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

	size_t head;
	size_t tail;

};

template <typename type>
StaticCircularQueue<type>::StaticCircularQueue() :
	maxSize(100),
	currentSize(0),
	head(0),
	tail(0),
	items(new type[maxSize])
{}

template <typename type>
StaticCircularQueue<type>::StaticCircularQueue(size_t capacity) :
	maxSize(capacity > 0 ? capacity : throw std::invalid_argument("Capacity must be > 0")),
	currentSize(0),
	head(0),
	tail(0),
	items(new type[capacity])
{}

template <typename type>
StaticCircularQueue<type>::~StaticCircularQueue()
{
	delete[] items;
}

template <typename type>
void StaticCircularQueue<type>::push(type item)
{
	if (isFull())
		throw QueueOverflowException("Queue is full");

	items[tail] = item;

	tail = (tail + 1) % maxSize;
	++currentSize;
}

template <typename type>
type StaticCircularQueue<type>::shift()
{
	if (isEmpty())
		throw QueueUnderflowException("Queue is empty");

	type nextItem = items[head];

	head = (head + 1) % maxSize;
	--currentSize;

	return nextItem;
}

template<typename type>
type StaticCircularQueue<type>::peek() const
{
	if (isEmpty())
		throw QueueUnderflowException("Queue is empty");

	return items[head];
}

template <typename type>
size_t StaticCircularQueue<type>::size() const { return currentSize; }

template <typename type>
size_t StaticCircularQueue<type>::capacity() const { return maxSize; }

template <typename type>
bool StaticCircularQueue<type>::isEmpty() const { return currentSize == 0; }

template <typename type>
bool StaticCircularQueue<type>::isFull() const { return currentSize == maxSize; }

#endif // !STATIC_CIRCULAR_QUEUE_HPP