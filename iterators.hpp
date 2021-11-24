#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
	struct input_iterator_tag {};
	class random_access_iterator_tag{};

	//this is not my code;
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type       difference_type;

		typedef typename Iterator::value_type            value_type;

		typedef typename Iterator::pointer               pointer;

		typedef typename Iterator::reference             reference;

		typedef typename Iterator::iterator_category     iterator_category;
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

//	template<class C, class T, class Dist = ptrdiff_t,
//	class Pt = T*, class Rt = T&, struct vec_iterator
//	{
//		typedef C iterator_category;
//		typedef T value_type;
//		typedef Dist difference_type;
//		typedef Pt pointer;
//		typedef Rt reference;
//	};
template<class Type>
class Iterator : public std::iterator<random_access_iterator_tag, Type>
		{
	// Lifecycle:
		public:
			Iterator() : _ptr(nullptr) {;}
			Iterator(Type* rhs) : _ptr(rhs) {;}
			Iterator(const Iterator &rhs) : _ptr(rhs._ptr) {;}

			// Operators : misc
		public:
			inline Iterator& operator=(Type* rhs) {_ptr = rhs; return *this;}
			inline Iterator& operator=(const Iterator &rhs) {_ptr = rhs._ptr; return *this;}
			inline Iterator& operator+=(const int& rhs) {_ptr += rhs; return *this;}
			inline Iterator& operator-=(const int& rhs) {_ptr -= rhs; return *this;}
			inline Type& operator*() {return *_ptr;}
			inline Type* operator->() {return _ptr;}
			inline Type& operator[](const int& rhs) {return _ptr[rhs];}

			// Operators : arithmetic
		public:
			inline Iterator& operator++() {++_ptr; return *this;}
			inline Iterator& operator--() {--_ptr; return *this;}
			inline Iterator& operator++(int) {++_ptr; return (*this);}
			inline Iterator& operator--(int) {--_ptr; return (*this);}
			inline Iterator operator+(const Iterator& rhs) {return Iterator(_ptr+rhs.ptr);}
			inline Iterator operator-(const Iterator& rhs) {return Iterator(_ptr-rhs.ptr);}
			inline Iterator operator+(const int& rhs) {return Iterator(_ptr+rhs);}
			inline Iterator operator-(const int& rhs) {return Iterator(_ptr-rhs);}
//			friend inline Iterator operator+(const int& lhs, const Iterator& rhs) {return Iterator(lhs+_ptr);}
//			friend inline Iterator operator-(const int& lhs, const Iterator& rhs) {return Iterator(lhs-_ptr);}

			// Operators : comparison
		public:
			inline bool operator==(const Iterator& rhs) {return _ptr == rhs._ptr;}
			inline bool operator!=(const Iterator& rhs) {return _ptr != rhs._ptr;}
			inline bool operator>(const Iterator& rhs) {return _ptr > rhs._ptr;}
			inline bool operator<(const Iterator& rhs) {return _ptr < rhs._ptr;}
			inline bool operator>=(const Iterator& rhs) {return _ptr >= rhs._ptr;}
			inline bool operator<=(const Iterator& rhs) {return _ptr <= rhs._ptr;}

			// Data members
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
