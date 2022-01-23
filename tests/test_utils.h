#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <vector>
#include "../vector.hpp"
#include <stack>
#include "../stack.hpp"
#include <map>
#include "../map.hpp"
#include <time.h>
#include <set>
#include "../set.hpp"

void ft_result(std::string name_test, std::vector<int> v1, std::vector<int> v2, unsigned long t1, unsigned long t2);

void start_vec();
void start_stack();
void start_map();
void start_set();

#endif
