#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP

#include "../Linear/Stack/static_stack.hpp"

class StackTest
{
public:
	static void staticStackTest();

private:
	static void showStaticStackProperties(StaticStack<int>* stack);
};

#endif // !STACK_TEST_HPP