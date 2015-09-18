#pragma once
#ifndef UM_COMPILER_UM1_H
#define UM_COMPILER_UM1_H

#include <vector>

#include "Lm.h"
#include "Memory.h"

class Lm1 : public Lm{
public:
	Lm1();
	virtual void execute_the_program();
	virtual void set_program(const std::vector<std::vector<int> > &program);
	virtual std::vector<std::vector<int> > get_program() const;
	virtual void init_variable(int position, std::string name);
	virtual void init_variable(int position, int value);
	virtual void init_variable(int position, std::string name, int value);
	virtual void clear_memory()override final;
	
private:
	int current_address;
	Memory ram_memory;
	std::unordered_map<int, int> cpu_memory;

	virtual Memory get_memory()override final;
	virtual void set_memory(Memory)override final;

	void setCellCheck(bool, int, const std::vector<std::vector<int> > &, int);

	int perfom_commands();

	void go_to_next_command(int);

	void clear_commands_in_memory();

	void perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*), int);
	void perform_comparison_operation(int);
	void perform_input_operation(void(*func)(MemoryItem*&, const std::string));
	void perform_output_operation(void(*func)(const MemoryItem*, const std::string));
	void perform_assignment_operation(int);
	void perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
		MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*), int);
	void perform_go_to_operation();

	void conditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*), int);
	void unconditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*));

	void cmd_rm_assigment_1_work();
	void cmd_rm_assigment_2_work();
	void cmd_rr_assigment_work();

	bool is_command_long(int);

	int get_cmp_command(int);
	//The commant for getting the number of the comparison command 
	//for "perform_comparison_operation"

	int get_r1_register();
	int get_a2_register();
	int get_m2_register();
	int get_r2_register();
	int get_ram_value(int);
	int get_cpu_value(int);
	
	int get_transit_address();

	int get_first_operand_adress();
	int get_first_operand_value();
	int get_second_operand_adress(int);
	int get_second_operand_value(int);
	MemoryItem* get_first_operand();
	MemoryItem* get_second_operand(int);
	MemoryItem* get_operand(const int, int);

	void process_command(std::vector<int>, bool&);
	void command_initialisation(std::vector<int>, bool&);
	void long_command_initialisation(std::vector<int>, int);
	void short_command_initialisation(std::vector<int>, int, bool&);
	void check_command_address(int);
	
	void check_long_command_correctness(std::vector<int>);
	void check_short_command_correctness(std::vector<int>);
};

#endif