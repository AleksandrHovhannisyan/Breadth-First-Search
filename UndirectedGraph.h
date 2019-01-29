#pragma once
#include "Graph.h"


template<typename Type>
class UndirectedGraph : public Graph<Type>
{
public:
	void addEdge(SearchNode<Type> *start, SearchNode<Type> *end);
};


template<typename Type>
void UndirectedGraph<Type>::addEdge(SearchNode<Type> *start, SearchNode<Type> *end)
{
	adjacencyList[start].push_back(end);
	adjacencyList[end].push_back(start);
}