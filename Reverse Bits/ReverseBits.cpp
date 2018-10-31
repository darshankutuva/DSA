#include <iostream>

using namespace std;

int ReverseBits(int number)
{
	int revNum = 0;
	
	unsigned int numBits = sizeof(number) * 8;
	
	for (int i = 0; i < numBits; i++)
	{
		if (number & 0x1)
		{
			revNum |= 0x1 << (numBits - 1 - i); 
		}
		
		number = number >> 0x1;
	}
	
	return revNum;
}

int main()
{
	int number;
	
	cout << "Enter a Number: ";
	
	cin >> number;
	
	number = ReverseBits(number);
	
	cout << "Reversed Number = " << std::hex << number << endl;
	
}