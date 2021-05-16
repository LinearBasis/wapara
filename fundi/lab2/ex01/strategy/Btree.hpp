#pragma once

#include "Btree_.hpp"

template <class T>
Node<T>::Node() : left(nullptr), right(nullptr)
{

}

template <class T>
Node<T>::Node(const T &_data) : Node(), data(_data)
{

}

template <class T>
Node<T>::~Node()
{

}

template <class T>
RBNode<T>::RBNode() : color(RED), left(nullptr), right(nullptr), prev(nullptr)
{

}

template <class T>
RBNode<T>::RBNode(T &&_data) : RBNode()
{
	this->data = _data;
}

template <class T>
RBNode<T>::RBNode(T &&_data, char _color) : RBNode(static_cast<T &&>(_data))
{
	this->color = _color;
}

template <class T>
Btree<T>::Btree(Comparator<T> *_comp) : comp(_comp)
{
	
}

template <class T>
RBNode<T>		*RBNode<T>::get_far_left()
{
	RBNode<T>	*cpy;

	cpy = this;

	while (cpy->left)
		cpy = cpy->left;
	return (cpy);
}

template <class T>
RBNode<T>		*RBNode<T>::get_far_right()
{
	RBNode<T>	*cpy;

	cpy = this;

	while (cpy->right)
		cpy = cpy->right;
	return (cpy);
}


template <class T>
char	getColor(RBNode<T> *node)
{
	if (!node)
		return (BLACK);
	return (node->color);
}



template <class T>
RBNode<T>	*RBNode<T>::uncle()
{
	if (this->prev == nullptr || prev->prev == nullptr)
		return (nullptr);

		if (this->prev->is_on_left())
			return (this->prev->prev->right);
		else
			return (this->prev->prev->left);
}

template <class T>
bool		RBNode<T>::is_on_left()
{
	return (this == this->prev->left);
}

template <class T>
RBNode<T>	*RBNode<T>::sibling()
{
	if (this->prev == nullptr)
		return (nullptr);
	if (this->is_on_left())
		return (this->prev->right);
	
	return (this->prev->left);
}

template <class T>
void		RBNode<T>::move_down(RBNode<T> *n_parent)
{
	if (this->prev != nullptr)
	{
		if (is_on_left())
			this->prev->left = n_parent;
		else
			this->prev->right = n_parent;
	}
	n_parent->prev = this->prev;
	this->prev = n_parent;
}

template <class T>
bool		RBNode<T>::has_red_child()
{
	return ((left != nullptr && left->color == RED) ||
			(right != nullptr && right->color == RED));
}
