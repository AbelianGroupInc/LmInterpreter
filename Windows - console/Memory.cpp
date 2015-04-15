#include "Memory.h"

const int SIZE_OF_MEMORY(65535);

Memory::Memory(){
	for (int i = 0; i < SIZE_OF_MEMORY; i++)
		this->memory[i] = nullptr;
}

MemoryItem* Memory::get(int position){
	if (this->memory.find(position) == this->memory.end())
		throw std::exception();

	return this->memory[position].get();
}

void Memory::set(int position, MemoryItem* item){
	this->memory[position] = std::shared_ptr<MemoryItem>(item);
}