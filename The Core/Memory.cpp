#include "Memory.h"

const int SIZE_OF_MEMORY(65535);

Memory::Memory(){
	for (int i = 0; i < SIZE_OF_MEMORY; i++)
		this->memory[i] = nullptr;
}

Memory::~Memory(){
	/*for (std::unordered_map<int, MemoryItem*>::iterator itr = this->memory.begin();
		itr != this->memory.end(); itr++)
		delete itr->second;*/
}

MemoryItem* Memory::get(int position){
	if (this->memory.find(position) == this->memory.end())
		throw std::exception();

	return this->memory[position];
}

void Memory::set(int position, MemoryItem* item){
	this->memory[position] = item;
}