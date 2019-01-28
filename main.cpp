#include "Graph.h"
#include "SearchNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <set>


template<typename Type>
struct PlannerNode
{
	PlannerNode<Type>(SearchNode<Type> *node) : state(node) { }
	SearchNode<Type> *state = nullptr;
	PlannerNode *parent = nullptr;
};


template<typename Type>
PlannerNode<Type> *BFS(Graph<Type> &graph, SearchNode<Type> *start, SearchNode<Type> *goal)
{
	std::queue<PlannerNode<Type>*> frontier;
	std::set<SearchNode<Type>*> visited;
	frontier.push(new PlannerNode<Type>(start));

	// Continue the search until we've exhausted all possibilities
	while (!frontier.empty())
	{
		PlannerNode<Type> *current = frontier.front();
		frontier.pop();

		// If we found our goal, return true
		if (current->state == goal)
		{
			return current;
		}

		// Log the current node as having been visited (optimization)
		visited.insert(current->state);
		
		std::vector<SearchNode<Type>*> neighbors = graph.neighborsOf(current->state);

		// Loop through each neighbor of the current node
		for (auto i = 0; i < neighbors.size(); i++)
		{
			SearchNode<Type> *successor = neighbors[i];
			
			// If we never visited this successor node before, add it to the frontier (optimization)
			if (visited.find(successor) == visited.end())
			{
				PlannerNode<Type> *successorNode = new PlannerNode<Type>(successor);
				successorNode->parent = current;
				frontier.push(successorNode);
			}
		}
	}

	return nullptr;
}


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