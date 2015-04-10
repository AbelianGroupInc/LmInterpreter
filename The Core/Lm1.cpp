#include "Lm1.h"
#include "Lm1LongCommand.h"
#include "Lm1ShortCommand.h"
#include "Variable.h"
#include "LmCommands.h"
#include "Converter.h"

const int MAX_CPU_MEMORY_SIZE = 16;
const int MAX_RAM_MEMORY_SIZE = 65535;
const int
	CMD_RM_INPUT                     = 6,
	CMD_RM_OUTPUT                    = 7,
	CMD_RM_UNSIGNED_INPUT            = 22,
	CMD_RM_UNSIGNED_OUTPUT           = 23,
	CMD_RM_ADD                       = 1,
	CMD_RM_SUBSRACT                  = 2,
	CMD_RM_MULTIPLICATION            = 3,
	CMD_RM_DIVISION                  = 4,
	CMD_RM_UNSIGNED_MULTIPLICATION   = 19,
	CMD_RM_UNSIGNED_DIVISION         = 20,
	CMD_RM_ASSIGMENT_1               = 0,
	CMD_RM_ASSIGMENT_2               = 16,
	CMD_RM_LESS                      = 131,
	CMD_RM_GREATER                   = 133,
	CMD_RM_LESS_OR_EQUAL             = 134,
	CMD_RM_GREATER_OR_EQUAL          = 132,
	CMD_RM_EQUAL                     = 129,
	CMD_RM_UNSIGNED_LESS             = 147,
	CMD_RM_UNSIGNED_GREATER          = 149,
	CMD_RM_UNSIGNED_LESS_OR_EQUAL    = 148,
	CMD_RM_UNSIGNED_GREATER_OR_EQUAL = 150;
const int
	CMD_RR_STOP                      = 153,
	CMD_RR_ASSIGMENT                 = 32,
	CMD_RR_ADD                       = 33,
	CMD_RR_SUBSTRACT                 = 34,
	CMD_RR_MULTIPLICATION            = 35,
	CMD_RR_UNSIGNED_MULTIPLICATION   = 51,
	CMD_RR_DIVISION                  = 36,
	CMD_RR_UNSIGNED_DIVISION         = 52,
	CMD_RR_EQUAL                     = 37;

Lm1::Lm1() :current_address(0), ram_memory(){
		for (int i = 0; i < MAX_CPU_MEMORY_SIZE; i++)
			this->cpu_memory[i] = nullptr;
}

void Lm1::execute_the_program(){
	while (true){
		int command = this->ram_memory.get(this->current_address)->get_value();
		switch (command){
		case CMD_RM_INPUT:
			this->perform_input_operation(LmCommands::input);
			break;
		case CMD_RM_OUTPUT:
			this->perform_output_operation(LmCommands::output);
			break;
		case CMD_RM_UNSIGNED_INPUT:
			this->perform_input_operation(LmCommands::unsigned_input);
			break;
		case CMD_RM_UNSIGNED_OUTPUT:
			this->perform_output_operation(LmCommands::unsigned_output);
			break;
		case CMD_RM_ADD:
			this->perform_arithmetic_operation(LmCommands::add,command);
			break;
		case CMD_RR_ADD:
			this->perform_arithmetic_operation(LmCommands::add,command);
			break;
		case CMD_RM_SUBSRACT:
			this->perform_arithmetic_operation(LmCommands::subsract,command);
			break;
		case CMD_RR_SUBSTRACT:
			this->perform_arithmetic_operation(LmCommands::subsract,command);
			break;
		case CMD_RM_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::multiplication,command);
			break;
		case CMD_RR_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::multiplication,command);
			break;
		case CMD_RM_DIVISION:
			this->perform_arithmetic_operation(LmCommands::division,command);
			break;
		case CMD_RR_DIVISION:
			this->perform_arithmetic_operation(LmCommands::division,command);
			break;
		case CMD_RM_UNSIGNED_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::unsigned_multiplication,command);
			break;
		case CMD_RR_UNSIGNED_MULTIPLICATION:
			this->perform_arithmetic_operation(LmCommands::unsigned_multiplication,command);
			break;
		case CMD_RM_UNSIGNED_DIVISION:
			this->perform_arithmetic_operation(LmCommands::unsigned_division,command);
			break;
		case CMD_RR_UNSIGNED_DIVISION:
			this->perform_arithmetic_operation(LmCommands::unsigned_division,command);
			break;
		case CMD_RM_ASSIGMENT_1:
			this->perform_assignment_operation(command);
			break;
		case CMD_RM_ASSIGMENT_2:
			this->perform_assignment_operation(command);
			break;
		case CMD_RR_ASSIGMENT:
			this->perform_assignment_operation(command);
			break;
		case CMD_RM_LESS:
			this->perform_comparison_operation(LmCommands::less);
			break;
		case CMD_RM_GREATER:
			this->perform_comparison_operation(LmCommands::greater);
			break;
		case CMD_RM_LESS_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::less_or_equal);
			break;
		case CMD_RM_GREATER_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::greater_or_equal);
			break;
		case CMD_RM_EQUAL:
			this->perform_comparison_operation(LmCommands::equal);
			break;
		case CMD_RR_EQUAL:
			this->perform_comparison_operation(LmCommands::equal, command);
			break;
		case CMD_RM_UNSIGNED_LESS:
			this->perform_comparison_operation(LmCommands::unsigned_less);
			break;
		case CMD_RM_UNSIGNED_GREATER:
			this->perform_comparison_operation(LmCommands::unsigned_greater);
			break;
		case CMD_RM_UNSIGNED_LESS_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::unsigned_less_or_equal);
			break;
		case CMD_RM_UNSIGNED_GREATER_OR_EQUAL:
			this->perform_comparison_operation(LmCommands::unsigned_greater_or_equal);
			break;
		case CMD_RR_STOP:
			return;
			break;
		default:
			std::exception();
			break;
		}
	}
}

bool Lm1::is_command_long(int command){
	if (command == CMD_RM_INPUT ||
		command == CMD_RM_OUTPUT ||
		command == CMD_RM_UNSIGNED_INPUT ||
		command == CMD_RM_UNSIGNED_OUTPUT ||
		command == CMD_RM_ADD ||
		command == CMD_RM_SUBSRACT ||
		command == CMD_RM_MULTIPLICATION ||
		command == CMD_RM_DIVISION ||
		command == CMD_RM_UNSIGNED_MULTIPLICATION ||
		command == CMD_RM_UNSIGNED_DIVISION ||
		command == CMD_RM_ASSIGMENT_1 ||
		command == CMD_RM_ASSIGMENT_2 ||
		command == CMD_RM_LESS ||
		command == CMD_RM_GREATER ||
		command == CMD_RM_LESS_OR_EQUAL ||
		command == CMD_RM_GREATER_OR_EQUAL ||
		command == CMD_RM_EQUAL ||
		command == CMD_RM_UNSIGNED_LESS ||
		command == CMD_RM_UNSIGNED_GREATER ||
		command == CMD_RM_UNSIGNED_LESS_OR_EQUAL ||
		command == CMD_RM_UNSIGNED_GREATER_OR_EQUAL)
		return true;
	else
		return false;
}

MemoryItem* Lm1::get_operand(const int operandNumb, int command){
	int operand_adress, operand_value;
	MemoryItem* operand;
	if (operandNumb == 1){
		operand_adress = this->ram_memory.get(this->current_address)->get().at(1);
		operand_value = this->cpu_memory[operand_adress]->get_value();

	}
	else{
		if (is_command_long(command)){
			int register_a2 = this->ram_memory.get(this->current_address)->get().at(3);
			int register_m2 = this->cpu_memory[
				this->ram_memory.get(this->current_address)->get().at(2)]->get_value();
				operand_adress = register_a2 + (register_m2 * 2);
				operand_value = this->ram_memory.get(operand_adress)->get_value();
		}
		else{
			operand_adress = this->ram_memory.get(this->current_address)->get().at(2);
			operand_value = this->cpu_memory[operand_adress]->get_value();
		}
	}
	operand = new Variable(operand_value);
	return operand;
}

MemoryItem* Lm1::get_operand(const int operandNumb){
	int operand_adress, operand_value;
	MemoryItem* operand;
	if (operandNumb == 1){
		operand_adress = this->ram_memory.get(this->current_address)->get().at(1);
		operand_value = this->cpu_memory[operand_adress]->get_value();

	}
	else{
		int register_a2 = this->ram_memory.get(this->current_address)->get().at(3);
		int register_m2 = this->cpu_memory[
			this->ram_memory.get(this->current_address)->get().at(2)]->get_value();
			operand_adress = register_a2 + (register_m2 * 2);
			operand_value = this->ram_memory.get(operand_adress)->get_value();
	}
	operand = new Variable(operand_value);
	return operand;
}

void Lm1::set_program(const std::vector<std::vector<int> > &program){
	if (program.size() == 0)
		return;

	if (program.front().front() >= 0 && program.front().front() <= MAX_RAM_MEMORY_SIZE)
		this->current_address = program.front().front();

	for (size_t i = 0; i < program.size(); i++){
		int cur_command = program[i].front();
		if (cur_command >= 0){							//possible mistake
			if (is_command_long(cur_command))
				this->ram_memory.set(cur_command, new Lm1LongCommand(program[i][1], program[i][2], program[i][3], program[i][4]));
			else
				this->ram_memory.set(cur_command, new Lm1ShortCommand(program[i][1], program[i][2], program[i][3]));
		}
		else
			throw std::exception();
	}
}

std::vector<std::vector<int> > Lm1::get_program()const{
	return std::vector<std::vector<int> >();
}

void Lm1::perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*), int command){
	MemoryItem* first_operand = get_operand(1, command);
	MemoryItem* second_operand = get_operand(2, command);

	this->cpu_memory[this->ram_memory.get(this->current_address)->get().at(1)] =
		func(first_operand, second_operand);
	this->current_address++;
}

void Lm1::perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*)){
	MemoryItem* first_operand = get_operand(1);
	MemoryItem* second_operand = get_operand(2);

	this->current_address = func(first_operand, second_operand) ? this->ram_memory.get(this->current_address)->get().at(3) : this->current_address + 1;
}

void Lm1::perform_comparison_operation(bool(*func)(const MemoryItem*, const MemoryItem*), int command){
	MemoryItem* first_operand = get_operand(1,command);
	MemoryItem* second_operand = get_operand(2,command);

	this->current_address = func(first_operand, second_operand) ? this->ram_memory.get(this->current_address)->get().at(3) : this->current_address + 1;
}

void Lm1::perform_input_operation(void(*func)(MemoryItem*&, const std::string)){
	MemoryItem* var = new Variable();

	func(var, Converter::to_hex(this->cpu_memory[this->current_address]->get().at(1), 4));
	this->ram_memory.set(this->ram_memory.get(this->current_address)->get().at(1), var);

	this->current_address++;
}

void Lm1::perform_output_operation(void(*func)(const MemoryItem*, const std::string)){
	MemoryItem* var = get_operand(1);

	func(var, Converter::to_hex(this->cpu_memory[this->current_address]->get().at(1), 4));

	this->current_address++;
}

void Lm1::perform_assignment_operation(int command){
	int in_position;
	int from_position;
	if (CMD_RM_ASSIGMENT_2){
		in_position = this->ram_memory.get(this->current_address)->get().at(3) +
			this->cpu_memory[this->ram_memory.get(this->current_address)->get().at(2)]->get_value();
		from_position = this->cpu_memory[this->current_address]->get().at(1);
	}
	else if (CMD_RM_ASSIGMENT_1){
		in_position = this->cpu_memory[this->current_address]->get().at(1);
		from_position = this->ram_memory.get(this->current_address)->get().at(3) +
			this->cpu_memory[this->ram_memory.get(this->current_address)->get().at(2)]->get_value();
	}
	else{
		in_position = this->cpu_memory[this->current_address]->get().at(1);
		from_position = this->cpu_memory[this->current_address]->get().at(2);
	}
	this->current_address++;
}