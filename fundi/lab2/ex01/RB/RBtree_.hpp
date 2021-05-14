#pragma once
#include "../strategy/Btree.hpp"
#include <vector>
#include <iostream>

template <class T>
class RBtree final: public Btree<T>
{
private:
	RBNode<T>	*node;
	RBNode<T>	*naive_add(T &&data);
	
	void		check_cases(RBNode<T> *added);
	bool		check_case1(RBNode<T> *added);
	bool		check_case2(RBNode<T> *added);
	bool		check_case3(RBNode<T> *added);

	int			deep(RBNode<T> *node, int this_high, int &max);

public:
	RBtree();
	RBtree(Comparator<T> *_comp);
	~RBtree() {};

	template <class U> friend void	print_node(RBNode <U> *node, int level);
	void		print();
	
	void		add(T &&data) override;
	void		del(T &&data) override;
	bool		find(T &&data) const override;
	
	bool		is_rbtree();
	void		left_rotation(RBNode<T> **node);
	void		right_rotation(RBNode<T> **node);

	
};
