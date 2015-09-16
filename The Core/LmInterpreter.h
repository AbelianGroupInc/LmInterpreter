#pragma once
#ifndef LM_INTERPRETER_LM_INTERPRETER_H
#define LM_INTERPRETER_LM_INTERPRETER_H

#include <vector>

#include "Lm.h"

class LmInterpreter{
public:
	LmInterpreter(Lm* machine);
	~LmInterpreter();

	void read_program();
	void read_program(const char* file_name);
	
	void run_program();

	void save_programm(const char* file_name)const;
private:
	Lm* machine;
	std::vector<std::vector<int> > program;
	std::ostream *temp_file;

	void parsing(std::istream* input);
	//Parsing lm's input program
	void parsing_code_string(std::istream* input);
	//Parsing code segment of program
	void parsing_init_string(std::istream* input);
	//Parsing initialization segment of program

	int init_address(std::string &str, int &index);
	void init_name(std::string &str, int address, int &index);
	void init_value(std::string &str, int address, int &index);
};

#endif