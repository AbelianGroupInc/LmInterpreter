#pragma once
#ifndef LM_INTERPRETER_LM_COMMANDS_H
#define LM_INTERPRETER_LM_COMMANDS_H

#include "MemoryItem.h"

namespace LmCommands{
	void output(System::Windows::Forms::RichTextBox^ out, const MemoryItem* variable, const std::string name);
	void unsigned_output(System::Windows::Forms::RichTextBox^ out, const MemoryItem* variable, const std::string name);

	MemoryItem* add(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* subsract(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* multiplication(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* division(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* module(const MemoryItem* variable_1, const MemoryItem* variable_2);
	
	MemoryItem* unsigned_add(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* unsigned_subsract(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* unsigned_multiplication(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* unsigned_division(const MemoryItem* variable_1, const MemoryItem* variable_2);
	MemoryItem* unsigned_module(const MemoryItem* variable_1, const MemoryItem* variable_2);

	bool less(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool greater(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool less_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool greater_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool not_equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool go_to(const MemoryItem* variable_1, const MemoryItem* variable_2);

	bool unsigned_less(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool unsigned_greater(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool unsigned_less_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
	bool unsigned_greater_or_equal(const MemoryItem* variable_1, const MemoryItem* variable_2);
};

#endif