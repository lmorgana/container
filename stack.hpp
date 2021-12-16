#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef std::size_t	size_type;

	protected:
		container_type container;

	public:
		explicit stack (const container_type& ctnr = container_type()) : container(ctnr) {};

		bool empty() const {return (container.empty());};
		size_type size() const {return (container.size());};
		value_type& top() {return (container.back());};
		const value_type& top() const {return (container.back());};
		void push (const value_type& val) {container.push_back(val);};
		void pop() {container.pop_back();};


		friend bool operator==(const stack &lhs, const stack &rhs) 				{ return lhs.container == rhs.container; };
		friend bool operator!=(const stack &lhs, const stack &rhs) 				{ return lhs.container != rhs.container; };
		friend bool operator<=(const stack &lhs, const stack &rhs) 				{ return lhs.container <= rhs.container; };
		friend bool operator>=(const stack &lhs, const stack &rhs) 				{ return lhs.container >= rhs.container; };
		friend bool operator<(const stack &lhs, const stack &rhs) 				{ return lhs.container < rhs.container; };
		friend bool operator>(const stack &lhs, const stack &rhs) 				{ return lhs.container > rhs.container; };
	};
}

#endif
