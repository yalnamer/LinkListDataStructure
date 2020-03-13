#pragma once
#include "Node.h"

template <class T> class LinkedList
{

private:

	Node<T>* head; //> Store the pointer to the first element

public:

	int length;

	LinkedList();

	//Insert a item into the linked list, by default items are inserted to beginning
	void insert(T x, bool insertBeg = true);
	// Insert a element into the nth position
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
inline void LinkedList<T>::insert(T x,bool insertBeg)
{
	Node<T>* temp1 = new Node<T>();//Create a new node
	temp1->data = x; //> set data in new node to x
	temp1->next = head; //>new node now points to where head points

	
	if (insertBeg || length == 0) //> insert to beginning, if insertBeg setting on, or empty list
	{
		head = temp1; //> head points to new node
	}
	else
	{
		Node<T>* temp2 = head; // create a temp node for traversal

		//traverse to element before last element
		for (int i = 0; i < length - 1; i++)
			temp2 = temp2->next;
		
		
		//Fix links
		temp1->next = nullptr; //new to nullptr, which indicates end
		temp2->next = temp1; //element at last node now point

	}
	length++;
}

template<class T>
inline void LinkedList<T>::insert(T x, int position)
{
	//Make sure that position is valid for linked list
	if (position < 0 || position >(length + 1))
	{
		std::cout << "Error: Out of Range\n";
		return;
	}

	//Create a new node to add to linked list
	Node<T>* temp1 = new Node<T>();
	temp1->data = x; //> Store data into new element
	temp1->next = head; //>Temporarily set address to head, to start traversing

	// in the case that the desired position is the 0th element( the first element)
	// we don't need to traverse, all we have to do is adjust the links of the nodes
	// the new element now points to the element that the head used to point to
	// and the head now points to the new element itself, finished
	if (position == 0)
	{
		temp1->next = head;
		head = temp1;
		length++;
		return;
	}

	Node<T>* temp2 = head; //Create a node to use for traversal

	//traverse to the element before the desired position
	for (int i = 0; i < (position - 1);i++)
		temp2 = temp2->next;

	temp1->next = temp2->next;//>the new node now points to the element which was in the nth position
	temp2->next = temp1; //> the the element in the n-1 position now points to the new node

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
