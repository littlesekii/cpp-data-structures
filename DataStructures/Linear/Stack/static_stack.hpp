#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP

#include <optional>
#include "stack_exception.hpp"

template <typename type>
class StaticStack
{
public:

	StaticStack();
	StaticStack(size_t size);

	~StaticStack();

	void push(type item);
	type pop();
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
StaticStack<type>::StaticStack(): 
	maxSize(100), 
	currentSize(0), 
	items(new type[maxSize]) 
{}

template <typename type>
StaticStack<type>::StaticStack(size_t capacity): 
	maxSize(capacity > 0 ? capacity : throw std::invalid_argument("Capacity must be > 0")),
	currentSize(0), 
	items(new type[capacity]) 
{}

template <typename type>
StaticStack<type>::~StaticStack()
{
	delete[] items;
}

template <typename type>
void StaticStack<type>::push(type item)
{
	if (isFull())
		throw StackOverflowException("Stack is full");

	items[currentSize++] = item;
}

template <typename type>
type StaticStack<type>::pop()
{
	if (isEmpty())
		throw StackUnderflowException("Stack is empty");

	return items[--currentSize];
}

template<typename type>
type StaticStack<type>::peek() const
{
	if (isEmpty())
		throw StackUnderflowException("Stack is empty");

	return items[currentSize - 1];
}

template <typename type>
size_t StaticStack<type>::size() const { return currentSize; }

template <typename type>
size_t StaticStack<type>::capacity() const { return maxSize; }

template <typename type>
bool StaticStack<type>::isEmpty() const { return currentSize == 0; }

template <typename type>
bool StaticStack<type>::isFull() const { return currentSize == maxSize; }

#endif // !STATIC_STACK_HPP