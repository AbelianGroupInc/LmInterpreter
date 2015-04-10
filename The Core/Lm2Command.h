#pragma once
#ifndef LM_INTERPRETER_LM_2_COMMAND_H
#define LM_INTERPRETER_LM_2_COMMAND_H

#include <vector>

#include "Command.h"

class Lm2Command : public Command{
public:
	Lm2Command();
	Lm2Command(int cmd, int r_1, int r_2);
	virtual std::vector<int>& get()override final;
	virtual int get_value()const override final;
private:
	std::vector<int> command;
};
#endif