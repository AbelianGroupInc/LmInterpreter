#include <iostream>
#include <vector>
#include <conio.h>

#include "LmInterpreter.h"
#include "Lm3.h"
#include "Lm2.h"
#include "Lm1.h"
#include "Converter.h"

int showMenu(std::string name,std::vector<std::string> menu){
	int temp(0);

	while (true){
		system("cls");
		std::cout << name << std::endl;
		for (size_t i = 0; i < menu.size(); i++)
			std::cout << "\t" << i + 1 << ") "<< menu[i] << std::endl;

		temp = _getch() - '0';

		if (temp > 0 && temp <= (int)menu.size())
			return temp;
	}
}

int main(){
	LmInterpreter* umc = nullptr;
	std::vector<std::string> menu = { "LM - 3", "LM - 2", "LM - RM" };

	switch (showMenu("Choose learning machine:",menu)){
	case 1:
		umc = new LmInterpreter(new Lm3());
		break;
	case 2:
		umc = new LmInterpreter(new Lm2());
		break;
	case 3:
		umc = new LmInterpreter(new Lm1());
		break;
	}

	menu.clear();
	menu = {"Write program","Read program","Save program","Run program","Exit"};
	std::string file_name;

	while (true){
		switch (showMenu("Choose learning machine:", menu)){
		case 1:
			system("cls");
			std::cout << "Write here the program and ending with the word \'end\'\n" << std::endl << "#start\n";
			umc->read_program();
			break;
		case 2:
			std::cout << "Enter file name: ";
			std::cin >> file_name;
			umc->read_program(file_name.c_str());
			break;
		case 3:
			std::cout << "Enter file name: ";
			std::cin >> file_name;
			umc->save_programm(file_name.c_str());
			break;
		case 4:
			system("cls");
			umc->run_program();
			system("pause");
			break;
		case 5:
			exit(0);
			break;
		}
	}

	return 0;
}