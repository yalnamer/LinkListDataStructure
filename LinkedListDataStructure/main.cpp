
#include "LinkedList.h"
#include "Node.h"
#include <iostream>




int main()
{


	LinkedList<int> list;

	
	//int n; //How many numbers does user want to input?

	//
	//while (std::cout << "How many numbers would you like to input: " && !(std::cin >> n))
	//{
	//	std::cout << "Not a Valid Number \n";
	//	std::cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//}
	//

	//std::cout << "\n";

	//for (int i = 0; i < n; i++)
	//{
	//	int x;

	//	bool valid = false;

	//	while (std::cout << "Enter your number: " && !(std::cin >> x))
	//	{
	//		std::cout << "!! Not a Valid Number\n";
	//		std::cin.clear();
	//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	}
	//	list.insert(x);
	//	list.print();

	//}

	list.insert(878, 0);
	list.insert(5);
	list.insert(23, 1);
	list.insert(13);

	list.print();
}
