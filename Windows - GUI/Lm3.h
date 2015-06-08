#pragma once
#ifndef LM_INTERPRETER_LM3_H
#define LM_INTERPRETER_LM3_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm3 : public Lm{
public:
	Lm3() :current_address(0), memory(),end_flag(false),input_flag(false){}

	virtual void do_one_step(System::Windows::Forms::RichTextBox^ out)override final;

	virtual void set_program(const std::vector<std::vector<int> > &program)override final;
	virtual std::string current_command() ;
	virtual bool is_end()override final;
	virtual void input(int value) ;


	virtual std::vector<std::string> get_var_inf();
	virtual std::vector<std::string> get_cmd_inf();
	virtual std::vector<std::vector<int> > get_program()const override final;

	virtual void init_variable(int position, std::string name)override final;
	virtual void init_variable(int position, int value)override final;
	virtual void init_variable(int position, std::string name, int value)override final;

	virtual void clear_memory()override final;
private:
	int current_address;
	Memory memory;

	bool end_flag;
	bool input_flag;

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*));
	void perform_comparison_operation(bool (*func)(const MemoryItem*, const MemoryItem*));
	void perform_input_operation(int value);
	void perform_output_operation(void(*func)(System::Windows::Forms::RichTextBox^ out, const MemoryItem*, const std::string), System::Windows::Forms::RichTextBox^ out);
	void perform_assignment_operation();
	void perform_go_to_operation();
	void perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
		MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*));

	int get_value_operand(int position_in_memory, int number_of_operands);
	int get_address_operand(int position_in_memory, int number_of_operands);
};

#endif