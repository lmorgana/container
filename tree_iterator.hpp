#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "map.hpp"
#include "enable_if.hpp"
#include "iterators.hpp"


namespace ft
{
	template<class T>
	struct node;

	template<class Type>
	class treeIterator
	{
		typedef node<typename ft::remove_const<Type>::type> *node_ptr;
		node_ptr _node;

	private:
		node_ptr min(node_ptr x)
		{
			while (x->left->is_nil == false)
				x = x->left;
			return (x);
		}

		node_ptr max(node_ptr x)
		{
			while (!x->right->is_nil)
				x = x->right;
			return (x);
		}

	public:
		typedef typename iterator_traits<Type*>::difference_type		difference_type;
		typedef typename iterator_traits<Type*>::value_type			value_type;
		typedef typename iterator_traits<Type*>::pointer				pointer;
		typedef typename iterator_traits<Type*>::reference			reference;
		typedef std::bidirectional_iterator_tag						iterator_category;
		typedef treeIterator<typename ft::remove_const<value_type>::type> iter;

		explicit treeIterator(node_ptr it = nullptr) : _node(it) {}
		treeIterator(const iter &other)
		{
			this->_node = other.base();
		}

		~treeIterator() {};

		treeIterator& operator=(const iter &other)
		{
			_node = other.base();
			return (*this);
		}
		node_ptr base() const
		{
			return (_node);
		}
		reference operator*() const
		{
			return *_node->key;
		}
		pointer operator->() const
		{
			return &**this;
		}
		treeIterator& operator++()
		{
			if (_node->right && _node->right->is_nil == false)
				_node = min(_node->right);
			else
			{
				node_ptr y = _node->parent;
				while (y && y->is_nil == false && _node == y->right)
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return (*this);
		}

		treeIterator operator++(int)
		{
			treeIterator tmp(*this);

			++(*this);
			return (tmp);
		}

		treeIterator& operator--()
		{
			if (_node->left && _node->left->is_nil == false)
				_node = max(_node->left);
			else
			{
				node_ptr y = _node->parent;
				while (y && y->is_nil == false && _node == y->left)
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return (*this);
		}

		treeIterator operator--(int)
		{
			treeIterator tmp(*this);

			--(*this);
			return (tmp);
		}
	};

	template <class A, class B>
	bool operator==(const treeIterator<A>& lhs,
					const treeIterator<B>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class A, class B>
	bool operator!=(const treeIterator<A>& lhs,
					const treeIterator<B>& rhs)
	{
		return lhs.base() != rhs.base();
	}
}

#endif
