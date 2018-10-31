/* Fibonacci Series */

#include <stddef.h>
#include <iostream>
using namespace std;

int main()
{
	unsigned int maxElements;
	
	unsigned int index = 2;
	
	unsigned int num1 = 0;
	
	unsigned int num2 = 1;
	
	unsigned int next = 0;
	
	cout << "Enter Number of Elements in Fibonnaci Series: ";
	
	cin >> maxElements;
	
	if (maxElements < 2)
	{
		cout << "Max elements less than 2" << endl;
		
		goto Exit;
	}
	
	cout << endl;
	
	cout << num1 << " ";
	
	cout << num2 << " ";
	
	while (index < maxElements)
	{
		next = num1 + num2;
		
		cout << next << " ";
		
		num1 = num2;
		
		num2 = next;
		
		index++;
	}
	
	cout << endl;
	
Exit:

	return 1;
	
}