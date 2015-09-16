#include <iostream>
#include <string>
#include <math.h>
#include <cctype>
#include <stdexcept>

#include "LmCommands.h"
#include "Variable.h"

void LmCommands::input(MemoryItem* &variable, const std::string name){
	int value;
	std::cout << "Enter " << name << ": ";
	std::cin >> value;
	
	if (std::cin.fail() ){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		throw std::invalid_argument("Entered the wrong input");
	}
			
	variable = new Variable(value);
}

void LmCommands::output(const MemoryItem* variable, const std::string name){
	std::cout << name << ": " << variable->get_value() << std::endl;
}

void LmCommands::unsigned_input(MemoryItem* &variable, const std::string name){
	int value;
	std::cout << "Enter " << name << ": ";
	std::cin >> value;
	variable = new Variable(abs(value));
}

void LmCommands::unsigned_output(const MemoryItem* variable, const std::string name){
	std::cout << name << ": " << abs(variable->get_value()) << std::endl;
}

MemoryItem* LmCommands::add(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() + variable_2->get_value();
	return new Variable(value);
}

MemoryItem* LmCommands::subsract(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() - variable_2->get_value();
	return new Variable(value);
}

MemoryItem* LmCommands::multiplication(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() * variable_2->get_value();
	return new Variable(value);
}

MemoryItem* LmCommands::division(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() / variable_2->get_value();
	return new Variable(value);
}

MemoryItem* LmCommands::module(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() % variable_2->get_value();
	return new Variable(value);
}

MemoryItem* LmCommands::unsigned_add(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() + variable_2->get_value();
	return new Variable(abs(value));
}

MemoryItem* LmCommands::unsigned_subsract(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() - variable_2->get_value();
	return new Variable(abs(value));
}

MemoryItem* LmCommands::unsigned_multiplication(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() * variable_2->get_value();
	return new Variable(abs(value));
}

MemoryItem* LmCommands::unsigned_division(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() / variable_2->get_value();
	return new Variable(abs(value));
}

MemoryItem* LmCommands::unsigned_module(const MemoryItem* variable_1, const MemoryItem* variable_2){
	int value = variable_1->get_value() % variable_2->get_value();
	return new Variable(abs(value));
}

bool LmCommands::less(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() < variable_2->get_value();
}

bool LmCommands::greater(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() > variable_2->get_value();
}

bool LmCommands::less_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() <= variable_2->get_value();
}

bool LmCommands::greater_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() >= variable_2->get_value();
}

bool LmCommands::equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() == variable_2->get_value();
}

bool LmCommands::not_equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return variable_1->get_value() != variable_2->get_value();
}

bool LmCommands::go_to(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return true;
}

bool LmCommands::unsigned_less(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return abs(variable_1->get_value()) < abs(variable_2->get_value());
}

bool LmCommands::unsigned_greater(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return abs(variable_1->get_value()) > abs(variable_2->get_value());
}

bool LmCommands::unsigned_less_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return abs(variable_1->get_value()) <= abs(variable_2->get_value());
}

bool LmCommands::unsigned_greater_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2){
	return abs(variable_1->get_value()) >= abs(variable_2->get_value());
}