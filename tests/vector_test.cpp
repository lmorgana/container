
#include "test_utils.h"

template <class T>
std::vector<int> copy_constructor(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	std::vector<T> orig2(vector);
	for (int i = 0; i < 1000; i+=10)
		result.push_back(orig2[i]);
	result.push_back(orig2.size());
	return (result);
}

template <class T>
std::vector<int> copy_constructor(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	ft::vector<T> orig2(vector);
	for (int i = 0; i < 1000; i+=10)
		result.push_back(orig2[i]);
	result.push_back(orig2.size());
	return (result);
}

template <class T>
std::vector<int> assign_operator(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	std::vector<T> orig2;
	orig2 = vector;
	for (int i = 0; i < 1000; i+=10)
		result.push_back(orig2[i]);
	result.push_back(orig2.size());
	return (result);
}

template <class T>
std::vector<int> assign_operator(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	ft::vector<T> orig2;
	orig2 = vector;
	for (int i = 0; i < 1000; i+=10)
		result.push_back(orig2[i]);
	result.push_back(orig2.size());
	return (result);
}

template <class T>
std::vector<int> begin(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename std::vector<T>::iterator iter = vector.begin();
	result.push_back(*iter);
	iter++;
	iter++;
	iter++;
	iter++;
	result.push_back(*iter);
	++iter;
	++iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> begin(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename ft::vector<T>::iterator iter = vector.begin();
	result.push_back(*iter);
	iter++;
	iter++;
	iter++;
	iter++;
	result.push_back(*iter);
	++iter;
	++iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> end(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename std::vector<T>::iterator iter = vector.end();
	result.push_back(*iter);
	iter--;
	iter--;
	iter--;
	iter--;
	result.push_back(*iter);
	--iter;
	--iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> end(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename ft::vector<T>::iterator iter = vector.end();
	result.push_back(*iter);
	iter--;
	iter--;
	iter--;
	iter--;
	result.push_back(*iter);
	--iter;
	--iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> rbegin(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename std::vector<T>::iterator iter = vector.begin();
	result.push_back(*iter);
	iter++;
	iter++;
	iter++;
	iter++;
	result.push_back(*iter);
	++iter;
	++iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> rbegin(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename ft::vector<T>::iterator iter = vector.begin();
	result.push_back(*iter);
	iter++;
	iter++;
	iter++;
	iter++;
	result.push_back(*iter);
	++iter;
	++iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> rend(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename std::vector<T>::iterator iter = vector.end();
	result.push_back(*iter);
	iter--;
	iter--;
	iter--;
	iter--;
	result.push_back(*iter);
	--iter;
	--iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> rend(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	typename ft::vector<T>::iterator iter = vector.end();
	result.push_back(*iter);
	iter--;
	iter--;
	iter--;
	iter--;
	result.push_back(*iter);
	--iter;
	--iter;
	++iter;
	++iter;
	--iter;
	result.push_back(*iter);
	return (result);
}

template <class T>
std::vector<int> size(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int> buff;

	result.push_back(vector.size());
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.size());
	vector.push_back(12);
	result.push_back(vector.size());
	buff = vector;
	result.push_back(buff.size());
	return (result);
}

template <class T>
std::vector<int> size(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int> buff;

	result.push_back(vector.size());
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.size());
	vector.push_back(12);
	result.push_back(vector.size());
	buff = vector;
	result.push_back(buff.size());
	return (result);
}

template <class T>
std::vector<int> resize(std::vector<T> vector)
{
	std::vector<int> result;

	vector.resize(2);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	vector.resize(123);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.resize(1230);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.resize(1230);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> resize(ft::vector<T> vector)
{
	std::vector<int> result;

	vector.resize(2);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	vector.resize(123);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.resize(1230);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.resize(1230);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> cap_empty(std::vector<T> vector)
{
	std::vector<int> result;

	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.push_back(2);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		result.push_back(vector.capacity());
	}
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.resize(1230);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	return (result);
}

template <class T>
std::vector<int> cap_empty(ft::vector<T> vector)
{
	std::vector<int> result;

	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.push_back(2);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		result.push_back(vector.capacity());
	}
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.resize(1230);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	return (result);
}

template <class T>
std::vector<int> reserve(std::vector<T> vector)
{
	std::vector<int> result;

	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.push_back(1);
	vector.push_back(2);
	vector.reserve(1);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		result.push_back(vector.capacity());
	}
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.reserve(111);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.reserve(2000);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	return (result);
}

template <class T>
std::vector<int> reserve(ft::vector<T> vector)
{
	std::vector<int> result;

	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.push_back(1);
	vector.push_back(2);
	vector.reserve(1);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		result.push_back(vector.capacity());
	}
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.reserve(111);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	vector.reserve(2000);
	result.push_back(vector.capacity());
	result.push_back(vector.empty());
	return (result);
}

template <class T>
std::vector<int> sc(std::vector<T> vector)
{
	std::vector<int> result;

	vector.reserve(444);
	result.push_back(555);
	result.push_back(vector.capacity());
	result.push_back(vector.capacity());
	result.push_back(vector.size());
	return (result);
}

template <class T>
std::vector<int> sc(ft::vector<T> vector)
{
	std::vector<int> result;

	vector.reserve(444);
	result.push_back(555);
	result.push_back(vector.capacity());
	result.push_back(vector.capacity());
	result.push_back(vector.size());
	return (result);
}

template <class T>
std::vector<int> at(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.at(12));
	result.push_back(vector.at(999));
	return (result);
}

template <class T>
std::vector<int> at(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.at(12));
	result.push_back(vector.at(999));
	return (result);
}

template <class T>
std::vector<int> front(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.front());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> front(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.front());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> back(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.back());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> back(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector.back());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> assign(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<T>	buff, buff2, buff3;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff2.push_back(i*2);
		buff3.push_back(i*3);
	}
	buff.assign(vector.begin(), vector.end());
	for (int i = 0; i < 1000; i += 10)
		result.push_back(i);
	result.push_back(buff.size());
	buff2.assign(12, 200);
	result.push_back(buff.size());
	result.push_back(buff.capacity());
	buff3.assign(1200, 1200);
	result.push_back(buff.size());
	result.push_back(buff.capacity());
	return (result);
}

template <class T>
std::vector<int> assign(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<T>	buff, buff2, buff3;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff2.push_back(i*2);
		buff3.push_back(i*3);
	}
	buff.assign(vector.begin(), vector.end());
	for (int i = 0; i < 1000; i += 10)
		result.push_back(i);
	result.push_back(buff.size());
	buff2.assign(12, 200);
	result.push_back(buff.size());
	result.push_back(buff.capacity());
	buff3.assign(1200, 1200);
	result.push_back(buff.size());
	result.push_back(buff.capacity());
	return (result);
}

template <class T>
std::vector<int> pop_back(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 10; i++)
		vector.push_back(i);
	vector.pop_back();
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.pop_back();
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> pop_back(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 10; i++)
		vector.push_back(i);
	vector.pop_back();
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.pop_back();
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_iter(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, 12);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.insert(iter, 12);
	result.push_back(*iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter++;
	iter++;
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_iter(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, 12);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.insert(iter, 12);
	result.push_back(*iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter++;
	iter++;
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_val(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, 12, 20);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.insert(iter, 1, 12);
	iter = vector.begin();
	result.push_back(*iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter++;
	iter++;
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_val(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, 12, 20);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.insert(iter, 1, 12);
	iter = vector.begin();
	result.push_back(*iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter++;
	iter++;
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i++)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_range(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int>::iterator iter;
	std::vector<int> buff;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff.push_back(i);
	}
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, buff.begin(), buff.end());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.begin();
	vector.insert(iter, iter, iter+5);
	for (size_t i = 0; i < vector.size(); i += 50)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> insert_range(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int>::iterator iter;
	ft::vector<int> buff;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff.push_back(i);
	}
	iter = vector.begin();
	iter++;
	iter++;
	vector.insert(iter, buff.begin(), buff.end());
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.begin();
	vector.insert(iter, iter, iter+5);
	for (size_t i = 0; i < vector.size(); i += 50)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> erase(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.erase(iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.begin();
	vector.erase(iter, vector.end()-5);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i += 50)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> erase(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int>::iterator iter;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	iter = vector.begin();
	iter++;
	iter++;
	vector.erase(iter);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	iter = vector.begin();
	vector.erase(iter, vector.end()-5);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	for (size_t i = 0; i < vector.size(); i += 50)
		result.push_back(vector[i]);
	return (result);
}

template <class T>
std::vector<int> swap(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<int> tmp(50000, 5), tmp2(100000, 10), tmp3(150000, 15), tmp4(300000, 30);

	vector.assign(110000, 11);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.swap(tmp3);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	std::swap(vector, tmp2);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	std::swap(vector, tmp4);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> swap(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<int> tmp(50000, 5), tmp2(100000, 10), tmp3(150000, 15), tmp4(300000, 30);

	vector.assign(110000, 11);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.swap(tmp3);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	ft::swap(vector, tmp2);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	ft::swap(vector, tmp4);
	result.push_back(vector[2]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> clear(std::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector[1]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.clear();
	result.push_back(vector[1]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> clear(ft::vector<T> vector)
{
	std::vector<int> result;

	for (int i = 0; i < 1000; i++)
		vector.push_back(i);
	result.push_back(vector[1]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	vector.clear();
	result.push_back(vector[1]);
	result.push_back(vector.size());
	result.push_back(vector.capacity());
	return (result);
}

template <class T>
std::vector<int> operators(std::vector<T> vector)
{
	std::vector<int> result;
	std::vector<T> buff;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff.push_back(i);
	}
	result.push_back(vector == buff);
	vector.push_back(123);
	result.push_back(vector == buff);
	result.push_back(vector > buff);
	result.push_back(vector < buff);
	buff.pop_back();
	result.push_back(vector >= buff);
	result.push_back(vector <= buff);
	return (result);
}

template <class T>
std::vector<int> operators(ft::vector<T> vector)
{
	std::vector<int> result;
	ft::vector<T> buff;

	for (int i = 0; i < 1000; i++)
	{
		vector.push_back(i);
		buff.push_back(i);
	}
	result.push_back(vector == buff);
	vector.push_back(123);
	result.push_back(vector == buff);
	result.push_back(vector > buff);
	result.push_back(vector < buff);
	buff.pop_back();
	result.push_back(vector >= buff);
	result.push_back(vector <= buff);
	return (result);
}

template<class T>
void test( std::vector<int> (func1)(std::vector<T>), std::vector<int> (func2)(ft::vector<T>), std::string name_func)
{
	std::vector<T> orig;
	ft::vector<T> my;
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

void start_vec()
{
	std::cout <<  "\x1B[1;33m" << "Vector tests starts" << "\033[0m" << std::endl;
	test<int>(copy_constructor, copy_constructor, "copy constructor");
	test<int>(assign_operator, assign_operator, "assign_operator");
	test<int>(begin, begin, "begin");
	test<int>(end, end, "end");
	test<int>(rbegin, rbegin, "rbegin");
	test<int>(rend, rend, "rend");
	test<int>(size, size, "size");
	test<int>(resize, resize, "resize");
	test<int>(cap_empty, cap_empty, "capacity and empty");
	test<int>(reserve, reserve, "reserve");
	test<int>(sc, sc, "[]");
	test<int>(at, at, "at");
	test<int>(front, front, "front");
	test<int>(back, back, "back");
	test<int>(assign, assign, "assign");
	test<int>(pop_back, pop_back, "pop_back");
	test<int>(insert_iter, insert_iter, "insert(iter)");
	test<int>(insert_val, insert_val, "insert(val)");
	test<int>(insert_range, insert_range, "insert(range)");
	test<int>(erase, erase, "erase");
	test<int>(swap, swap, "swap");
	test<int>(clear, clear, "clear");
	test<int>(operators, operators, "operators");
}
