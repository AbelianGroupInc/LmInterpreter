#include "Lm1.h"

#define STOP_COMMAND 153

void Lm1::clear_memory(){
	this->ram_memory.clear();
}

void Lm1::execute_the_program(){
	while (this->perfom_commands() != STOP_COMMAND);
	return;
}

