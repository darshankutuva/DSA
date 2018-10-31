#include "BST.h"

int main()
{
	unsigned short operation;
	
	int value;
	
	CBST<int> bst;
	
	while (1)
	{
		cout << "Enter Operation: ";
	
		cin >> operation;
		
		if (operation == 4)
		{
			break;
		}
		
		switch (operation)
		{
			case 1:
			{
				cout << "Enter Value: ";
				
				cin >> value;
				
				bst.Insert(value);
				
				break;
			}
			case 2:
			{	
				bool status;
				
				cout << "Enter Value: ";
				
				cin >> value;
				
				status = bst.Delete(value);
				
				if (!status)
				{
					cout << "Operation Failed" << endl;
				}
				
				break;
			}
			case 3:
			{	
				bst.Traverse(PRE_ORDER);
				
				bst.Traverse(IN_ORDER);
				
				bst.Traverse(POST_ORDER);
				
				break;
			}
		}
	}
	
	return 0;
}