#pragma once

#include "../strategy/Btree.hpp"

template <class T>
class AVLtree final : public Btree<T>
{
private:
	AVLtree();
	T			data;
	AVLNode<T>	*node;

	int			left_rotates;
	int			right_rotates;

	int			big_left_rotates;
	int			big_right_rotates;

	short int	height(AVLNode<T> *x);
	int			bfactor(AVLNode<T> *x);
	void		fixheight(AVLNode<T> *x);

	AVLNode<T>	*left_rotation(AVLNode <T> *x);
	AVLNode<T>	*right_rotation(AVLNode<T> *x);

	AVLNode<T>	*big_left_rotation(AVLNode<T> *x);
	AVLNode<T>	*big_right_rotation(AVLNode<T> *x);

	AVLNode<T>	*balance(AVLNode<T> *x);
	AVLNode<T>	*insert(AVLNode<T> *x, T &&data);


	AVLNode<T>	*get_min(AVLNode<T> *x);
	AVLNode<T>	*remove_min(AVLNode<T> *x);
	AVLNode<T>	*remove(AVLNode<T> *x, T &&data);


	void		print(AVLNode<T> *x, int i);
	bool		is_avltree(AVLNode<T> *x);

public:
	AVLtree(Comparator<T> *_comp);
	void		add(T &&data) override;
	void		del(T &&data) override;
	bool		find(T &&data) const override { return true;};
	
	void		print();
	bool		is_avltree();
	void		print_rotates();
};