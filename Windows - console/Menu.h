#pragma once

#ifndef LM_INTERPRETER_MENU_H
#define LM_INTERPRETER_MENU_H

#include <string>
#include <deque>

#include "MenuItem.h"

enum Console—olor{Black, Blue, Green ,Cyan ,Red ,Magenta ,Brown ,LightGray ,DarkGray ,LightBlue,
	LightGreen ,LightCyan ,LightRed ,LightMagenta ,Yellow, White};

class Menu{
public:
	Menu(std::string menu_name, std::string exit_name);
	Menu(std::string menu_name, std::string exit_name, std::function<void()> exit_func);

	void push_front(std::string name, std::function<void()> func, bool lock);
	void push_back(std::string name, std::function<void()> func, bool lock);
	void push(std::string name, std::function<void()> func, bool lock, size_t position);
	void set_exit_func(std::function<void()> func);

	void remove(size_t position);

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
	void set_color(Console—olor text, Console—olor background)const;
	void print_item(size_t position)const;
};

#endif
