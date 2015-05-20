#include <string.h>
#include <sstream>

#include "InterpreterException.h"


const char* InterpreterException::what()const{
	std::ostringstream str_out; 
	char* out = new char[strlen(this->what_arg) + 1]; 

	str_out << this->what_arg << ". In line " << this->line;
	strcpy(out, str_out.str().c_str());

	return out;
}