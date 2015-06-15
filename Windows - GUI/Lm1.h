#pragma once
#ifndef UM_COMPILER_UM1_H
#define UM_COMPILER_UM1_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm1 : public Lm{
public:
	Lm1();
	virtual void do_one_step(System::Windows::Forms::RichTextBox^ out)override final;
	virtual void set_program(const std::vector<std::vector<int> > &program)override final;;
	virtual std::vector<std::vector<int> > get_program() const;
	virtual void init_variable(int position, std::string name)override final;
	virtual void init_variable(int position, int value)override final;
	virtual void init_variable(int position, std::string name, int value)override final;
	virtual void clear_memory()override final;

	virtual std::string current_command();
	virtual bool is_end()override final;
	virtual void input(int value);
	
	virtual std::vector<std::string> get_var_inf();
	virtual std::vector<std::string> get_cmd_inf();

private:
	int current_address;
	Memory ram_memory;
	std::unordered_map<int, int> cpu_memory;

	bool end_flag;
	bool input_flag;

	void setCellCheck(bool, int, const std::vector<std::vector<int> > &, int);

	void perfom_command(System::Windows::Forms::RichTextBox^ out);

	int get_r1_register();
	int get_a2_register();
	int get_m2_register();
	int get_r2_register();
	int get_ram_value(int);
	int get_cpu_value(int);

	void go_to_next_command(int);
	int get_cmp_command(int);

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*), int);
	void perform_comparison_operation(int);
	void perform_input_operation(int);
	void perform_output_operation(void(*func)(System::Windows::Forms::RichTextBox^ out, const MemoryItem*, const std::string),
		System::Windows::Forms::RichTextBox^ out);
	void perform_assignment_operation(int);
	void perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
		MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*), int);

	void conditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*), int);
	void unconditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*));

	void cmd_rm_assigment_1_work();
	void cmd_rm_assigment_2_work();
	void cmd_rr_assigment_work();

	bool is_command_long(int);
	
	int get_first_operand_adress();
	int get_first_operand_value();
	int get_second_operand_adress(int);
	int get_second_operand_value(int);
	MemoryItem* get_first_operand();
	MemoryItem* get_second_operand(int);
	MemoryItem* get_operand(const int, int);
	
};

#endif