
#include "LinkedList.h"
#include "Node.h"
#include <iostream>


//void insert(Node** ptrToHead,int x);
//void print(Node* head);

int main()
{


	LinkedList<int> list;

	
	int n; //How many numbers does user want to input?

	std::cout << "How many numbers would you like to input? :";
	std::cin >> n;
	std::cout << "\n";

	for (int i = 0; i < n; i++)
	{
		int x;

		std::cout << "Enter number: ";
		std::cin >> x;

		list.insert(x);
		list.print();


	}
}
//
//	//A function to insert a element into the linked list
//	void insert(Node** ptrToHead, int x)
//	{
//		Node* temp = new Node(); //Creating a new node
//		temp->data = x; //Let the data of the new node be equal to x
//		temp->next = *ptrToHead; 
//
//		*ptrToHead = temp; //Link head to new node, which means new node is the first element
//	}

	//void print(Node* head)
	//{
	//	std::cout << "List is: ";
	//	Node* temp = head;
	//	while (temp != nullptr)
	//	{
	//		std::cout << temp->data << " ";
	//		temp = temp->next;
	//	}
	//	std::cout << std::endl;
	//}
