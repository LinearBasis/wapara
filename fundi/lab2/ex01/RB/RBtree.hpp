#pragma once

#include "RBtree_.hpp"


template <class T>
RBtree<T>::RBtree(Comparator<T> *_comp) : Btree<T>(_comp)
{
	node = nullptr;
}

template <class T>
void	RBtree<T>::left_rotation(RBNode<T> **node)
{
	RBNode<T> *right;		//NODE - A, PARENT - PARENT, RIGHT - B
	RBNode<T> *parent;

	if (!node || !*node || !(*node)->right)
		return ;
	right = (*node)->right;
	parent = (*node)->prev;

	if (right->left)
	{
		right->left->prev = *node;
	}
	(*node)->right = right->left;

	right->left = *node;
	(*node)->prev = right;

	right->prev = parent;
	if (parent == nullptr)
	{
		*node = right;
	}
	else if (parent->left == *node)
		parent->left = right;
	else if (parent->right == *node)
		parent->right = right;
	*node = right;
}

//	меняет верширу node с ее левым ребенком (ставит node правее ребенка, поднимая выше ребенка)
template <class T>
void	RBtree<T>::right_rotation(RBNode<T> **node)
{
	RBNode<T> *left;
	RBNode<T> *parent;

	if (!node || !*node || !(*node)->left)
		return ;
	left = (*node)->left;
	parent = (*node)->prev;

	printf("in right rotate\n");
	(*node)->left = left->right;
	if (left->right)
	{
		left->right->prev = (*node);
	}

	left->right = (*node);
	(*node)->prev = left;

	printf("asd\n");
	left->prev = parent;
	if (parent && parent->left == (*node))
		parent->left = left;
	else if (parent && parent->right == (*node))
		parent->right = left;
	(*node) = left;
}



template <class T>
void	RBtree<T>::stan

template <class T>
void	RBtree<T>::add(T &&data)
{
	RBNode<T>	*cpy = this->node;
	int			comp;

	if (this->node == nullptr)
	{
		this->node = new RBNode<T>(data, BLACK);
		// print_node(node, 1);
		return ;
	}
	// printf("______BEFORE ADDING BEFORE BALANSING\n");
	// print_node(node, 1);

	while (cpy)
	{
		comp = this->comp->compare(data, cpy->data);
		if (comp >= 0)
		{
			if (cpy->right)
				cpy = cpy->right;
			else
			{
				cpy->right = new RBNode<T>(data, RED);
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
				cpy->left = new RBNode<T>(data, RED);
				cpy->left->prev = cpy;
				break ;
			}
		}
	}
	this->check_cases(cpy);
	while (cpy->prev)
		cpy = cpy->prev;
	this->node = cpy;
	// printf("______AFTER ADDING BEFORE BALANSING node value - %p\n", this->node);
	print_node(this->node, 1);
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
			left_rotation(&(added->left));
			return (true);
		}
	}
	if (added && added->right)
	{
		if (getColor(added) == BLACK && getColor(added->left) == BLACK &&
			getColor(added->right) == RED && getColor(added->right->left) == RED)
		{
			right_rotation(&(added->right));
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
			printf("%p\t%p\t%p\n", added, added->left, added->right);
			printf("added->left->data - %d\n", added->left->data);
			right_rotation(&added);
			printf("added->data - %d\n", added->data);
			added->color = BLACK;
			if (added->right)
			{
				added->right->color = RED;
				printf("added->right->data - %d\n", added->right->data);
			}
			if (added->left)
			{
				printf("added->left->data - %d\n", added->left->data);
				added->left->color = RED;
			}
			check_case1(added);
			return (true);
		}
	}
	if (added && added->right)
	{
		if (getColor(added) == BLACK && getColor(added->left) == BLACK &&
			getColor(added->right) == RED && getColor(added->right->right) == RED)
		{
			// printf("BEFORE LEFT ROTATION:\n");
			// print_node(added, 1);
			left_rotation(&added);
			added->color = BLACK;
			added->right->color = RED;
			added->left->color = RED;
			check_case1(added);
			// printf("AFTER LEFT ROTATION:\n");
			// print_node(added, 1);
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
void	RBtree<T>::del(T &&data)
{

}

template <class T>
bool	RBtree<T>::find(T &&data) const
{
	return (true);
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
		printf("\x1b[37;41m %d \x1b[0m | this - %p, prev - %p\n", node->data, node, node->prev);
	else
		printf("\x1b[37;40m %d \x1b[0m | this - %p, prev - %p\n", node->data, node, node->prev);
	print_node(node->left, level + 1);
	print_node(node->right, level + 1);
}

template <class T>
void		RBtree<T>::print()
{
	// printf("%d - right\n", this->node->right);
	print_node(this->node, 0);
}