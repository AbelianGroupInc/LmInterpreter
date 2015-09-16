#pragma once
#ifndef LM_INTERPRETER_LM_H
#define LM_INTERPRETER_LM_H

#include <vector>
#include "Memory.h"

class Lm{
public:
	virtual void execute_the_program() = 0;
	virtual void set_program(const std::vector<std::vector<int> > &program) = 0;
	//Processing the lm's program code, setting commands in memory
	virtual std::vector<std::vector<int> > get_program()const = 0;

	virtual void init_variable(int position, std::string name) = 0;
	virtual void init_variable(int position, int value) = 0;
	virtual void init_variable(int position, std::string name, int value) = 0;

	virtual Memory get_memory() = 0;
	virtual void set_memory(Memory) = 0;

	virtual void clear_memory() = 0;
};

#endif