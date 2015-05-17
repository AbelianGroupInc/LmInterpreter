#pragma once
#ifndef LM_INTERPRETER_MEMORY_ITEM_H
#define LM_INTERPRETER_MEMORY_ITEM_H

#include <vector>

class MemoryItem{
public:
	virtual std::vector<int>& get() _NOEXCEPT = 0;
	virtual int get_value()const _NOEXCEPT = 0;
};

#endif