
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterators.hpp"
#include "reverse_iterator.hpp"
#include <map>

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
	ft::vector<int> my2(6, 2);
//	std::vector<int> orig(6, 2);

	ft::vector<int>::iterator rev = my2.begin();

//const ft::vector<int> my;

//	std::vector<int>::const_iterator iter_orig = orig.begin();

//	(void) iter_orig;
	(void) rev;
}

//int	main(void)
//{
//	std::vector<int> origin(5, 2);
//	//	std::vector<int>::iterator orig_iter = origin.begin();
//
//	Vector<int>			my(5, 2);
//	//	ft::Iterator<int>	my_iter = my.begin();
//
//
//
//	origin.resize(7, 1);
//	my.resize(7, 1);
//
//	std::cout << "Original:" << std::endl;
//	ft_print_vector(origin.begin(), origin.end());
//	std::cout << "size: " << origin.size() << std::endl;
//	std::cout << "capacity: " << origin.capacity() << std::endl;
//
//	std::cout << std::endl;
//
//	std::cout << "My:" << std::endl;
//	ft_print_vector(my.begin(), my.end());
//	std::cout << "size: " << my.size() << std::endl;
//	std::cout << "capacity: " << my.capacity() << std::endl;
//
//}


//int	main(void)
//{
//	std::vector<int> origin(5, 2);
//	std::vector<int>::iterator orig_iter = origin.begin();
//
//	Vector<int>			my(5, 2);
//	ft::Iterator<int>	my_iter = my.begin();
//
//
//
//	origin.resize(2);
//	my.resize(2);
//
//	std::cout << "Original:" << std::endl;
//	ft_print_vector(origin.begin(), origin.end());
//	std::cout << "size: " << origin.size() << std::endl;
//	std::cout << "capacity: " << origin.capacity() << std::endl;
//
//	std::cout << std::endl;
//
//	std::cout << "My:" << std::endl;
//	ft_print_vector(my.begin(), my.end());
//	std::cout << "size: " << my.size() << std::endl;
//	std::cout << "capacity: " << my.capacity() << std::endl;
//}

//int main(void)
//{
//
//	std::vector<int> origin(5, 2);
//	std::vector<int>::iterator orig_iter = origin.begin();
//
//	for (std::vector<int>::iterator buff = orig_iter; buff != origin.end(); buff++)
//		*buff = 141414;//ft::distance(origin.begin(), buff);
//
//	Vector<int>			my(15, 2);
//	ft::Iterator<int>	my_iter = my.begin();
//	for (ft::Iterator<int> buff = my_iter; buff != my.end(); buff++)
//		*buff = ft::distance(my.begin(), buff);
//
//	my_iter ++;
//	my_iter ++;
//	my_iter ++;
//	my_iter ++;
//	my_iter ++;
//
//	my.insert(my_iter, 2, -1111);
//
//	ft::Iterator<int>	my_iter2 = my.begin();
//	my_iter2++;
//	my_iter2++;
//	my_iter2++;
//
//	std::cout << "size1 :" << my.size() << std::endl;
//	my.insert(my_iter2, origin.begin(), origin.end());
//
//	ft_print_vector(my.begin(), my.end());
//
//	std::cout << "size2 :" << my.size() << std::endl;
//	std::cout << "capacity: " << my.capacity() << std::endl;
//
//	return (0);
//}

