#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "vector.hpp"

namespace ft
{
	struct input_iterator_tag {};
	class random_access_iterator_tag{};

	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::difference_type       difference_type;

		typedef typename iterator::value_type            value_type;

		typedef typename iterator::pointer               pointer;

		typedef typename iterator::reference             reference;

		typedef typename iterator::iterator_category     iterator_category;
	};

	template<class T>
	struct iterator_traits<T *>
	{
		typedef input_iterator_tag	iterator_category;

		typedef T 					value_type;

		typedef ptrdiff_t 			distance_type;

		typedef T*					pointer;

		typedef T&					reference;
	};

template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
		};

	template<class Type>
	class vector_iterator : public ft::iterator<random_access_iterator_tag, Type>
	{

	public:
		typedef typename ft::iterator<random_access_iterator_tag, Type>::pointer pointer;
		vector_iterator() : _ptr(nullptr) {;}
		vector_iterator(Type* rhs) : _ptr(rhs) {;}
		vector_iterator(const vector_iterator &rhs) : _ptr(rhs._ptr) {;}

	public:
//		vector_iterator& operator=(vector_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		vector_iterator& operator=(const vector_iterator &rhs) {_ptr = rhs._ptr; return *this;}
		vector_iterator& operator+=(const int& rhs) {_ptr += rhs; return *this;}
		vector_iterator& operator-=(const int& rhs) {_ptr -= rhs; return *this;}
		Type& operator*() {return *_ptr;}
		Type* operator->() {return _ptr;}
		Type& operator[](const int& rhs) {return _ptr[rhs];}

	public:
		vector_iterator& operator++() {++_ptr; return *this;}
		vector_iterator& operator--() {--_ptr; return *this;}
		vector_iterator& operator++(int) {++_ptr; return (*this);}
		vector_iterator& operator--(int) {--_ptr; return (*this);}
		vector_iterator operator+(const vector_iterator& rhs) {return vector_iterator(_ptr+rhs.ptr);}
		vector_iterator operator-(const vector_iterator& rhs) {return vector_iterator(_ptr-rhs.ptr);}
		vector_iterator operator+(const int& rhs) {return vector_iterator(_ptr+rhs);}
		vector_iterator operator-(const int& rhs) {return vector_iterator(_ptr-rhs);}
		pointer base() { return  this->_ptr; };

		//            friend inline Iterator operator+(const int& lhs, const Iterator& rhs) {return Iterator(lhs+_ptr);}
		//            friend inline Iterator operator-(const int& lhs, const Iterator& rhs) {return Iterator(lhs-_ptr);}

	public:
		bool operator==(const vector_iterator& rhs) {return _ptr == rhs._ptr;}
		bool operator!=(const vector_iterator& rhs) {return _ptr != rhs._ptr;}
		bool operator>(const vector_iterator& rhs) {return _ptr > rhs._ptr;}
		bool operator<(const vector_iterator& rhs) {return _ptr < rhs._ptr;}
		bool operator>=(const vector_iterator& rhs) {return _ptr >= rhs._ptr;}
		bool operator<=(const vector_iterator& rhs) {return _ptr <= rhs._ptr;}

	protected:
		Type* _ptr;
	};

	template<class Type>
	class const_vector_iterator : public ft::iterator<random_access_iterator_tag, const Type>
	{
	public:
		const_vector_iterator() : _ptr(nullptr) {;}
		const_vector_iterator(Type* rhs) : _ptr(rhs) {;}
		template <class iter111>
			const_vector_iterator(iter111 k){
			this->_ptr = k.base();
		}
		const_vector_iterator(const const_vector_iterator &rhs) : _ptr(rhs._ptr) {;}

	public:
//		const_vector_iterator& operator=(const_vector_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
		const_vector_iterator& operator=(const const_vector_iterator &rhs) {_ptr = rhs._ptr; return *this;}
		const_vector_iterator& operator+=(const int& rhs) {_ptr += rhs; return *this;}
		const_vector_iterator& operator-=(const int& rhs) {_ptr -= rhs; return *this;}
		Type& operator*() {return *_ptr;}
		Type* operator->() {return _ptr;}
		Type& operator[](const int& rhs) {return _ptr[rhs];}

	public:
		const_vector_iterator& operator++() {++_ptr; return *this;}
		const_vector_iterator& operator--() {--_ptr; return *this;}
		const_vector_iterator& operator++(int) {++_ptr; return (*this);}
		const_vector_iterator& operator--(int) {--_ptr; return (*this);}
		const_vector_iterator operator+(const const_vector_iterator& rhs) {return const_vector_iterator(_ptr+rhs.ptr);}
		const_vector_iterator operator-(const const_vector_iterator& rhs) {return const_vector_iterator(_ptr-rhs.ptr);}
		const_vector_iterator operator+(const int& rhs) {return const_vector_iterator(_ptr+rhs);}
		const_vector_iterator operator-(const int& rhs) {return const_vector_iterator(_ptr-rhs);}
		//            friend inline Iterator operator+(const int& lhs, const Iterator& rhs) {return Iterator(lhs+_ptr);}
		//            friend inline Iterator operator-(const int& lhs, const Iterator& rhs) {return Iterator(lhs-_ptr);}

	public:
		bool operator==(const const_vector_iterator& rhs) {return _ptr == rhs._ptr;}
		bool operator!=(const const_vector_iterator& rhs) {return _ptr != rhs._ptr;}
		bool operator>(const const_vector_iterator& rhs) {return _ptr > rhs._ptr;}
		bool operator<(const const_vector_iterator& rhs) {return _ptr < rhs._ptr;}
		bool operator>=(const const_vector_iterator& rhs) {return _ptr >= rhs._ptr;}
		bool operator<=(const const_vector_iterator& rhs) {return _ptr <= rhs._ptr;}

	protected:
		Type* _ptr;
	};



	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
			while (first != last)
			{
				first++;
				rtn++;
			}
			return (rtn);
		}
}

#endif
