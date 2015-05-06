#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>

#include "LmInterpreter.h"
#include "Lm3.h"
#include "Lm2.h"
#include "Lm1.h"
#include "Converter.h"
#include "Menu.h"

int main(){
	std::shared_ptr<LmInterpreter> umc(nullptr);

	Menu main_menu("Main menu", "Back");
	Menu lm("Choose learning machine:", "Exit");

	main_menu.push_back("Write program", [&](){
		std::cout << "Write here the program and ending with the word \'end\'\n" << std::endl << "#start\n";
		umc->read_program();

		main_menu.unlock_item(3);
		main_menu.unlock_item(2);
	},false);

	main_menu.push_back("Read program", [&](){
		std::string file_name;
		std::cout << "Enter file name: ";
		std::cin >> file_name;
		umc->read_program(file_name.c_str());

		main_menu.unlock_item(3);
		main_menu.unlock_item(2);
	}, false);

	main_menu.push_back("Save program", [&](){
		std::string file_name;
		std::cout << "Enter file name: ";
		std::cin >> file_name;
		umc->save_programm(file_name.c_str());
	}, true);

	main_menu.push_back("Run program", [&](){
		umc->run_program();
		system("PAUSE");
	}, true);

	
	lm.push_back("LM - 3", [&](){
		std::cout << "Please wait...";
		std::shared_ptr<Lm> temp(new Lm3());
		umc = std::shared_ptr<LmInterpreter>(new LmInterpreter(temp.get()));
		main_menu.show_menu();
	}, false);

	lm.push_back("LM - 2", [&](){
		std::cout << "Please wait...";
		std::shared_ptr<Lm> temp(new Lm2());
		umc = std::shared_ptr<LmInterpreter>(new LmInterpreter(temp.get()));
		main_menu.show_menu();
	}, false);

	lm.push_back("LM - RM", [&](){
		std::cout << "Please wait...";
		std::shared_ptr<Lm> temp(new Lm1());
		umc = std::shared_ptr<LmInterpreter>(new LmInterpreter(temp.get()));
		main_menu.show_menu();
	}, false);

	lm.show_menu();

	return 0;
}