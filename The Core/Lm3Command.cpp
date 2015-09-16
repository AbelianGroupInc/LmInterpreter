#include "Lm3Command.h"

const int AMOUNT_OF_COMMANDS(23);
const int MAX_SIZE_OF_REGISTER(65535);
const int CMD_LIST[AMOUNT_OF_COMMANDS] = { 153, 0, 1, 2, 3, 4, 6, 7, 19, 20, 22, 23,
	128, 129, 130, 131, 132, 133, 134, 147, 148, 149, 150};


Lm3Command::Lm3Command(){
	command = std::vector<int>(4, 0);
}

Lm3Command::Lm3Command(int cmd, int r_1, int r_2, int r_3){
	this->command = {cmd,r_1,r_2,r_3};

	if ((r_1 < 0 || r_1 > MAX_SIZE_OF_REGISTER) || 
		(r_2 < 0 || r_2 > MAX_SIZE_OF_REGISTER) ||
		(r_3 < 0 || r_3 > MAX_SIZE_OF_REGISTER))
		throw std::out_of_range("Memory bounds violation");

	for (int i = 0; i < AMOUNT_OF_COMMANDS; i++)
		if (cmd == CMD_LIST[i])
			return;

	throw std::invalid_argument("Invalid command!");
}

std::vector<int>& Lm3Command::get(){
	return this->command;
}

int Lm3Command::get_value()const{
	return this->command.front();
}
