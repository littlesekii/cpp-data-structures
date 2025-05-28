#include "stacktest.hpp"

#include <iostream>
#include <stdexcept>
#include "../Linear/Stack/stack.hpp"

void StackTest::staticStackTest()
{
	const size_t MAX_CAP = 5;

	StaticStack<int>* stack = new StaticStack<int>(MAX_CAP);

	showStaticStackProperties(stack);

	std::cout << "Filling stack...\n";
	int i = 0;
	while(!stack->isFull())
	{
		try {
			stack->push(++i);
			std::cout << i << '\n';
		}
		catch (StackOverflowException e) {
			std::cout << e.what() << '\n';
		}
		
	}

	std::cout << "----------------------------\n";

	showStaticStackProperties(stack);

	std::cout << "Emptying stack..\n";
	while (!stack->isEmpty()) {
		try {
			std::cout << stack->pop() << '\n';
		}
		catch (StackUnderflowException e) {
			std::cout << e.what() << '\n';
		}
	}
}

void StackTest::showStaticStackProperties(StaticStack<int>* stack) {
	
	if (stack->isEmpty())
		std::cout << "Stack is empty!\n";
	else
		std::cout << "Stack is not empty!\n";

	if (stack->isFull())
		std::cout << "Stack is full!\n";
	else
		std::cout << "Stack is not full!\n";
	std::cout << std::endl;

	std::cout << "Stack capacity: " << stack->capacity() << '\n';
	std::cout << "Stack size: " << stack->size() << '\n';
	try {
		std::cout << "Current value from top: " << stack->peek() << '\n';
	}
	catch (StackUnderflowException e) {
		std::cout << "Current value from top: NULL\n";
	}
	std::cout << std::endl;
}
