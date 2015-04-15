#pragma once
#ifndef LM_INTERPRETER_LM_INTERPRETER_H
#define LM_INTERPRETER_LM_INTERPRETER_H

#include <vector>
#include <memory>

#include "Lm.h"

class LmInterpreter{
public:
	LmInterpreter(Lm* machine);

	void read_program();
	void read_program(const char* file_name);
	
	void run_program();

	void save_programm(const char* file_name)const;
private:
	std::shared_ptr<Lm> machine;
	std::vector<std::vector<int> > program;

	void parsing_string(std::istream* input);
};

#endif