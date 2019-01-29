#include "Graph.h"
#include "SearchNode.h"
#include "bfs.h"
#include <iostream>
#include <stack>


int main()
{
	Graph<char*> graph;

	SearchNode<char*> *A = new SearchNode<char*>("A");
	SearchNode<char*> *B = new SearchNode<char*>("B");
	SearchNode<char*> *C = new SearchNode<char*>("C");
	SearchNode<char*> *D = new SearchNode<char*>("D");
	SearchNode<char*> *E = new SearchNode<char*>("E");
	SearchNode<char*> *F = new SearchNode<char*>("F");
	SearchNode<char*> *G = new SearchNode<char*>("G");
	
	graph.addEdge(A, B);
	graph.addEdge(B, C);
	graph.addEdge(C, E);
	graph.addEdge(C, D);
	graph.addEdge(E, D);
	graph.addEdge(E, F);
	graph.addEdge(D, F);
	graph.addEdge(D, G);

	PlannerNode<char*> *foundNode = BFS(graph, A, F);
	std::stack<char*> order;

	// foundNode is the last, so we need to backtrack to the initial node
	while (foundNode != nullptr)
	{
		order.push((foundNode->state)->getValue());
		foundNode = foundNode->parent;
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

	return 0;
}