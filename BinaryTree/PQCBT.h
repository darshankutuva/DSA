/* Priority Queue Complete Binary Tree */

#ifndef _CBT_
#define _CBT_

#include <stddef.h>
#include <iostream>
using namespace std;

template <class Type>
class CPQCBT
{
	private:
	
		Type *m_pValues;
		
		unsigned int m_MaxElements;
		
		unsigned int m_NumElements;
		
		void PushDown();
		
		void PushUp();
		
	public:
	
		CPQCBT(unsigned int MaxElements);
		
		bool Insert(Type Value);
		
		bool DeleteMin(Type &MinValue);
		
		~CPQCBT();
		
};

template <class Type>
CPQCBT<Type>::CPQCBT(unsigned int MaxElements)
{
	m_pValues = new Type[MaxElements];
	
	m_MaxElements = MaxElements;
	
	m_NumElements = 0;
}

template <class Type>
bool CPQCBT<Type>::Insert(Type Value)
{	
	bool status = false;
	
	if (m_NumElements >= m_MaxElements)
	{
		cout << "Priority Queue Full, Unable to insert values" << endl;
		
		goto Exit;
	}

	m_pValues[m_NumElements] = Value;

	m_NumElements++;
	
	PushUp();
	
	status = true;
	
Exit:

	return status;
}

template <class Type>
bool CPQCBT<Type>::DeleteMin(Type &MinValue)
{
	bool status = true;
	
	if (m_NumElements == 0)
	{
		status = false;
		
		goto Exit;
	}	
	
	MinValue = m_pValues[0];
	
	m_NumElements--;
	
	if (m_NumElements == 0)
	{	
		goto Exit;
	}
	
	m_pValues[0] = m_pValues[m_NumElements];
	
	PushDown();
	
Exit:

	return status;
	
}

template <class Type>
void CPQCBT<Type>::PushUp()
{
	unsigned int index = m_NumElements - 1;
	
	unsigned int parent = 0;
	
	Type tempValue;
	
	while (index > 0)
	{
		parent = (index - 1) / 2;
		
		if (m_pValues[index] < m_pValues[parent])
		{
			tempValue = m_pValues[parent];
			
			m_pValues[parent] = m_pValues[index];
			
			m_pValues[index] = tempValue;
			
			index = parent;
		}
		else
		{
			break;
		}
	}
}

template <class Type>
void CPQCBT<Type>::PushDown()
{
	unsigned int index = 0;
	
	unsigned int leftChild;
	
	unsigned int rightChild;
	
	unsigned int swapIndex;
	
	Type tempValue;
	
	while (index < m_NumElements)
	{
		leftChild = (2 * index) + 1;
		
		rightChild = (2 * index) + 2;
		
		//
		// If the value is greater than both its children, then swap it with the least of the two children.
		//
		
		if ((leftChild < m_NumElements) && (rightChild < m_NumElements) && (m_pValues[index] > m_pValues[leftChild]) && (m_pValues[index] > m_pValues[rightChild]))
		{
			if (m_pValues[leftChild] <= m_pValues[rightChild])
			{
				swapIndex = leftChild;
			}
			else
			{
				swapIndex = rightChild;
			}
		}
		else if ((leftChild < m_NumElements) && (m_pValues[index] > m_pValues[leftChild]))
		{
			swapIndex = leftChild;
		}
		else if ((rightChild < m_NumElements) && (m_pValues[index] > m_pValues[rightChild]))
		{
			swapIndex = rightChild;
		}
		else
		{
			break;
		}
		
		tempValue = m_pValues[index];
		
		m_pValues[index] = m_pValues[swapIndex];
		
		m_pValues[swapIndex] = tempValue;
		
		index = swapIndex;
	}
}

template <class Type>
CPQCBT<Type>::~CPQCBT()
{
	delete[] m_pValues;
}

#endif