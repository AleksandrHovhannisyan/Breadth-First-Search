#pragma once
#include "SearchNode.h"
#include <vector>
#include <map>


template<typename Type>
class Graph
{
public:
	Graph() {}
	void addEdge(SearchNode<Type> *start, SearchNode<Type> *end);
	std::vector<SearchNode<Type>*> neighborsOf(SearchNode<Type> *node);
	int size() { return adjacencyList.size(); }

private:
	std::map<SearchNode<Type>*, std::vector<SearchNode<Type>*>> adjacencyList;
};


template<typename Type>
inline void Graph<Type>::addEdge(SearchNode<Type> *start, SearchNode<Type> *end)
{
	adjacencyList[start].push_back(end);
	adjacencyList[end].push_back(start);
}


template<typename Type>
inline std::vector<SearchNode<Type>*> Graph<Type>::neighborsOf(SearchNode<Type> *node)
{
	if (node != nullptr)
	{
		return adjacencyList[node];
	}

	return std::vector<SearchNode<Type>*>();
}

