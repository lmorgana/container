#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterators.hpp"
#include "random_access_iterator.hpp"

#include "enable_if.hpp"

template <class T, class Alloc = std::allocator<T> >
class Vector
{
public:
	typedef	T															value_type;
	typedef Alloc														allocator_type;
	typedef	typename allocator_type::reference							reference;
	typedef	typename allocator_type::const_reference					const_reference;
	typedef	typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef typename ft::Iterator<value_type>							iterator;
//	typedef	typename ft::random_access_iterator<const value_type>		const_iterator;
//	typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
//	typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
	typedef typename allocator_type::size_type							size_type;

private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_end_capacity;

public:
	explicit Vector(const allocator_type& alloc = allocator_type()) :
		_alloc(alloc),
		_start(nullptr),
		_end(nullptr),
		_end_capacity(nullptr)
	{};

	//need to catch exception when constructor fail;
	//because can be leaks=

	explicit Vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
		_alloc(alloc)
	{
		_start = _alloc.allocate(n);
		_end = _start;
		_end_capacity = _start + n;
		while (n--)
		{
			try
			{
				_alloc.construct(_end, val);
			} catch (...)
			{
				while (_start != _end)
				{
					_alloc.destroy(_start);
					_start++;
				}
				throw std::exception(); // need to change to another exception;
			}
			_end++;
		}
	};

	//need to make InputIterator
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last,
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
//	Vector(const Vector& x)
//	{
//
//	}

	~Vector()
	{
		pointer	buff = _start;

		while (buff != _end)
		{
			_alloc.destroy(buff);
			buff++;
		}
		_alloc.deallocate(_start, this->size());
	};

	Vector& operator= (const Vector& x)
	{
		(void) x;
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
		size_type	old_len = _end_capacity - _start;
		size_type	new_len = _end - _start + n;

		if (old_len < new_len)
		{
			try
			{
				pointer old_start = _start;
				new_len = old_len * 2 > new_len ? old_len * 2 : new_len;
				_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
				_end_capacity = _start + new_len;
				my_copy(old_start, old_start + index, _start);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(_start + index, val);
					index++;
				}
				my_copy(old_start + index - n, old_start + old_len, _start + index);
				_end = _start + old_len + n;
			}
			catch (std::exception e)
			{
				//надо будет исправить если что
				this->~Vector();
				throw e;
			}
		}
		else
		{
			try
			{
				old_len = _end - _start;
				my_copyR(_start + index, _end, _start + index + n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(_start + index, val);
					index++;
				}
				_end = _start + old_len + n;
			}
			catch (std::exception e)
			{
				//надо будет исправить если что
				this->~Vector();
				throw e;
			}
		}
	}

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::stat, void>::type
	insert (iterator position, InputIterator first, InputIterator last)
	{
		size_type	n = ft::distance(first, last);
		size_type	index = ft::distance(begin(), position);
		size_type	old_len = _end_capacity - _start;
		size_type	new_len = _end - _start + n;
		if (old_len < new_len)
		{
			try
			{
				pointer old_start = _start;
				new_len = old_len * 2 > new_len ? old_len * 2 : new_len;
				_start = _alloc.allocate(new_len); //maybe need to know if new_len > max_size
				_end_capacity = _start + new_len;
				my_copy(old_start, old_start + index, _start);
				while (first != last)
				{
					_alloc.construct(_start + index, *first);
					first++;
					index++;
				}
				my_copy(old_start + index - n, old_start + old_len, _start + index);
				_end = _start + old_len + n;
			}
			catch (std::exception e)
			{
				//надо будет исправить если что
				this->~Vector();
				throw e;
			}
		}
		else
		{
			try
			{
				old_len = _end - _start;
				my_copyR(_start + index, _end, _start + index + n);
				while (first != last)
				{
					_alloc.construct(_start + index, *first);
					first++;
					index++;
				}
				_end = _start + old_len + n;
			}
			catch (std::exception e)
			{
				//надо будет исправить если что
				this->~Vector();
				throw e;
			}
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
		size_type	old_len = _end_capacity - _start;

		if (old_len <= n)
		{
			while ()
		}
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
			try
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
			catch (std::exception e)
			{
				//надо будет исправить если что
				this->~Vector();
				throw e;
			}
		}
	}

	reference operator[](size_type n)
	{
		return (*(_start + n));
	};

	const_reference operator[](size_type n) const
	{
		return (*(_start + n));
	};

	reference at(size_type n)
	{
		if (n >= 0 && n < this->size())
			return (*(_start + n));
		else
			throw std::exception(); //make new exception;
	};

	iterator begin()
	{
		return (ft::Iterator<T>(_start));
	}

	iterator end()
	{
		return (ft::Iterator<T>(_end));
	}
//	reference front()
//	{
//		return (_start);
//	};
//
//	const_reference front()
//	{
//		return (_start);
//	};
//
//	reference back()
//	{
//		return (_end);
//	};
//
//	const_reference back()
//	{
//		return (_end);
//	};

};

#endif