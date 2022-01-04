#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "tree.hpp"
#include "tree_iterator.hpp"



namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key																	key_type;
		typedef T																	mapped_type;
		typedef ft::pair<const Key, T>												value_type;
		typedef std::size_t															size_type;
		typedef std::ptrdiff_t														difference_type;
		typedef Compare																key_compare;
		typedef A																	allocator_type;
		typedef value_type&															reference;
		typedef const value_type&													const_reference;
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef ft::treeIterator<value_type>										iterator;
		typedef ft::treeIterator<const value_type>									const_iterator;
		typedef ft::reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef typename allocator_type::template rebind<node<value_type> >::other	alloc_rebind_node;
		typedef typename allocator_type::template rebind<Tree<value_type> >::other	alloc_rebind_tree;

	private:
		allocator_type		_alloc;
		Compare				_comp;
		Tree<value_type>	*_tree;
		alloc_rebind_node	_alloc_rebind_node;
		alloc_rebind_tree	_alloc_rebind_tree;

	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type())
					  : _alloc(alloc), _comp(comp)
		{
			_tree = _alloc_rebind_tree.allocate(1);
			_alloc_rebind_tree.construct(_tree);
		}

		//need insert method to work
//		template <class InputIterator>
//		map (InputIterator first, InputIterator last,
//			 const key_compare& comp = key_compare(),
//			 const allocator_type& alloc = allocator_type())
//			: _alloc(alloc), _comp(comp)
//		{
//			_tree = _alloc_rebind_tree.allocate(1);
//			_alloc_rebind_tree.construct(_tree);
//			for (; first != last; first++)
//				insert(ft::make_pair(first->first, first->second));
//		}

//		map (const map& x)
//		{
//			iterator first(x.begin());
//			iterator last(x.end());
//			_tree = _alloc_rebind_tree.allocate(1);
//			_alloc_rebind_tree.construct(_tree);
//			for (; first != last; first++)
//				insert(ft::make_pair(first->first, first->second));
//		}

		~map()
		{
			_alloc_rebind_tree.destroy(_tree);
			_alloc_rebind_tree.deallocate(_tree, 1);
		}

		//need insert;
//		map& operator= (const map& x)
//		{
//			clear(_tree); // method which clear all tree;
//			iterator first(x.begin());
//			iterator last(x.end());
//			for (; first != last; first++)
//				insert(ft::make_pair(first->first, first->second));
//		}


		//***********
		//**getters**
		//***********

		iterator begin() { return (iterator(_tree->min())); }
		const_iterator begin() const { return (const_iterator(_tree->min())); }
		iterator end() { return (iterator(_tree->max()->right)); }
		const_iterator end() const {return (const_iterator(_tree->max()->right)); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		//*****************
		//**other methods**
		//*****************

		bool empty() const
		{
			return (begin() != end());
		}

		size_type size() const
		{

		}
	};
}

#endif