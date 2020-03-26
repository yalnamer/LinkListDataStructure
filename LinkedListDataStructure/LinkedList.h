#pragma once
#include "Node.h"

template <class T> class LinkedList
{

private:

	Node<T>* head; //> Store the pointer to the first element
	int length;

public:

	

	LinkedList();

	//Insert a item into the linked list, by default items are inserted to beginning
	void insert(T x, bool insertBeg = true);
	// Insert a element into the nth position
	void insert(T x, int position); 
	// Remove an element from the nth position 
	void remove(int position);

	//Reverse the linked list
	void reverse();

	//Reverse the linked list using recursion
	void reverse(Node<T>* node);

	//Print the elements of the list
	void print();
	
	//print the elements of the list using recursion
	void print(Node<T>* node);

	//print the elements in reverse order using recursion
	void reversePrint(Node<T>* node);

	Node<T>* getHead() { return head; }
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
	if (position < 0 || position > length)
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
	for (int i = 0; i < (position - 1); i++)
	{
		if(temp2->next != nullptr)
			temp2 = temp2->next;
	}
	temp1->next = temp2->next;//>the new node now points to the element which was in the nth position
	temp2->next = temp1; //> the the element in the n-1 position now points to the new node

	length++;
}

template<class T>
inline void LinkedList<T>::remove(int position)
{

	//If the length of the list is zero, then the list is empty, therefore can't remove anything
	if (length == 0)
	{
		std::cout << "ERROR: The list is empty, nothing to remove.\n";
		return;
	}
	
	//Make sure the position is within range of the list
	if ( ( position < 0 )  || ( position > (length - 1) ) )
	{
		std::cout << "ERROR: Out of range.\n";
		return;
	}
	
	Node<T>* temp1 = head; //> Create a node that points to the first element

	//For the special case of deleting a node at the first element
	if (position == 0) 
	{
		head = temp1->next;
		delete(temp1);
		length--;
		return;
	}

	//traverse to the n-1 node of the list
	for (int i = 0; i < (position - 1); i++)
	{
		temp1 = temp1->next;
	}

	Node<T>* temp2 = temp1->next; //> Create a node that will point to the element which will be remved
	temp1->next = temp2->next; //The n-1 element will now point to the node after the removed element, so the links has been fixed
	delete(temp2); //free the memory of the old element

	length--;
}

template<class T>
inline void LinkedList<T>::reverse()
{
	//If the list is empty, there is nothing to reverse
	if (length == 0)
	{
		std::cout << "ERROR: Empty list";
		return;
	}

	//If there is only one element, there is no need to reverse the list will be the same
	if (length == 1)
		return;

	Node<T>* temp1 = head; //> The current node whose link will be reversed
	Node<T>* prev = nullptr; //> Need to store previous node to reverse link
	Node<T>* nextNode = nullptr; //> Need to store next link to traverse through list

	while (temp1 != nullptr)
	{
		nextNode = temp1->next; //>Store next node

		temp1->next = prev; //>Reverse link
		prev = temp1; //>Update previous node

		temp1 = nextNode; //> Traverse to next node
	}

	head = prev; //> After the while loop, point head to new first element
}

template<class T>
inline void LinkedList<T>::reverse(Node<T>* node)
{
	//Recursion exit condition
	//If the next node is null, we are at the last element,
	//So now we make the head point to last element, making it
	//the now the first element
	if (node->next == nullptr)
	{
		head = node;
		return;
	}

	//Call reverse on the next node in list
	reverse(node->next);


	Node<T>* newLink = node->next; //>New node will be the original list next node
	newLink->next = node; //>Set the node's next parameter to the current node, which will reverse the order 
	node->next = nullptr; //> Set the next element to nullptr, if this is the last call, then this will be the last element which is why it points to null
	

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

template<class T>
inline void LinkedList<T>::print(Node<T>* node)
{
	//Recurssion exit condition
	if (node == nullptr)
		return;

	std::cout << node->data << " - " ; //Print the element's data
	print(node->next); //Call print on the next element


}

template<class T>
inline void LinkedList<T>::reversePrint(Node<T>* node)
{
	//Recurrsion exit condition
	if (node == nullptr)
		return;

	reversePrint(node->next); //Call print on the next element
	std::cout << node->data << " - "; // print the current element data

}
