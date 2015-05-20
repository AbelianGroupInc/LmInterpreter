#include "Lm1.h"
#include "Variable.h"
#include "Converter.h"
#include "LmCommands.h"
#include "InterpreterException.h"

const int 
	MAX_CPU_MEMORY_SIZE = 16,
	MAX_RAM_MEMORY_SIZE = 65535;

int const
	CMD_RM_ASSIGMENT_1            = 0,
	CMD_RM_ASSIGMENT_2            = 16,
	CMD_LESS                      = 131,
	CMD_GREATER                   = 133,
	CMD_LESS_OR_EQUAL             = 134,
	CMD_GREATER_OR_EQUAL          = 132,
	CMD_EQUAL                     = 129,
	CMD_NOT_EQUAL                 = 130,
	CMD_UNSIGNED_LESS             = 147,
	CMD_UNSIGNED_GREATER          = 149,
	CMD_UNSIGNED_LESS_OR_EQUAL    = 148,
	CMD_UNSIGNED_GREATER_OR_EQUAL = 150,
	CMD_GO_TO                     = 128,
	COMMAND_IS_LONG               = 100;

int const
	FIRST_OPERAND  = 1,
	SECOND_OPERAND = 2;

void Lm1::perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*), int command){
	MemoryItem* first_operand = this->get_operand(FIRST_OPERAND, command);
	MemoryItem* second_operand = this->get_operand(SECOND_OPERAND, command);

	this->cpu_memory[get_r1_register()] = func(first_operand, second_operand)->get_value();

	this->go_to_next_command(command);
}

void Lm1::perform_comparison_operation(int command){
	if (this->current_address + 1 > MAX_RAM_MEMORY_SIZE)
		throw std::exception();

	int comp_command = this->get_cmp_command(command);

	switch (comp_command){
	case CMD_LESS:
		this->conditional_transit(LmCommands::less, command);
		break;
	case CMD_GREATER:
		this->conditional_transit(LmCommands::greater, command);
		break;
	case CMD_LESS_OR_EQUAL:
		this->conditional_transit(LmCommands::less_or_equal, command);
		break;
	case CMD_GREATER_OR_EQUAL:
		this->conditional_transit(LmCommands::greater_or_equal, command);
		break;
	case CMD_EQUAL:
		this->conditional_transit(LmCommands::equal, command);
		break;
	case CMD_NOT_EQUAL:
		this->conditional_transit(LmCommands::not_equal, command);
		break;
	case CMD_UNSIGNED_LESS:
		this->conditional_transit(LmCommands::unsigned_less, command);
		break;
	case CMD_UNSIGNED_GREATER:
		this->conditional_transit(LmCommands::unsigned_greater, command);
		break;
	case CMD_UNSIGNED_LESS_OR_EQUAL:
		this->conditional_transit(LmCommands::unsigned_less_or_equal, command);
		break;
	case CMD_UNSIGNED_GREATER_OR_EQUAL:
		this->conditional_transit(LmCommands::unsigned_greater_or_equal, command);
		break;
	case CMD_GO_TO:
		this->unconditional_transit(LmCommands::go_to);
		break;
	default:
		std::exception();
		break;
	}
}

void Lm1::perform_input_operation(void(*func)(MemoryItem*&, const std::string)){
	MemoryItem* var1 = new Variable();

	if (this->get_second_operand_adress(COMMAND_IS_LONG) + 1 >= MAX_RAM_MEMORY_SIZE)
		throw std::out_of_range("Out of Memory");

	func(var1, this->ram_memory.get_name(this->get_second_operand_adress(COMMAND_IS_LONG)));
	MemoryItem* var2 = new Variable(var1->get_value());
	this->ram_memory.set(this->get_second_operand_adress(COMMAND_IS_LONG), var1);
	this->ram_memory.set(this->get_second_operand_adress(COMMAND_IS_LONG) + 1, var2);

	go_to_next_command(COMMAND_IS_LONG);
}

void Lm1::perform_output_operation(void(*func)(const MemoryItem*, const std::string)){
	MemoryItem* var = this->get_operand(SECOND_OPERAND, COMMAND_IS_LONG);

	func(var, this->ram_memory.get_name(this->get_second_operand_adress(COMMAND_IS_LONG)));

	this->go_to_next_command(COMMAND_IS_LONG);
}

void Lm1::perform_assignment_operation(int command){
	if (command == CMD_RM_ASSIGMENT_1)
		this->cmd_rm_assigment_1_work();
	else if (command == CMD_RM_ASSIGMENT_2)
		this->cmd_rm_assigment_2_work();
	else
		this->cmd_rr_assigment_work();
	
	this->go_to_next_command(command);
}

void Lm1::perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
	MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*), int command){
	MemoryItem* var_1 = new Variable(this->get_first_operand_value());
	MemoryItem* var_2 = new Variable(this->get_second_operand_value(COMMAND_IS_LONG));

	if (this->get_cpu_value(this->get_first_operand_adress() + 1) != INT_MAX)
		throw std::out_of_range("Out of Memory");

	this->cpu_memory[this->get_first_operand_adress()] = division_func(var_1, var_2)->get_value();
	this->cpu_memory[this->get_first_operand_adress() + 1] = module_func(var_1, var_2)->get_value();
	
	this->go_to_next_command(command);
}