/* Binary Search Tree */

#ifndef _BST_
#define _BST_

#include <stddef.h>
#include <iostream>
using namespace std;
#include "../Stack/Stack.h"
#include "../Common/Common.h"

template <class Type>
class CBST
{
		
	private:
	
		typedef struct _NODE
		{
			struct _NODE *Parent;
					
			Type Value;
					
			struct _NODE *LeftChild;
					
			struct _NODE *RightChild;
					
		} NODE, *PNODE;
		
		PNODE m_pRoot;
		
		void Preorder();
		
		void Inorder();
		
		void Postorder(bool DeleteNode);
		
		void PreorderRecursive(PNODE pNode);
		
		void InorderRecursive(PNODE pNode);
		
		void PostorderRecursive(PNODE pNode, bool DeleteNode);
		
		PNODE FindNode(Type Value);
		
		PNODE FindReplacement(PNODE pNode);
		
	public:
	
		CBST();
	
		void Insert(Type Value);
		
		bool Delete(Type Value);
		
		void Traverse(TRAVERSE_TYPE TraverseType);
		
		~CBST();
};

template <class Type>
CBST<Type>::CBST()
{
	m_pRoot = NULL;
}

template <class Type>
CBST<Type>::~CBST()
{
	PostOrder(true);
}

template <class Type>
void CBST<Type>::Insert(Type Value)
{
	PNODE pNode = new NODE;
	
	PNODE pTemp = NULL;
	
	pNode->Value = Value;
	
	pNode->LeftChild = NULL;
	
	pNode->RightChild = NULL;
	
	if (m_pRoot == NULL)
	{
		pNode->Parent = NULL;
		
		m_pRoot = pNode;
	}
	else
	{
		pTemp = m_pRoot;
		
		while (1)
		{
			if (Value == pTemp->Value)
			{
				delete pNode;
				
				break;
			}
			else if (Value > pTemp->Value)
			{
				if (pTemp->RightChild != NULL)
				{
					pTemp = pTemp->RightChild;
				}
				else
				{
					pTemp->RightChild = pNode;
					
					pNode->Parent = pTemp;
					
					break;
				}
			}
			else
			{
				if (pTemp->LeftChild != NULL)
				{
					pTemp = pTemp->LeftChild;
				}
				else
				{
					pTemp->LeftChild = pNode;
					
					pNode->Parent = pTemp;
					
					break;
				}
			}
		}
	}
}

template <class Type>
bool CBST<Type>::Delete(Type Value)
{
	bool status = false;
	
	PNODE pNode = FindNode(Value);
	
	PNODE pReplacementNode = NULL;
	
	if (pNode == NULL)
	{
		goto Exit;
	}
	else
	{
		if (pNode->LeftChild != NULL && pNode->RightChild != NULL)
		{
			pReplacementNode = FindReplacement(pNode->RightChild);
		}
		else if (pNode->LeftChild != NULL)
		{
			pReplacementNode = pNode->LeftChild;
		}
		else if (pNode->RightChild != NULL)
		{
			pReplacementNode = pNode->RightChild;
		}
		
		if (pNode->Parent->LeftChild == pNode)
		{
			pNode->Parent->LeftChild = pReplacementNode;
		}
		else
		{
			pNode->Parent->RightChild = pReplacementNode;
		}
		
		status = true;
	}
	
Exit:

	return status;
}

template <class Type>
typename CBST<Type>::PNODE CBST<Type>::FindReplacement(PNODE pNode)
{
	while (pNode->LeftChild != NULL)
	{
		pNode = pNode->LeftChild;
	}
	
	if (pNode->RightChild != NULL)
	{
		pNode->Parent->LeftChild = pNode->RightChild;
	}
	else
	{
		pNode->Parent->LeftChild = NULL;
	}
	
	return pNode;
}

template <class Type>
typename CBST<Type>::PNODE CBST<Type>::FindNode(Type Value)
{
	PNODE pTemp = m_pRoot;
	
	while (pTemp != NULL)
	{
		if (pTemp->Value == Value)
		{
			break;
		}
		else if (pTemp->Value > Value)
		{
			pTemp = pTemp->RightChild;
		}
		else
		{
			pTemp = pTemp->LeftChild;
		}
	}
	
	return pTemp;
}

template <class Type>
void CBST<Type>::Traverse(TRAVERSE_TYPE TraverseType)
{
	switch (TraverseType)
	{
		case PRE_ORDER:
		{
			Preorder();
			
			PreorderRecursive(m_pRoot);
			
			break;
		}
		case IN_ORDER:
		{
			Inorder();
			
			InorderRecursive(m_pRoot);
			
			break;
		}
		case POST_ORDER:
		{
			Postorder(false);
			
			PostorderRecursive(m_pRoot, false);
			
			break;
		}
	}
}

template <class Type>
void CBST<Type>::InorderRecursive(PNODE pNode)
{
	if (pNode != NULL)
	{
		InOrderRecursive(pNode->LeftChild);
		
		cout << pNode->Value << " ";
		
		InOrderRecursive(pNode->RightChild);
	}
}

template <class Type>
void CBST<Type>::PreorderRecursive(PNODE pNode)
{
	if (pNode != NULL)
	{
		cout << pNode->Value << " ";
		
		PreOrderRecursive(pNode->LeftChild);
		
		PreOrderRecursive(pNode->RightChild);
	}
}

template <class Type>
void CBST<Type>::PostorderRecursive(PNODE pNode, bool DeleteNode)
{
	if (pNode != NULL)
	{	
		PostOrderRecursive(pNode->LeftChild, DeleteNode);
		
		PostOrderRecursive(pNode->RightChild, DeleteNode);
	
		cout << pNode->Value << " ";
		
		if(DeleteNode)
		{
			delete pNode;
		}
	}
}

template <class Type>
void CBST<Type>::Inorder()
{
	CStack<PNODE> stack;
	
	PNODE pNode = m_pRoot;
	
	while (true)
	{
		while (pNode != NULL)
		{
			stack.Push(pNode);
		
			pNode = pNode->LeftChild;
		}
		
		if (stack.IsEmpty())
		{
			break;
		}
		
		stack.Pop(pNode);
		
		cout << pNode->Value << " ";
		
		pNode = pNode->RightChild;
	}
}

template <class Type>
void CBST<Type>::Preorder()
{
	CStack<PNODE> stack;
	
	PNODE pNode = m_pRoot;
	
	while (true)
	{
		while (pNode != NULL)
		{
			stack.Push(pNode);
			
			cout << pNode->Value << " ";
		
			pNode = pNode->LeftChild;
		}
		
		if (stack.IsEmpty())
		{
			break;
		}
		
		stack.Pop(pNode);
		
		pNode = pNode->RightChild;
	}
}

template <class Type>
void CBST<Type>::Postorder(bool DeleteNode)
{
	CStack<PNODE> s1;
	
	CStack<PNODE> s2;
	
	PNODE pNode = NULL;
	
	s1.Push(m_pRoot);
	
	while(!s1.IsEmpty())
	{
		s1.Pop(pNode);
		
		s2.Push(pNode);
		
		if (pNode->LeftChild != NULL)
		{
			s1.Push(pNode->LeftChild);
		}
		
		if (pNode->RightChild != NULL)
		{
			s1.Push(pNode->RightChild);
		}
	}
	
	while (!s2.IsEmpty())
	{
		s2.Pop(pNode);
		
		cout << pNode->Value;
		
		if (DeleteNode)
		{
			delete pNode;
		}
	}
}



#endif