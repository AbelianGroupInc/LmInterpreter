#pragma once
#ifndef LM_INTERPRETER_LM2_H
#define LM_INTERPRETER_LM2_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm2 : public Lm{
public:
	Lm2() :current_address(0), memory(){}
	virtual void execute_the_program();
	virtual void set_program(const std::vector<std::vector<int> > &program);
	virtual std::vector<std::vector<int> > get_program()const;
private:
	int current_address;
	Memory memory;

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*));
	void perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*));
	void perform_input_operation(void(*func)(MemoryItem*&, const std::string));
	void perform_output_operation(void(*func)(const MemoryItem*, const std::string));
	void perform_assignment_operation();

	int get_value_operand(int position_in_memory, int number_of_operands);
	int get_address_operand(int position_in_memory, int number_of_operands);
};

#endif