#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <stdexcept>

class StackOverflowException : public std::runtime_error 
{
public:
	StackOverflowException(const char* msg) : std::runtime_error(msg) {}
};

class StackUnderflowException : public std::runtime_error
{
public:
	StackUnderflowException(const char* msg) : std::runtime_error(msg) {}
};

#endif // !STACK_EXCEPTION_HPP