#ifndef ITERATORS_HPP
#define ITERATORS_HPP

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
		typedef random_access_iterator_tag	iterator_category;

		typedef T 							value_type;

		typedef ptrdiff_t 					difference_type;

		typedef T*							pointer;

		typedef T&							reference;
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

template <class Tag, class Type>
class base_vector : public ft::iterator<Tag, Type>
		{
		public:
			typedef typename ft::iterator<Tag, Type>::pointer			pointer;
			typedef typename ft::iterator<Tag, Type>::difference_type	difference_type;
			typedef typename ft::iterator<Tag, Type>::reference			reference;

			base_vector(pointer rhs = nullptr) : _ptr(rhs) {};
			base_vector(const base_vector &copy): _ptr(copy._ptr) {}
			~base_vector() {}

		public:
			pointer _ptr;
		};

template<class Type>
		class vector_iterator : public base_vector<random_access_iterator_tag, Type>
				{

				public:
					typedef typename base_vector<random_access_iterator_tag, Type>::pointer pointer;
					typedef typename base_vector<random_access_iterator_tag, Type>::difference_type difference_type;
					typedef typename base_vector<random_access_iterator_tag, Type>::reference reference;
					typedef typename base_vector<random_access_iterator_tag, Type>::value_type value_type;
					typedef typename base_vector<random_access_iterator_tag, Type>::iterator_category iterator_category;

					vector_iterator(Type* rhs = nullptr) : base_vector<random_access_iterator_tag, Type>(rhs) {}
					vector_iterator(const vector_iterator &rhs) : base_vector<random_access_iterator_tag, Type>(rhs._ptr){}
					~vector_iterator() {}

				public:
					vector_iterator& operator=(vector_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
					vector_iterator& operator=(const vector_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
					vector_iterator& operator+=(difference_type rhs) {this->_ptr += rhs; return (*this);}
					vector_iterator& operator-=(difference_type rhs) {return (*this += -rhs);}
					Type& operator*() {return *this->_ptr;}
					Type* operator->() {return this->_ptr;}
					Type& operator[](const int& rhs) const {return this->_ptr[rhs];}

				public:
					vector_iterator& operator++() {++this->_ptr; return *this;}
					vector_iterator& operator--() {--this->_ptr; return *this;}
					vector_iterator operator++(int) {vector_iterator tmp = *this; ++this->_ptr; return (tmp);}
					vector_iterator operator--(int) {vector_iterator tmp = *this; --this->_ptr; return (tmp);}
					friend vector_iterator		operator+(int n, vector_iterator& p)
					{
						p._ptr = p._ptr + n;
						return (p._ptr);
					}

				public:
					vector_iterator operator+(difference_type rhs) const {return vector_iterator(this->_ptr+rhs);}
					vector_iterator operator-(difference_type rhs) const {return vector_iterator(this->_ptr-rhs);}
					friend difference_type	operator- (const vector_iterator& a, const vector_iterator& b)			{ return (a._ptr - b._ptr); }

					bool operator==(const vector_iterator& rhs) {return this->_ptr == rhs._ptr;}
					bool operator!=(const vector_iterator& rhs) {return this->_ptr != rhs._ptr;}
					bool operator>(const vector_iterator& rhs) {return this->_ptr > rhs._ptr;}
					bool operator<(const vector_iterator& rhs) {return this->_ptr < rhs._ptr;}
					bool operator>=(const vector_iterator& rhs) {return this->_ptr >= rhs._ptr;}
					bool operator<=(const vector_iterator& rhs) {return this->_ptr <= rhs._ptr;}
				};

template<class Type>
		class const_vector_iterator : public base_vector<random_access_iterator_tag, Type>
				{
				public:
					typedef typename  base_vector<random_access_iterator_tag, Type>::pointer			pointer;
					typedef typename  base_vector<random_access_iterator_tag, Type>::difference_type	difference_type;
					typedef typename  base_vector<random_access_iterator_tag, Type>::reference			reference;

					const_vector_iterator() {this->_ptr = nullptr;}
					const_vector_iterator(pointer rhs) {this->_ptr = rhs;}
					const_vector_iterator(const const_vector_iterator &rhs) {this->_ptr = rhs._ptr;}
					const_vector_iterator(const vector_iterator<Type> &rhs) {this->_ptr = rhs._ptr;}

				public:
					const const_vector_iterator& operator=(const const_vector_iterator &rhs) {this->_ptr = rhs._ptr; return *this;}
					const_vector_iterator& operator+=(difference_type rhs) {this->_ptr += rhs; return *this;}
					const_vector_iterator& operator-=(difference_type rhs) {this->_ptr += -rhs; return *this;}
					reference operator*() {return *(this->_ptr);}
					Type* operator->() {return this->_ptr;}
					Type& operator[](const int& rhs) const {return this->_ptr[rhs];}

				public:
					const_vector_iterator& operator++() {++this->_ptr; return *this;}
					const_vector_iterator& operator--() {--this->_ptr; return *this;}
					const_vector_iterator operator++(int) {const_vector_iterator tmp = *this; ++this->_ptr; return (tmp);}
					const_vector_iterator operator--(int) {const_vector_iterator tmp = *this; --this->_ptr; return (tmp);}
					friend const_vector_iterator		operator+(int n, const_vector_iterator& p)
					{
						p._ptr = p._ptr + n;
						return (p._ptr);
					}

				public:
					const_vector_iterator operator+(difference_type rhs) const {return const_vector_iterator(this->_ptr+rhs);}
					const_vector_iterator operator-(difference_type rhs) const {return const_vector_iterator(this->_ptr + (-rhs));}
					friend difference_type	operator- (const const_vector_iterator& a, const const_vector_iterator& b) { return (a._ptr - b._ptr); }

					bool operator==(const const_vector_iterator& rhs) {return this->_ptr == rhs._ptr;}
					bool operator!=(const const_vector_iterator& rhs) {return this->_ptr != rhs._ptr;}
					bool operator>(const const_vector_iterator& rhs) {return this->_ptr > rhs._ptr;}
					bool operator<(const const_vector_iterator& rhs) {return this->_ptr < rhs._ptr;}
					bool operator>=(const const_vector_iterator& rhs) {return this->_ptr >= rhs._ptr;}
					bool operator<=(const const_vector_iterator& rhs) {return this->_ptr <= rhs._ptr;}
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
