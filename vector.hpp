#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterators.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include <iostream>

#include "enable_if.hpp"

namespace ft
{



template <class T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef	T															value_type;
	typedef Alloc														allocator_type;
	typedef	typename allocator_type::reference							reference;
	typedef	typename allocator_type::const_reference					const_reference;
	typedef	typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef vector_iterator<value_type>									iterator;
	typedef const_vector_iterator<value_type>							const_iterator;
	typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef typename allocator_type::size_type							size_type;

private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_end_capacity;

public:
	explicit vector(const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_start(nullptr),
		_end(nullptr),
		_end_capacity(nullptr)
	{};

	//need to catch exception when constructor fail;
	//because can be leaks=

	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
		_alloc(alloc)
	{
		_start = _alloc.allocate(n);
		_end = _start;
		_end_capacity = _start + n;
		while (n--)
		{
			_alloc.construct(_end, val);
			_end++;
		}
	};

	//need to make InputIterator
	template<class InputIterator>
	vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::stat, void>::type* = 0) :
		_alloc(alloc)
	{
		difference_type n = ft::distance(first, last);
//		if (n > max_size())
//			throw std::exception(); // make some exception;
		_start = _alloc.allocate(n);
		_end = _start + n;
		_end_capacity = _start + n;
		for (pointer i = _start; first != last; first++, i++)
			_alloc.construct(i, *first);
	};

	//need to make insert or other function to add range of elements
	vector(const vector& x)
	{
		iterator	first = x.begin();
		iterator	last = x.end();
		size_type	new_len = x.size();
		int			index = 0;

		_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
		_end_capacity = _start + new_len;
		while (first != last)
		{
			_alloc.construct(_start + index, *first);
			first++;
			index++;
		}
		_end = _start + index;
	}

	~vector()
	{
		size_type capacity = this->capacity();

		clear();
		_alloc.deallocate(_start, capacity); // maybe has leaks
	};

	vector& operator= (const vector& x) //maybe need to be rewrite
	{
		size_type	n = x.size();
		size_type	old_len = _end_capacity - _start;
		size_type	new_len = _end - _start + n;
		iterator	it_begin = x.begin();
		iterator	it_end= x.end();
		int 		index = 0;


		if (old_len < new_len)
		{
			clear();
			_alloc.deallocate(_start, old_len);
			new_len = old_len * 2 > new_len ? old_len * 2 : new_len;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end_capacity = _start + new_len;
			while (it_begin != it_end)
			{
				_alloc.construct(_start + index, *it_begin);
				index++;
				it_begin++;
			}
			_end = _start + index;
		}
		else
		{
			while (it_begin != it_end)
			{
				*(_start + index) = *it_begin;
				index++;
				it_begin++;
			}
			_end = _start + index;
		}
		return (*this);
	};

	// my own methods
	void	my_copy (pointer begin, pointer end, pointer start_position)
	{
		while (begin != end)
		{
			_alloc.construct(start_position, *begin);
			_alloc.destroy(begin);
			begin++;
			start_position++;
		}
	}

	void	my_copyR (pointer begin, pointer end, pointer start_position)
	{
		end--;
		start_position += (end - begin);
		while (begin <= end)
		{
			_alloc.construct(start_position, *end);
			_alloc.destroy(end);
			end--;
			start_position--;
		}
	}

	iterator insert (iterator position, const value_type& val)
	{
		size_type	index = ft::distance(begin(), position);

		insert(position, 1, val);

		return (_start + index);
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		size_type	index = ft::distance(begin(), position);
		size_type	old_cap = _end_capacity - _start;
		size_type	old_size = _end - _start;
		size_type	new_len = old_size + n;

		if (old_cap < new_len)
		{
			pointer old_start = _start;
			new_len = old_cap * 2 > new_len ? old_cap * 2 : new_len;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end_capacity = _start + new_len;
			my_copy(old_start, old_start + index, _start);
			for (size_type i = 0; i < n; i++, index++)
				_alloc.construct(_start + index, val);
			my_copy(old_start + index - n, old_start + old_size, _start + index);
			_alloc.deallocate(old_start, old_cap);
			_end = _start + old_size + n;
		}
		else
		{
			my_copyR(_start + index, _end, _start + index + n);
			for (size_type i = 0; i < n; i++, index++)
				_alloc.construct(_start + index, val);
			_end = _start + old_size + n;
		}
	}

	template <class InputIterator>
	bool _valid_iter(InputIterator first, InputIterator last, size_type range)
	{
		pointer		reserved_buffer = _alloc.allocate(range);
		bool		result = true;
		size_t		i = 0;

		for (;first != last; ++first, ++i)
		{
			try{ reserved_buffer[i] = *first; }
			catch (...) { result = false; break; }
		}
		_alloc.deallocate(reserved_buffer, range);
		return result;
	}

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::stat, void>::type
	insert (iterator position, InputIterator first, InputIterator last)
	{
		size_type	n = ft::distance(first, last);
		size_type	index = ft::distance(begin(), position);
		size_type	old_cap = _end_capacity - _start;
		size_type	old_size = _end - _start;
		size_type	new_len = old_size + n;
		pointer		old_start = _start;

		if (!_valid_iter(first, last, n))
			throw std::exception();

		if (old_cap < new_len)
		{
			pointer	buff = _alloc.allocate(n);

			new_len = old_cap * 2 > new_len ? old_cap * 2 : new_len;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end_capacity = _start + new_len;
			my_copy(old_start, old_start + index, _start);
			while (first != last)
			{
				_alloc.construct(_start + index, buff[index]);
				first++;
				index++;
			}
			my_copy(old_start + index - n, old_start + old_size, _start + index);
			_alloc.deallocate(old_start, old_cap);
			_end = _start + old_size + n;
			for (size_type i = 0; i < index; i++)
				_alloc.destroy(buff + i);
			_alloc.deallocate(buff, index);
		}
		else
		{
			my_copyR(_start + index, _end, _start + index + n);
			while (first != last)
			{
				_alloc.construct(_start + index, *first);
				first++;
				index++;
			}
			_end = _start + old_size + n;
		}
	}

	size_type size() const
	{
		return (_end - _start);
	};

	size_type max_size() const
	{
		return (_alloc.max_size());
	};

	void resize(size_type n, value_type val = value_type())
	{
		size_type	size = this->size();

		if (n > this->max_size())
			throw std::exception ();
		if (n < size)
		{
			while (size > n)
			{
				_alloc.destroy(_end);
				size--;
				_end--;
			}
		}
		else
			insert(end(), n - size, val);
	};

	size_type capacity() const
	{
		return (_end_capacity - _start);
	};

	bool empty() const
	{
		return (_start == _end);
	};

	void	reserve(size_type n)
	{
		size_type	old_len = _end_capacity - _start;

		if (old_len < n)
		{
			pointer old_start = _start;
			size_type new_len = old_len * 2 > n ? old_len * 2 : n;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end = _start + old_len;
			_end_capacity = _start + new_len;
			for (size_type i = 0; i < old_len; i++)
			{
				_alloc.construct(_start + i, *(old_start + i));
				_alloc.destroy(old_start + i);
			}
			_alloc.deallocate(old_start, old_len);
		}
	}

	reference operator[](size_type n) {return (*(_start + n));};
	const_reference operator[](size_type n) const {return (*(_start + n));};

//	reference at(size_type n)
//	{
//		if (n >= 0 && n < this->size())
//			return (*(_start + n));
//		else
//			throw std::exception();
//	};

	const_reference at (size_type n) const
	{
		if (n >= 0 && n < this->size())
			return (*(_start + n));
		else
			throw std::exception();
	}

	reference front() {return (*_start);};
	const_reference front() const {return (*_start);};

	reference back() {return (*(_end - 1));};
	const_reference back() const {return (*(_end - 1));};

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::stat, void>::type
	assign (InputIterator first, InputIterator last)
	{
		this->clear();
		size_type	old_len = _end_capacity - _start;
		size_type	new_len = ft::distance(first, last);

		if (old_len < new_len)
		{
			_alloc.deallocate(_start, old_len);
			new_len = old_len * 2 > new_len ? old_len * 2 : new_len;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end_capacity = _start + new_len;
			for (int i = 0; first != last; i++, first++)
				_alloc.construct(_start + i, *first);
			_end = _start + new_len;
		}
		else
		{
			for (int i = 0; first != last; i++, first++)
				_alloc.construct(_start + i, *first);
			_end = _start + new_len;
		}
	};
	void assign (size_type n, const value_type& val)
	{
		this->clear();
		size_type	old_len = _end_capacity - _start;

		if (old_len < n)
		{
			n = old_len * 2 > n ? old_len * 2 : n;
			_alloc.deallocate(_start, old_len);
			_start = _alloc.allocate(n); //maybe need to know if new_len > max_size
			_end_capacity = _start + n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_start + i, val);
			_end = _start + n;
		}
		else
		{
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_start + i, val);
			_end = _start + n;
		}
	};

	void push_back (const value_type& val)
	{
		size_type	old_cap = _end_capacity - _start;
		size_type	old_size = _end - _start;
		size_type	new_len = old_size + 1;

		if (old_cap < new_len)
		{
			pointer old_start = _start;
			new_len = old_cap * 2 > new_len ? old_cap * 2 : new_len;
			_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
			_end_capacity = _start + new_len;
			my_copy(old_start, old_start + old_size, _start);
			_alloc.construct(_start + old_size, val);
			_alloc.deallocate(old_start, old_cap);
			_end = _start + old_size + 1;
		}
		else
		{
			_alloc.construct(_start + old_size, val);
			_end = _start + old_size + 1;
		}
	};
	void pop_back() {resize(size() - 1);};

	pointer for_erase(iterator position, size_type n) //нужно спрятать
	{
		int 		index = ft::distance(begin(), position);
		pointer	point = _start + index;


		 for (size_type i = 0; i < n; i++)
			 _alloc.destroy(point + i);
		my_copy(_start + index + n, _end, point);
		_end -= n;
		return (point);
	}

	iterator erase (iterator position)
	{
		return (iterator(for_erase(position, 1)));
	};

	iterator erase (iterator first, iterator last)
	{
		size_type	len = ft::distance(first, last);
		return (for_erase(first, len));
	};

	void swap(const vector& x)
	{
		if (this != &x)
		{
			std::swap(_start, x._start);
			std::swap(_end, x._end);
			std::swap(_end_capacity, x._end_capacity);
		}
	}

	void clear()
	{
		size_type size = this->size();
		for (size_type i = 0; i < size; i++)
			_alloc.destroy(_end + i);
		_end = _start;
	}

	allocator_type get_allocator() const
	{
		return (_alloc);
	}

//	const_iterator begin() const
//	{
//		return (const_iterator(_start));
//	}

	iterator begin() const
	{
		return (iterator(_start));
	}

//	const_iterator end() const
//	{
//		return (const_iterator(_end));
//	}

	iterator end() const
	{
		return (iterator(_end));
	}

//	const_reverse_iterator rbegin() const
//	{
//		return (const_reverse_iterator(end()));
//	}

	reverse_iterator rbegin() const
	{
		return (reverse_iterator(end()));
	}

//	const_reverse_iterator rend() const
//	{
//		return (const_reverse_iterator(begin()));
//	}

	reverse_iterator rend() const
	{
		return (reverse_iterator(begin()));
	}
};
	typedef	std::size_t		size_type;

	template <typename T, typename Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{return (lhs.size() != rhs.size() ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template <typename T, typename Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs == rhs); }

	template <typename T, typename Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <typename T, typename Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(rhs < lhs)); }

	template <typename T, typename Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)		{ return (rhs < lhs); }

	template <typename T, typename Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return (!(lhs < rhs)); }

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)							{ x.swap(y); }
}
#endif
