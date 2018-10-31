/* Doubly Linked List */

#ifndef _DLINKED_LIST_H_
#define _DLINKED_LIST_H_

#include <stddef.h>
#include <iostream>
using namespace std;

template <class Type>
class CDLinkedList
{
	private:
		typedef struct _Node
		{
			 struct _Node *Next;
	
			Type Value;
	
			struct _Node *Prev;
	
		} Node, *PNode;

		PNode m_Head;
		
		PNode m_Tail;
	
	public:
	
		CDLinkedList();
		
		void InsertHeadList(Type Value);
		
		void InsertTailList(Type Value);
		
		void RemoveHeadList();
		
		void RemoveTailList();
		
		void PrintList();
		
		void Reverse();
		
		~CDLinkedList();
};

template <class Type>
CDLinkedList<Type>::CDLinkedList()
{
	m_Head = NULL;
	
	m_Tail = NULL;
}

template <class Type>
void CDLinkedList<Type>::InsertHeadList(Type Value)
{
	PNode newNode = new Node;
	
	newNode->Value = Value;
	
	if (m_Head != NULL)
	{
		newNode->Next = m_Head;
		
		newNode->Prev = NULL;
		
		m_Head->Prev = newNode;
		
		m_Head = newNode;
	}
	else
	{
		newNode->Next = NULL;
		
		newNode->Prev = NULL;
		
		m_Head = newNode;
		
		m_Tail = newNode;
	}
}

template <class Type>
void CDLinkedList<Type>::InsertTailList(Type Value)
{
	PNode newNode = new Node;
	
	newNode->Value = Value;
	
	if (m_Tail != NULL)
	{
		newNode->Prev = m_Tail;
		
		newNode->Next = NULL;
		
		m_Tail->Next = newNode;
		
		m_Tail = newNode;
	}
	else
	{
		newNode->Next = NULL;
		
		newNode->Prev = NULL;
		
		m_Head = newNode;
		
		m_Tail = newNode;
	}
}

template <class Type>
void CDLinkedList<Type>::RemoveHeadList()
{
	PNode removeNode;
	
	if (m_Head != NULL)
	{
		removeNode = m_Head;
		
		m_Head = m_Head->Next;
		
		if (m_Head != NULL)
		{
			m_Head->Prev = NULL;
		}
		else
		{
			m_Tail = NULL;
		}
		
		delete removeNode;
	}
}

template <class Type>
void CDLinkedList<Type>::RemoveTailList()
{
	PNode removeNode;
	
	if (m_Tail != NULL)
	{
		removeNode = m_Tail;
		
		m_Tail = m_Tail->Prev;
		
		if (m_Tail != NULL)
		{
			m_Tail->Next = NULL;
		}
		else
		{
			m_Head = NULL;
		}
		
		delete removeNode;
	}
}

template <class Type>
void CDLinkedList<Type>::PrintList()
{
	PNode temp;
	
	temp = m_Head;
	
	while (temp != NULL)
	{
		cout << temp->Value << " ";
		
		temp = temp->Next;
	}
}

template <class Type>
void CDLinkedList<Type>::Reverse()
{
	PNode temp;
	
	m_Tail = m_Head;
	
	while (m_Head->Next != NULL)
	{
		temp = m_Head->Next;
		
		m_Head->Next = m_Head->Prev;
		
		m_Head->Prev = temp;
		
		m_Head = temp;

	}
	
	m_Head->Next = m_Head->Prev;
		
	m_Head->Prev = NULL;
}

template <class Type>
CDLinkedList<Type>::~CDLinkedList()
{
	PNode temp;
	
	cout << "Deleting Doubly Linked List" << endl;
	
	while (m_Head != NULL)
	{
		temp = m_Head;
		
		m_Head = m_Head->Next;
		
		cout << temp->Value << " ";
		
		delete temp;
	}
	
	m_Tail = NULL;
	
	cout << endl;
}

#endif

