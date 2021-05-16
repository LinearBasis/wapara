#pragma once

#include "../strategy/Btree.hpp"

template <class T>
class AVLtree final : Btree<T>
{
	T			data;
	AVLNode<T>	*root;

	
}