#include "Lm1.h"
#include "Variable.h"

const int
MAX_CPU_MEMORY_SIZE = 15,
MAX_RAM_MEMORY_SIZE = 65535;

int const
COMMAND_IS_LONG = 100,
COMMAND_IS_NOT_LONG = 200;

int const
FIRST_OPERAND = 1,
SECOND_OPERAND = 2;

int Lm1::get_r1_register(){
	return this->ram_memory.get(this->current_address)->get().at(1);
}

int Lm1::get_a2_register(){
	return this->ram_memory.get(this->current_address)->get().at(3);
}

int Lm1::get_m2_register(){
	return this->ram_memory.get(this->current_address)->get().at(2);
}

int Lm1::get_r2_register(){
	return this->ram_memory.get(this->current_address)->get().at(2);
}

int Lm1::get_ram_value(int adress){
	return ram_memory.get(adress)->get_value();
}

int Lm1::get_cpu_value(int adress){
	return this->cpu_memory[adress];
}

void Lm1::go_to_next_command(int command){
	if (this->is_command_long(command)){
		if (this->current_address + 2 > MAX_RAM_MEMORY_SIZE)
			throw std::exception();

		this->current_address += 2;
	}
	else{
		if (this->current_address + 1 > MAX_RAM_MEMORY_SIZE)
			throw std::exception();

		this->current_address++;
	}
}

int Lm1::get_cmp_command(int command){
	int comp_command;
	if (this->is_command_long(command)){
		if (this->current_address + 2 > MAX_RAM_MEMORY_SIZE)
			throw std::exception();
		comp_command = this->get_ram_value(this->current_address + 2);
	}
	else {
		if (this->current_address + 1 > MAX_RAM_MEMORY_SIZE)
			throw std::exception();

		comp_command = this->get_ram_value(this->current_address + 1);
	}
	return comp_command;
}

int Lm1::get_first_operand_adress(){
	return this->get_r1_register();
}

int Lm1::get_first_operand_value(){
	int temp = this->get_first_operand_adress();
	return this->get_cpu_value(this->get_first_operand_adress());
}

int Lm1::get_second_operand_adress(int command){
	int operand_adress;
	if (this->is_command_long(command)){
		if (this->get_m2_register() == 0)
			operand_adress = this->get_a2_register();
		else
			operand_adress = this->get_a2_register() + (this->get_cpu_value(this->get_m2_register()) * 2);
	}
	else
		operand_adress = get_r2_register();

	return operand_adress;
}

int Lm1::get_second_operand_value(int command){
	int operand_value;
	if (this->is_command_long(command))
		operand_value = this->get_ram_value(this->get_second_operand_adress(command));
	else
		operand_value = this->get_cpu_value(this->get_second_operand_adress(command));

	return operand_value;
}

MemoryItem* Lm1::get_first_operand(){
	MemoryItem* operand;

	operand = new Variable(this->get_first_operand_value());

	return operand;
}

MemoryItem* Lm1::get_second_operand(int command){
	MemoryItem* operand = new Variable(this->get_second_operand_value(command));

	return operand;
}

MemoryItem* Lm1::get_operand(const int operandNumb, int command){
	MemoryItem* operand;
	if (operandNumb == FIRST_OPERAND)
		operand = this->get_first_operand();
	else
		operand = this->get_second_operand(command);

	return operand;
}

void Lm1::unconditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*)){
	MemoryItem* first_operand = this->get_operand(FIRST_OPERAND, COMMAND_IS_LONG);
	MemoryItem* second_operand = this->get_operand(SECOND_OPERAND, COMMAND_IS_LONG);

	this->current_address = func(first_operand, second_operand) ? this->get_a2_register() : this->current_address + 2;
}

void Lm1::conditional_transit(bool(*func)(const MemoryItem*, const MemoryItem*), int command){
	MemoryItem* first_operand = this->get_operand(FIRST_OPERAND, command);
	MemoryItem* second_operand = this->get_operand(SECOND_OPERAND, command);

	this->go_to_next_command(command);

	if (this->ram_memory.get(this->get_a2_register()) == nullptr ||
		this->current_address + 2 > MAX_RAM_MEMORY_SIZE)
		std::exception();

	this->current_address = func(first_operand, second_operand) ? this->get_a2_register() : this->current_address + 2;
}

void Lm1::cmd_rm_assigment_1_work(){
	if (this->get_first_operand_adress() >= MAX_CPU_MEMORY_SIZE ||
		this->get_operand(SECOND_OPERAND, COMMAND_IS_LONG) == nullptr)
		throw std::exception();

	this->cpu_memory[this->get_first_operand_adress()] =
		this->get_operand(SECOND_OPERAND, COMMAND_IS_LONG)->get_value();
}

void Lm1::cmd_rm_assigment_2_work(){
	if (this->get_first_operand_adress() + 1 >= MAX_CPU_MEMORY_SIZE ||
		this->get_first_operand_value() == INT_MAX)
		throw std::exception();

	MemoryItem* newVal = new Variable(this->get_cpu_value(this->get_r1_register()));
	this->ram_memory.set(this->get_second_operand_adress(COMMAND_IS_LONG), newVal);
}

void Lm1::cmd_rr_assigment_work(){
	if (this->get_first_operand_adress() >= MAX_CPU_MEMORY_SIZE ||
		this->get_second_operand_adress(COMMAND_IS_NOT_LONG) >= MAX_CPU_MEMORY_SIZE ||
		this->get_operand(SECOND_OPERAND, COMMAND_IS_LONG) == nullptr)
		throw std::exception();

	this->cpu_memory[this->get_r1_register()] = this->cpu_memory[this->get_r2_register()];
}