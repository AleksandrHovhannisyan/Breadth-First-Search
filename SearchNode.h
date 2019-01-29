#pragma once


/* A SearchNode represents a vertex in a graph. It's simply a wrapper
 * around a value and has no other special information.
 */

template<typename Type>
class SearchNode
{
public:
	SearchNode(Type value) { this->value = value; }
	inline void setValue(Type value) { this->value = value; }
	inline Type getValue() const { return this->value; }
private:
	Type value;
};