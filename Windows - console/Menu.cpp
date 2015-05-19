#include <string>
#include <deque>
#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "Menu.h"

const int KEY_ENTER = 13,
		  KEY_UP    = 72,
		  KEY_DOWN  = 80;

Menu::Menu(std::string menu_name, std::string exit_name) :name(menu_name), exit_name(exit_name), pointer(0){
	this->push_back(exit_name, [](){}, false);
}

Menu::Menu(std::string menu_name, std::string exit_name, std::function<void()> exit_func) : name(menu_name), exit_name(exit_name), pointer(0){
	this->push_back(exit_name, exit_func, false);
}

void Menu::push_front(std::string name, std::function<void()> func, bool lock){
	this->items.push_front(MenuItem(name, func, lock));
}

void Menu::push_back(std::string name, std::function<void()> func, bool lock){
	this->items.push_back(MenuItem(name, func, lock));

	if (this->items.size() > 1)
		std::swap(this->items[this->items.size() - 1], this->items[this->items.size() - 2]);
}

void Menu::push(std::string name, std::function<void()> func, bool lock, size_t position){
	if (position < this->items.size())
		throw std::out_of_range("Wrong position");

	this->items.insert(std::begin(this->items) + position, MenuItem(name, func, lock));
}

void Menu::set_exit_func(std::function<void()> func){
	this->items[this->items.size() - 1].func = func;
}

void Menu::remove(size_t position){
	if (position < this->items.size())
		throw std::out_of_range("Wrong position");

	this->items.erase(std::begin(this->items) + position);
}

void Menu::lock_item(size_t position){
	if (position < this->items.size())
		this->items[position].lock = true;
}

void Menu::unlock_item(size_t position){
	if (position < this->items.size())
		this->items[position].lock = false;
}

void Menu::show_menu(){
	while (true){
		system("cls");
		
		std::cout << this->name << std::endl << std::endl;
		for (size_t i = 0; i < this->items.size(); i++)
			this->print_item(i);

		char key;
		key = _getch();

		if (key == -32){
			key = _getch();

			switch (key){
			case KEY_UP:
				this->pointer_up();
				break;
			case KEY_DOWN:
				this->pointer_down();
				break;
			}
		}

		try{
			if (key == KEY_ENTER){
				if (!this->items.at(this->pointer).lock){
					system("cls");
					this->items.at(this->pointer).func();
				}

				if (this->pointer == this->items.size() - 1)
					return;
			}
		}
		catch (std::exception& exp){
			system("cls");
			std::cout << "Error: " << exp.what() << std::endl;
			system("PAUSE");
		}
	}
}

void Menu::print_item(size_t position)const{
	Console—olor background(Black);
	Console—olor text(Green);

	if (position == this->pointer)
		background = LightGray;

	if (this->items.at(position).lock)
		text = Red;

	this->set_color(text, background);
	std::cout << this->items.at(position).name << std::endl;
	this->set_color(LightGray, Black);
}

void Menu::pointer_down(){
	this->pointer++;
	this->pointer %= this->items.size();
}

void Menu::pointer_up(){
	this->pointer = (this->pointer ? this->pointer - 1 : this->items.size() - 1);
}

void Menu::set_color(Console—olor text, Console—olor background)const{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}



