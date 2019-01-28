#pragma once


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