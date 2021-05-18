#pragma once
#include "Comparator.hpp"

#define RED 'R'
#define BLACK 'B'
	
template <class T>
class Node
{
private:
	T		data;
	Node	*left;
	Node	*right;
	Node();
	Node(const T &_data);
	virtual ~Node();
};

template <class T>
class RBNode final : public Node<T>
{
private:
	char	color;
	RBNode	*prev;
	RBNode();
	RBNode(const T &_data);
	RBNode(const T &_data, char _color);
	~RBNode();
};

template <class T>
class Btree
{
private:
	friend class	Node<T>;
	Node			*node;
	Comparator<T>	comp;

	Btree();
	Btree(Btree &tree);
public:
	Btree(Comparator<T> &_comp);

	virtual void	add(T &data) = 0;
	virtual void	delete(T &data) = 0;
	virtual bool	find(T &data) const = 0;
};

