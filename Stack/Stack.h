#ifndef _STACK_H_
#define _STACK_H_

#include "../SLinkedList/SLinkedList.h"

template <class Type>
class CStack
{
	private:
		
		CSLinkedList<Type> m_Stack;

	public:
	
		CStack();
	
		void Push(Type Value);
		
		bool Pop(Type &Value);
		
		void PrintStack();
		
		bool IsEmpty();
		
		~CStack();
};

template <class Type>
CStack<Type>::CStack() : m_Stack()
{

}

template <class Type>
void CStack<Type>::Push(Type Value)
{
	m_Stack.InsertTailList(Value);
}

template <class Type>
bool CStack<Type>::Pop(Type &Value)
{
	return m_Stack.RemoveTailList(Value);
}

template <class Type>
bool CStack<Type>::IsEmpty()
{
	return m_Stack.IsEmpty();
}

template <class Type>
void CStack<Type>::PrintStack()
{
	m_Stack.PrintList();
}

template <class Type>
CStack<Type>::~CStack()
{
	
}

#endif