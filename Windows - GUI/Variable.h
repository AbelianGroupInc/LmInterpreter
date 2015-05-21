#ifndef LM_INTERPRETER_VARIABLE_H
#define LM_INTERPRETER_VARIABLE_H

#include <vector>

#include "MemoryItem.h"

const int VAR_MAX = 65535;

class Variable : public MemoryItem{
public:
	Variable() :variable(1, 0){}
	Variable(int value) :variable(1, value % VAR_MAX){}

	virtual std::vector<int>& get() _NOEXCEPT override final;
	virtual int get_value()const _NOEXCEPT override final;
private:
	std::vector<int> variable;
};

#endif