#ifndef I_QUEUE_HPP
#define I_QUEUE_HPP

template <typename type>
class IQueue
{
public:

	virtual ~IQueue() = default;

	virtual void push(type item) = 0;
	virtual type shift() = 0;
	virtual type peek() const = 0;

	virtual size_t size() const = 0;
	virtual size_t capacity() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
};

#endif // !I_QUEUE_HPP