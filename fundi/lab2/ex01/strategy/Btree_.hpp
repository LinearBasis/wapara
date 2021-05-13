#pragma once
#include "Comparator.hpp"

#define RED 'R'
#define BLACK 'B'
	
template <class T>
class Node
{
	template <class U> friend class Btree;
private:
	T		data;
	Node	*left;
	Node	*right;
	Node();
	Node(const T &_data);
	~Node();
};

template <class T>
class RBNode final
{
	template <class U> friend class RBtree;
private:
	T			data;
	RBNode<T>	*left;
	RBNode<T>	*right;

	RBNode<T>	*prev;
	char	color;

	template <class U> friend void	print_node(RBNode <U> *node, int level);
	RBNode();
	RBNode(const T &_data, char _color);
	~RBNode();
	template <class U> friend char	getColor(RBNode<U> *node);
public:
	RBNode(const T &_data);
};

template <class T>
class Btree
{
protected:
	Comparator<T>	*comp;

	Btree(Btree &tree);
public:
	Btree(Comparator<T> *_comp);

	virtual void	add(T &&data) = 0;
	virtual void	del(T &&data) = 0;
	virtual bool	find(T &&data) const = 0;
};

