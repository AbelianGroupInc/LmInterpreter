#pragma once
#ifndef LM_INTERPRETER_LM_1_SHORT_COMMAND_H
#define LM_INTERPRETER_LM_1_SHORT_COMMAND_H

#include "Lm1Command.h"

class Lm1ShortCommand : public Lm1Command{
public:
	Lm1ShortCommand();
	Lm1ShortCommand(int cmd, int r_1, int r_2);
	virtual std::vector<int>& get();
	virtual int get_value() const;
private:
	std::vector<int> command;
};

#endif