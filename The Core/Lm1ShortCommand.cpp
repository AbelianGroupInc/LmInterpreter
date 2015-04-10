#include "Lm1ShortCommand.h"

const int AMOUNT_OF_COMMANDS(9);
const int MAX_SIZE_OF_REGISTER(65535);
const int CMD_LIST[AMOUNT_OF_COMMANDS] = { 153, 32, 33, 34, 35, 51, 36, 52, 37 };

Lm1ShortCommand::Lm1ShortCommand(){
	command = std::vector<int>(4, 0);
}

Lm1ShortCommand::Lm1ShortCommand(int cmd, int r_1, int r_2){
	this->command = { cmd, r_1, r_2 };

	if ((r_1 < 0 || r_1 > MAX_SIZE_OF_REGISTER) ||
		(r_2 < 0 || r_2 > MAX_SIZE_OF_REGISTER))
		throw std::exception();

	for (int i = 0; i < AMOUNT_OF_COMMANDS; i++)
		if (cmd == CMD_LIST[i])
			return;

	throw std::exception();
}

std::vector<int>& Lm1ShortCommand::get(){
	return this->command;
}

int Lm1ShortCommand::get_value()const{
	return this->command.front();
}