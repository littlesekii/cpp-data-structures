#ifndef LINKED_LIST_TEST_HPP
#define LINKED_LIST_TEST_HPP

#include "../Linear/LinkedList/linked_list.hpp"

class LinkedListTest
{
public:
	static void linkedListTest();

private:
	static void showLinkedListProperties(LinkedList<int>* list);
};

#endif // !LINKED_LIST_TEST_HPP