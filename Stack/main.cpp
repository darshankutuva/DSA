#include "Stack.h"

int main()
{
	unsigned short operation;
	
	int value;
	
	CStack<int> stack;
	
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
				cout << "Enter Push Value: ";
				
				cin >> value;
				
				stack.Push(value);
				
				break;
			}
			case 2:
			{	
				bool status;
				
				status = stack.Pop(value);
				
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
			case 3:
			{
				cout << "Printing Stack" << endl;
				
				stack.PrintStack();
				
				break;
			}
		}
	}
	
	return 0;
}