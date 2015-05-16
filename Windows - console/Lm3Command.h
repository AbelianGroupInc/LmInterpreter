#pragma once
#ifndef LM_INTERPRETER_LM_3_COMMAND_H
#define LM_INTERPRETER_LM_3_COMMAND_H

#include <vector>

#include "Command.h"

class Lm3Command : public Command{
public:
	Lm3Command();
	Lm3Command(int cmd, int r_1, int r_2, int r_3);
	virtual std::vector<int>& get() _NOEXCEPT override final;
	virtual int get_value()const _NOEXCEPT override final;
private:
	std::vector<int> command;
};

#endif