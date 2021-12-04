#ifndef FT_CONTAINER_REVERSE_ITERATOR_HPP
#define FT_CONTAINER_REVERSE_ITERATOR_HPP

namespace ft
{

	template<class iterator_type>
			class reverse_iterator : public ft::iterator<typename iterator_traits<iterator_type>::iterator_category,
					typename iterator_traits<iterator_type>::value_type,
					typename iterator_traits<iterator_type>::difference_type,
					typename iterator_traits<iterator_type>::pointer,
					typename iterator_traits<iterator_type>::reference>

					{

					public:
						typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
						typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
						typedef typename iterator_traits<iterator_type>::reference			reference;
						typedef typename iterator_traits<iterator_type>::pointer			pointer;
						typedef typename iterator_traits<iterator_type>::value_type			value_type;

						reverse_iterator() : _iter(nullptr) {;}
						explicit reverse_iterator(iterator_type it) : _iter(it) {;}
						template<class Iter>
								reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()){;}

								iterator_type base() const {return (_iter);}

								reference operator*() const {return (*_iter);}
								reverse_iterator operator+ (difference_type n) const {return (_iter + n);}
								reverse_iterator& operator++() {--_iter; return (*this);}
								reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --_iter; return (tmp);}
								reverse_iterator& operator+= (difference_type n) {_iter -= n; return (*this);}
								reverse_iterator operator- (difference_type n) const {_iter += n; return (*this);}
								reverse_iterator& operator--() {++_iter; return (*this);}
								reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++_iter; return (tmp);}
								reverse_iterator& operator-= (difference_type n) {_iter += n; return (*this);}
								pointer operator->() const {return (_iter._ptr);}
								reference operator[] (difference_type n) const {retutrn (_iter[n]);}

					protected:
						iterator_type	_iter;
					};

	template <class Iter1, class Iter2>
			bool operator== (const reverse_iterator<Iter1>& lhs,
					const reverse_iterator<Iter2>& rhs) {return (lhs.base() == rhs.base());}

	template <class Iter1, class Iter2>
			bool operator!= (const reverse_iterator<Iter1>& lhs,
					const reverse_iterator<Iter2>& rhs) {return (lhs.base() != rhs.base());}

	template <class Iter1, class Iter2>
			bool operator<  (const reverse_iterator<Iter1>& lhs,
					const reverse_iterator<Iter2>& rhs) {return (lhs.base() > rhs.base());}

	template <class Iter1, class Iter2>
			bool operator<= (const reverse_iterator<Iter1>& lhs,
					const reverse_iterator<Iter2>& rhs) {return (lhs.base() >= rhs.base());}

	template <class Iter1, class Iter2>
			bool operator>  (const reverse_iterator<Iter1>& lhs,
							 const reverse_iterator<Iter2>& rhs) {return (lhs.base() < rhs.base());}

	 template <class Iter1, class Iter2>
			bool operator>= (const reverse_iterator<Iter1>& lhs,
					const reverse_iterator<Iter2>& rhs) {return (lhs.base() <= rhs.base());}

	template <class Iter>
			reverse_iterator<Iter> operator+ ( typename reverse_iterator<Iter>::difference_type n,
					const reverse_iterator<Iter>& rev_it) {(reverse_iterator<Iter>(rev_it.base() - n));}

}
#endif
