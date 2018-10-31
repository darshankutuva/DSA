/* Statistics */

#include <stddef.h>
#include <iostream>
#include <math.h>
#include "../Sorting/Sort.h"
using namespace std;

long Partition(long Start, long End, double *Elements)
{
	long indexI, indexJ;
	
	double pivot = Elements[End], temp;
	
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

void Sort(long Start, long End, double *Elements)
{
	long stack[End - Start + 1];
	
	long top = -1, pivot;
	
	stack[++top] = Start;
	
	stack[++top] = End;
	
	while (top >= 0)
	{
		End = stack[top--];
		
		Start = stack[top--];
		
		pivot = Partition(Start, End, Elements);
		
		if (pivot - 1 > Start)
		{
			stack[++top] = Start;
			
			stack[++top] = pivot - 1;
		}
		
		if (pivot + 1 < End)
		{
			stack[++top] = pivot + 1;
			
			stack[++top] = End;
		}
	}
}

double ArithmeticMean(unsigned long N, double *Elements)
{
	unsigned long index;
	
	double sum = 0, average = 0;
	
	if (Elements == NULL || N == 0)
	{
		goto Exit;
	}
	
	for (index = 0; index < N; index++)
	{
		sum += Elements[index];
	}
	
	average = sum / N;
	
Exit:

	return average;
}

double HarmonicMean(unsigned long N, double *Elements)
{
	unsigned long index;
	
	double sum = 0, average = 0;
	
	if (Elements == NULL || N == 0)
	{
		goto Exit;
	}
	
	for (index = 0; index < N; index++)
	{
		sum = sum + (1 / Elements[index]);
	}
	
	average = sum / N;
	
Exit:

	return average;
}

double GeometricMean(unsigned long N, double *Elements)
{
	unsigned long index;
	
	double product = 1, average = 0;
	
	if (Elements == NULL || N == 0)
	{
		goto Exit;
	}
	
	for (index = 0; index < N; index++)
	{
		product *= Elements[index];
	}
		
	average = pow(product, 1/N);

Exit:

	return average;
}

double Median(unsigned long N, double *Elements)
{
	double median = 0;
	
	if (Elements == NULL || N == 0)
	{
		goto Exit;
	}
	
	Sort(0, N - 1, Elements);
	
	if ((N % 2) == 0)
	{
		median = (Elements[N/2] + Elements[(N/2) + 1])/2;
	}
	else
	{
		median = Elements[(N + 1)/2];
	}
	
Exit:
	
	return median;
}

bool CalcVariance(unsigned long N, double *Elements, double *Variance)
{
	bool status = true;
	
	unsigned long index;
	
	double mean = 0;
	
	if (Elements == NULL || N == 0)
	{
		status = false;
		
		goto Exit;
	}
	
	for (index = 0; index < N; index++)
	{
		mean += Elements[index];
	}
	
	mean = mean / N;
	
	*Variance = 0;
	
	for (index = 0; index < N; index++)
	{
		*Variance = *Variance + pow(Elements[index] - mean, 2.0);
	}
	
	*Variance = *Variance / N;
	
Exit:

	return status;
}

bool CalcEValue(unsigned long N, double *Elements, double *Probs, double *EValue, double *EVariance)
{
	bool status = true;
	
	unsigned long index;
	
	double EValueSquared;
	
	if (Elements == NULL || Probs == NULL || N == 0)
	{
		status = false;
		
		goto Exit;
	}
	
	*EValue = 0;
	
	EValueSquared = 0;
	
	for (index = 0; index < N; index++)
	{
		*EValue = *EValue + (Elements[index] * Probs[index]);
		
		EValueSquared = EValueSquared + (pow(Elements[index], 2.0) * Probs[index]);
	}
	
	*EVariance = EValueSquared - pow(*EValue, 2.0);
	
Exit:

	return status;
	
}

bool Mode(unsigned long N, double *Elements, double *Mode)
{
	bool status = true;
	
	double prevRepeats = 0, currRepeats;
	
	unsigned long index;
	
	if (Elements == NULL || N == 0)
	{
		status = false;
		
		goto Exit;
	}
	
	Sort(0, N - 1, Elements);
	
	*Mode = Elements[0];
	
	currRepeats = 1;
	
	for (index = 1; index < N; index++)
	{
		if (Elements[index] != Elements[index - 1])
		{
			if (currRepeats == prevRepeats)
			{
				status = false;
				
				goto Exit;
			}
			else if (currRepeats > prevRepeats)
			{
				prevRepeats = currRepeats;
				
				*Mode = Elements[index - 1];
			}
			
			currRepeats = 1;
		}
		else
		{
			currRepeats++;
		}
	}
	
	if (prevRepeats == 1)
	{
		status = false;
	}
	
Exit:

	return status;
}

int main()
{
	int status = 0;
	
	unsigned long n, index;
	
	double *elements, *probs, value, value1;
	
	cout << "Enter Number of Elements: ";
	
	cin >> n;
	
	elements = new double[n];
	
	probs = new double[n];
	
	if (elements == NULL || probs == NULL)
	{
		status = 1;
		
		goto Exit;
	}
	
	for (index = 0; index < n; index++)
	{
		cout << "Enter Element Number " << index << ": ";
		
		cin >> elements[index];
		
		cout << "Enter Probability Element Number " << index << ": ";
		
		cin >> probs[index];
	}
	
	status = CalcEValue(n, elements, probs, &value, &value1);
	
	if (!status)
	{
		cout << "No Expected Value and EVariance" << endl;
	}
	else
	{
		cout << "Expected Value = " << value << endl;
		
		cout << "Expected Variance = " << value1 << endl;
	}
	
	Sort(0, n - 1, elements);
	
	//ArithmeticMean(n, elements);
	
	//HarmonicMean(n, elements);
	
	//GeometricMean(n, elements);
	
	//Median(n, elements);
	
	status = Mode(n, elements, &value);
	
	if (!status)
	{
		cout << "No Mode" << endl;
	}
	else
	{
		cout << "Mode = " << value << endl;
	}
	
	cout << "Sorted Array" << endl;
	
	for (index = 0; index < n; index++)
	{
		cout << elements[index] << " ";
	}
	
	cout << endl;
	
	status = CalcVariance(n, elements, &value);
	
	if (!status)
	{
		cout << "No Variance" << endl;
	}
	else
	{
		cout << "Variance = " << value << endl;
		
		cout << "Standard Deviation = " << sqrt(value) << endl;
	}
	
Exit:

	if (elements != NULL)
	{
		delete[] elements;
	}
	
	if (probs != NULL)
	{
		delete[] probs;
	}

	return status;
}
	