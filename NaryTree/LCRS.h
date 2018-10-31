/* Left Child Right Sibling Tree */

#ifndef _LCRS_TREE_H_
#define _LCRS_TREE_H_

#include <stddef.h>
#include <iostream>
using namespace std;

#include "../Stack/Stack.h"
#include "../Common/Common.h"

template <class Type>
class CLCRS
{
	private:
	
		typedef struct _NODE
		{
			struct _LCRS *Parent;
			
			Type Value;
			
			struct _LCRS *LeftChild;
			
			struct _LCRS *RightSibling;
			
		} NODE, *PNODE;
		
		PNODE m_Root;
		
		unsigned int m_NumChildren;
		
		void Preorder();
		
		void Inorder();
		
		void Postorder();
		
	public:
	
		CLCRS(unsigned int NumChildren);
		
		bool AddSibling(PNODE pNode, Type Value);
		
		bool AddChild(PNODE pNode, Type Value); 
		
		void Traverse(TRAVERSE_TYPE Type);
		
		~CLCRS();
};

template <class Type>
CLCRS<Type>::CLCRS(unsigned int NumChildren, Type RootValue)
{
	m_NumChildren = NumChildren;
	
	m_Root = new NODE;
	
	m_Root->Parent = NULL;
	
	m_Root->Value = RootValue;
	
	m_Root->LeftChild = NULL;
	
	m_Root->RightChild = NULL;
}

template <class Type>
bool CLCRS<Type>::AddChild(PNODE pNode, Type Value)
{
	bool status = false;
	
	PNODE pTemp;
	
	if (pNode == NULL)
	{
		goto Exit;
	}
		
	(pNode->LeftChild != NULL)
	{
		status = AddSibling(pNode->LeftChild, Value);
	}
	else
	{
		pTemp = new NODE;
	
		if (pTemp == NULL
		{
			goto Exit;
		}
	
		pNode->LeftChild = pTemp;
		
		pTemp->Parent = pNode;
		
		pTemp->Value = Value;
		
		pTemp->LeftChild = NULL;
		
		pTemp->RightSibling = NULL;
		
		status = true;
	}
	
Exit:

	return status;
	
}

template <class Type>
bool CLCRS<Type>::AddSibling(PNODE pNode, Type Value)
{
	bool status = false;
	
	PNODE pTemp;
	
	if (pNode == NULL)
	{
		goto Exit;
	}
	
	pTemp = new Node;
	
	if (pTemp == NULL)
	{
		goto Exit;
	}
	
	while (pNode->RightSibling != NULL)
	{
		pNode = pNode->RightSibling;
	}
	
	pNode->RightSibling = pTemp;
	
	pTemp->Parent = pNode->Parent;
	
	pTemp->RightSibling = NULL;
	
	pTemp->LeftChild = NULL;
	
Exit:

	return status;
}

template <class Type>
bool CLCRS<Type>::DeleteNode(PNODE pNode)
{
	bool status = false;
	
	if ((pNode == NULL) || (pNode->LeftChild != NULL))
	{
		goto Exit;
	}
	
	if (pNode->RightSibling != NULL)
	{
		PNODE pTemp = pNode->Parent->LeftChild;
		
		while (pTemp->RightSibling != pNode)
		{
			pTemp = pTemp->RightSibling;
		}
		
		pTemp->RightSibling = pNode->RightSibling;
	}
	
	delete pNode;
	
	status = true;
	
Exit:

	return status;
}

template <class Type>
void CLCRS<Type>::Traverse(TRAVERSE_TYPE TraverseType)
{
	switch(TraverseType)
	{
		case PRE_ORDER:
		{
			Preorder();
			break;
		}
		case IN_ORDER:
		{
			Inorder();
			break;
		}
		case POST_ORDER:
		{
			Postorder(false);
			break;
		}
	}
}

template <class Type>
void CLCRS<Type>::Preorder()
{
	CStack<PNODE> stack;
	
	PNODE pTemp = m_Root;
	
	while (1)
	{
		while (pTemp != NULL)
		{
			cout << pTemp;
			
			stack.Push(pTemp);
			
			pTemp = pTemp->LeftChild;
		}
		
		if (stack.IsEmpty())
		{
			break;
		}
		
		stack.Pop(pTemp);
		
		pTemp = pTemp->RightSibling;
	}
}

template <class Type>
void CLCRS<Type>::Inorder()
{
	CStack<PNODE> stack;
	
	PNODE pTemp = m_Root;
	
	while (1)
	{
		while (pTemp != NULL)
		{
			stack.Push(pTemp);
			
			pTemp =  pTemp->LeftChild;
		}
		
		if (stack.IsEmpty())
		{
			break;
		}
		
		stack.Pop(pTemp);
		
		cout << pTemp->Value;
		
		pTemp = pTemp->RightChild;
	}
}

template <class Type>
void CLCRS<Type>::Postorder(bool IsDeleteNode)
{
	CStack<PNODE> s1;
	
	CStack<PNODE> s2;
	
	PNODE pTemp;
	
	s1.Push(m_Root)
	
	while (!s1.IsEmpty())
	{
		s1.Pop(pTemp);
		
		s2.Push(pTemp);
		
		pTemp = pTemp->LeftChild;
		
		while (pTemp != NULL)
		{
			s1.Push(pTemp);
			
			pTemp = pTemp->RightSibling;
		}
	}
	
	while (!s2.IsEmpty())
	{
		s2.Pop(pTemp);
		
		cout << pTemp->Value;
		
		if (IsDeleteNode)
		{
			DeleteNode(pTemp);
		}
	}
}

template <class Type>
void CLCRS<Type>::PreorderRecurssive(PNODE pNode)
{
	if (pNode != NULL)
	{
		cout << pNode->Value;
		
		pNode = pNode->LeftChild;
		
		while (pNode != NULL)
		{
			PreorderTraversal(pNode);
		
			pNode = pNode->RightSibling;
		}
		
	}
}

template <class Type>
void CLCRS<Type>::InorderRecurssive(PNODE pNode)
{
	if (pNode != NULL)
	{
		PreorderTraversal(pNode->LeftChild);
		
		cout << pNode->Value;
		
		if (pNode->LeftChild != NULL
		{
			pNode = pNode->LeftChild->RightSibling;
	
			while (pNode != NULL)
			{
				PreorderTraversal(pNode);
		
				pNode = pNode->RightSibling;
			}
		}
		
	}
}

template <class Type>
void CLCRS<Type>::PostorderRecurssive(PNODE pNode)
{
	if (pNode != NULL)
	{
		pNode = pNode->LeftChild;
		
		while (pNode != NULL)
		{
			PreorderTraversal(pNode);
		
			pNode = pNode->RightSibling;
		}
		
		cout << pNode->Value;
	}
}

template <class Type>
CLCRS<Type>::~CLCRS()
{
	Postorder(true);
}

#endif