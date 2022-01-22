
#include "../test_utils.h"

template <class T, class U>
std::vector<int> copy_constructor(std::map<T, U> map)
{
	std::vector<int> result;


	return (result);
}

template<class T, class U>
void test( std::vector<int> (func1)(std::map<T, U>), std::vector<int> (func2)(ft::map<T, U>), std::string name_func)
{
	std::map<T, U> orig;
	ft::map<T, U> my;
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

void start_map()
{
	std::cout <<  "\x1B[1;33m" << "Vector tests starts" << "\033[0m" << std::endl;
	test<int>(copy_constructor, copy_constructor, "copy constructor");

}
