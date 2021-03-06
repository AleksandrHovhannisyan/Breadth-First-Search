#pragma once
#include "Graph.h"


template<typename Type>
class DirectedGraph : public Graph<Type>
{
public:
	void addEdge(SearchNode<Type> *start, SearchNode<Type> *end);
};


template<typename Type>
void DirectedGraph<Type>::addEdge(SearchNode<Type> *start, SearchNode<Type> *end)
{
	adjacencyList[start].push_back(end);
}