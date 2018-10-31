/* Singly Linked List */

#ifndef _SLINKED_LIST_H_
#define _SLINKED_LIST_H_

#include <stddef.h>
#include <iostream>
using namespace std;

template <class Type>
class CSLinkedList
{
	private:
		typedef struct _Node
		{
			struct _Node *Next;
	
			Type Value;
	
		} Node, *PNode;

		PNode m_Head;
	
	public:
	
		CSLinkedList();
		
		void InsertHeadList(Type Value);
		
		void InsertTailList(Type Value);
		
		bool RemoveHeadList(Type &Value);
		
		bool RemoveTailList(Type &Value);
		
		bool IsEmpty();
		
		void PrintList();
		
		void Reverse();
		
		~CSLinkedList();
};

template <class Type>
CSLinkedList<Type>::CSLinkedList()
{
	m_Head = NULL;
}

template <class Type>
bool CSLinkedList<Type>::IsEmpty()
{
	if (m_Head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Type>
void CSLinkedList<Type>::InsertHeadList(Type Value)
{
	PNode newNode = new Node;
	
	newNode->Value = Value;
	
	if (m_Head != NULL)
	{
		newNode->Next = m_Head;
	}
	else
	{
		newNode->Next = NULL;
	}
	
	m_Head = newNode;
}

template <class Type>
void CSLinkedList<Type>::InsertTailList(Type Value)
{
	PNode temp;
	
	PNode newNode = new Node;
	
	newNode->Value = Value;
	
	if (m_Head != NULL)
	{
		temp = m_Head;
		
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		
		temp->Next = newNode;
	}
	else
	{
		m_Head = newNode;
	}
	
	newNode->Next = NULL;
}

template <class Type>
bool CSLinkedList<Type>::RemoveHeadList(Type &Value)
{
	PNode removeNode;
	
	bool status = false;
	
	if (m_Head != NULL)
	{
		removeNode = m_Head;
		
		Value = removeNode->Value;
		
		m_Head = m_Head->Next;
		
		delete removeNode;
		
		status = true;
	}
	
	return status;
}

template <class Type>
bool CSLinkedList<Type>::RemoveTailList(Type &Value)
{
	PNode temp;
	
	bool status = false;
	
	if (m_Head != NULL)
	{
		if (m_Head->Next == NULL)
		{
			Value = m_Head->Value;
			
			delete m_Head;
			
			m_Head = NULL;
		}
		else
		{
			temp = m_Head;
				
			while (temp->Next->Next != NULL)
			{
				temp = temp->Next;
			}
			
			Value = temp->Next->Value;
		
			delete temp->Next;
		
			temp->Next = NULL;
		}
		
		status = true;
	}
	
	return status;
}

template <class Type>
void CSLinkedList<Type>::PrintList()
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
void CSLinkedList<Type>::Reverse()
{
	PNode prevNode = NULL;
	
	PNode nextNode;
	
	if (m_Head != NULL)
	{
		while (m_Head->Next != NULL)
		{
			nextNode = m_Head->Next;
			
			m_Head->Next = prevNode;
		
			prevNode = m_Head;
			
			m_Head = nextNode;

		}
		
		m_Head->Next = prevNode;
	}
}

template <class Type>
CSLinkedList<Type>::~CSLinkedList()
{
	PNode temp;
	
	cout << "Deleting Singly Linked List" << endl;
	
	while (m_Head != NULL)
	{
		temp = m_Head;
		
		m_Head = m_Head->Next;
		
		cout << temp->Value << " ";
		
		delete temp;
	}
	
	cout << endl;
}

#endif

