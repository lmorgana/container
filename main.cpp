
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterators.hpp"

template<class T>
void ft_print_vector(T iter_begin, T iter_end)
{
	for (int i = 0; i < ft::distance(iter_begin, iter_end); i++)
	{
		std::cout << "index[" << i << "]=" << *(iter_begin + i) << std::endl;
	}
}

int main(void)
{

	std::vector<int> origin(15, 2);
	std::vector<int>::iterator orig_iter = origin.begin();

	for (std::vector<int>::iterator buff = orig_iter; buff != origin.end(); buff++)
		*buff = ft::distance(origin.begin(), buff) * 4;
//
//	orig_iter += 5;
//	origin.insert(orig_iter, 123131);
//	//*orig_iter = 1231231;
//
//	ft_print_vector(origin.begin(), origin.end());
//	std::cout << "capacity=" << origin.capacity() << std::endl;
//	std::cout << "size=" << origin.size() << std::endl;

	Vector<int>			my(15, 2);
	ft::Iterator<int>	my_iter = my.begin();
	for (ft::Iterator<int> buff = my_iter; buff != my.end(); buff++)
		*buff = ft::distance(my.begin(), buff);

	//ft_print_vector(my.begin(), my.end());

	my_iter ++;
	my_iter ++;
	my_iter ++;
	my_iter ++;
	my_iter ++;


	//ft::Iterator<int> new_iter = my.insert(my_iter, 555555);
	//my.insert(my_iter, 5, 0);
	my.insert(my_iter, origin.begin(), origin.end());

	//std::cout << "all" << std::endl;

	ft_print_vector(my.begin(), my.end());
	//std::cout << *new_iter << std::endl;


	return (0);
}

