#pragma once
#ifndef LM_INTERPRETER_LM_H
#define LM_INTERPRETER_LM_H

#include <vector>

class Lm{
public:
	virtual void execute_the_program() = 0;
	virtual void set_program(const std::vector<std::vector<int> > &program) = 0;
	virtual std::vector<std::vector<int> > get_program()const = 0;
};

#endif