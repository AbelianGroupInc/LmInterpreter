#pragma once
#ifndef LM_INTERPRETER_MEMORY_H
#define LM_INTERPRETER_MEMORY_H

#include <unordered_map>
#include <memory>

#include "MemoryItem.h"

class Memory{
public:
	Memory();
	Memory(Memory& copyingMemory);

	MemoryItem* get(int position);
	//Getting a cell content. A command or a variable 
	void set(int position, MemoryItem* item);
	void clear();
	bool is_memory_cell_empty(int position);
	void set_name(int position,std::string name);
	//Set variable name
	std::string get_name(int position)const;
	//Get variable name
	std::unordered_map<int, std::shared_ptr<MemoryItem> > get_memory();
	std::unordered_map<int, std::string> get_names();
	
private:
	std::unordered_map<int,std::shared_ptr<MemoryItem> > memory;
	std::unordered_map<int, std::string> names;
	//Names of variables 

	void check(int position)const;
};

#endif