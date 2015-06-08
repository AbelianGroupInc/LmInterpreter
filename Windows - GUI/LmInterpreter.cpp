#include "LmInterpreter.h"

#include <queue>
#include <string>
#include <fstream>
#include <vcclr.h>
#include <ios>

#include "Converter.h"

LmInterpreter::LmInterpreter(Lm* machine) :machine(machine), program(){
	if (machine == nullptr)
		throw std::invalid_argument("Miss machine");
}

std::vector<std::string>  LmInterpreter::get_var_inf(){
	return this->machine->get_var_inf();
}

std::vector<std::string>  LmInterpreter::get_cmd_inf(){
	return this->machine->get_cmd_inf();
}

void LmInterpreter::input(int value){
	this->machine->input(value);
}

std::string LmInterpreter::current_command(){
	return this->machine->current_command();
}

void LmInterpreter::read_program(System::String^ file_name){
	std::ifstream input_file(sstring_to_wchar(file_name));
	
	if (!input_file.good())
		throw std::exception("Can't open file");

	this->parsing(&input_file);

	input_file.close();
}

void LmInterpreter::parsing(std::istream* input){
	this->machine->clear_memory();
	this->program.clear();

	std::string temp_str;

	while (getline(*input, temp_str)){
		if (temp_str == "#code"){
			this->parsing_code_string(input);
			break;
		}

		if (temp_str == "#init")
			this->parsing_init_string(input);
	}
}

void LmInterpreter::parsing_code_string(std::istream* input){
	std::string temp_str;
	std::vector<int> temp_arr;

	while (getline(*input, temp_str)){
		if (temp_str == "#end")
			return;

		std::string tmp;

		for (int i = 0; i <= (int)temp_str.size(); i++){
			if (i == temp_str.size() || temp_str[i] == ' ' || temp_str[i] == '\t' || temp_str[i] == ';'){
				if (tmp.size() > 0){
					temp_arr.push_back(Converter::to_dec(tmp));
					tmp.clear();
				}
			}
			else{
				tmp += (char)temp_str[i];
			}

			if (temp_str[i] == ';')
				break;
		}

		if (!temp_arr.empty())
			this->program.push_back(temp_arr);

		temp_arr.clear();
	}
}

void LmInterpreter::parsing_init_string(std::istream* input){
	std::string temp_str;

	while (getline(*input, temp_str)){
		int index(0);
		int address;

		if (temp_str.empty())
			continue;

		if (temp_str == "#end")
			return;

		address = this->init_address(temp_str, index);

		for (; index < (int)temp_str.size(); index++){
			if (temp_str[index] == ';')
				break;

			if (temp_str[index] == '\"')
				this->init_name(temp_str, address, index);
			else if (temp_str[index] != ' '  && temp_str[index] != '\t')
				this->init_value(temp_str, address, index);
		}
	}
}

int LmInterpreter::init_address(std::string &str, int &index){
	std::string address;

	for (; index < (int)str.size(); index++){
		if (index == str.size() || str[index] == ' ' || str[index] == '\t'){
			if (!address.empty())
				return Converter::to_dec(address);
		}
		else{
			address += str[index];
		}
	}

	throw std::exception("Wrong Address");
}

void LmInterpreter::init_name(std::string &str, int address, int &index){
	std::string name;

	while (true){
		if (++index == str.size())
			throw std::exception("Lost end of the name");

		if (str[index] == '\"'){
			this->machine->init_variable(address, name);
			return;
		}

		name += str[index];
	}
}

void LmInterpreter::init_value(std::string &str, int address, int &index){
	std::string value;

	for (; index <= (int)str.size(); index++){
		if (index == str.size() || str[index] == ' ' || str[index] == '\t' || str[index] == ';'){
			if (!value.empty()){
				this->machine->init_variable(address, Converter::to_dec(value));
				return;
			}
		}
		else{
			value += str[index];
		}
	}
}

void LmInterpreter::init_program(){
	this->machine->set_program(this->program);
}

void LmInterpreter::step(System::Windows::Forms::RichTextBox^ out){
	this->machine->do_one_step(out);
}

bool LmInterpreter::is_end(){
	return this->machine->is_end();
}

const wchar_t * LmInterpreter::sstring_to_wchar(System::String^ str){
	pin_ptr<const wchar_t> convertedValue = PtrToStringChars(str);
	return convertedValue;
}