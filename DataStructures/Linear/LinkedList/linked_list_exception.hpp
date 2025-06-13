#ifndef LINKED_LIST_EXCEPTION_HPP
#define LINKED_LIST_EXCEPTION_HPP

#include <stdexcept>

class LinkedListUnderflowException : public std::runtime_error
{
public:
	LinkedListUnderflowException(const char* msg) : std::runtime_error(msg) {}
};

class LinkedListNotFoundException : public std::runtime_error
{
public:
	LinkedListNotFoundException(const char* msg) : std::runtime_error(msg) {}
};

#endif // !LINKED_LIST_EXCEPTION_HPP