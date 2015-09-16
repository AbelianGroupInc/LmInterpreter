#pragma once
#ifndef LM_INTERPRETER_LM3_H
#define LM_INTERPRETER_LM3_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm3 : public Lm{
public:
	Lm3() :current_address(0), memory(){}
	virtual void execute_the_program()override final;
	virtual void set_program(const std::vector<std::vector<int> > &program)override final;
	virtual std::vector<std::vector<int> > get_program()const override final;
	virtual void init_variable(int position, std::string name)override final;
	virtual void init_variable(int position, int value)override final;
	virtual void init_variable(int position, std::string name, int value)override final;
	virtual void clear_memory()override final;
private:
	int current_address;
	Memory memory;

	virtual Memory get_memory()override final;
	virtual void set_memory(Memory)override final;

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*));
	void perform_comparison_operation(bool (*func)(const MemoryItem*, const MemoryItem*));
	void perform_input_operation(void(*func)(MemoryItem*&, const std::string));
	void perform_output_operation(void(*func)(const MemoryItem*, const std::string));
	void perform_assignment_operation();
	void perform_go_to_operation();
	void perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
		MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*));

	int get_value_operand(int position_in_memory, int number_of_operands);
	int get_address_operand(int position_in_memory, int number_of_operands);
};

#endif