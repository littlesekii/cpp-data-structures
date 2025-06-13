#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "linked_list_exception.hpp"

template<typename type>
class LinkedList 
{
public:

	LinkedList();
	~LinkedList();

	void push_back(type item);
	void push_front(type item);

	type pop_front();
	type pop_back();
	type remove(type);

	type peek_head() const;
	type peek_tail() const;

	size_t size() const;
	bool isEmpty() const;

private:

	class Node
	{
	private:
		type item;
		Node* next;

	public:
		Node(type item);
		~Node();

		type value() const;
		void setValue(type item);
		Node* nextNode() const;
		void setNextNode(Node* next);

	};

	Node* head;
	Node* tail;
	size_t currentSize;

};

/* LINKED LIST */

template<typename type>
LinkedList<type>::LinkedList() : head(nullptr), tail(nullptr), currentSize(0) {}

template<typename type>
LinkedList<type>::~LinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{ 
		Node* next = current->nextNode();
		delete current;
		current = next;
	}
	head = tail = nullptr;
}

template<typename type>
void LinkedList<type>::push_back(type item)
{
	Node* newNode = new Node(item);

	++currentSize;
	if (head == nullptr)
	{
		head = newNode;
		tail = head;
		return;
	}

	tail->setNextNode(newNode);
	tail = tail->nextNode();
}

template<typename type>
void LinkedList<type>::push_front(type item)
{
	Node* newNode = new Node(item);

	++currentSize;
	if (head == nullptr)
	{
		head = newNode;
		tail = head;
		return;
	}

	newNode->setNextNode(head);
	head = newNode;
}

template<typename type>
type LinkedList<type>::pop_front()
{
	if (isEmpty())
		throw LinkedListUnderflowException("Linked List is empty");

	type item = head->value();

	--currentSize;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;

		return item;
	}

	Node* next = head->nextNode();
	delete head;

	head = next;	

	return item;
}

template<typename type>
type LinkedList<type>::pop_back()
{
	if (isEmpty())
		throw LinkedListUnderflowException("Linked List is empty");

	type item = tail->value();
	--currentSize;

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;

		return item;
	}

	Node* newLastNode = head;
	while(newLastNode->nextNode() != tail)
	{
		newLastNode = newLastNode->nextNode();
	}
	delete newLastNode->nextNode();
	newLastNode->setNextNode(nullptr);

	tail = newLastNode;

	return item;
}

template<typename type>
type LinkedList<type>::remove(type item)
{
	if (isEmpty())
		throw LinkedListUnderflowException("Linked List is empty");

	if (head->value() == item)
	{	
		if (head == tail) 
		{
			delete head;
			head = tail = nullptr;
			return item;
		}
		
		Node* removedNode = head;
		head = head->nextNode();

		delete removedNode;
		--currentSize;

		return item;
	}

	Node* nodeBefore = head;
	while (nodeBefore->nextNode() != nullptr && nodeBefore->nextNode()->value() != item)
	{
		nodeBefore = nodeBefore->nextNode();
	}
	
	if (nodeBefore->nextNode() == nullptr) 
	{
		throw LinkedListUnderflowException("Element not found");
	}

	Node* removedNode = nodeBefore->nextNode();
	nodeBefore->setNextNode(removedNode->nextNode());
	
	if (removedNode == tail) 
	{
		tail = nodeBefore;
	}

	delete removedNode;
	--currentSize;
	
	return item;
}

template<typename type>
type LinkedList<type>::peek_head() const
{
	if (isEmpty())
		throw LinkedListUnderflowException("Linked List is empty");

	type item = head->value();
	return item;
}

template<typename type>
type LinkedList<type>::peek_tail() const
{
	if (isEmpty())
		throw LinkedListUnderflowException("Linked List is empty");

	type item = tail->value();
	return item;
}

template<typename type>
size_t LinkedList<type>::size() const
{
	return currentSize;
}

template<typename type>
bool LinkedList<type>::isEmpty() const
{
	return head == nullptr;
}

/* NODE */

template<typename type>
LinkedList<type>::Node::Node(type item) : item(item), next(nullptr) {}

template<typename type>
LinkedList<type>::Node::~Node() {}

template<typename type>
type LinkedList<type>::Node::value() const
{
	return item;
}

template<typename type>
inline void LinkedList<type>::Node::setValue(type item)
{
	this->item = item;
}

template<typename type>
typename LinkedList<type>::Node* LinkedList<type>::Node::nextNode() const
{
	return next;
}

template<typename type>
inline void LinkedList<type>::Node::setNextNode(Node* next)
{
	this->next = next;
}

#endif // !LINKED_LIST_HPP