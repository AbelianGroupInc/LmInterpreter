#include <string.h>

#include "Lm3.h"
#include "Lm3Command.h"
#include "Variable.h"
#include "LmCommands.h"
#include "Converter.h"
#include "InterpreterException.h"

const int MAX_MEMORY_SIZE = 65535;
const int
	CMD_INPUT                     = 6,
	CMD_OUTPUT                    = 7,
	CMD_UNSIGNED_INPUT            = 22,
	CMD_UNSIGNED_OUTPUT           = 23,
	CMD_ADD                       = 1,
	CMD_SUBSRACT                  = 2,
	CMD_MULTIPLICATION            = 3,
	CMD_DIVISION                  = 4,
	CMD_UNSIGNED_MULTIPLICATION   = 19,
	CMD_UNSIGNED_DIVISION         = 20,
	CMD_ASSIGMENT                 = 0,
	CMD_GOTO                      = 128,
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
	CMD_STOP                      = 153;


void Lm3::execute_the_program(){
	while (true){
		switch (this->memory.get(this->current_address)->get_value()){
		case CMD_INPUT:
			this->perform_input_operation(LmCommands::input);
			break;
		case CMD_OUTPUT:
			this->perform_output_operation(LmCommands::output);
			break;
		case CMD_UNSIGNED_INPUT:
			this->perform_input_operation(LmCommands::unsigned_input);
			break;
		case CMD_UNSIGNED_OUTPUT:
			this->perform_output_operation(LmCommands::unsigned_output);
			break;
		case CMD_ADD:
			this->perform_arithmetic_operation(LmCommands::add);
			break;
		case CMD_SUBSRACT:
			this->perform_arithmetic_operation(LmCommands::subsract);
			break;
		case CMD_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::multiplication);
			break;
		case CMD_DIVISION:
			this->perform_division_operation(LmCommands::division, LmCommands::module);
			break;
		case CMD_UNSIGNED_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::unsigned_multiplication);
			break;
		case CMD_UNSIGNED_DIVISION:
			this->perform_division_operation(LmCommands::unsigned_division, LmCommands::unsigned_module);
			break;
		case CMD_ASSIGMENT:
			perform_assignment_operation();
			break;
		case CMD_GOTO:
			this->perform_go_to_operation();
			break;
		case CMD_LESS:
			this->perform_comparison_operation(LmCommands::less);
			break;
		case CMD_GREATER:
			this->perform_comparison_operation(LmCommands::greater);
			break;
		case CMD_LESS_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::less_or_equal);
			break;
		case CMD_GREATER_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::greater_or_equal);
			break;
		case CMD_EQUAL:
			this->perform_comparison_operation(LmCommands::equal);
			break;
		case CMD_NOT_EQUAL:
			this->perform_comparison_operation(LmCommands::not_equal);
			break;
		case CMD_UNSIGNED_LESS:
			this->perform_comparison_operation(LmCommands::unsigned_less);
			break;
		case CMD_UNSIGNED_GREATER:
			this->perform_comparison_operation(LmCommands::unsigned_greater);
			break;
		case CMD_UNSIGNED_LESS_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::unsigned_less_or_equal);
			break;
		case CMD_UNSIGNED_GREATER_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::unsigned_greater_or_equal);
			break;
		case CMD_STOP:
			return;
			break;
		default:
			std::exception();
			break;
		}
	}
}

void Lm3::init_variable(int position, std::string name){
	this->memory.set_name(position, name);
}

void Lm3::init_variable(int position, int value){
	this->memory.set(position, new Variable(value));
}

void Lm3::init_variable(int position, std::string name, int value){
	this->init_variable(position, name);
	this->init_variable(position, value);
}

void Lm3::set_program(const std::vector<std::vector<int> > &program){
	bool end = false;
	if (program.size() == 0)
		throw std::exception("Lost end of program");

	if (program.front().front() >= 0 && program.front().front() <= MAX_MEMORY_SIZE)
		this->current_address=program.front().front();

	for (size_t i = 0; i < program.size(); i++){
		if (program[i].front() >= 0 && program[i].front() <= MAX_MEMORY_SIZE){
			try{
				this->memory.set(program[i].front(), new Lm3Command(program[i][1], program[i][2], program[i][3], program[i][4]));

				if (this->memory.get(program[i].front())->get_value() == CMD_STOP)
					end = true;
			}
			catch(std::exception& exp){
				char* temp = new char[strlen(exp.what()) + 1];
				strcpy(temp, exp.what());
				throw InterpreterException(temp, i + 1);
			}
			
		}
		else{
			throw std::out_of_range("Out of Memory");
		}
	}

	if (!end)
		throw std::exception("Lost end of program");
}

std::vector<std::vector<int> > Lm3::get_program()const{
	return std::vector<std::vector<int> >();
}

void Lm3::perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*)){
	MemoryItem* var_1 = new Variable(this->get_value_operand(this->current_address,1));
	MemoryItem* var_2 = new Variable(this->get_value_operand(this->current_address,2));

	this->memory.set(this->get_address_operand(this->current_address,3), func(var_1, var_2));
	this->current_address++;
}

void Lm3::perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*)){
	MemoryItem* var_1 = new Variable(this->get_value_operand(this->current_address, 1));
	MemoryItem* var_2 = new Variable(this->get_value_operand(this->current_address, 2));

	this->current_address = func(var_1, var_2) ? this->get_address_operand(this->current_address, 3) : this->current_address + 1;
}

void Lm3::perform_go_to_operation(){
	this->current_address = this->get_address_operand(this->current_address, 3);
}

void Lm3::perform_input_operation(void(*func)(MemoryItem*&, const std::string)){
	MemoryItem* var = new Variable();

	func(var, this->memory.get_name(this->get_address_operand(this->current_address, 1)));
	this->memory.set(this->get_address_operand(this->current_address, 1), var);

	this->current_address++;
}

void Lm3::perform_output_operation(void(*func)(const MemoryItem*, const std::string)){
	MemoryItem* var = new Variable(this->get_value_operand(this->current_address, 1));

	func(var, this->memory.get_name(this->get_address_operand(this->current_address, 1)));

	this->current_address++;
}

void Lm3::perform_assignment_operation(){
	int in_position = this->get_address_operand(this->current_address, 3);
	int value = this->get_value_operand(this->current_address, 1);

	MemoryItem* var = new Variable(value);

	this->memory.set(in_position, var);
	this->current_address++;
}

void Lm3::perform_division_operation(MemoryItem* (*division_func)(const MemoryItem*, const MemoryItem*),
	MemoryItem* (*module_func)(const MemoryItem*, const MemoryItem*)){
	MemoryItem* var_1 = new Variable(this->get_value_operand(this->current_address, 1));
	MemoryItem* var_2 = new Variable(this->get_value_operand(this->current_address, 2));

	this->memory.set(this->get_address_operand(this->current_address, 3), division_func(var_1, var_2));
	this->memory.set(this->get_address_operand(this->current_address, 3) + 1, module_func(var_1, var_2));
	this->current_address++;
}

int Lm3::get_value_operand(int position_in_memory, int number_of_operands){
	if (position_in_memory < 0 || position_in_memory > MAX_MEMORY_SIZE)
		throw std::out_of_range("Wrong position in memory");

	if (number_of_operands < 0 || number_of_operands > 3)
		throw std::length_error("Invalid numbers of operands!");

	return this->memory.get(this->memory.get(position_in_memory)->get().at(number_of_operands))->get_value();
}

int Lm3::get_address_operand(int position_in_memory, int number_of_operands){
	if (position_in_memory < 0 || position_in_memory > MAX_MEMORY_SIZE)
		throw std::out_of_range("Wrong position in memory");

	if (number_of_operands < 0 || number_of_operands > 3)
		throw std::length_error("Invalid numbers of operands!");

	return this->memory.get(position_in_memory)->get().at(number_of_operands);
}