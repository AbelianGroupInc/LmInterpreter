#pragma once
#ifndef LM_INTERPRETER_CONVERTER_H
#define LM_INTERPRETER_CONVERTER_H

#include <iostream>
#include <string>

namespace Converter{
	namespace Details{
		std::string to_k_system(int dec_number, size_t k);
		int to_dec_system(const std::string &number, size_t k, size_t cur = 0);
		char int_to_char(int number);
		int char_to_int(char number);
		std::string added_zeros(const std::string &number, size_t number_size);
	}

	int to_dec(std::string hex_number);
	std::string to_dec(const std::string &hex_number, size_t number_size);
	std::string to_hex(int dec_number);
	std::string to_hex(int dec_number, size_t number_size);
	std::string to_hex(const std::string &dec_number);
	std::string to_hex(std::string dec_number, size_t number_size);
};

#endif