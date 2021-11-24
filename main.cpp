
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

	//Vector<int> my(3, 2);
	std::vector<int> origin(15, 2);
	std::vector<int>::iterator orig_iter = origin.begin();

	for (std::vector<int>::iterator buff = orig_iter; buff != origin.end(); buff++)
		*buff = ft::distance(origin.begin(), buff);

	orig_iter += 5;
	origin.insert(orig_iter, 123131);
	//*orig_iter = 1231231;

	ft_print_vector(origin.begin(), origin.end());
	std::cout << "capacity=" << origin.capacity() << std::endl;
	std::cout << "size=" << origin.size() << std::endl;
	//std::cout << "capacity=" << origin.capacity() << std::endl;


	//ft::Iterator<int>			my_iter = my.begin();
	//std::vector<int>::iterator	orig_iter = origin.begin();

	//Vector<int> 				my(origin.begin(), origin.end());
	//ft::Iterator<int>			my_iter = my.begin();

//	std::cout << "Orgin:" << std::endl;
//	ft_print_vector(origin.begin(), origin.end());

// 	std::cout << ft::distance(my.begin(), my.end()) << std::endl;

//	std::cout << "my:" << std::endl;
	//ft_print_vector(my.begin(), my.end());



	return (0);
}

