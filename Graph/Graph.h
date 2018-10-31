/* Graph */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stddef.h>
#include <iostream>
using namespace std;

#include "../Stack/Stack.h"
#include "../Queue/Queue.h"
#include "../NaryTree/ParentPointer.h"

#define NO_EDGE	-1

class CGraph
{
	private:
		int** m_pAdjaMatrix;
		
		unsigned int m_NumNodes;
		
	public:
		CGraph(unsigned int NumNodes);
		
		bool AddEdge(unsigned int Node1, unsigned int Node2, unsigned int EdgeWeight);
		
		bool DeleteEdge(unsigned int Node1, unsigned int Node2);
		
		bool DFS(unsigned int StartNode);
		
		bool BFS(unsigned int StartNode);
		
		~CGraph();
};

CGraph::CGraph(unsigned int NumNodes)
{
	unsigned int indexI, indexJ;
	
	m_pAdjaMatrix = NULL;
	
	if (NumNodes == 0)
	{
		goto Exit;
	}
	
	m_NumNodes = NumNodes;
	
	m_pAdjaMatrix = new int* [m_NumNodes];
	
	for (indexI = 0; indexI < m_NumNodes; indexI++)
	{
		m_pAdjaMatrix[indexI] = new int[m_NumNodes];
	}
	
	for (indexI = 0; indexI < m_NumNodes; indexI++)
	{
		for (indexJ = 0; indexJ < m_NumNodes; indexJ++)
		{
			m_pAdjaMatrix[indexI][indexJ] = NO_EDGE;
		}
	}
	
Exit:
	return;
}

CGraph:;~CGraph()
{
	if (m_pAdjaMatrix != NULL)
	{
		for (index = 0; index < m_NumNodes; index++)
		{
			if (m_pAdjaMatrix[index] != NULL)
			{
				delete[] m_pAdjaMatrix[index];
			}
		}
		
		delete[] m_pAdjaMatrix;
	}
	
	m_pNumNodes = 0;
}

bool CGraph::AddEdge(unsigned int Node1, unsigned int Node2, unsigned int EdgeWeight)
{
	bool status = false;
	
	if (Node1 >= m_pNumNodes || Node2 >= m_pNumNodes || m_pAdjaMatrix == NULL)
	{
		goto Exit;
	}
	
	m_pAdjaMatrix[Node1][Node2] = EdgeWeight;
	
	status = true;
	
Exit:
	return status;
}

bool CGraph::DeleteEdge(unsigned int Node1, unsigned int Node2)
{
	bool status = false;
	
	if (Node1 >= m_pNumNodes || Node2 >= m_pNumNodes || m_pAdjaMatrix == NULL)
	{
		goto Exit;
	}
	
	m_pAdjaMatrix[Node1][Node2] = NO_EDGE;
	
	status = true;
	
Exit:
	return status;
}

bool CGraph::DFS(unsigned int StartNode)
{
	bool status = false;
	
	unsigned int node;
	
	unsigned int index;
	
	bool visited[m_NumNodes];
	
	CStack<unsigned int> stack;
	
	if (StartNode >= m_NumNodes)
	{
		goto Exit;
	}
	
	for (index = 0; index < m_NumNodes; index++)
	{
		visited[index] = false;
	}
	
	stack.Push(StartNode);
	
	while(!stack.IsEmpty())
	{
		stack.Pop(node);
		
		visited[node] = true;
		
		cout << node << " ";
		
		for (index = 0; index < m_NumNodes; index++)
		{
			if ((m_pAdjaMatrix[node][index] != NO_EDGE) && visited[index] == false)
			{
				stack.Push(index);
			}
		}
	}
	
	status = true;
	
Exit:

	return status;
}

bool CGraph::TopSort()
{
	bool status = false;
	
	unsigned int node;
	
	unsigned int indexI, indexJ;
	
	bool visited[m_NumNodes];
	
	CStack<unsigned int> stack;
	
	CStack<unsigned int> visitStack;
	
	for (indexI = 0;  indexI < m_NumNodes; indexI++)
	{
		visited[m_NumNodes] = 0;
	}
	
	for (indexI = 0; indexI < m_NumNodes; indexI++)
	{
		if (!visited[indexI])
		{
			stack.Push(indexI);
			
			while (!stack.IsEmpty())
			{
				stack.Pop(node);
				
				visited[node] = true;
		
				visitStack.Push(node);
		
				for (indexJ = 0; indexJ < m_NumNodes; indexJ++)
				{
					if ((m_pAdjaMatrix[node][indexJ] != NO_EDGE) && visited[indexJ] == false)
					{
						stack.Push(indexJ);
					}
				}
				
			}
			
			while (!visitStack.IsEmpty())
			{
				visitStack.Pop(node);
				
				cout << node << " ";
			}
		}
	}
	
}

bool CGraph::BFS(unsigned int StartNode)
{
	bool status = false;
	
	unsigned int node;
	
	unsigned int index;
	
	bool visited[m_NumNodes];
	
	CQueue<unsigned int> queue;
	
	if (StartNode >= m_NumNodes)
	{
		goto Exit;
	}
	
	for (index = 0; index < m_NumNodes; index++)
	{
		visited[index] = false;
	}
	
	queue.Enqueue(StartNode);
	
	while(!queue.IsEmpty())
	{
		queue.Dequeue(node);
		
		visited[node] = true;
		
		cout << node << " ";
		
		for (index = 0; index < m_NumNodes; index++)
		{
			if ((m_pAdjaMatrix[node][index] != NO_EDGE) && visited[index] == false)
			{
				queue.Enqueue(index);
			}
		}
	}
	
	status = true;
	
Exit:

	return status;
}

#endif