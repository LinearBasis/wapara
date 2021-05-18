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
RBNode<T>::RBNode() : Node(), color(RED)
{
	
}

template <class T>
RBNode<T>::RBNode(const T &_data) : Node(_data)
{

}

template <class T>
Btree<T>::Btree() : node(nullptr)
{

}

template <class T>
Btree<T>::Btree(Comparator<T> &_comp) : node(nullptr), comp(_comp)
{

}

template <class T>
RBNode<T>::RBNode(const T &_data, char _color) : color(_color)
{

}
