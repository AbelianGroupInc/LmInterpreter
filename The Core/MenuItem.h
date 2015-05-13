#pragma once

#ifndef LM_INTERPRETER_MENU_ITEM_H
#define LM_INTERPRETER_MENU_ITEM_H

#include <functional>
#include <string>

struct MenuItem{
	std::string name;
	std::function<void()> func;
	bool lock;

	MenuItem(std::string name, std::function<void()> func, bool lock) :name(name), func(func), lock(lock){}
};

#endif
