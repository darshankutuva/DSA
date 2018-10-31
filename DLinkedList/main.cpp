#include "DLinkedList.h"

int main()
{
	unsigned short operation;
	
	int value;
	
	CDLinkedList<int> *doublyLinkedList = new CDLinkedList<int>();
	
	while (1)
	{
		cout << "Enter Operation: ";
	
		cin >> operation;
		
		if (operation == 7)
		{
			break;
		}
		
		switch (operation)
		{
			case 1:
			{
				cout << "Enter Insert Head List Value: ";
				
				cin >> value;
				
				doublyLinkedList->InsertHeadList(value);
				
				break;
			}
			case 2:
			{
				cout << "Enter Insert Tail List Value: ";
				
				cin >> value;
				
				doublyLinkedList->InsertTailList(value);
				
				break;
			}
			case 3:
			{
				cout << "Removing Head List" << endl;
				
				doublyLinkedList->RemoveHeadList();
				
				break;
			}
			case 4:
			{
				cout << "Removing Tail List" << endl;
				
				doublyLinkedList->RemoveTailList();
				
				break;
			}
			case 5:
			{
				cout << "Printing List" << endl;
				
				doublyLinkedList->PrintList();
				
				cout << endl;
				
				break;
			}
			case 6:
			{
				cout << "Revering List" << endl;
				
				doublyLinkedList->Reverse();
				
				break;
			}
		}
	}
	
	delete doublyLinkedList;
	
	return 0;
}