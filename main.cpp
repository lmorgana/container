
#include "iostream"
//#include "iterators.hpp"
#include <map>
#include "map.hpp"
//#include "tree.hpp"


//iterators doesn't work
int main(void)
{
	std::map<int, int> m;
	ft::map<int, int> p;

	ft::map<int, int>::iterator my = p.end();

	p.insert(ft::make_pair<int, int>(13, 123));

	return (0);
}