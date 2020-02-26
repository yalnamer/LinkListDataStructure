#pragma once
#include "Node.h"

template <class T> class LinkedList
{

private:

	Node<T>* head;


public:

	LinkedList();

	void insert(int x);

	void print();
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template<class T>
inline void LinkedList<T>::insert(int x)
{
	Node<T>* temp = new Node<T>();//Create a new node
	temp->data = x; //> set data in new node to x
	temp->next = head;
	head = temp;
}

template<class T>
inline void LinkedList<T>::print()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " - ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
