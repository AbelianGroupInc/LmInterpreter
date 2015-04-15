#include "LmInterpreter.h"

#include <queue>
#include <string>
#include <fstream>
#include <ios>

#include "Converter.h"

LmInterpreter::LmInterpreter(Lm* machine) :machine(machine), program(){
	if (machine == nullptr)
		throw std::exception();
}

void LmInterpreter::read_program(){
	this->parsing_string(&std::cin);
}

void LmInterpreter::read_program(const char* file_name){
	std::ifstream input_file(file_name);
	
	if (!input_file.good())
		throw std::exception("Error: Can not open file. File does not exist.");

	this->parsing_string(&input_file);

	input_file.close();
}

void LmInterpreter::parsing_string(std::istream* input){
	std::string temp_str;
	std::vector<int> temp_arr;

	while (getline(*input, temp_str)){
		if (temp_str == "#end")
			return;

		std::string tmp;

		for (int i = 0; i <= (int)temp_str.size(); i++){
			if (i == temp_str.size() || temp_str[i] == ' '){
				if (tmp.size() > 0){
					temp_arr.push_back(Converter::to_dec(tmp));
					tmp.clear();
				}
			}
			else{
				tmp += (char)temp_str[i];
			}
		}

		if (!temp_arr.empty())
			this->program.push_back(temp_arr);

		temp_arr.clear();
	}
}

void LmInterpreter::run_program(){
	this->machine->set_program(this->program);
	this->machine->execute_the_program();
}

void LmInterpreter::save_programm(const char* file_name)const{
	std::string temp(file_name);

	if (temp.find(".txt") == -1)
		temp += ".txt";

	std::ofstream output_file(temp.c_str());

	for (size_t i = 0; i < this->program.size(); i++){
		for (size_t k = 0; k < this->program[i].size(); k++){
			if (k == 1)
				output_file << Converter::to_hex(this->program[i][k], 2) << ' ';
			else
				output_file << Converter::to_hex(this->program[i][k], 4) << ' ';
		}
		std::endl(output_file);
	}

	output_file.close();
}