#include <iostream>
#include <string>
#include <math.h>

#include "Converter.h"

int Converter::to_dec(std::string hex_number){
	return Details::to_dec_system(hex_number, 16);
}

std::string Converter::to_dec(const std::string &hex_number, size_t number_size){
	return Details::added_zeros(Details::to_k_system(to_dec(hex_number), 10), number_size);
}

std::string Converter::to_hex(int dec_number){
	return Details::to_k_system(dec_number, 16);
}

std::string Converter::to_hex(int dec_number, size_t number_size){
	return Details::added_zeros(to_hex(dec_number), number_size);
}

std::string Converter::to_hex(const std::string &dec_number){
	return to_hex(Details::to_dec_system(dec_number, 10));
}

std::string Converter::to_hex(std::string dec_number, size_t number_size){
	return Details::added_zeros(to_hex(dec_number), number_size);
}

std::string Converter::Details::to_k_system(int dec_number, size_t k){
	return dec_number ? to_k_system(dec_number / k, k) + int_to_char(dec_number %  k) : std::string();
}

int Converter::Details::to_dec_system(const std::string &number, size_t k, size_t cur){
	return cur < number.size() ? char_to_int(number[cur]) * int(pow(double(k), number.size() - 1 - cur)) + 
		to_dec_system(number, k, cur + 1) : 0;
}

char Converter::Details::int_to_char(int number){
	if (number > 36 || number < 0)
		throw std::exception();

	return number > 9 ? number - 10 + 'A' : number + '0';
}

int Converter::Details::char_to_int(char number){
	if (!((number >= '0' && number <= '9') || (number >= 'A' && number <= 'Z')))
		throw std::exception();

	return number <= '9' ? number - '0' : number + 10 - 'A';
}

std::string Converter::Details::added_zeros(const std::string &number, size_t number_size){
	int numer_of_zeros((int)number_size - (int)number.size());

	if (numer_of_zeros < 0)
		throw std::exception();

	return std::string(numer_of_zeros, '0') + number;
}