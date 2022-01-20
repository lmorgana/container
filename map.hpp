#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"


# define RED true
# define BLACK false

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

	template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<ft::pair<const Key, T> > >
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
		typedef typename allocator_type::template rebind<ft::node<value_type> >::other	alloc_rebind_node;
		typedef node<value_type>*													node_ptr;
		typedef std::less<value_type>												value_compare;

	private:
		allocator_type		_alloc;
		Compare				_comp;
		value_compare		_vcomp;
		alloc_rebind_node	_alloc_rebind_node;
		node_ptr			_root;
		node<value_type>	_end;
		node<value_type>	_nil;

	public:
		explicit map (const key_compare& comp = key_compare(),
					   const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp)
		{
			init_tree();
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			  const key_compare& comp = key_compare(),
			  const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp)
		{
			init_tree();
			for (; first != last; first++)
				insert(ft::make_pair(first->first, first->second));
		}

		map (const map& x)
		{
			init_tree();
			const_iterator first = x.begin();
			const_iterator last = x.end();

			for (; first != last; first++)
				insert(ft::make_pair(first->first, first->second));
		}

		map& operator=(const map &other)
		{
			if (this != &other)
			{
				clear_tree(_root);
				init_tree();

				const_iterator first = other.begin();
				const_iterator last = other.end();
				for (; first != last; first++)
					insert(ft::make_pair(first->first, first->second));
			}
			return (*this);
		}

		~map()
		{
			clear_tree(_root);
		}


		//***********
		//**getters**
		//***********

		iterator begin() { return (iterator(min(_root))); }
		const_iterator begin() const { return (const_iterator(min(_root))); }
		iterator end() { return (iterator(max(_root)->right)); }
		const_iterator end() const {return (const_iterator(max(_root)->right)); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		bool empty() const { return (begin() == end()); }
		size_type size() const { return tree_size(_root); }
		size_type max_size() const { return (_alloc_rebind_node.max_size()); }

		// maybe need to modify
		mapped_type& operator[] (const key_type& k) { return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second; }


		//  ***************
		//  *** methods ***
		//  ***************

		ft::pair<iterator,bool> insert (const value_type& val)
		{
			return insert_node(_root, val);
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void) position;
			return insert_node(_root, val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				insert_node(_root, *first);
		}

		void erase (iterator position)
		{
			delete_node(position.base());
		}

		size_type erase (const key_type& k)
		{
			iterator iter = find(k);

			if (iter == end())
				return (0);
			delete_node(iter.base());
			return (1);
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}

		node_ptr search(const key_type& k) const
		{
			node_ptr node = _root;

			while (!is_nil(node) && (_comp(k, node->key->first) || _comp(node->key->first, k)))
			{
				if (_comp(k, node->key->first))
					node = node->left;
				else
					node = node->right;
			}
			if (is_nil(node))
				return (nullptr);
			return (node);
		}

		iterator find (const key_type& k)
		{
			node_ptr node = search(k);

			if (node)
				return (iterator(node));
			return (end());
		}
		const_iterator find (const key_type& k) const
		{
			node_ptr node = search(k);

			if (node)
				return (const_iterator(node));
			return (end());
		}

		void clear()
		{
			clear_tree(_root);
			_root = &_nil;
			fix_end();
		}

		void swap(map &x)
		{
			if (this != &x)
			{
				std::swap(*this, x);
			}
		}

		size_type count (const key_type& k) const
		{
			return (search(k) != nullptr);
		}

		iterator lower_bound (const key_type& k)
		{
			node_ptr node = _root;
			node_ptr par = &_end;

			while (!is_nil(node))
			{
				if (!_comp(node->key->first, k))
				{
					par = node;
					node = node->left;
				}
				else
					node = node->right;

			}
			return (iterator(par));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			node_ptr node = _root;
			node_ptr par = &_end;

			while (!is_nil(node))
			{
				if (!_comp(node->key->first, k))
				{
					par = node;
					node = node->left;
				}
				else
					node = node->right;

			}
			return (const_iterator(par));
		}

		iterator upper_bound (const key_type& k)
		{
			node_ptr node = _root;
			node_ptr par = &_end;

			while (!is_nil(node))
			{
				if (_comp(k, node->key->first))
				{
					par = node;
					node = node->left;
				}
				else
					node = node->right;

			}
			return (iterator(par));
		}
		const_iterator upper_bound (const key_type& k) const
		{
			node_ptr node = _root;
			node_ptr par = &_end;

			while (!is_nil(node))
			{
				if (_comp(k, node->key->first))
				{
					par = node;
					node = node->left;
				}
				else
					node = node->right;

			}
			return (const_iterator(par));
		}

		pair<iterator, iterator> equal_range (const key_type& k)
		{
			ft::pair<iterator, iterator>	pr;

			pr.first = lower_bound(k);
			pr.second = upper_bound(k);
			return (pr);
		}

		pair<const_iterator, const_iterator>             equal_range (const key_type& k) const
		{
			ft::pair<const_iterator, const_iterator>	pr;

			pr.first = lower_bound(k);
			pr.second = upper_bound(k);
			return (pr);
		}

		key_compare key_comp() const
		{
			return (_comp);
		}

		value_compare value_comp() const
		{
			return (_vcomp);
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		//  **********
		//  *** my ***
		//  **********

	private:
		void clear_node(node_ptr node)
		{
			if (is_nil(node))
				return ;
			_alloc.destroy(node->key);
			_alloc.deallocate(node->key, 1);
			_alloc_rebind_node.destroy(node);
			_alloc_rebind_node.deallocate(node, 1);
		}

		void clear_tree(node_ptr node)
		{
			if (is_nil(node))
				return ;
			clear_tree(node->left);
			clear_tree(node->right);
			clear_node(node);
		}

		void init_tree()
		{
			_nil.is_nil = true;
			_nil.left = &_nil;
			_nil.right = &_nil;
			_nil.color = BLACK;
			_nil.parent = &_nil;
			_end.left = &_nil;
			_end.is_nil = false;
			_end.right = &_nil;
			_end.parent = &_nil;
			_end.color = BLACK;
			_root = &_nil;
		}

		//check if node is _nil or _end because it's node work nodes
		bool is_nil(node_ptr node) const
		{
//			return (node->is_nil);
			return (node == &_nil || node == &_end);
		}

		node_ptr min(node_ptr x) const
		{
			while (!is_nil(x) && !is_nil(x->left))
				x = x->left;
			return (x);
		}

		node_ptr max(node_ptr x) const
		{
			while (!is_nil(x) && !is_nil(x->right))
				x = x->right;
			return (x);
		}

		size_type tree_size(node_ptr x) const
		{
			if (is_nil(x))
				return (0);
			return (tree_size(x->left) + tree_size(x->right) + 1);
		}

		node_ptr new_node(const value_type &value)
		{
			node_ptr node;

			node = _alloc_rebind_node.allocate(1);
			_alloc_rebind_node.construct(node);

			node->key = _alloc.allocate(1);
			_alloc.construct(node->key, value);

			node->left = &_nil;
			node->right = &_nil;
			node->parent = &_nil;
			node->is_nil = false;
			node->color = RED;
			return (node);
		}

		void left_rotate(node_ptr x)
		{
			node_ptr y = x->right;

			x->right = y->left;
			if (!is_nil(y->left))
				y->left->parent = x;
			y->parent = x->parent;
			if (is_nil(x->parent))
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void right_rotate(node_ptr y)
		{
			node_ptr x = y->left;

			y->left = x->right;
			if (!is_nil(x->right))
				x->right->parent = y;
			x->parent = y->parent;
			if (is_nil(y->parent))
				_root = x;
			else if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
			x->right = y;
			y->parent = x;
		}

		void rb_insert_fixup(node_ptr z)
		{
			node_ptr y;

			while (z != _root && z->parent->color == RED)
			{
				if (z->parent == z->parent->parent->left)
				{
					y = z->parent->parent->right;
					if (y->color == RED)
					{
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->right)
						{
							z = z->parent;
							left_rotate(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						right_rotate(z->parent->parent);
					}
				}
				else  // возможно нужно исправить
				{
					y = z->parent->parent->left;
					if (y->color == RED)
					{
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else
					{

						if (z == z->parent->left)
						{
							z = z->parent;
							right_rotate(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						left_rotate(z->parent->parent);
					}
				}
			}
			_root->color = BLACK;
		}

		void fix_end()
		{
			node_ptr max_node;

			max_node = max(_root);
			max_node->right = &_end;
			_end.parent = max_node;
			_nil.right = max_node;
			_nil.left = min(_root);
		}

		ft::pair<iterator, bool> insert_node(node_ptr elem, const value_type &value)
		{
			node_ptr curr, parent, x;

			curr = elem;
			parent  = &_nil;
			while (!is_nil(curr))
			{
				if (value.first == curr->key->first)
					return (ft::make_pair(curr, false));
				parent = curr;
				if (_comp(value.first, curr->key->first))
					curr = curr->left;
				else
					curr = curr->right;
			}

			x = new_node(value);
			x->parent = parent;

			if (is_nil(parent))
				_root = x;
			else if (_comp(value.first, parent->key->first))
				parent->left = x;
			else
				parent->right = x;

			rb_insert_fixup(x);

			if (x == max(_root))
				_nil.parent = x;
			fix_end();
			return (ft::make_pair(x, true));
		}

		void rb_delete_fixup(node_ptr x)
		{
			node_ptr w;

			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					w = x->parent->right;

					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->parent;
					}
					else
					{
						if (w->right->color == BLACK)
						{
							w->left->color = BLACK;
							w->color = RED;
							right_rotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					w = x->parent->left;

					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK)
					{
						w->color = RED;
						x = x->parent;
					}
					else
					{
						if (w->left->color == BLACK)
						{
							w->right->color = BLACK;
							w->color = RED;
							left_rotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK;
		}

		void rb_transplant(node_ptr u, node_ptr v)
		{
			if (is_nil(u->parent))
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void delete_node(node_ptr z)
		{
			node_ptr y = z;
			node_ptr x;
			bool y_original_color = y->color;


			if (is_nil(z->left))
			{
				x = z->right;
				rb_transplant(z, z->right);
			}
			else if (is_nil(z->right))
			{
				x = z->left;
				rb_transplant(z, z->left);
			}
			else
			{
				y = min(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rb_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (y_original_color == BLACK)
				rb_delete_fixup(x);
			fix_end();
			clear_node(z);
		}
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const map<T, Compare, Alloc>& lhs, const map<T, Compare, Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Compare, class Alloc>
	bool operator!=(const map<T, Compare, Alloc>& lhs, const map<T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator<(const map<T, Compare, Alloc>& lhs,
				   const map<T, Compare, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Compare, class Alloc>
	bool operator>(const map<T, Compare, Alloc>& lhs, const map<T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator<=(const map<T, Compare, Alloc>& lhs,
					const map<T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator>=(const map<T, Compare, Alloc>& lhs, const map<T, Compare, Alloc>& rhs)
	{
		return !(rhs > lhs);
	}

	template <class T, class Compare, class Alloc>
	void swap(map<T, Compare, Alloc>& x, map<T, Compare, Alloc>& y)
	{
		x.swap(y);
	}

}

#endif