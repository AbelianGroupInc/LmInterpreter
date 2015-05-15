#pragma once
#ifndef LM_INTERPRETER_INTERPRETER_EXCEPTION
#define LM_INTERPRETER_INTERPRETER_EXCEPTION

#include <exception>


class InterpreterException : public std::exception{

public:
	InterpreterException(const char* what_arg, int line) :what_arg(what_arg), line(line){}
	virtual ~InterpreterException(){}
	virtual const char* what() const throw();
private:
	int line;
	const char* what_arg;
};


#endif