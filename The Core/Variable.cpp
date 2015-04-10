#include "Variable.h"

int Variable::get_value()const {
	return this->variable.front();
}

std::vector<int>&  Variable::get(){
	return this->variable;
}