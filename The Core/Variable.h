#ifndef LM_INTERPRETER_VARIABLE_H
#define LM_INTERPRETER_VARIABLE_H

#include <vector>

#include "MemoryItem.h"

class Variable : public MemoryItem{
public:
	Variable() :variable(1, 0){}
	Variable(int value) :variable(1, value){}

	virtual std::vector<int>& get();
	virtual int get_value()const;
private:
	std::vector<int> variable;
};

#endif