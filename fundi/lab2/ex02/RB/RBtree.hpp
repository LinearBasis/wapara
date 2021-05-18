#pragma once

#include "RBtree_.hpp"
#include <queue>
#include <vector>

template <class T>
RBtree<T>::RBtree(Comparator<T> *_comp) : Btree<T>(_comp)
{
	node = nullptr;
	left_rotates = 0;
	right_rotates = 0;
}

template <class T>
bool		RBtree<T>::is_rbtree()
{
	int		i;
	std::vector <std::pair <int, RBNode<T>* > >	vec;
	vec.push_back(std::make_pair(0, this->node));

	i = 0;
	while (1)
	{
		if (vec[i].second)
		{
			if (getColor(vec[i].second) == RED &&
				(getColor(vec[i].second->left) == RED ||
				getColor(vec[i].second->right) == RED))
					return (false);
			if (getColor(vec[i].second) == BLACK)	
			{
				vec.push_back(std::make_pair(vec[i].first + 1, vec[i].second->left));
				vec.push_back(std::make_pair(vec[i].first + 1, vec[i].second->right));
			}
			else
			{
				vec.push_back(std::make_pair(vec[i].first, vec[i].second->left));
				vec.push_back(std::make_pair(vec[i].first, vec[i].second->right));
			}
			vec.erase(vec.begin() + i);
			i = 0;
		}
		else
			i++;

		if (i == vec.size())
			break ;
	}

	i = vec[0].first;
	std::cout << "BH - " << i << std::endl;
	for (int j = 1; j < vec.size(); j++)
	{
		if (vec[j].first != i)
			return (false);
	}
	return (true);


}

template <class T>
void	RBtree<T>::left_rotation(RBNode<T> *node)
{
	RBNode<T>	*n_parent;

	left_rotates++;
	n_parent = node->right;
	if (node == this->node)
		this->node = n_parent;
	
	node->move_down(n_parent);	//

	node->right = n_parent->left;
	if (n_parent->left != nullptr)
		n_parent->left->prev = node;

	n_parent->left = node;
}

//	меняет верширу node с ее левым ребенком (ставит node правее ребенка, поднимая выше ребенка)
template <class T>
void	RBtree<T>::right_rotation(RBNode<T> *node)
{
	RBNode<T>	*n_parent;

	right_rotates++;
	n_parent = node->left;
	if (node == this->node)
		this->node = n_parent;
	
	node->move_down(n_parent);	//

	node->left = n_parent->right;
	if (n_parent->right != nullptr)
		n_parent->right->prev = node;
	n_parent->right = node;
}

template <class T>
void		RBtree<T>::swap_colors(RBNode<T> *x1, RBNode<T> *x2)
{
	char	temp;

	temp = x1->color;
    x1->color = x2->color;
    x2->color = temp;
}

template <class T>
void		RBtree<T>::swap_values(RBNode<T> *u, RBNode<T> *v)
{
	T	temp;

	temp = u->data;
    u->data = v->data;
    v->data = temp;
}

template <class T>
RBNode<T>	*RBtree<T>::naive_add(T && data)
{
	RBNode<T>	*cpy = this->node;
	int			comp;

	while (cpy)
	{
		comp = this->comp->compare(data, cpy->data);
		if (comp >= 0)
		{
			if (cpy->right)
				cpy = cpy->right;
			else
			{
				cpy->right = new RBNode<T>(static_cast<T &&>(data), RED);
				cpy->right->prev = cpy;
				break ;
			}
		}
		else if (comp < 0)
		{
			if (cpy->left)
				cpy = cpy->left;
			else
			{
				cpy->left = new RBNode<T>(static_cast<T &&>(data), RED);
				cpy->left->prev = cpy;
				break ;
			}
		}
	}
	return (cpy);
}

template <class T>
void	RBtree<T>::add(T &&data)
{
	RBNode<T>	*cpy;

	if (this->node == nullptr)
	{
		this->node = new RBNode<T>(static_cast<T &&>(data), BLACK);
		return ;
	}
	cpy = this->naive_add(static_cast<int&&>(data));
	this->check_cases(cpy);
	while (cpy->prev)
		cpy = cpy->prev;
	this->node = cpy;
	// print_node(this->node, 1);
}

template <class T>
bool	RBtree<T>::check_case1(RBNode<T> *added)
{
	if (!added || !added->left || !added->right)
		return (false);
	if (added->color == BLACK && added->right->color == RED 
		&& added->left->color == RED &&
		(getColor(added->left->right) == RED ||
		getColor(added->left->left) == RED ||
		getColor(added->right->right) == RED ||
		getColor(added->right->left) == RED
		) )
	{
		added->color = RED;
		added->right->color = BLACK;
		added->left->color = BLACK;
		if (added->prev == nullptr)
			added->color = BLACK;
		return (true);
	}
	return (false);
}

template <class T>
bool	RBtree<T>::check_case2(RBNode<T> *added)
{
	if (added && added->left)
	{
		if (getColor(added) == BLACK && getColor(added->right) == BLACK &&
			getColor(added->left) == RED && getColor(added->left->right) == RED)
		{
			left_rotation((added->left));
			return (true);
		}
	}
	if (added && added->right)
	{
		if (getColor(added) == BLACK && getColor(added->left) == BLACK &&
			getColor(added->right) == RED && getColor(added->right->left) == RED)
		{
			right_rotation((added->right));
			print_node(added, 1);
			// added->right = added->right->prev;
			return (true);
		}
	}
	return (false);
}

template <class T>
bool	RBtree<T>::check_case3(RBNode<T> *added)
{
	if (added && added->left)
	{
		if (getColor(added) == BLACK && getColor(added->right) == BLACK &&
			getColor(added->left) == RED && getColor(added->left->left) == RED)
		{
			// printf("BEFORE ROTATE - %p, data - %d\n", added, added->data);
			right_rotation(added);
			// printf("AFTER ROTATE - %p, data - %d\n", added, added->data);
			added = added->prev;
			if (added)
			{
				added->color = BLACK;
				if (added->right)
					added->right->color = RED;
				if (added->left)
					added->left->color = RED;
				check_case1(added);
			}
			return (true);
		}
	}
	if (added && added->right)
	{
		if (getColor(added) == BLACK && getColor(added->left) == BLACK &&
			getColor(added->right) == RED && getColor(added->right->right) == RED)
		{
			// printf("BEFORE ROTATE - %p, data - %d, right - %p\n", added, added->data, added->right);
			left_rotation((added));
			// printf("AFTER ROTATE - %p, data - %d, left - %p\n", added, added->data, added->left);
			added = added->prev;
			added->color = BLACK;
			added->right->color = RED;
			added->left->color = RED;
			check_case1(added);
			return (true);
		}
	}
	return (false);
}

template <class T>
void	RBtree<T>::check_cases(RBNode<T> *added)
{
	if (added == NULL)
		return ;
	check_case1(added);
	check_case2(added);
	check_case3(added);
	check_cases(added->prev);
}

template <class T>
void	RBtree<T>::fix_red_red(RBNode<T> *x)
{
	if (x == this->node)
	{
		x->color = BLACK;
		return ;
	}

	RBNode<T>	*parent = x->prev;
	RBNode<T>	*grandparent = x->prev->prev;
	RBNode<T>	*uncle = x->uncle();

	if (parent->color == BLACK)
		return ;

	if (uncle && uncle->color == RED)
	{
		parent->color = BLACK;
		uncle->color = BLACK;
		grandparent->color = RED;
		fix_red_red(grandparent);
	}
	else
	{
		if (parent->is_on_left())
		{
			if (x->is_on_left())
			{
				swap_colors(parent, grandparent);
			}
			else
			{
				left_rotation(parent);
				swap_colors(x, grandparent);
			}
			right_rotation(grandparent);
		}
		else
		{
			if (x->is_on_left())
			{

				right_rotation(parent);
				swap_colors(x, grandparent);
			}
			else
			{
				swap_colors(parent, grandparent);
			}
			left_rotation(grandparent);
		}
	}
}

template <class T>
RBNode<T>	*RBtree<T>::BSTreplace(RBNode <T> *x)
{
	if (x->left && x->right)
		return (x->right->get_far_left());
	if (!x->left && !x->right)
		return (nullptr);
	if (x->left)
		return (x->left);
	return (x->right);
}

template <class T>
void		RBtree<T>::delete_node(RBNode <T> *v)
{
	RBNode<T>	*u;


	u = BSTreplace(v);

	bool uv_black = ((u == nullptr || u->color == BLACK)
					&& v->color == BLACK);
	RBNode<T>	*parent = v->prev;

	if (u == nullptr)
	{
		if (v == this->node)
		{
			this->node = nullptr;
		}
		else
		{
			if (uv_black)
			{
				fix_double_black(v);
			}
			else
			{
				if (v->sibling() != nullptr)
					v->sibling()->color = RED;
			}
			if (v->is_on_left())
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
		}
		delete v;
		return ;
	}

	if (!v->left || !v->right)
	{
		if (v == this->node)
		{
			v->data = u->data;
			v->left = v->right = NULL;
			delete u;
		}
		else
		{
			if (v->is_on_left())
			{
				parent->left = u;
			}
			else
			{
				parent->right = u;
			}
			delete v;
			u->prev = parent;
			if (uv_black)
			{
				fix_double_black(u);
			}
			else
			{
				u->color = BLACK;
			}
		}
		return ;
	}
	swap_values(u, v);
	delete_node(u);
}

template <class T>
void	RBtree<T>::fix_double_black(RBNode <T> *x)
{
	if (x == this->node)
		return ;
	
	RBNode <T>	*sibling = x->sibling();
	RBNode <T>	*parent = x->prev;

	if (!sibling)
	{
		fix_double_black(parent);
	}
	else
	{
		if (sibling->color == RED)
		{
			parent->color = RED;
			sibling->color = BLACK;
			if (sibling->is_on_left())
			{
				right_rotation(parent);
			}
			else
			{
				left_rotation(parent);
			}
			fix_double_black(x);
		}
		else
		{
			if (sibling->has_red_child())
			{
				if (sibling->left && sibling->left->color == RED)
				{
					if (sibling->is_on_left())
					{
						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						right_rotation(parent);
					}
					else
					{
						sibling->left->color = parent->color;
						right_rotation(sibling);
						left_rotation(parent);
					}
				}
				else
				{
					if (sibling->is_on_left())
					{
						sibling->right->color = parent->color;
						left_rotation(sibling);
						right_rotation(parent);
					}
					else
					{
						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						left_rotation(parent);
					}
				}
				parent->color = BLACK;
			}
			else
			{
				sibling->color = RED;
				if (parent->color == BLACK)
					fix_double_black(parent);
				else
					parent->color = BLACK;
			}
		}
	}
}

template <class T>
void	RBtree<T>::del(T &&data)
{
	if (this->node == nullptr)
		return ;
	
	RBNode<T>	*v = search(static_cast<T &&>(data));
	if (v)
		delete_node(v);
	else
		std::cout << "Element data not found" << std::endl;
}

template <class T>
RBNode<T>	*RBtree<T>::search(T &&data) const
{
	RBNode<T>	*cpy = this->node;
	int			comp;

	while (cpy)
	{
		comp = this->comp->compare(data, cpy->data);
		if (comp > 0)
		{
			if (cpy->right)
				cpy = cpy->right;
			else
				return (nullptr);
		}
		else if (comp < 0)
		{
			if (cpy->left)
				cpy = cpy->left;
			else
				return (nullptr);
		}
		else
			return (cpy);
	}
	return (cpy);
}

template <class T>
bool	RBtree<T>::find(T &&data) const
{
	if (search(static_cast<T &&>(data)) != nullptr)
		return (true);
	return (false);
}

template <class T>
void	print_node(RBNode <T> *node, int level)
{
	int i;

	i = 0;
	while (i < level)
	{
		i++;
		printf("\t");
	}
	if (node == NULL)
	{
		printf("\x1b[37;40m (null) \x1b[0m\n");
		return ;
	}
	if (node->color == RED)
		printf("\x1b[37;41m %d \x1b[0m\n", node->data);
	else
		printf("\x1b[37;40m %d \x1b[0m\n", node->data);
	print_node(node->left, level + 1);
	print_node(node->right, level + 1);
}

template <class T>
void		RBtree<T>::print()
{
	print_node(this->node, 0);
}