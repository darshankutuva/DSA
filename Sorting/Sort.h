/* Sorting */

#ifndef _SORTING_H_
#define _SORTING_H_

#include <stddef.h>
#include <iostream>
using namespace std;

#include "../BinaryTree/PQCBT.h"

template <class Type>
class CSort
{
	private:
		
		unsigned int m_Count;
		
		Type *m_Elements;
		
		void MergeIterative(unsigned int left, unsigned int mid, unsigned int right);
		
		void MergeRecursive(unsigned int left, unsigned int mid, unsigned int right);
		
		void MergeSortIterative();
		
		void MergeSortRecursive(unsigned int left, unsigned int right);
		
		void Partition(unsigned long Start, unsigned long End);
		
	public:
	
		CSort(unsigned int Count);
		
		void BubbleSort();
		
		void InsertionSort();
		
		void QuickSort();
		
		void MergeSort();
		
		bool HeapSort();
		
		void PrintList();
		
		~CSort();
};

template <class Type>
CSort<Type>::CSort(unsigned int Count)
{
	unsigned int indexI;
	
	this->m_Count = Count;
	
	m_Elements = new Type[m_Count];
	
	if (m_Elements == NULL)
	{
		goto Exit;
	}
	
	for (indexI = 0; indexI < m_Count; indexI++)
	{
		cout << "Enter element " << indexI << ": ";
		
		cin >> m_Elements[indexI];
		
		cout << endl;
	}
	
Exit:

	return;
}

template <class Type>
void
CSort<Type>::PrintList()
{
	unsigned int indexI;
	
	for (indexI = 0; indexI < m_Count; indexI++)
	{
		cout << m_Elements[indexI] << " ";
	}
	
	cout << endl;
}

template <class Type>
void 
CSort<Type>::BubbleSort()
{
	unsigned int indexI, indexJ;
	
	Type temp;
	
	for (indexI = 0; indexI < m_Count; indexI++)
	{
		for (indexJ = indexI + 1; indexJ < m_Count; indexJ++)
		{
			if (m_Elements[indexI] > m_Elements[indexJ])
			{
				temp = m_Elements[indexI];
				
				m_Elements[indexI] = m_Elements[indexJ];
				
				m_Elements[indexJ] = temp;
			}
		}
	}
}

template <class Type>
void 
CSort<Type>::InsertionSort()
{
	int indexI, indexJ, sortIndex;
	
	Type temp;
	
	for (indexI = 0 ; indexI < m_Count; indexI++)
	{
		sortIndex = indexI;
		
		for (indexJ = indexI - 1; indexJ >= 0; indexJ--)
		{
			if (m_Elements[sortIndex] < m_Elements[indexJ])
			{
				temp = m_Elements[sortIndex];
				
				m_Elements[sortIndex] = m_Elements[indexJ];
				
				m_Elements[indexJ] = temp;
				
				sortIndex = indexJ;
			}
		}
	}
}

template <class Type>
void 
CSort<Type>::Partition(unsigned int Start, unsigned int End)
{
	unsigned int indexI, indexJ;
	
	Type pivot = m_Elements[End], temp;
	
	indexI = Start;
	
	for (indexJ = Start; indexJ < End; indexJ++)
	{
		if (m_Elements[indexJ] < pivot)
		{
			temp = m_Elements[indexJ];
			
			m_Elements[indexJ] = m_Elements[indexI];
			
			m_Elements[indexI] = temp;
			
			indexI++;
		}
	}
	
	temp = m_Elements[indexI];
	
	m_Elements[indexI] = m_Elements[End];
	
	m_Elements[End] = temp;
	
	return indexI;
}

template <class Type>
void
CSort<Type>::QuickSort(unsigned int Start, unsigned int End)
{
	unsigned int stack[End - Start + 1];
	
	long top = -1;
	
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

template <class Type>
void 
CSort<Type>::MergeSort()
{
	//MergeSortIterative();
	
	MergeSortRecursive(0, m_Count - 1);
}

template <class Type>
void 
CSort<Type>::MergeSortIterative()
{
	unsigned int currSize;
	
	unsigned int left;
	
	unsigned int mid;
	
	unsigned int right;
	
	for (currSize = 1; currSize <= m_Count; currSize = currSize * 2)
	{
		for (left = 0; left < m_Count; left = left + (2 * currSize))
		{
			
			mid = left + currSize;
			
			if (mid >= m_Count)
			{
				break;
			}
			
			right = left + (2 * currSize);
			
			if (right > m_Count)
			{				
				right = m_Count;
			}
			
			MergeIterative(left, mid, right);
		}
	}
}

template <class Type>
void
CSort<Type>::MergeSortRecursive(unsigned int left, unsigned int right)
{
	unsigned int mid;
	
	if (left < right)
	{
		mid = (left + right) / 2;
		
		MergeSortRecursive(left, mid);
		
		MergeSortRecursive(mid + 1, right);
		
		MergeRecursive(left, mid, right);
	}
}

template <class Type>
void
CSort<Type>::MergeIterative(unsigned int left, unsigned int mid, unsigned int right)
{
	unsigned int leftCount = mid - left;
	
	unsigned int rightCount = right - mid;
	
	Type leftArray[leftCount], rightArray[rightCount];
	
	unsigned int leftIndex, rightIndex, index;
	
	for (leftIndex = 0; leftIndex < leftCount; leftIndex++)
	{
		leftArray[leftIndex] = m_Elements[left + leftIndex];
	}
	
	for (rightIndex = 0; rightIndex < rightCount; rightIndex++)
	{
		rightArray[rightIndex] = m_Elements[mid + rightIndex];
	}
	
	leftIndex = 0;
	
	rightIndex = 0;
	
	index = left;
	
	while ((leftIndex < leftCount) && (rightIndex < rightCount))
	{
		if (leftArray[leftIndex] < rightArray[rightIndex])
		{
			m_Elements[index] = leftArray[leftIndex];
			
			leftIndex++;
		}
		else
		{
			m_Elements[index] = rightArray[rightIndex];
			
			rightIndex++;
		}
		
		index++;
	}
	
	while (leftIndex < leftCount)
	{
		m_Elements[index] = leftArray[leftIndex];
		
		index++;
		
		leftIndex++;
	}
	
	while (rightIndex < rightCount)
	{
		m_Elements[index] = rightArray[rightIndex];
		
		index++;
		
		rightIndex++;
	}
}

template <class Type>
void
CSort<Type>::MergeRecursive(unsigned int left, unsigned int mid, unsigned int right)
{
	unsigned int leftCount = mid - left + 1;
	
	unsigned int rightCount = right - mid;
	
	Type leftArray[leftCount], rightArray[rightCount];
	
	unsigned int leftIndex, rightIndex, index;
	
	for (leftIndex = 0; leftIndex < leftCount; leftIndex++)
	{
		leftArray[leftIndex] = m_Elements[left + leftIndex];
	}
	
	for (rightIndex = 0; rightIndex < rightCount; rightIndex++)
	{
		rightArray[rightIndex] = m_Elements[mid + 1 + rightIndex];
	}
	
	leftIndex = 0;
	
	rightIndex = 0;
	
	index = left;
	
	while ((leftIndex < leftCount) && (rightIndex < rightCount))
	{
		if (leftArray[leftIndex] < rightArray[rightIndex])
		{
			m_Elements[index] = leftArray[leftIndex];
			
			leftIndex++;
		}
		else
		{
			m_Elements[index] = rightArray[rightIndex];
			
			rightIndex++;
		}
		
		index++;
	}
	
	while (leftIndex < leftCount)
	{
		m_Elements[index] = leftArray[leftIndex];
		
		index++;
		
		leftIndex++;
	}
	
	while (rightIndex < rightCount)
	{
		m_Elements[index] = rightArray[rightIndex];
		
		index++;
		
		rightIndex++;
	}
}

template <class Type>
bool
CSort<Type>::HeapSort()
{
	unsigned int index;
	
	bool status = false;
	
	Type minValue;
	
	CPQCBT<Type> heap = CPQCBT<Type>(m_Count);
	
	for (index = 0; index < m_Count; index++)
	{
		status = heap.Insert(m_Elements[index]);
		
		if (!status)
		{
			cout << "Failed to insert in to heap" << endl;
			
			goto Exit;
		}
	}
	
	for (index = 0; index < m_Count; index++)
	{
		status = heap.DeleteMin(minValue);
		
		if (!status)
		{
			cout << "Failed to delete min value" << endl;
			
			goto Exit;
		}
		
		m_Elements[index] = minValue;
	}
	
	status = true;
	
Exit:

	return status;
	
}

template <class Type>
CSort<Type>::~CSort()
{
	cout << "Deleting List" << endl;
	
	if (m_Elements != NULL)
	{
		delete[] m_Elements;
		
		m_Count = 0;
	}
}

#endif