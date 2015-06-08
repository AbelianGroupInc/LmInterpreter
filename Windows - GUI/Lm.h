#pragma once
#ifndef LM_INTERPRETER_LM_H
#define LM_INTERPRETER_LM_H

#include <vector>

class Lm{
public:
	virtual void do_one_step(System::Windows::Forms::RichTextBox^ out) = 0;
	virtual bool is_end() = 0;
	virtual void input(int value) = 0;
	virtual std::string current_command() = 0;
	virtual void set_program(const std::vector<std::vector<int> > &program) = 0;
	virtual std::vector<std::string> get_var_inf() = 0;
	virtual std::vector<std::string> get_cmd_inf() = 0;
	virtual std::vector<std::vector<int> > get_program()const = 0;
	virtual void init_variable(int position, std::string name) = 0;
	virtual void init_variable(int position, int value) = 0;
	virtual void init_variable(int position, std::string name, int value) = 0;
	virtual void clear_memory() = 0;
};

#endif