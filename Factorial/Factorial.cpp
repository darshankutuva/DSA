/* Fibonacci Series */

#include <stddef.h>
#include <iostream>
using namespace std;

int main()
{
	unsigned long n, index, fact = 1;
	
	cout << "Enter Number ";
	
	cin << n;
	
	for (index = n; index > 0; index--)
	{
		fact = fact * index;
	}
	
	cout << "Factorial = " << fact;
}	