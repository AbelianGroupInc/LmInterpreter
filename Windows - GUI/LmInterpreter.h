#pragma once
#ifndef LM_INTERPRETER_LM_INTERPRETER_H
#define LM_INTERPRETER_LM_INTERPRETER_H

#include <vector>

#include "Lm.h"

class LmInterpreter{
public:
	LmInterpreter(Lm* machine);
	~LmInterpreter();

	void read_program(System::String^ file_name);
	void LmInterpreter::input(int value);
	std::string current_command();

	std::vector<std::string> get_var_inf();
	std::vector<std::string> get_cmd_inf();

	void init_program();
	void step(System::Windows::Forms::RichTextBox^ out);

	bool is_end();
private:
	Lm* machine;
	std::vector<std::vector<int> > program;

	void parsing(std::istream* input);
	void parsing_code_string(std::istream* input);
	void parsing_init_string(std::istream* input);

	int init_address(std::string &str, int &index);
	void init_name(std::string &str, int address, int &index);
	void init_value(std::string &str, int address, int &index);
	const wchar_t * sstring_to_wchar(System::String^ str);
};

#endif