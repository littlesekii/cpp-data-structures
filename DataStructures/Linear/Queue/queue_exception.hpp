#ifndef QUEUE_EXCEPTION_HPP
#define QUEUE_EXCEPTION_HPP

#include <stdexcept>

class QueueOverflowException : public std::runtime_error 
{
public:
	QueueOverflowException(const char* msg) : std::runtime_error(msg) {}
};

class QueueUnderflowException : public std::runtime_error
{
public:
	QueueUnderflowException(const char* msg) : std::runtime_error(msg) {}
};

#endif // !QUEUE_EXCEPTION_HPP