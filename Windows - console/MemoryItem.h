#pragma once
#ifndef LM_INTERPRETER_MEMORY_ITEM_H
#define LM_INTERPRETER_MEMORY_ITEM_H

#include <vector>

class MemoryItem{
	//The abstract class that represents a command or a variable
public:
	virtual std::vector<int>& get() _NOEXCEPT = 0;
	//Returns the vector which represents a command or a variable
	virtual int get_value()const _NOEXCEPT = 0;
	//Getting a command number or a variable value
};

#endif