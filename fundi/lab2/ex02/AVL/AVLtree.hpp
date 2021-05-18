#pragma once

# include "AVLtree_.hpp"

template <class T>
AVLtree<T>::AVLtree() : node(nullptr)
{
	left_rotates= 0;
	right_rotates= 0;
	big_left_rotates= 0;
	big_right_rotates= 0;
}

template <class T>
AVLtree<T>::AVLtree(Comparator<T> *_comp) : Btree<T>(_comp)
{
	left_rotates= 0;
	right_rotates= 0;
	big_left_rotates= 0;
	big_right_rotates= 0;
	node = nullptr;
}

template <class T>
short int	AVLtree<T>::height(AVLNode<T> *x)
{
	if (x)
		return x->h;
	return (0);
}

template <class T>
int			AVLtree<T>::bfactor(AVLNode<T> *x)
{
	return (height(x->right) - height(x->left));
}

template <class T>
void		AVLtree<T>::fixheight(AVLNode<T> *x)
{
	x->h = std::max(height(x->left), height(x->right)) + 1;
}

template <class T>
AVLNode<T>	*AVLtree<T>::left_rotation(AVLNode <T> *x)
{
	AVLNode<T>	*cpy;

	left_rotates++;

	cpy = x->right;
	x->right = cpy->left;
	cpy->left = x;

	fixheight(x);
	fixheight(cpy);
	return (cpy);
}

template <class T>
AVLNode<T>	*AVLtree<T>::right_rotation(AVLNode<T> *x)
{
	AVLNode<T>	*cpy;
	
	right_rotates++;
	cpy = x->left;
	x->left = cpy->right;
	cpy->right = x;

	fixheight(x);
	fixheight(cpy);
	return (cpy);
}

template <class T>
AVLNode<T>	*AVLtree<T>::big_left_rotation(AVLNode<T> *x)
{
	left_rotates--;
	right_rotates--;
	big_left_rotates++;
	x->right = right_rotation(x->right);
	return (left_rotation(x));
}

template <class T>
AVLNode<T>	*AVLtree<T>::big_right_rotation(AVLNode<T> *x)
{
	
	left_rotates--;
	right_rotates--;
	big_right_rotates++;
	x->left = left_rotation(x->left);
	return (right_rotation(x));
}


template <class T>
AVLNode<T>	*AVLtree<T>::balance(AVLNode<T> *x)
{
	fixheight(x);
	if (bfactor(x) == 2)
	{
		if (bfactor(x->right) < 0)
			return (big_left_rotation(x));
		else
			return (left_rotation(x));
	}
	else if (bfactor(x) == -2)
	{
		if (bfactor(x->left) > 0)
			return (big_right_rotation(x));
		else
			return (right_rotation(x));
	}
	return (x);
}


template <class T>
AVLNode<T>	*AVLtree<T>::insert(AVLNode<T> *x, T &&data)
{
	if (!x)
		return (new AVLNode<T>(data));
	if (this->comp->compare(data, x->data) < 0)
		x->left = insert(x->left, static_cast<T &&>(data));
	else
		x->right = insert(x->right, static_cast<T &&>(data));
	return (balance(x));
}

template <class T>
void		AVLtree<T>::add(T &&data)
{
	this->node = insert(this->node, static_cast<T &&>(data));
}

template <class T>
void		AVLtree<T>::print(AVLNode<T> *x, int i)
{
	
	for (int j = 0; j < i; j++)
	{
		std::cout << "\t";
	}
	if (!x)
	{
		printf("\x1b[37;42m (null) \x1b[0m\n");
		return ;
	}
	printf("\x1b[37;42m %d \x1b[0m \x1b[33;44m(%d)\x1b[0m\n", x->data, x->h);
	print(x->left, i + 1);
	print(x->right, i + 1);
}

template <class T>
void		AVLtree<T>::print_rotates()
{
	std::cout << "ROTATES:" << std::endl;
	std::cout << "left - " << left_rotates << std::endl;
	std::cout << "right - " << right_rotates << std::endl;
	std::cout << "big left (equal left + right) - " << big_left_rotates << std::endl;
	std::cout << "big right (equal right + left) - " << big_right_rotates << std::endl;
}

template <class T>
void		AVLtree<T>::print()
{
	
	print(this->node, 1);
	std::cout << "MAX HIGH - " << this->node->h << std::endl;
}

template <class T>
bool		AVLtree<T>::is_avltree(AVLNode<T> *x)
{
	if (!x)
		return (true);
	if (abs(bfactor(x)) > 1)
		return (false);
	return (is_avltree(x->left) && is_avltree(x->right));
}

template <class T>
bool		AVLtree<T>::is_avltree()
{
	return (is_avltree(this->node));
}


template <class T>
AVLNode<T>	*AVLtree<T>::get_min(AVLNode<T> *x)
{
	while (x->left)
		x = x->left;
	return (x);
}

template <class T>
AVLNode<T>	*AVLtree<T>::remove_min(AVLNode<T> *x)
{
	if (!x->left)
		return (x->right);
	x->left = remove_min(x->left);
	return (balance(x));
}

template <class T>
AVLNode<T>	*AVLtree<T>::remove(AVLNode<T> *x, T &&data)
{
	int	cmp;

	if (!x)
		return nullptr;
	
	cmp = this->comp->compare(data, x->data);
	if (cmp > 0)
	{
		x->right = remove(x->right, static_cast<T &&>(data));
	}
	else if (cmp < 0)
	{
		x->left = remove(x->left, static_cast<T &&>(data));
	}
	else
	{
		AVLNode <T>	*l = x->left;
		AVLNode <T>	*r = x->right;
		delete x;

		if (!r)
			return (l);
		AVLNode <T>	*min = get_min(r);
		min->right = remove_min(r);
		min->left = l;
		return (balance(min));
	}
	return (balance(x));
}

template <class T>
void		AVLtree<T>::del(T &&data)
{
	this->node = remove(this->node, static_cast<T &&>(data));
}
