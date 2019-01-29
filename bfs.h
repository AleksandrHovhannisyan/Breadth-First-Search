#pragma once
#include "Graph.h"
#include "SearchNode.h"
#include <queue>
#include <stack>
#include <set>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif


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
	frontier.push(DBG_NEW PlannerNode<Type>(start));

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

	std::set<SearchNode<Type>*>::iterator it;
	for (it = visited.begin(); it != visited.end(); ++it)
	{
		delete (*it);
	}

	return nullptr;
}