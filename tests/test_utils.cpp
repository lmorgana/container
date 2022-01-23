
#include "../vector.hpp"
#include "test_utils.h"
#include "iostream"
#include "iomanip"

const std::string GREEN_COLOR = "\x1B[1;32m";
const std::string RED_COLOR = "\x1B[1;31m";
const std::string DEFAULT_COLOR = "\033[0m";

void ft_result(std::string name_test, std::vector<int> v1, std::vector<int> v2, unsigned long t1, unsigned long t2)
{
	std::cout << "|" << std::setw(30) << std::left << name_test << "|  ";
	std::cout << (v1 == v2 ? GREEN_COLOR + "OK" : RED_COLOR + "KO")  << DEFAULT_COLOR << "  | " <<
	" orig: " << t1 << "ms; my: " << t2 << "ms;" << std::endl;
//	std::cout << std::endl;
}

int main(void)
{
	start_vec();
	start_stack();
	start_map();
	start_set();
}

