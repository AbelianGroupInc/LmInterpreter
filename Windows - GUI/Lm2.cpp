#include <sstream>

#include "Lm2.h"
#include "Lm2Command.h"
#include "Variable.h"
#include "LmCommands.h"
#include "InterpreterException.h"
#include "Converter.h"

const int MAX_MEMORY_SIZE = 65535;
const int
	CMD_COMPARE                   = 5,
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
	CMD_UNSIGNED_LESS_OR_EQUAL    = 150,
	CMD_UNSIGNED_GREATER_OR_EQUAL = 148,
	CMD_STOP                      = 153;


std::vector<std::string> Lm2::get_var_inf(){
	return this->memory.get_var_inf();
}

std::vector<std::string> Lm2::get_cmd_inf(){
	return this->memory.get_cmd_inf();
}

bool Lm2::is_end(){
	return this->end_flag;
}

void Lm2::input(int value){
	if (this->memory.get(this->current_address)->get_value() == CMD_INPUT)
		this->perform_input_operation(value);
}

void Lm2::do_one_step(System::Windows::Forms::RichTextBox^ out){
	if (this->end_flag)
		throw std::out_of_range("Program end");

	if (this->input_flag)
		throw std::exception("The value is not received, enter please");

	switch (this->memory.get(this->current_address)->get_value()){
	case CMD_COMPARE:
		this->perfom_flag_determination();
		break;
	case CMD_INPUT:
		this->input_flag = true;
		break;
	case CMD_OUTPUT:
		this->perform_output_operation(LmCommands::output, out);
		break;
	case CMD_UNSIGNED_INPUT:
		this->input_flag = true;
		break;
	case CMD_UNSIGNED_OUTPUT:
		this->perform_output_operation(LmCommands::unsigned_output, out);
		break;
	case CMD_ADD:
		this->perform_arithmetic_operation(LmCommands::add, CMD_ADD);
		break;
	case CMD_SUBSRACT:
		this->perform_arithmetic_operation(LmCommands::subsract, CMD_SUBSRACT);
		break;
	case CMD_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::multiplication, CMD_MULTIPLICATION);
		break;
	case CMD_DIVISION:
		this->perform_arithmetic_operation(LmCommands::division, CMD_DIVISION);
		break;
	case CMD_UNSIGNED_MULTIPLICATION:
		this->perform_arithmetic_operation(LmCommands::unsigned_multiplication, CMD_UNSIGNED_MULTIPLICATION);
		break;
	case CMD_UNSIGNED_DIVISION:
		this->perform_arithmetic_operation(LmCommands::unsigned_division, CMD_UNSIGNED_DIVISION);
		break;
	case CMD_ASSIGMENT:
		perform_assignment_operation();
		break;
	case CMD_GOTO:
		this->perform_goto();
		break;
	case CMD_LESS:
		this->perform_comparison_operation(flags::LESS);
		break;
	case CMD_GREATER:
		this->perform_comparison_operation(flags::GREATER);
		break;
	case CMD_LESS_OR_EQUAL:
		this->perform_comparison_operation(flags::LESS_OR_EQUAL);
		break;
	case CMD_GREATER_OR_EQUAL:
		this->perform_comparison_operation(flags::GREATER_OR_EQUAL);
		break;
	case CMD_EQUAL:
		this->perform_comparison_operation(flags::EQUAL);
		break;
	case CMD_NOT_EQUAL:
		this->perform_comparison_operation(flags::N_EQUAL);
		break;
	case CMD_UNSIGNED_LESS:
		this->perform_comparison_operation(flags::INS_LESS);
		break;
	case CMD_UNSIGNED_GREATER:
		this->perform_comparison_operation(flags::INS_GREATER);
		break;
	case CMD_UNSIGNED_LESS_OR_EQUAL:
		this->perform_comparison_operation(flags::INS_LESS_OR_EQUAL);
		break;
	case CMD_UNSIGNED_GREATER_OR_EQUAL:
		this->perform_comparison_operation(flags::INS_GREATER_OR_EQUAL);
		break;
	case CMD_STOP:
		this->end_flag = true;
		break;
	default:
		std::exception();
		break;
	}
}


	void Lm2::clear_memory(){
		this->memory.clear();
	}

void Lm2::init_variable(int position, std::string name){
	this->memory.set_name(position, name);
}

void Lm2::init_variable(int position, int value){
	this->memory.set(position, new Variable(value));
}

void Lm2::init_variable(int position, std::string name, int value){
	this->init_variable(position, name);
	this->init_variable(position, value);
}

void Lm2::set_program(const std::vector<std::vector<int> > &program){
	bool end = false;
	if (program.size() == 0)
		throw std::exception("Lost end of program");

	if (program.front().front() >= 0 && program.front().front() <= MAX_MEMORY_SIZE)
		this->current_address=program.front().front();

	for (size_t i = 0; i < program.size(); i++){
		if (program[i].front() >= 0 && program[i].front() <= MAX_MEMORY_SIZE){
			try{
				this->memory.set(program[i].front(), new Lm2Command(program[i][1], program[i][2], program[i][3]));
				
					if (this->memory.get(program[i].front())->get_value() == CMD_STOP)
					 end = true;
				
			}
			catch (std::exception& exp){
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

std::vector<std::vector<int> > Lm2::get_program()const{
	return std::vector<std::vector<int> >();
}

void Lm2::perform_arithmetic_operation(MemoryItem* (*func)(const MemoryItem*, const MemoryItem*),int type){
	MemoryItem* var_1 = new Variable(this->get_value_operand(this->current_address,1));
	MemoryItem* var_2 = new Variable(this->get_value_operand(this->current_address,2));
	this->memory.set(this->get_address_operand(this->current_address, 1), func(var_1, var_2));
	
	if (type == CMD_DIVISION || type == CMD_UNSIGNED_DIVISION)
		this->memory.set(this->get_address_operand(this->current_address, 1) + 1, LmCommands::module(var_1, var_2));
	
	this->current_address++;
}

void Lm2::perform_goto(){
	this->current_address = this->get_address_operand(this->current_address, 1);
}

void Lm2::perfom_flag_determination(){
	MemoryItem* var_1 = new Variable(this->get_value_operand(this->current_address, 1));
	MemoryItem* var_2 = new Variable(this->get_value_operand(this->current_address, 2));

	cmp_op[flags::EQUAL] = LmCommands::equal(var_1, var_2);
	cmp_op[flags::N_EQUAL] = LmCommands::not_equal(var_1, var_2);
	cmp_op[flags::LESS] = LmCommands::less(var_1, var_2);
	cmp_op[flags::GREATER] = LmCommands::greater(var_1, var_2);
	cmp_op[flags::LESS_OR_EQUAL] = LmCommands::less_or_equal(var_1, var_2);
	cmp_op[flags::GREATER_OR_EQUAL] = LmCommands::greater_or_equal(var_1, var_2);
	cmp_op[flags::INS_LESS] = LmCommands::unsigned_less(var_1, var_2);
	cmp_op[flags::INS_GREATER] = LmCommands::unsigned_greater(var_1, var_2);
	cmp_op[flags::INS_LESS_OR_EQUAL] = LmCommands::unsigned_less_or_equal(var_1, var_2);
	cmp_op[flags::INS_GREATER_OR_EQUAL] = LmCommands::unsigned_greater_or_equal(var_1, var_2);

	this->current_address++;
}
void Lm2::perform_comparison_operation(flags flag){
	this->current_address = cmp_op[flag] ? this->get_address_operand(this->current_address, 1) : this->current_address + 1;
}

void Lm2::perform_input_operation(int value){
	MemoryItem* var = new Variable(value);

	this->memory.set(this->get_address_operand(this->current_address, 1), var);

	this->input_flag = false;
	this->current_address++;
}

std::string Lm2::current_command(){
	std::ostringstream out;
	std::vector<int> temp = this->memory.get(this->current_address)->get();

	out << Converter::to_hex(this->current_address) << ' ';

	for (auto &i : temp){
		std::string x = Converter::to_hex(i);
		out << (x.empty() ? "0" : x) << ' ';
	}

	return out.str();
}
void Lm2::perform_output_operation(void(*func)(System::Windows::Forms::RichTextBox^ out, const MemoryItem*, const std::string), System::Windows::Forms::RichTextBox^ out){
	MemoryItem* var = new Variable(this->get_value_operand(this->current_address, 1));

	func(out, var, this->memory.get_name(this->get_address_operand(this->current_address, 1)));

	this->current_address++;
}

void Lm2::perform_assignment_operation(){
	int in_position = this->memory.get(this->current_address)->get().at(1);
	int value = this->get_value_operand(this->current_address, 2);

	MemoryItem* var = new Variable(value);
	
	this->memory.set(in_position, var);
	this->current_address++;
}

int Lm2::get_value_operand(int position_in_memory, int number_of_operands){
	if (position_in_memory < 0 || position_in_memory > MAX_MEMORY_SIZE)
		throw std::out_of_range("Wrong position in memory");

	if (number_of_operands < 0 || number_of_operands > 2)
		throw std::length_error("Invalid numbers of operands!");

	return this->memory.get(this->memory.get(position_in_memory)->get().at(number_of_operands))->get_value();
}

int Lm2::get_address_operand(int position_in_memory, int number_of_operands){
	if (position_in_memory < 0 || position_in_memory > MAX_MEMORY_SIZE)
		throw std::out_of_range("Wrong position in memory");

	if (number_of_operands < 0 || number_of_operands > 2)
		throw std::length_error("Invalid numbers of operands!");

	return this->memory.get(position_in_memory)->get().at(number_of_operands);
}