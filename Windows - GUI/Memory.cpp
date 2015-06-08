#include <sstream>

#include "Memory.h"
#include "Converter.h"

const int SIZE_OF_MEMORY(65535);

Memory::Memory(){
	this->clear();
}

std::vector<std::string> Memory::get_var_inf(){
	std::vector<std::string> answer;

	for (std::unordered_map<int, std::shared_ptr<MemoryItem> >::iterator itr = this->memory.begin();
		itr != this->memory.end(); itr++){

		if (itr->second && itr->second->get().size() == 1){
			std::ostringstream out;
			out << Converter::to_hex(itr->first, 4);

			if (this->names.find(itr->first) != this->names.end())
				out << " (" << this->get_name(itr->first) << ")";

			out << " = " << itr->second->get_value();
			answer.push_back(out.str());
		}
	}

	return answer;
}

std::vector<std::string> Memory::get_cmd_inf(){
	std::vector<std::string> answer;

	for (std::unordered_map<int, std::shared_ptr<MemoryItem> >::iterator itr = this->memory.begin();
		itr != this->memory.end(); itr++){

		if (itr->second && itr->second->get().size() > 1){
			std::ostringstream out;
			out << Converter::to_hex(itr->first, 4);

			if (this->names.find(itr->first) != this->names.end())
				out << " (" << this->get_name(itr->first) << ")";

			out << " = ";

			std::vector<int> cmd = itr->second->get();

			for (int k = 0; k < cmd.size(); k++)
				out << Converter::to_hex(cmd[k]) << ' ';

			answer.push_back(out.str());
		}
	}

	return answer;
}

void Memory::clear(){
	for (int i = 0; i < SIZE_OF_MEMORY; i++)
		this->memory[i] = NULL;
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