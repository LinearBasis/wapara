#pragma once
#include "Comparator.hpp"

#define RED 'R'
#define BLACK 'B'
	
template <class T>
class AVLNode final
{
	template <class U> friend class AVLtree;
private:
	T			data;
	AVLNode<T>	*left;
	AVLNode<T>	*right;
	short int	h;

	AVLNode();
	AVLNode(const T &_data);
	~AVLNode();
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
	char		color;

	RBNode();
	RBNode(T &&_data, char _color);
	~RBNode() {};

	template <class U> friend char	getColor(RBNode<U> *node);
	template <class U> friend void	print_node(RBNode <U> *node, int level);

	RBNode<T>						*get_far_left();
	RBNode<T>						*get_far_right();
	void							swap(RBNode<T> * deleted);
	
	RBNode<T>	*uncle();
	bool		is_on_left();
	RBNode<T>	*sibling();
	void		move_down(RBNode<T> *n_parent);
	bool		has_red_child();
public:
	RBNode(T &&_data);
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

