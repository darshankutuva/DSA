#include "iostream"
#include "stack"

using namespace std;

typedef struct _QS_STACK_ELEMENT
{
	unsigned int Start;
	
	unsigned int End;
	
} QS_STACK_ELEMENT, *PQS_STACK_ELEMENT;

unsigned int 
Partition(unsigned int Start, unsigned int End, int *Elements)
{
	unsigned int indexI, indexJ;
	
	unsigned int pivot = Elements[End], temp;
	
	indexI = Start;
	
	for (indexJ = Start; indexJ < End; indexJ++)
	{
		if (Elements[indexJ] < pivot)
		{
			temp = Elements[indexJ];
			
			Elements[indexJ] = Elements[indexI];
			
			Elements[indexI] = temp;
			
			indexI++;
		}
	}
	
	temp = Elements[indexI];
	
	Elements[indexI] = Elements[End];
	
	Elements[End] = temp;
	
	return indexI;
}

bool QuickSort(unsigned int Start, unsigned int End, int *Elements)
{
	bool status = true;
	
	stack<QS_STACK_ELEMENT> qsStack;
	
	QS_STACK_ELEMENT qsStackElement;
	
	unsigned int pivot;
	
	
	if (Elements == NULL || Start >= End)
	{
		status = false;
		
		goto Exit;
	}
	
	qsStackElement.Start = Start;
	
	qsStackElement.End = End;
	
	qsStack.push(qsStackElement);
	
	while(!qsStack.empty())
	{
		qsStackElement = qsStack.top();
		
		qsStack.pop();
		
		Start = qsStackElement.Start;
		
		End = qsStackElement.End;
		
		pivot = Partition(Start, End, Elements);
		
		if ((pivot > 0) && (pivot - 1 > Start))
		{
			qsStackElement.Start = Start;
			
			qsStackElement.End = pivot - 1;
			
			qsStack.push(qsStackElement);
		}
		
		if (pivot + 1 < End)
		{
			qsStackElement.Start = pivot + 1;
			
			qsStackElement.End = End;
			
			qsStack.push(qsStackElement);
		}
	}
	
Exit:

	return status;
}

int main()
{
	int *elements;
	
	unsigned short numberOfElements;
	
	cout << "Enter Number of Elements: ";
	
	cin >> numberOfElements;
	
	elements = new int[numberOfElements];
	
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		cout << "Enter Element" << i << ": ";
		
		cin >> elements[i];
	}

	cout << "Un-sorted List" << endl;
	
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		cout << elements[i] << " ";
	}
	
	cout << endl;
	
	QuickSort(0, numberOfElements - 1, elements);
	
	cout << "Sorted List" << endl;
	
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		cout << elements[i] << " ";
	}
	
	cout << endl;
	
	delete[] elements;
	
	return 0;
}