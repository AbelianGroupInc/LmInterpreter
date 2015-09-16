//Implementation of perfoming of commands is located in "Lm1MainMethods.cpp"

#include "Lm1.h"

#define STOP_COMMAND 153

const int MAX_CPU_MEMORY_SIZE = 15;

void Lm1::clear_memory(){
	this->ram_memory.clear();

	for (int i = 0; i < MAX_CPU_MEMORY_SIZE; i++)
		this->cpu_memory[i] = INT_MAX;
}

void Lm1::execute_the_program(){
	while (this->perfom_commands() != STOP_COMMAND);
	return;
}

