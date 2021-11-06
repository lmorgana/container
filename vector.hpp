#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

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
//	typedef typename ft::_random_access_iterator<value_type>			iterator;
//	typedef	typename ft::_random_access_iterator<const value_type>		const_iterator;
//	typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
//	typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
//	typedef	typename ft::iterator_traits<iterator>::difference_type>	difference_type;
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

	explicit Vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
		_alloc(alloc)
	{
		_start = _alloc.allocate(n);
		_end = _start;
		_end_capacity = _start + n;
		while (n--)
		{
			alloc.construct(_end, val);
			_end++;
		}
	};

	//need to make InputIterator
//	template<class InputIterator>
//	Vector(InputIterator first, InputIterator last,
//			const allocator_type& alloc = allocator_type()) :
//		_alloc(alloc)
//	{
//		difference_type n = ft::distance(first, last);
//		_start = _alloc.allocate(n);
//		_end = _start;
//		_end_capacity = start + n;
//		while (n--)
//		{
//			alloc.construct(_end, val);
//			_end++;
//		}
//	};

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

	size_type size() const
	{
		return (_end - _start);
	};

	size_type max_size() const
	{
		return (_alloc.max_size());
	};

//	void resize(size_type n, value_type val = value_type())
//	{
//		if ()
//	};

	size_type capacity() const
	{
		return (_end_capacity - _start);
	};

	bool empty() const
	{
		return (_start == _end);
	};

	//need to make insert or other function to add range of elements
	void reserve(size_type n)
	{
		(void) n;
	};

	reference operator[](size_type n)
	{
		return (_start + n);
	};

	const_reference operator[](size_type n) const
	{
		return (_start + n);
	};

	reference at(size_type n)
	{
		if (n >= 0 && n < this->size())
			return (_start + n);
		else
			throw std::exception(); //make new exception;
	};

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