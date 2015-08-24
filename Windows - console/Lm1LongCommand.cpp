#include "Lm1LongCommand.h"

const int AMOUNT_OF_COMMANDS(22);
const int MAX_SIZE_OF_REGISTER(65535);
const int CMD_LIST[AMOUNT_OF_COMMANDS] = { 0, 16, 1, 2, 3, 19, 4, 20, 5, 6, 7,
	128, 129, 130, 131, 132, 133, 134, 147, 148, 149, 150 };

Lm1LongCommand::Lm1LongCommand(){
	command = std::vector<int>(4, 0);
}

Lm1LongCommand::Lm1LongCommand(int cmd, int r_1, int m_2, int a_2){
	this->command = { cmd, r_1, m_2, a_2 };

	if ((r_1 < 0 || r_1 > MAX_SIZE_OF_REGISTER) ||
		(m_2 < 0 || m_2 > MAX_SIZE_OF_REGISTER) ||
		(a_2 < 0 || a_2 > MAX_SIZE_OF_REGISTER))
		throw std::out_of_range("Memory bounds violation");

	for (int i = 0; i < AMOUNT_OF_COMMANDS; i++)
		if (cmd == CMD_LIST[i])
			return;

	throw std::invalid_argument("Invalid command!");
}

std::vector<int>& Lm1LongCommand::get(){
	return this->command;
}

int Lm1LongCommand::get_value()const{
	return this->command.front();
}