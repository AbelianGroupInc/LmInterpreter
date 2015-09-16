#pragma once
#ifndef LM_INTERPRETER_LM2_H
#define LM_INTERPRETER_LM2_H

#include <vector>
#include <cstdlib>
#include <stdexcept>

#include "Lm.h"
#include "Memory.h"

class Lm2 : public Lm{
public:
	Lm2() :current_address(0), memory(),cmp_op(10){}
	virtual void execute_the_program() override final;
	virtual void set_program(const std::vector<std::vector<int> > &program)override final;
	virtual std::vector<std::vector<int> > get_program()const override final;
	virtual void init_variable(int position, std::string name)override final;
	virtual void init_variable(int position, int value) override final;
	virtual void init_variable(int position, std::string name, int value)override final;
	virtual void clear_memory()override final;
private:
	enum flags { EQUAL, N_EQUAL, LESS, GREATER, LESS_OR_EQUAL, GREATER_OR_EQUAL, INS_LESS, INS_GREATER, INS_LESS_OR_EQUAL, INS_GREATER_OR_EQUAL };

	std::vector<bool> cmp_op;
	int current_address;
	Memory memory;

	virtual Memory get_memory()override final;
	virtual void set_memory(Memory)override final;

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*),int type);
	void perform_comparison_operation(flags flag);
	void perform_input_operation(void(*func)(MemoryItem*&, const std::string));
	void perform_output_operation(void(*func)(const MemoryItem*, const std::string));
	void perform_assignment_operation();
	void perfom_flag_determination();
	void perform_goto();
	void perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
		MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*));

	int get_value_operand(int position_in_memory, int number_of_operands);
	int get_address_operand(int position_in_memory, int number_of_operands);
};

#endif