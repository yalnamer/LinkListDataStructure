#pragma once
#include "Node.h"

template <class T> class LinkedList
{

private:

	Node<T>* head;
	

public:

	int length;

	LinkedList();

	void insert(T x);
	void insert(T x, int position);

	void print();
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
	length = 0;
}

template<class T>
inline void LinkedList<T>::insert(T x)
{
	Node<T>* temp = new Node<T>();//Create a new node
	temp->data = x; //> set data in new node to x
	temp->next = head;
	head = temp;
	length++;
}

template<class T>
inline void LinkedList<T>::insert(T x, int position)
{
	if (position < 0 || position >(length + 1))
	{
		std::cout << "Error: Out of Range\n";
		return;
	}

	Node<T>* temp1 = new Node<T>();
	temp1->data = x;
	temp1->next = head;

	if (position == 0)
	{
		temp1->next = head;
		head = temp1;
		length++;
		return;
	}

	Node<T>* temp2 = head;

	for (int i = 0; i < (position - 1);i++)
	{
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	temp2->next = temp1;

	length++;
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
