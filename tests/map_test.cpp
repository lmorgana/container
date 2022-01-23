
#include "test_utils.h"

template <class T, class U>
std::vector<int> constructor_range(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));

	result.push_back(map.size());
	result.push_back(map[20]);

	std::map<T, U> buff(map.begin(), map.end());

	result.push_back(buff.size());
	result.push_back(buff[20]);
	return (result);
}

template <class T, class U>
std::vector<int> constructor_range(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));

	result.push_back(map.size());
	result.push_back(map[20]);

	ft::map<T, U> buff(map.begin(), map.end());

	result.push_back(buff.size());
	result.push_back(buff[20]);
	return (result);
}

template <class T, class U>
std::vector<int> constructor_copy_assign(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));
	result.push_back(map.size());
	result.push_back(map[20]);

	std::map<T, U> buff(map);
	std::map<T, U> buff1;

	buff1 = buff;
	result.push_back(buff.size());
	result.push_back(buff[20]);
	result.push_back(buff1.size());
	result.push_back(buff1[20]);
	return (result);
}

template <class T, class U>
std::vector<int> constructor_copy_assign(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));
	result.push_back(map.size());
	result.push_back(map[20]);

	ft::map<T, U> buff(map);
	ft::map<T, U> buff1;

	buff1 = buff;
	result.push_back(buff.size());
	result.push_back(buff[20]);
	result.push_back(buff1.size());
	result.push_back(buff1[20]);
	return (result);
}

template <class T, class U>
std::vector<int> begin(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));
	result.push_back((map.begin())->first);
	map.erase((map.begin())->first);
	result.push_back((map.begin())->first);
	result.push_back(map.size());
	result.push_back(map[20]);
	return (result);
}

template <class T, class U>
std::vector<int> begin(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));
	result.push_back((map.begin())->first);
	map.erase((map.begin())->first);
	result.push_back((map.begin())->first);
	result.push_back(map.size());
	result.push_back(map[20]);
	return (result);
}

template <class T, class U>
std::vector<int> end(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));
	typename std::map<T, U>::iterator iter = map.end();
	iter--;
	result.push_back(iter->first);
	map.erase(iter);
	iter = map.end();
	iter--;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> end(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));
	typename ft::map<T, U>::iterator iter = map.end();
	iter--;
	result.push_back(iter->first);
	map.erase(iter);
	iter = map.end();
	iter--;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> rbegin(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));
	typename std::map<T, U>::reverse_iterator iter = map.rbegin();
	iter++;
	result.push_back(iter->first);
	map.erase(iter.base());
	iter = map.rbegin();
	iter++;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> rbegin(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));
	typename ft::map<T, U>::reverse_iterator iter = map.rbegin();
	iter++;
	result.push_back(iter->first);
	map.erase(iter.base());
	iter = map.rbegin();
	iter++;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> rend(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(std::make_pair(i, i*2));
	typename std::map<T, U>::reverse_iterator iter = map.rend();
	iter--;
	result.push_back(iter->first);
	map.erase(iter.base());
	iter = map.rend();
	iter--;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> rend(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, i*2));
	typename ft::map<T, U>::reverse_iterator iter = map.rend();
	iter--;
	result.push_back(iter->first);
	map.erase(iter.base());
	iter = map.rend();
	iter--;
	result.push_back(iter->first);
	return (result);
}

template <class T, class U>
std::vector<int> empty_size(std::map<T, U> map)
{
	std::vector<int> result;

	result.push_back(map.empty());
	result.push_back(map.size());
	for (int i = 0; i < 100; i++)
	{
		map.insert(std::make_pair(i, i*2));
		result.push_back(map.size());
	}
	result.push_back(map.empty());
	result.push_back(map.size());
	map.erase(0);
	map.erase(1);
	map.erase(2);
	map.erase(3);
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> empty_size(ft::map<T, U> map)
{
	std::vector<int> result;

	result.push_back(map.empty());
	result.push_back(map.size());
	for (int i = 0; i < 100; i++)
	{
		map.insert(ft::make_pair(i, i*2));
		result.push_back(map.size());
	}
	result.push_back(map.empty());
	result.push_back(map.size());
	map.erase(0);
	map.erase(1);
	map.erase(2);
	map.erase(3);
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> oper(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	result.push_back(map[1]);
	result.push_back(map[2]);
	return (result);
}

template <class T, class U>
std::vector<int> oper(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	result.push_back(map[1]);
	result.push_back(map[2]);
	return (result);
}

template <class T, class U>
std::vector<int> insert_val(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
	{
		std::pair<typename std::map<T, U>::iterator, U> pr = map.insert(std::make_pair(i, i*2));
		result.push_back(pr.first->first);
		result.push_back(pr.second);
	}
	std::pair<typename std::map<T, U>::iterator, U> pr = map.insert(std::make_pair(0, 0));
	result.push_back(pr.first->first);
	result.push_back(pr.second);
	return (result);
}

template <class T, class U>
std::vector<int> insert_val(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i++)
	{
		ft::pair<typename ft::map<T, U>::iterator, U> pr = map.insert(ft::make_pair(i, i*2));
		result.push_back(pr.first->first);
		result.push_back(pr.second);
	}
	ft::pair<typename ft::map<T, U>::iterator, U> pr = map.insert(ft::make_pair(0, 0));
	result.push_back(pr.first->first);
	result.push_back(pr.second);
	return (result);
}

template <class T, class U>
std::vector<int> insert_iter(std::map<T, U> map)
{
	std::vector<int> result;
	typename std::map<T, U>::iterator iter;
	typename std::map<T, U>::iterator iter2;


	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		iter2 = map.insert(iter, std::make_pair(iter->first*12, iter->first));
		result.push_back(iter2->first);
	}
	result.push_back(map[12]);
	result.push_back(map[25]);
	return (result);
}

template <class T, class U>
std::vector<int> insert_iter(ft::map<T, U> map)
{
	std::vector<int> result;
	typename ft::map<T, U>::iterator iter;
	typename ft::map<T, U>::iterator iter2;


	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		iter2 = map.insert(iter, ft::make_pair(iter->first*12, iter->first));
		result.push_back(iter2->first);
	}
	result.push_back(map[12]);
	result.push_back(map[25]);
	return (result);
}

template <class T, class U>
std::vector<int> insert_range(std::map<T, U> map)
{
	std::vector<int> result;
	std::map<T, U> buff;

	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	result.push_back(map.size());
	buff.insert(map.begin(), map.end());
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> insert_range(ft::map<T, U> map)
{
	std::vector<int> result;
	ft::map<T, U> buff;

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	result.push_back(map.size());
	buff.insert(map.begin(), map.end());
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> erase_iter(std::map<T, U> map)
{
	std::vector<int> result;
	typename std::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	iter = map.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	map.erase(iter);
	result.push_back(map.size());
	iter = map.begin();
	iter++;
	iter++;
	map.erase(iter);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}

	return (result);
}

template <class T, class U>
std::vector<int> erase_iter(ft::map<T, U> map)
{
	std::vector<int> result;
	typename ft::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	iter = map.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	map.erase(iter);
	result.push_back(map.size());
	iter = map.begin();
	iter++;
	iter++;
	map.erase(iter);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}

	return (result);
}

template <class T, class U>
std::vector<int> erase_key(std::map<T, U> map)
{
	std::vector<int> result;
	typename std::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	for(int i = 0; i < 10; i+=2)
		map.erase(i);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}

	return (result);
}

template <class T, class U>
std::vector<int> erase_key(ft::map<T, U> map)
{
	std::vector<int> result;
	typename ft::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	for(int i = 0; i < 10; i+=2)
		map.erase(i);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}

	return (result);
}

template <class T, class U>
std::vector<int> erase_range(std::map<T, U> map)
{
	std::vector<int> result;
	typename std::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(std::make_pair(i, i*2));
	iter = map.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	map.erase(map.begin(), iter);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}
	map.erase(map.begin(), map.end());
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> erase_range(ft::map<T, U> map)
{
	std::vector<int> result;
	typename ft::map<T, U>::iterator iter;

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i*2));
	iter = map.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	map.erase(map.begin(), iter);
	result.push_back(map.size());
	for (iter = map.begin(); iter != map.end(); iter++)
	{
		result.push_back(iter->first);
		result.push_back(iter->second);
	}
	map.erase(map.begin(), map.end());
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> swap(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(std::make_pair(i, j));
	std::map<T, U> mp2;
	for (int i = 250, j = 0; i < 350; ++i, --j)
		map.insert(std::make_pair(i, j));
	map.swap(mp2);
	result.push_back(mp2.size());
	typename std::map<T, U>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it) {
		result.push_back(it->first);
		result.push_back(it->second);
	}
	std::swap(map, mp2);
	typename std::map<T, U>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		result.push_back(it2->first);
		result.push_back(it2->second);
	}
	return (result);
}

template <class T, class U>
std::vector<int> swap(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(ft::make_pair(i, j));
	ft::map<T, U> mp2;
	for (int i = 250, j = 0; i < 350; ++i, --j)
		map.insert(ft::make_pair(i, j));
	map.swap(mp2);
	result.push_back(mp2.size());
	typename ft::map<T, U>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it) {
		result.push_back(it->first);
		result.push_back(it->second);
	}
	ft::swap(map, mp2);
	typename ft::map<T, U>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2) {
		result.push_back(it2->first);
		result.push_back(it2->second);
	}
	return (result);
}

template <class T, class U>
std::vector<int> clear(std::map<T, U> map)
{
	std::vector<int> result;

	result.push_back(map.size());
	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(std::make_pair(i, j));
	map.clear();
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> clear(ft::map<T, U> map)
{
	std::vector<int> result;

	result.push_back(map.size());
	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(ft::make_pair(i, j));
	map.clear();
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> find(std::map<T, U> map)
{
	std::vector<int> result;
	typename std::map<T, U>::iterator iter;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(std::make_pair(i, j));
	result.push_back(map.find(0)->first);
	result.push_back(map.find(40)->first);
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> find(ft::map<T, U> map)
{
	std::vector<int> result;
	typename ft::map<T, U>::iterator iter;

	for (int i = 0, j = 0; i < 2500; ++i, ++j)
		map.insert(ft::make_pair(i, j));
	result.push_back(map.find(0)->first);
	result.push_back(map.find(40)->first);
	result.push_back(map.size());
	return (result);
}

template <class T, class U>
std::vector<int> lower_bound(std::map<T, U> map)
{
	std::vector<int> result;

	map.insert(std::make_pair(10, 10));
	if (map.lower_bound(11) == map.end())
		result.push_back(1);
	if (map.lower_bound(1) == map.end())
		result.push_back(1);
	map.insert(std::make_pair(20, 20));
	map.insert(std::make_pair(30, 30));
	map.insert(std::make_pair(40, 40));
	map.insert(std::make_pair(50, 50));
	map.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = map.lower_bound(i);
		result.push_back(it->first);
	}
	return (result);
}

template <class T, class U>
std::vector<int> lower_bound(ft::map<T, U> map)
{
	std::vector<int> result;

	map.insert(ft::make_pair(10, 10));
	if (map.lower_bound(11) == map.end())
		result.push_back(1);
	if (map.lower_bound(1) == map.end())
		result.push_back(1);
	map.insert(ft::make_pair(20, 20));
	map.insert(ft::make_pair(30, 30));
	map.insert(ft::make_pair(40, 40));
	map.insert(ft::make_pair(50, 50));
	map.insert(ft::make_pair(60, 60));
	ft::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = map.lower_bound(i);
		result.push_back(it->first);
	}
	return (result);
}

template <class T, class U>
std::vector<int> upper_bound(std::map<T, U> map)
{
	std::vector<int> result;

	map.insert(std::make_pair(10, 10));
	if (map.upper_bound(11) == map.end())
		result.push_back(1);
	if (map.upper_bound(1) == map.end())
		result.push_back(1);
	map.insert(std::make_pair(20, 20));
	map.insert(std::make_pair(30, 30));
	map.insert(std::make_pair(40, 40));
	map.insert(std::make_pair(50, 50));
	map.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = map.upper_bound(i);
		result.push_back(it->first);
	}
	return (result);
}

template <class T, class U>
std::vector<int> upper_bound(ft::map<T, U> map)
{
	std::vector<int> result;

	map.insert(ft::make_pair(10, 10));
	if (map.upper_bound(11) == map.end())
		result.push_back(1);
	if (map.upper_bound(1) == map.end())
		result.push_back(1);
	map.insert(ft::make_pair(20, 20));
	map.insert(ft::make_pair(30, 30));
	map.insert(ft::make_pair(40, 40));
	map.insert(ft::make_pair(50, 50));
	map.insert(ft::make_pair(60, 60));
	ft::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = map.upper_bound(i);
		result.push_back(it->first);
	}
	return (result);
}

template <class T, class U>
std::vector<int> equal_range(std::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i+=10)
		map.insert(std::make_pair(i, i));
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair = map.equal_range(10);
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair2 = map.equal_range(11);
	const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair3 = map.equal_range(1);
	result.push_back(pair.first->first);
	result.push_back(pair.first->second);
	result.push_back(pair.second->first);
	result.push_back(pair.second->second);
	result.push_back(pair2.first->first);
	result.push_back(pair2.first->second);
	result.push_back(pair2.second->first);
	result.push_back(pair2.second->second);
	result.push_back(pair3.first->first);
	result.push_back(pair3.first->second);
	result.push_back(pair3.second->first);
	result.push_back(pair3.second->second);
	return (result);
}

template <class T, class U>
std::vector<int> equal_range(ft::map<T, U> map)
{
	std::vector<int> result;

	for (int i = 0; i < 100; i+=10)
		map.insert(ft::make_pair(i, i));
	const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair = map.equal_range(10);
	const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair2 = map.equal_range(11);
	const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair3 = map.equal_range(1);
	result.push_back(pair.first->first);
	result.push_back(pair.first->second);
	result.push_back(pair.second->first);
	result.push_back(pair.second->second);
	result.push_back(pair2.first->first);
	result.push_back(pair2.first->second);
	result.push_back(pair2.second->first);
	result.push_back(pair2.second->second);
	result.push_back(pair3.first->first);
	result.push_back(pair3.first->second);
	result.push_back(pair3.second->first);
	result.push_back(pair3.second->second);
	return (result);
}

template <class T, class U>
std::vector<int> operators(std::map<T, U> map)
{
	std::vector<int> result;
	std::map<T, U> buff;

	for (int i = 0; i < 1000; i++)
	{
		map.insert(std::make_pair(i, i));
		buff.insert(std::make_pair(i, i));
	}
	result.push_back(map == buff);
	map.insert(std::make_pair(123, 123));
	result.push_back(map == buff);
	result.push_back(map > buff);
	result.push_back(map < buff);
	buff.erase(--buff.end());
	result.push_back(map >= buff);
	result.push_back(map <= buff);
	return (result);
}

template <class T, class U>
std::vector<int> operators(ft::map<T, U> map)
{
	std::vector<int> result;
	ft::map<T, U> buff;

	for (int i = 0; i < 1000; i++)
	{
		map.insert(ft::make_pair(i, i));
		buff.insert(ft::make_pair(i, i));
	}
	result.push_back(map == buff);
	map.insert(ft::make_pair(123, 123));
	result.push_back(map == buff);
	result.push_back(map > buff);
	result.push_back(map < buff);
	buff.erase(--buff.end());
	result.push_back(map >= buff);
	result.push_back(map <= buff);
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
	std::cout <<  "\n\x1B[1;33m" << "Map tests starts" << "\033[0m" << std::endl;
	test<int, int>(constructor_range, constructor_range, "constructor(range)");
	test<int, int>(constructor_copy_assign, constructor_copy_assign, "constructor (copy, assign)");
	test<int, int>(begin, begin, "begin");
	test<int, int>(end, end, "end");
	test<int, int>(rbegin, rbegin, "rbegin");
	test<int, int>(rend, rend, "rend");
	test<int, int>(empty_size, empty_size, "empty and size");
	test<int, int>(oper, oper, "operator []");
	test<int, int>(insert_val, insert_val, "insert(val)");
	test<int, int>(insert_iter, insert_iter, "insert(iter)");
	test<int, int>(insert_range, insert_range, "insert_range");
	test<int, int>(erase_iter, erase_iter, "erase(iter)");
	test<int, int>(erase_key, erase_key, "erase(key)");
	test<int, int>(erase_range, erase_range, "erase(range)");
	test<int, int>(swap, swap, "swap");
	test<int, int>(clear, clear, "clear");
	test<int, int>(find, find, "find");
	test<int, int>(lower_bound, lower_bound, "lower_bound");
	test<int, int>(upper_bound, upper_bound, "upper_bound");
	test<int, int>(equal_range, equal_range, "equal_range");
	test<int, int>(operators, operators, "operators");
}
