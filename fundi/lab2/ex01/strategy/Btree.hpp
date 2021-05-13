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
RBNode<T>::RBNode(const T &_data) : RBNode()
{
	this->data = _data;
}

template <class T>
RBNode<T>::RBNode(const T &_data, char _color) : RBNode(_data)
{
	this->color = _color;
}

template <class T>
Btree<T>::Btree(Comparator<T> *_comp) : comp(_comp)
{

}

template <class T>
char	getColor(RBNode<T> *node)
{
	if (!node)
		return (BLACK);
	return (node->color);
}
