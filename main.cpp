
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "iterators.hpp"
#include "reverse_iterator.hpp"
#include <map>

template<class vec>
void ft_print_vector(vec vector)
{
	typedef typename vec::iterator iterator;
	iterator iter_begin = vector.begin();
	iterator iter_end = vector.end();

	for (int i = 0; i < ft::distance(iter_begin, iter_end); i++)
	{
		std::cout << "index[" << i << "]=" << *(iter_begin + i) << std::endl;
	}
}

template <class my_vector, class origin_vector>
bool	ft_is_equal(my_vector my, origin_vector origin)
{
	typedef typename my_vector::iterator		my_it;
	typedef typename origin_vector::iterator	orig_it;

	my_it my_begin = my.begin();
	my_it my_end = my.end();
	orig_it	orig_begin = origin.begin();

	if (my.size() != origin.size() || my.capacity() != origin.capacity())
		return (false);
	while (my_begin != my_end)
	{
		if (*my_begin != *orig_begin)
			return (false);
		my_begin++;
		orig_begin++;
	}
	return (true);
}

//template <typename T>
//std::vector<int> assign_test(T vector) {
//	std::vector<int> v;
//	std::vector<int> tmp, tmp2;
//	vector.assign(3, 3);
//	tmp.assign(40000000, 1);
//	tmp2.assign(4000, 1);
//	vector.assign(tmp.begin(), tmp.end());
//	v.push_back(vector[1]);
//	v.push_back(vector.size());
//	v.push_back(vector.capacity());
//	vector.assign(tmp2.begin(), tmp2.end());
//	v.push_back(vector[444]);
//	v.push_back(vector.size());
//	v.push_back(vector.capacity());
//	return v;
//}

//template <typename T>
//std::vector<int> assign_test(T vector) {
//
//	return (v);
//}


int main(void)
{
	ft::vector<int> my;

	for (int i = 0;  i < 10; i++)
		my.push_back(i);

	std::cout << my.at(7) << std::endl;
}

//int	main(void)
//{
//	ft::vector<int> my;
//	std::vector<int> origin;
//
//	std::vector<int> v1 = assign_test(my);
//	std::vector<int> v2 = assign_test(origin);
//
//
//	std::cout << ft_is_equal(v1, v2) << std::endl;
//
//	ft_print_vector(v1);
//	ft_print_vector(v2);
//
//	return (0);
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

