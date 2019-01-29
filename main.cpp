#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include "Graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "SearchNode.h"
#include "bfs.h"
#include <iostream>
#include <stack>


int main()
{
	// You can change this to an undirected graph to verify that a path is found
	DirectedGraph<char*> graph;

	SearchNode<char*> *A = DBG_NEW SearchNode<char*>("A");
	SearchNode<char*> *B = DBG_NEW SearchNode<char*>("B");
	SearchNode<char*> *C = DBG_NEW SearchNode<char*>("C");
	SearchNode<char*> *D = DBG_NEW SearchNode<char*>("D");
	SearchNode<char*> *E = DBG_NEW SearchNode<char*>("E");
	SearchNode<char*> *F = DBG_NEW SearchNode<char*>("F");
	SearchNode<char*> *G = DBG_NEW SearchNode<char*>("G");
	
	graph.addEdge(A, B);
	graph.addEdge(B, C);
	graph.addEdge(E, C);
	graph.addEdge(C, D);
	graph.addEdge(E, D);
	graph.addEdge(E, F);
	graph.addEdge(F, D);
	graph.addEdge(D, G);

	SearchNode<char*> *start = A;
	SearchNode<char*> *end = F;
	char* startValue = start->getValue();
	char* endValue = end->getValue();

	PlannerNode<char*> *foundNode = BFS(graph, start, end);

	if (foundNode == nullptr)
	{
		std::cout << "No such path from " << startValue << " to " << endValue << std::endl;
		_CrtDumpMemoryLeaks();
		return -1;
	}

	std::stack<char*> order;

	// foundNode is the last, so we need to backtrack to the initial node
	while (foundNode != nullptr)
	{
		order.push((foundNode->state)->getValue());
		
		PlannerNode<char*> *parent = foundNode->parent;
		delete foundNode;
		foundNode = parent;
	}

	// And now print the nodes in order
	while (!order.empty())
	{
		std::cout << order.top() << " -> ";
		order.pop();
	}

	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	delete G;

	_CrtDumpMemoryLeaks();

	return 0;
}