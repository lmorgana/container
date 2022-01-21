
#include "iostream"
//#include "iterators.hpp"
#include <map>
#include "map.hpp"
#include "vector"
//#include "tree.hpp"


#include "time.h"

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(ft::map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

template <class T, class V>
		std::vector<int> copy_constructor_test0(std::map<T, V> mp) {

	std::vector<int> v;
	std::map<int, int> mpp;
	fillMap(mpp);
	for (std::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++){v.push_back(it->first);}
	for (std::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
	std::map<int, int> mp0;
	std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<int, int>::iterator it = mp.begin();
	std::map<int, int>::iterator it2 = mp.end();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	return v;
		}

template <class T, class V>
		std::vector<int> copy_constructor_test1(ft::map<T, V> mp) {

	std::vector<int> v;
	ft::map<int, int> mpp;
	fillMap(mpp);
	std::cout << "mpp.size = " << mpp.size() << std::endl;
	for ( ft::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++)
	{
//		std::cout << it->first << std::endl;
		v.push_back(it->first);
	}
	for ( ft::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
	ft::map<int, int> mp0;
	ft::map<int, int>::iterator ii = mp0.insert(ft::make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	ft::map<int, int>::iterator it = mp.begin();
	ft::map<int, int>::iterator it2 = mp.end();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	return v;


		}

template <class T>
		bool ft_is_equal(T &arr1, T &arr2)
		{
			if (arr1.size() != arr2.size())
				return (false);
			for (size_t i = 0; i < arr1.size(); i++)
			{
				if (arr1[i] != arr2[i])
					return (false);
			}
			return (true);
		}

bool	print_status_comp(std::string orig, std::string my)
{
	std::string ret;

	std::cout << "Comp: ";
	if (orig == my)
	{
		std::cout << "(1)" << std::endl;
		return (0);
	}
	else
	{
		std::cout << "(0)" << std::endl;
		return (1);
	}
}

int main()
{
	std::string					temp_orig = "", temp_my = "", num_str = "";
	unsigned int			time_orig = 0, time_my = 0, rez = 0;
	std::map<int, std::string>	orig;
	ft::map<int, std::string>	my;
	std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator>	orig_pair;
	ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator>	my_pair;
	int size = 100;


	for (int i = 2; i <= size; i = i + 2)
	{
		num_str = std::to_string(i) + "_";
		orig.insert(std::pair<int, std::string>(i, num_str));
		my.insert(ft::pair<int, std::string>(i, num_str));
	}

	std::map<int, std::string> const orig_const(orig);
	ft::map<int, std::string> const my_const(my);

	//===========================ORIG==============================
	time_orig = clock();

	orig_pair = orig_const.equal_range(-size);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	for (int i = 0; i < size; i++)
	{
		orig_pair = orig_const.equal_range(i);
		temp_orig += orig_pair.first->second + orig_pair.second->second + "|";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();

	my_pair = my_const.equal_range(-size);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	for (int i = 0; i < size; i++)
	{
		my_pair = my_const.equal_range(i);
		temp_my += my_pair.first->second + my_pair.second->second + "|";
	}

	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);

	return (0);
}