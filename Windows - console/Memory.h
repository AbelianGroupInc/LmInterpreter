#pragma once
#ifndef LM_INTERPRETER_MEMORY_H
#define LM_INTERPRETER_MEMORY_H

#include <unordered_map>

#include "MemoryItem.h"

class Memory{
public:
	Memory();
	~Memory();

	MemoryItem* get(int position);
	void set(int position, MemoryItem* item);
private:
	std::unordered_map<int, MemoryItem*> memory;
};

#endif