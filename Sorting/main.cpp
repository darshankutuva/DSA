#include "Sort.h"

int main()
{
	unsigned short operation;
	
	unsigned short numberOfElements;
	
	cout << "Enter Operation: ";
	
	cin >> operation;
	
	cout << "Enter Number of Elements: ";
	
	cin >> numberOfElements;
	
	CSort<int> sort = CSort<int>(numberOfElements);

	cout << "Un-sorted List" << endl;
	
	sort.PrintList();
		
	switch (operation)
	{
		case 1:
		{
			sort.BubbleSort();
			
			break;
		}
		case 2:
		{
			sort.InsertionSort();
			
			break;
		}
		case 3:
		{
			sort.HeapSort();
			
			break;
		}
		case 4:
		{
			sort.MergeSort();
			
			break;
		}
	}
	
	cout << "Sorted List" << endl;
	
	sort.PrintList();
	
	return 0;
}