/* Parent Pointer */

#ifndef _PARENT_POINTER_H_
#define _PARENT_POINTER_H_

#include <stddef.h>
#include <iostream>
using namespace std;

template <class Type>
class CParentPointer
{
	private:
		
		typedef struct _NODE
		{
			int ParentIndex;
			
			Type Value;
			
		} NODE, *PNODE;
		
		unsigned int m_NumNodes;
		
		PNODE m_pTree;
		
	public:
	
		CParentPointer(unsigned int m_NumNodes);
		
		bool Insert(unsigned int NodeIndex, Type NodeValue);
		
		bool IsDisjointSet(unsigned int NodeIndex1, unsigned int NodeIndex2);
		
		bool Join(unsigned int NodeIndex1, unsigned int NodeIndex2, bool MinimizeDepth);
		
		~CParentPointer();
};

template <class Type>
CParentPointer<Type>::CParentPointer(unsigned int NumNodes)
{
	unsigned int index;
	
	if (NumNodes == 0)
	{
		goto Exit;
	}
	
	m_NumNodes = NumNodes;
	
	m_pTree = new NODE[m_NumNodes];
	
	for (index = 0; index < m_NumNodes; index++)
	{
		m_pTree[index].ParentIndex = -1;
	}
	
Exit:

	return;
}

template <class Type>
bool CParentPointer<Type>::Insert(unsigned int NodeIndex, Type NodeValue)
{
	bool status = false;
	
	if (NodeIndex >= m_NumNodes)
	{
		goto Exit;
	}
	
	m_pTree[NodeIndex].Value = NodeValue;
	
	status = true;
	
Exit:

	return status;
}

template <class Type>
bool CParentPointer<Type>::IsDisjointSet(unsigned int NodeIndex1, unsigned int NodeIndex2)
{
	bool status = false;
	
	if (NodeIndex1 >= m_NumNodes || NodeIndex2 >= m_NumNodes)
	{
		goto Exit;
	}
	
	while (m_pTree[NodeIndex1]->Parent != -1)
	{
		NodeIndex1 = m_pTree[NodeIndex1]->Parent;
	}
	
	while (m_pTree[NodeIndex2]->Parent != -1)
	{
		NodeIndex2 = m_pTree[NodeIndex2]->Parent;
	}
	
	if (NodeIndex1 == NodeIndex2)
	{
		status = false;
	}
	else
	{
		status = true;
	}
	
Exit:

	return status;
}

template <class Type>
bool CParentPointer<Type>::Join(unsigned int NodeIndex1, unsigned int NodeIndex2, bool MinimizeDepth)
{
	bool status = false;
	
	if (NodeIndex1 >= m_NumNodes || NodeIndex2 >= m_NumNodes)
	{
		goto Exit;
	}
	
	if (IsDisjointSet(NodeIndex1, NodeIndex2))
	{
		if (MinimizeDepth)
		{
			while (m_pTree[NodeIndex1]->Parent != -1)
			{
				NodeIndex1 = m_pTree[NodeIndex1]->Parent;
			}
		}
	
		while (m_pTree[NodeIndex2]->Parent != -1)
		{
			NodeIndex2 = m_pTree[NodeIndex2]->Parent;
		}
		
		m_pTree[NodeIndex2]->Parent = NodeIndex1;
		
		status = true;
	}
	
Exit:

	return status;
}

template <class Type>
CParentPointer<Type>::~CParentPointer()
{
	if (m_pTree != NULL)
	{
		delete[] m_pTree;
	}
}

#endif