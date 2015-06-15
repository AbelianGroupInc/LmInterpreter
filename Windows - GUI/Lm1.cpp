#include "Lm1.h"

#define STOP_COMMAND 153

void Lm1::clear_memory(){
	this->ram_memory.clear();
}

void Lm1::do_one_step(System::Windows::Forms::RichTextBox^ out){
	if (this->end_flag)
		throw std::out_of_range("Program end");

	if (this->input_flag)
		throw std::exception("The value is not received, enter please");

	this->perfom_command(out);
	return;
}

