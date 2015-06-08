#include "Memory.h"
#include "Converter.h"

const int SIZE_OF_MEMORY(65535);

Memory::Memory(){
	this->clear();
}

void Memory::clear(){
	for (int i = 0; i < SIZE_OF_MEMORY; i++)
		this->memory[i] = nullptr;
}

MemoryItem* Memory::get(int position){
	this->check(position);
	
	if (this->memory[position].get() == nullptr)
		throw std::out_of_range("Break the sequence of addresses");

	return this->memory[position].get();
}

void Memory::set(int position, MemoryItem* item){
	this->check(position);

	this->memory[position] = std::shared_ptr<MemoryItem>(item);
}

bool Memory::is_memory_cell_empty(int position){
	this->check(position);
	return this->memory[position].get() == nullptr;
}

void Memory::set_name(int position, std::string name){
	this->check(position);

	this->names[position] = name;
}

std::string Memory::get_name(int position)const{
	this->check(position);
	
	if (this->names.find(position) == this->names.end())
		return Converter::to_hex(position, 4);
	else
		return this->names.find(position)->second;
}

void Memory::check(int position)const{
	if (position < 0 || position > SIZE_OF_MEMORY)
		throw std::exception("Wrong address");
}