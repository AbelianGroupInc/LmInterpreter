#pragma once

#ifndef LM_INTERPRETER_MENU_H
#define LM_INTERPRETER_MENU_H

#include <string>
#include <deque>

#include "MenuItem.h"

enum ConsoleŅolor{Black, Blue, Green ,Cyan ,Red ,Magenta ,Brown ,LightGray ,DarkGray ,LightBlue,
	LightGreen ,LightCyan ,LightRed ,LightMagenta ,Yellow, White};

class Menu{
public:
	Menu(std::string menu_name, std::string exit_name);

	void push_front(std::string name, std::function<void()> func, bool lock);
	void push_back(std::string name, std::function<void()> func, bool lock);

	void lock_item(size_t position);
	void unlock_item(size_t position);

	void show_menu();
private:
	std::string name;
	std::string exit_name;
	std::deque<MenuItem> items;
	size_t pointer;

	void pointer_up();
	void pointer_down();
	void set_color(ConsoleŅolor text, ConsoleŅolor background)const;
	void print_item(size_t position)const;
};

#endif
