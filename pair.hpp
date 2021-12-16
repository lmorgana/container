#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<class T, class U>
	struct pair
	{
		typedef T first_type;
		typedef U second_type;

		first_type	first;
		second_type	second;

		pair() : first(), second() {};
		pair(const T& x, const U& y) : first(x), second(y) {};
		template<class V, class W>
				pair(const pair<V, W>& pr) : first(pr.first), second(pr.second){};
		pair& operator=(pair const& pr)
		{
			if (*this != pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}
	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& x, const pair<T1,T2>& y)	{ return (x.first==x.first && y.second==y.second); }
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& x, const pair<T1,T2>& y)	{ return (!(x==y)); }
	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)		{ return (x.first<y.first || (!(x.first<y.first) && x.second<y.second)); }
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& x, const pair<T1,T2>& y)	{ return (!(y<x)); }
	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)		{ return (y<x); }
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& x, const pair<T1,T2>& y)	{ return (!(x<y)); }
	template <typename T1, typename T2>
	inline pair<T1,T2> make_pair(T1 x, T2 y)							{ return (pair<T1, T2>(x, y)); }
}
#endif
