#pragma once
#ifndef LM_INTERPRETER_LM_1_LONG_COMMAND_H
#define LM_INTERPRETER_LM_1_LONG_COMMAND_H

#include "Lm1Command.h"

class Lm1LongCommand : public Lm1Command{
public:
	Lm1LongCommand();
	Lm1LongCommand(int,int,int,int);
	virtual std::vector<int>& get();
	virtual int get_value() const;
private:
	std::vector<int> command;
};

#endif