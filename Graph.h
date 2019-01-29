#pragma once
#include "SearchNode.h"
#include <vector>
#include <map>


/* A Graph relating SearchNodes to each other via an adjacency list.
 */

template<typename Type>
class Graph
{
public:
	std::vector<SearchNode<Type>*> neighborsOf(SearchNode<Type> *node);
	Graph() {}
	Graph(const Graph<Type> &other);
	Graph& operator=(const Graph &other);
	virtual void addEdge(SearchNode<Type> *start, SearchNode<Type> *end) = 0;
	inline int size() { return adjacencyList.size(); }

protected:
	std::map<SearchNode<Type>*, std::vector<SearchNode<Type>*>> adjacencyList;
};


// Copy constructor
template<typename Type>
inline Graph<Type>::Graph(const Graph<Type>& other)
{
	// TODO add code for deep copying the map objects
}


// Assignment overload
template<typename Type>
inline Graph<Type> &Graph<Type>::operator=(const Graph & other)
{
	// TODO change
	return new Graph<Type>();
}


template<typename Type>
std::vector<SearchNode<Type>*> Graph<Type>::neighborsOf(SearchNode<Type> *node)
{
	if (node != nullptr)
	{
		return adjacencyList[node];
	}

	return std::vector<SearchNode<Type>*>();
}

