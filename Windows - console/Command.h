#pragma once
#ifndef LM_INTERPRETER_COMMAND_H
#define LM_INTERPRETER_COMMAND_H

#include "MemoryItem.h"

class Command :public MemoryItem{
public:
	virtual std::vector<int>& get() = 0;
	virtual int get_value()const = 0;
};

#endif