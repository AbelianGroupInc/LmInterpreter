#pragma once
#ifndef LM_INTERPRETER_LM_1_COMMAND_H
#define LM_INTERPRETER_LM_1_COMMAND_H

#include "Command.h"

class Lm1Command :public Command{
public:
	virtual std::vector<int>& get() = 0;
	virtual int get_value() const = 0;
};

#endif