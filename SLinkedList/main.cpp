#include "SLinkedList.h"

int main()
{
	unsigned short operation;
	
	int value;
	
	bool status;
	
	CSLinkedList<int> *singlyLinkedList = new CSLinkedList<int>();
	
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
				
				singlyLinkedList->InsertHeadList(value);
				
				break;
			}
			case 2:
			{
				cout << "Enter Insert Tail List Value: ";
				
				cin >> value;
				
				singlyLinkedList->InsertTailList(value);
				
				break;
			}
			case 3:
			{
				cout << "Removing Head List ";
				
				status = singlyLinkedList->RemoveHeadList(value);
				
				if (status)
				{
					cout << "- Value = " << value << endl;
				}
				else
				{
					cout << "Operation Failed" << endl;
				}
				
				break;
			}
			case 4:
			{
				cout << "Removing Tail List " << endl;
				
				status = singlyLinkedList->RemoveTailList(value);
				
				if (status)
				{
					cout << "- Value = " << value << endl;
				}
				else
				{
					cout << "Operation Failed" << endl;
				}
				
				break;
			}
			case 5:
			{
				cout << "Printing List" << endl;
				
				singlyLinkedList->PrintList();
				
				cout << endl;
				
				break;
			}
			case 6:
			{
				cout << "Revering List" << endl;
				
				singlyLinkedList->Reverse();
				
				break;
			}
		}
	}
	
	delete singlyLinkedList;
	
	return 0;
}