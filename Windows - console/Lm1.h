#pragma once
#ifndef LM_INTERPRETER_LM1_H
#define LM_INTERPRETER_LM1_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm1 : public Lm{
public:
	Lm1();
	virtual void execute_the_program();
	virtual void set_program(const std::vector<std::vector<int> > &program);
	virtual std::vector<std::vector<int> > get_program() const;
private:
	int current_address;
	Memory ram_memory;
	std::unordered_map<int, MemoryItem*> cpu_memory;


	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*), int);
	void perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*));
	void perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*),int);
	void perform_input_operation(void(*func)(MemoryItem*&, const std::string));
	void perform_output_operation(void(*func)(const MemoryItem*, const std::string));
	void perform_assignment_operation(int);
	bool is_command_long(int);
	MemoryItem* get_operand(const int, int);
	MemoryItem* get_operand(const int);
};

#endif