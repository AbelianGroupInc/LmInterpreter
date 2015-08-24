#include <iostream>
#include <string>
#include <memory>

#include "LmInterpreter.h"
#include "Lm1.h"

void CriticalError(){
	system("cls");
	std::cout << "Critical error, the program is destroyed" << std::endl;
	system("PAUSE");
	exit(EXIT_FAILURE);
}

void runLm(std::string file_name){
	LmInterpreter *umc = new LmInterpreter(new Lm1());
	umc->read_program(file_name.c_str());
	umc->run_program();
}

int main(){
	std::set_terminate(&CriticalError);
	std::string file_name = "bin/temp.lm";

	try{
		runLm(file_name);
	}
	catch (std::exception &e){
		std::cout << "Error :" << e.what() << std::endl;
	}


	return 0;
}