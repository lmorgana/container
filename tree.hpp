#ifndef TREE_HPP
#define TREE_HPP

# define RED true
# define BLACK false


#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"

namespace ft
{

	template <class T>
	struct node
	{
		T		*key;
		node	*parent;
		node	*left;
		node	*right;
		bool 	color;
		bool 	is_nil;
	};

//red black tree
	template <class T, class Compare = std::less<T> >
	class Tree
	{
	private:
		node<T>	_nil;
		node<T> *_root;
		size_t	_size;

	public:

		Tree()
		{
			_nil.is_nil = true;
			_nil.color = BLACK;
			_size = 0;
			_root = &_nil;
		}

		Tree(Tree<T> &other)
		{
			(void) other;
			_nil->is_nil = true;
			_nil->color = BLACK;
			_size = 0;
			_root = _nil;
		}

		Tree &operator=(const Tree<T> &other)
		{
			if (this == &other)
				return (*this);
			_root = other._root;
			_nil = other._nil;
			_size = other._size;
			return (*this);
		}

//		don't need, don't have any allocator
//		node_pointer my_new(const value_type &val)
//		{
//			node_pointer buff;
//
//			buff = _node_alloc.allocate(1);
//			_node_alloc.construct(buff, node<T>());
//			buff->value = _val_alloc.allocate(1);
//			_val_alloc.construct(buff->value, val);
//			buff->left = _nil;
//			buff->right = _nil;
//			return (buff);
//		}

		void left_rotate(node<T> *x)
		{
			node<T> *y = x->right;

			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _nil)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;

			x->parent = y;
		}

		void right_rotate(node<T> *y)
		{
			node<T> *x = y->left;

			y->left = x->right;
			if (x->right != _nil)
				x->right->parent = y;
			x->parent = y->parent;
			if (y->parent == _nil)
				_root = x;
			else if (y->parent == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
			x->right = y;
			y->parent = x;
		}

		void rb_insert_fixup(node<T> *z)
		{
			while (z->parent->color == RED)
			{
				if (z->parent == z->parent->parent->left)
				{
					node<T> *y = z->parent->parent->right;
					if (y->color == RED)
					{
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else if (z == z->parent->right)
					{
						z = z->parent;
						left_rotate(z);
					}
					else
					{
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						right_rotate(z->parent->parent);
					}
				}
				else  // возможно нужно исправить
				{
					node<T> *y = z->parent->parent->left;
					if (y->color == RED)
					{
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else if (z == z->parent->left)
					{
						z = z->parent;
						right_rotate(z);
					}
					else
					{
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						left_rotate(z->parent->parent);
					}
				}
			}
		}

		void rb_insert(node<T> z)
		{
			node<T> *y = &_nil;
			node<T> *x = _root;

			while (x != _nil)
			{
				y = x;
				if (z->key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			z->parent = y;
			if (y == _nil)
				_root = _nil;
			else if (z->key < y->key)
				y->left = z;
			else
				y->right = z;
			z->left = _nil;
			z->right = _nil;
			z->color = RED;
			rb_insert_fixup(z);
		}

//		ft::pair<iterator, bool> insert(const value_type &key)
//		{
//			node_pointer	new_n;
//
//			new_n = search(key);
//			if (new_n)
//				return ft::pair<iterator, bool>(iterator(new_n), false);
//			new_n = my_new(key);
//			rb_nsert(new_n);
//			return ft::pair<iterator, bool>(iterator(new_n), true);
//		}

//		iterator insert(iterator position, const value_type &val)
//		{
//
//		}

//		node_pointer search(const value_type &key) const
//		{
//			node_pointer	x;
//
//			x = _root;
//			while (x->is_nil == false && (_comp(key, *x->value) || _comp(*x->value, key)))
//			{
//				if (_comp(key, *x->value))
//					x = x->left;
//				else
//					x = x->right;
//			}
//			if (x->is_nil)
//				return (NULL);
//			return (x);
//		}
		node<T>	*min()
		{
			node<T> *x = _root;

			while (!x->left->is_nil)
				x = x->left;
			return (x);
		}

		node<T>	*max()
		{
			node<T> *x = _root;

			while (!x->left->is_nil)
				x = x->left;
			return (x);
		}
	};
}

#endif
