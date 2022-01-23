
#include "test_utils.h"

template <class T, class U>
std::vector<int> constructor_range(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);

	result.push_back(set.size());

	std::set<T, U> buff(set.begin(), set.end());

	result.push_back(buff.size());
	return (result);
}

template <class T, class U>
std::vector<int> constructor_range(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);

	result.push_back(set.size());

	ft::set<T, U> buff(set.begin(), set.end());

	result.push_back(buff.size());
	return (result);
}

template <class T, class U>
std::vector<int> constructor_copy_assign(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	result.push_back(set.size());

	std::set<T, U> buff(set);
	std::set<T, U> buff1;

	buff1 = buff;
	result.push_back(buff.size());
	result.push_back(buff1.size());
	return (result);
}

template <class T, class U>
std::vector<int> constructor_copy_assign(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	result.push_back(set.size());

	ft::set<T, U> buff(set);
	ft::set<T, U> buff1;

	buff1 = buff;
	result.push_back(buff.size());
	result.push_back(buff1.size());
	return (result);
}

template <class T, class U>
std::vector<int> begin(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	result.push_back(*set.begin());
	set.erase(*set.begin());
	result.push_back(*set.begin());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> begin(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	result.push_back(*set.begin());
	set.erase(*set.begin());
	result.push_back(*set.begin());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> end(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename std::set<T, U>::iterator iter = set.end();
	iter--;
	result.push_back(*iter);
	set.erase(iter);
	iter = set.end();
	iter--;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> end(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename ft::set<T, U>::iterator iter = set.end();
	iter--;
	result.push_back(*iter);
	set.erase(iter);
	iter = set.end();
	iter--;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> rbegin(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename std::set<T, U>::reverse_iterator iter = set.rbegin();
	iter++;
	result.push_back(*iter);
	set.erase(iter.base());
	iter = set.rbegin();
	iter++;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> rbegin(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename ft::set<T, U>::reverse_iterator iter = set.rbegin();
	iter++;
	result.push_back(*iter);
	set.erase(iter.base());
	iter = set.rbegin();
	iter++;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> rend(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename std::set<T, U>::reverse_iterator iter = set.rend();
	iter--;
	result.push_back(*iter);
	set.erase(iter.base());
	iter = set.rend();
	iter--;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> rend(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		set.insert(i*2);
	typename ft::set<T, U>::reverse_iterator iter = set.rend();
	iter--;
	result.push_back(*iter);
	set.erase(iter.base());
	iter = set.rend();
	iter--;
	result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> empty_size(std::set<T, U> set)
{
	std::vector<int> result;

	result.push_back(set.empty());
	result.push_back(set.size());
	for (int i = 0; i < 100; i++)
	{
		set.insert(i*2);
		result.push_back(set.size());
	}
	result.push_back(set.empty());
	result.push_back(set.size());
	set.erase(0);
	set.erase(1);
	set.erase(2);
	set.erase(3);
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> empty_size(ft::set<T, U> set)
{
	std::vector<int> result;

	result.push_back(set.empty());
	result.push_back(set.size());
	for (int i = 0; i < 100; i++)
	{
		set.insert(i*2);
		result.push_back(set.size());
	}
	result.push_back(set.empty());
	result.push_back(set.size());
	set.erase(0);
	set.erase(1);
	set.erase(2);
	set.erase(3);
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> insert_val(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
	{
		std::pair<typename std::set<T, U>::iterator, T> pr = set.insert(i);
		result.push_back(*pr.first);
		result.push_back(pr.second);
	}
	std::pair<typename std::set<T, U>::iterator, T> pr = set.insert(0);
	result.push_back(*pr.first);
	result.push_back(pr.second);
	return (result);
}

template <class T, class U>
std::vector<int> insert_val(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
	{
		ft::pair<typename ft::set<T, U>::iterator, T> pr = set.insert(i);
		result.push_back(*pr.first);
		result.push_back(pr.second);
	}
	ft::pair<typename ft::set<T, U>::iterator, T> pr = set.insert(0);
	result.push_back(*pr.first);
	result.push_back(pr.second);
	return (result);
}

template <class T, class U>
std::vector<int> insert_iter(std::set<T, U> set)
{
	std::vector<int> result;
	typename std::set<T, U>::iterator iter;
	typename std::set<T, U>::iterator iter2;


	for (int i = 0; i < 100; i++)
		set.insert(i);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
	{
		iter2 = set.insert(iter, *iter*12);
		result.push_back(*iter2);
	}
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> insert_iter(ft::set<T, U> set)
{
	std::vector<int> result;
	typename ft::set<T, U>::iterator iter;
	typename ft::set<T, U>::iterator iter2;


	for (int i = 0; i < 100; i++)
		set.insert(i);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
	{
		iter2 = set.insert(iter, *iter*12);
		result.push_back(*iter2);
	}
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> insert_range(std::set<T, U> set)
{
	std::vector<int> result;
	std::set<T, U> buff;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	result.push_back(set.size());
	buff.insert(set.begin(), set.end());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> insert_range(ft::set<T, U> set)
{
	std::vector<int> result;
	ft::set<T, U> buff;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	result.push_back(set.size());
	buff.insert(set.begin(), set.end());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> erase_iter(std::set<T, U> set)
{
	std::vector<int> result;
	typename std::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	iter = set.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	set.erase(iter);
	result.push_back(set.size());
	iter = set.begin();
	iter++;
	iter++;
	set.erase(iter);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> erase_iter(ft::set<T, U> set)
{
	std::vector<int> result;
	typename ft::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	iter = set.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	set.erase(iter);
	result.push_back(set.size());
	iter = set.begin();
	iter++;
	iter++;
	set.erase(iter);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> erase_key(std::set<T, U> set)
{
	std::vector<int> result;
	typename std::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	for(int i = 0; i < 10; i+=2)
		set.erase(i);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> erase_key(ft::set<T, U> set)
{
	std::vector<int> result;
	typename ft::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	for(int i = 0; i < 10; i+=2)
		set.erase(i);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	return (result);
}

template <class T, class U>
std::vector<int> erase_range(std::set<T, U> set)
{
	std::vector<int> result;
	typename std::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	iter = set.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	set.erase(set.begin(), iter);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	set.erase(set.begin(), set.end());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> erase_range(ft::set<T, U> set)
{
	std::vector<int> result;
	typename ft::set<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		set.insert(i);
	iter = set.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	set.erase(set.begin(), iter);
	result.push_back(set.size());
	for (iter = set.begin(); iter != set.end(); iter++)
		result.push_back(*iter);
	set.erase(set.begin(), set.end());
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> swap(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		set.insert(i);
	std::set<T, U> mp2;
	for (int i = 250, j = 0; i < 350; ++i, --j)
		set.insert(i);
	set.swap(mp2);
	result.push_back(mp2.size());
	typename std::set<T, U>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it)
		result.push_back(*it);
	std::swap(set, mp2);
	typename std::set<T, U>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
		result.push_back(*it2);
	return (result);
}

template <class T, class U>
std::vector<int> swap(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 2500; ++i)
		set.insert(i);
	ft::set<T, U> mp2;
	for (int i = 250; i < 350; ++i)
		set.insert(i);
	set.swap(mp2);
	result.push_back(mp2.size());
	typename ft::set<T, U>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it)
		result.push_back(*it);
	ft::swap(set, mp2);
	typename ft::set<T, U>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
		result.push_back(*it2);
	return (result);
}

template <class T, class U>
std::vector<int> clear(std::set<T, U> set)
{
	std::vector<int> result;

	result.push_back(set.size());
	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		set.insert(i);
	set.clear();
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> clear(ft::set<T, U> set)
{
	std::vector<int> result;

	result.push_back(set.size());
	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		set.insert(i);
	set.clear();
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> find(std::set<T, U> set)
{
	std::vector<int> result;
	typename std::set<T, U>::iterator iter;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		set.insert(i);
	result.push_back(*set.find(0));
	result.push_back(*set.find(40));
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> find(ft::set<T, U> set)
{
	std::vector<int> result;
	typename ft::set<T, U>::iterator iter;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		set.insert(i);
	result.push_back(*set.find(0));
	result.push_back(*set.find(40));
	result.push_back(set.size());
	return (result);
}

template <class T, class U>
std::vector<int> lower_bound(std::set<T, U> set)
{
	std::vector<int> result;

	set.insert(10);
	if (set.lower_bound(11) == set.end())
		result.push_back(1);
	if (set.lower_bound(1) == set.end())
		result.push_back(1);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	set.insert(50);
	set.insert(60);
	std::set<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = set.lower_bound(i);
		result.push_back(*it);
	}
	return (result);
}

template <class T, class U>
std::vector<int> lower_bound(ft::set<T, U> set)
{
	std::vector<int> result;

	set.insert(10);
	if (set.lower_bound(11) == set.end())
		result.push_back(1);
	if (set.lower_bound(1) == set.end())
		result.push_back(1);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	set.insert(50);
	set.insert(60);
	ft::set<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = set.lower_bound(i);
		result.push_back(*it);
	}
	return (result);
}

template <class T, class U>
std::vector<int> upper_bound(std::set<T, U> set)
{
	std::vector<int> result;

	set.insert(10);
	if (set.upper_bound(11) == set.end())
		result.push_back(1);
	if (set.upper_bound(1) == set.end())
		result.push_back(1);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	set.insert(50);
	set.insert(60);
	std::set<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = set.upper_bound(i);
		result.push_back(*it);
	}
	return (result);
}

template <class T, class U>
std::vector<int> upper_bound(ft::set<T, U> set)
{
	std::vector<int> result;

	set.insert(10);
	if (set.upper_bound(11) == set.end())
		result.push_back(1);
	if (set.upper_bound(1) == set.end())
		result.push_back(1);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	set.insert(50);
	set.insert(60);
	ft::set<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = set.upper_bound(i);
		result.push_back(*it);
	}
	return (result);
}

template <class T, class U>
std::vector<int> equal_range(std::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i+=10)
		set.insert(i);
	const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair = set.equal_range(10);
	const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair2 = set.equal_range(11);
	const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& pair3 = set.equal_range(1);
	result.push_back(*pair.first);
	result.push_back(*pair.second);
	result.push_back(*pair2.first);
	result.push_back(*pair2.second);
	result.push_back(*pair3.first);
	result.push_back(*pair3.second);
	return (result);
}

template <class T, class U>
std::vector<int> equal_range(ft::set<T, U> set)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i+=10)
		set.insert(i);
	const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& pair = set.equal_range(10);
	const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& pair2 = set.equal_range(11);
	const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& pair3 = set.equal_range(1);
	result.push_back(*pair.first);
	result.push_back(*pair.second);
	result.push_back(*pair2.first);
	result.push_back(*pair2.second);
	result.push_back(*pair3.first);
	result.push_back(*pair3.second);
	return (result);
}

template <class T, class U>
std::vector<int> operators(std::set<T, U> set)
{
	std::vector<int> result;
	std::set<T, U> buff;

	for (int i = 0; i < 1000; i++)
	{
		set.insert(i);
		buff.insert(i);
	}
	result.push_back(set == buff);
	set.insert(123);
	result.push_back(set == buff);
	result.push_back(set > buff);
	result.push_back(set < buff);
	buff.erase(--buff.end());
	result.push_back(set >= buff);
	result.push_back(set <= buff);
	return (result);
}

template <class T, class U>
std::vector<int> operators(ft::set<T, U> set)
{
	std::vector<int> result;
	ft::set<T, U> buff;

	for (int i = 0; i < 1000; i++)
	{
		set.insert(i);
		buff.insert(i);
	}
	result.push_back(set == buff);
	set.insert(123);
	result.push_back(set == buff);
	result.push_back(set > buff);
	result.push_back(set < buff);
	buff.erase(--buff.end());
	result.push_back(set >= buff);
	result.push_back(set <= buff);
	return (result);
}

template<class T>
void test( std::vector<int> (func1)(std::set<T>), std::vector<int> (func2)(ft::set<T>), std::string name_func)
{
	std::set<T> orig;
	ft::set<T> my;
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

void start_set()
{
	std::cout <<  "\x1B[1;33m" << "Set tests starts" << "\033[0m" << std::endl;
	test<int>(constructor_range, constructor_range, "constructor(range)");
	test<int>(constructor_copy_assign, constructor_copy_assign, "constructor (copy, assign)");
	test<int>(begin, begin, "begin");
	test<int>(end, end, "end");
	test<int>(rbegin, rbegin, "rbegin");
	test<int>(rend, rend, "rend");
	test<int>(empty_size, empty_size, "empty and size");
	test<int>(insert_val, insert_val, "insert(val)");
	test<int>(insert_iter, insert_iter, "insert(iter)");
	test<int>(insert_range, insert_range, "insert_range");
	test<int>(erase_iter, erase_iter, "erase(iter)");
	test<int>(erase_key, erase_key, "erase(key)");
	test<int>(erase_range, erase_range, "erase(range)");
	test<int>(swap, swap, "swap");
	test<int>(clear, clear, "clear");
	test<int>(find, find, "find");
	test<int>(lower_bound, lower_bound, "lower_bound");
	test<int>(upper_bound, upper_bound, "upper_bound");
	test<int>(equal_range, equal_range, "equal_range");
	test<int>(operators, operators, "operators");
}

