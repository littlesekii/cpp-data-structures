#include "linked_list_test.hpp"

#include <iostream>

#include "../Linear/LinkedList/linked_list.hpp"

void LinkedListTest::linkedListTest() 
{
	LinkedList<int>* list = new LinkedList<int>();

	showLinkedListProperties(list);

	list->push_back(10);

	list->push_back(11);

	list->push_front(9);

	list->push_back(19);

	list->push_front(12);

	showLinkedListProperties(list);

	std::cout << list->remove(12) << "\n";
	//std::cout << list->remove(19) << "\n";

	//std::cout << list->remove(10) << "\n";

	std::cout << list->pop_front() << "\n";
	std::cout << list->pop_back() << "\n";
	std::cout << list->pop_front() << "\n";
	std::cout << list->pop_front() << "\n";


	showLinkedListProperties(list);

}

void LinkedListTest::showLinkedListProperties(LinkedList<int>* list) 
{

	if (list->isEmpty())
		std::cout << "Linked List is empty!\n";
	else
		std::cout << "Linked List is not empty!\n";
	std::cout << std::endl;

	std::cout << "Linked List size: " << list->size() << '\n';
	try {
		std::cout << "Current value from front: " << list->peek_head() << '\n';
	}
	catch (LinkedListUnderflowException e) {
		std::cout << "Current value from front: NULL\n";
	}
	try {
		std::cout << "Current value from back: " << list->peek_tail() << '\n';
	}
	catch (LinkedListUnderflowException e) {
		std::cout << "Current value from back: NULL\n";
	}
	std::cout << std::endl;
}