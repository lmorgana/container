
#include "test_utils.h"

template <class T>
std::vector<int> push(std::stack<T> stack)
{
	std::vector<int> result;

	stack.push(12);
	stack.push(13);
	stack.push(14);
	result.push_back(stack.size());
	result.push_back(stack.top());
	return (result);
}

template <class T>
std::vector<int> push(ft::stack<T> stack)
{
	std::vector<int> result;

	stack.push(12);
	stack.push(13);
	stack.push(14);
	result.push_back(stack.size());
	result.push_back(stack.top());
	return (result);
}

template <class T>
std::vector<int> empty(std::stack<T> stack)
{
	std::vector<int> result;

	result.push_back(stack.empty());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.empty());
	result.push_back(stack.size());
	result.push_back(stack.top());
	return (result);
}

template <class T>
std::vector<int> empty(ft::stack<T> stack)
{
	std::vector<int> result;

	result.push_back(stack.empty());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.empty());
	result.push_back(stack.size());
	result.push_back(stack.top());
	return (result);
}

template <class T>
std::vector<int> size(std::stack<T> stack)
{
	std::vector<int> result;
	std::stack<T> buff;

	result.push_back(stack.size());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.size());
	result.push_back(stack.top());
	for (int i = 0; i < 876; i++)
		buff.push(i);
	result.push_back(buff.size());
	return (result);
}

template <class T>
std::vector<int> size(ft::stack<T> stack)
{
	std::vector<int> result;
	ft::stack<T> buff;

	result.push_back(stack.size());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.size());
	result.push_back(stack.top());
	for (int i = 0; i < 876; i++)
		buff.push(i);
	result.push_back(buff.size());
	return (result);
}

template <class T>
std::vector<int> pop(std::stack<T> stack)
{
	std::vector<int> result;

	result.push_back(stack.size());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.size());
	result.push_back(stack.top());
	stack.pop();
	stack.pop();
	stack.pop();
	result.push_back(stack.size());
	result.push_back(stack.top());
	while (stack.size() > 0)
		stack.pop();
	result.push_back(stack.size());
	return (result);
}

template <class T>
std::vector<int> pop(ft::stack<T> stack)
{
	std::vector<int> result;

	result.push_back(stack.size());
	for (int i = 0; i < 1000; i++)
		stack.push(i);
	result.push_back(stack.size());
	result.push_back(stack.top());
	stack.pop();
	stack.pop();
	stack.pop();
	result.push_back(stack.size());
	result.push_back(stack.top());
	while (stack.size() > 0)
		stack.pop();
	result.push_back(stack.size());
	return (result);
}

template <class T>
std::vector<int> operators(std::stack<T> stack)
{
	std::vector<int> result;
	std::stack<T> buff;

	for (int i = 0; i < 1000; i++)
	{
		stack.push(i);
		buff.push(i);
	}
	result.push_back(stack == buff);
	stack.push(123);
	result.push_back(stack == buff);
	result.push_back(stack > buff);
	result.push_back(stack < buff);
	buff.pop();
	result.push_back(stack >= buff);
	result.push_back(stack <= buff);
	return (result);
}

template <class T>
std::vector<int> operators(ft::stack<T> stack)
{
	std::vector<int> result;
	ft::stack<T> buff;

	for (int i = 0; i < 1000; i++)
	{
		stack.push(i);
		buff.push(i);
	}
	result.push_back(stack == buff);
	stack.push(123);
	result.push_back(stack == buff);
	result.push_back(stack > buff);
	result.push_back(stack < buff);
	buff.pop();
	result.push_back(stack >= buff);
	result.push_back(stack <= buff);
	return (result);
}

template<class T>
void test( std::vector<int> (func1)(std::stack<T>), std::vector<int> (func2)(ft::stack<T>), std::string name_func)
{
	std::stack<T> orig;
	ft::stack<T> my;
	std::vector<int> v1, v2;
	unsigned long t1;
	unsigned long t2;

	t1 = clock();
	v1 = func1(orig);
	t1 = clock() - t1;

	t2 = clock();
	v2 = func2(my);
	t2 = clock() - t2;

	ft_result(name_func, v1, v2, t1, t2);
}

void start_stack()
{
	std::cout <<  "\n\x1B[1;33m" << "Stack tests starts" << "\033[0m" << std::endl;
	test<int>(push, push, "push");
	test<int>(empty, empty, "empty");
	test<int>(size, size, "size");
	test<int>(pop, pop, "pop");
	test<int>(operators, operators, "operators");

}