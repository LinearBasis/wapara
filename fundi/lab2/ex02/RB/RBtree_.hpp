#pragma once
#include "../strategy/Btree.hpp"
#include <vector>
#include <iostream>

template <class T>
class RBtree final: public Btree<T>
{
private:
	RBNode<T>	*node;

	void		left_rotation(RBNode<T> *node);
	void		right_rotation(RBNode<T> *node);
	RBNode<T>	*search(T &&data) const;
	int			left_rotates;
	int			right_rotates;
	
	RBNode<T>	*naive_add(T &&data);
	void		check_cases(RBNode <T> *added);
	bool		check_case1(RBNode <T> *added);
	bool		check_case2(RBNode <T> *added);
	bool		check_case3(RBNode <T> *added);

	void		swap_colors(RBNode <T> *x1, RBNode <T> *x2);
	void		swap_values(RBNode <T> *x1, RBNode <T> *x2);
	void		fix_red_red(RBNode <T> *x);
	RBNode<T>	*BSTreplace(RBNode <T> *x);
	void		delete_node(RBNode <T> *v);
	void		fix_double_black(RBNode <T> *x);
public:
	RBtree();
	RBtree(Comparator<T> *_comp);
	~RBtree() {};

	template <class U> 
	friend void	print_node(RBNode <U> *node, int level);
	void		print();
	
	void		add(T &&data) override;
	void		del(T &&data) override;
	bool		find(T &&data) const override;
	void		print_rotates() {
					printf("left - %d\nright - %d\n", left_rotates, right_rotates);};
	
	bool		is_rbtree();
	
};
