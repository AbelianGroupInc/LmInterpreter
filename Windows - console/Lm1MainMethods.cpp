//The file with implemention of the main methods of processing
//and executing Lm1 program

#include "Lm1.h"
#include "LmCommands.h"
#include "Lm1ShortCommand.h"
#include "Lm1LongCommand.h"
#include "InterpreterException.h"

const int
	MAX_CPU_MEMORY_SIZE = 15,
	MAX_RAM_MEMORY_SIZE = 65535;

const int
	CMD_RM_INPUT = 6,
	CMD_RM_OUTPUT = 7,
	CMD_RM_UNSIGNED_INPUT = 22,
	CMD_RM_UNSIGNED_OUTPUT = 23,
	CMD_RM_ADD = 1,
	CMD_RM_SUBSRACT = 2,
	CMD_RM_MULTIPLICATION = 3,
	CMD_RM_DIVISION = 4,
	CMD_RM_UNSIGNED_MULTIPLICATION = 19,
	CMD_RM_UNSIGNED_DIVISION = 20,
	CMD_RM_ASSIGMENT_1 = 0,
	CMD_RM_ASSIGMENT_2 = 16,
	CMD_GO_TO = 128,
	CMD_LESS = 131,
	CMD_GREATER = 133,
	CMD_LESS_OR_EQUAL = 134,
	CMD_GREATER_OR_EQUAL = 132,
	CMD_EQUAL = 129,
	CMD_NOT_EQUAL = 130,
	CMD_UNSIGNED_LESS = 147,
	CMD_UNSIGNED_GREATER = 149,
	CMD_UNSIGNED_LESS_OR_EQUAL = 148,
	CMD_UNSIGNED_GREATER_OR_EQUAL = 150,
	CMD_RM_COMPARISON = 05,
	COMMAND_IS_LONG = 100;
const int
	CMD_RR_STOP = 153,
	CMD_RR_ASSIGMENT = 32,
	CMD_RR_ADD = 33,
	CMD_RR_SUBSTRACT = 34,
	CMD_RR_MULTIPLICATION = 35,
	CMD_RR_UNSIGNED_MULTIPLICATION = 51,
	CMD_RR_DIVISION = 36,
	CMD_RR_UNSIGNED_DIVISION = 52,
	CMD_RR_COMPARISON = 37,
	COMMAND_IS_NOT_LONG = 200;

Lm1::Lm1() :current_address(0), ram_memory(){
	for (int i = 0; i < MAX_CPU_MEMORY_SIZE; i++)
		this->cpu_memory[i] = INT_MAX;
}

int Lm1::perfom_commands(){
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
		this->perform_arithmetic_operation(LmCommands::add, command);
		break;
	case CMD_RR_ADD:
		this->perform_arithmetic_operation(LmCommands::add, command);
		break;
	case CMD_RM_SUBSRACT:
		this->perform_arithmetic_operation(LmCommands::subsract, command);
		break;
	case CMD_RR_SUBSTRACT:
		this->perform_arithmetic_operation(LmCommands::subsract, command);
		break;
	case CMD_RM_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::multiplication, command);
		break;
	case CMD_RR_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::multiplication, command);
		break;
	case CMD_RM_DIVISION:
		this->perform_division_operation(LmCommands::division, LmCommands::module, command);
		break;
	case CMD_RR_DIVISION:
		this->perform_division_operation(LmCommands::division, LmCommands::module, command);
		break;
	case CMD_RM_UNSIGNED_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::unsigned_multiplication, command);
		break;
	case CMD_RR_UNSIGNED_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::unsigned_multiplication, command);
		break;
	case CMD_RM_UNSIGNED_DIVISION:
		this->perform_division_operation(LmCommands::unsigned_division, LmCommands::unsigned_module, command);
		break;
	case CMD_RR_UNSIGNED_DIVISION:
		this->perform_division_operation(LmCommands::unsigned_division, LmCommands::unsigned_module, command);
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
	
	case CMD_RM_COMPARISON:
		this->perform_comparison_operation(command);
		break;
	case CMD_RR_COMPARISON:
		this->perform_comparison_operation(command);
		break;
	case CMD_GO_TO:
		this->perform_comparison_operation(command);
		break;

	case CMD_RR_STOP:
		return CMD_RR_STOP;
		break;
	default:
		std::exception("Incorrect command");
		break;
	}
	
	return command;
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
		command == CMD_LESS ||
		command == CMD_GREATER ||
		command == CMD_LESS_OR_EQUAL ||
		command == CMD_GREATER_OR_EQUAL ||
		command == CMD_EQUAL ||
		command == CMD_UNSIGNED_LESS ||
		command == CMD_UNSIGNED_GREATER ||
		command == CMD_UNSIGNED_LESS_OR_EQUAL ||
		command == CMD_UNSIGNED_GREATER_OR_EQUAL ||
		command == COMMAND_IS_LONG)
		return true;
	else
		return false;
}

void Lm1::set_program(const std::vector<std::vector<int> > &program){
	bool end = false;
	if (program.size() == 0)
		throw std::exception("The program is empty");

	if (program.front().front() >= 0 && program.front().front() <= MAX_RAM_MEMORY_SIZE)
		this->current_address = program.front().front();

	for (size_t i = 0; i < program.size(); i++){
		int cur_command_adress = program[i][0];
		int cur_command_numb = program[i][1];
		if (cur_command_adress >= 0 && (cur_command_adress) <= MAX_RAM_MEMORY_SIZE &&
			ram_memory.is_memory_cell_empty(cur_command_adress)){
			if (this->is_command_long(cur_command_numb)){
				if ((cur_command_adress + 1) > MAX_RAM_MEMORY_SIZE)
					throw std::out_of_range("Memory bounds violation");
				if(!ram_memory.is_memory_cell_empty(cur_command_adress + 1))
					throw std::out_of_range("Writing in occupied cell");
				try{
					Lm1LongCommand* firstCommandB = new Lm1LongCommand(program[i][1], program[i][2], program[i][3], program[i][4]);
					Lm1LongCommand* secondCommandB = new Lm1LongCommand(program[i][1], program[i][2], program[i][3], program[i][4]);
					this->ram_memory.set(cur_command_adress, firstCommandB);
					this->ram_memory.set(cur_command_adress + 1, secondCommandB);
				}
				catch (std::exception& exp){
					char* temp = new char[strlen(exp.what()) + 1];
					strcpy(temp, exp.what());
					throw InterpreterException(temp, i + 1);
				}
			}
			else{
				this->ram_memory.set(cur_command_adress, new Lm1ShortCommand(program[i][1], program[i][2], program[i][3]));

				if (this->ram_memory.get(cur_command_adress)->get_value() == CMD_RR_STOP)
					end = true;
			}
		}
		else
			throw std::out_of_range("Memory bounds violation");
	}

	if (!end)
		throw std::exception("Lost end of program");
}

std::vector<std::vector<int> > Lm1::get_program()const{
	return std::vector<std::vector<int> >();
}
