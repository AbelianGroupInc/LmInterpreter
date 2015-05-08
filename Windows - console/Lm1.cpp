#include "Lm1.h"

#define STOP_COMMAND 153

void Lm1::execute_the_program(){
	while (this->perfom_commands() != STOP_COMMAND){
	}
	return;
}

void Lm1::init_variable(int position, std::string name){

}

void Lm1::init_variable(int position, int value){

}

void Lm1::init_variable(int position, std::string name, int value){

}

