#pragma once

#include <forward_list>
#include "../RB/RBtree.hpp"
#include "../AVL/AVLtree.hpp"
#include <memory>

template <class T>
class Relation
{
private:
	std::forward_list<T*>			data;
	std::forward_list<Btree<T*>* >	trees;

public:
	Relation() {};
	~Relation() {};

	bool	search_data(const T &val);
	void	print_data();
	void	insert_data(const T &val);
	void	remove_data(const T &val);
	void	insert_index(Btree<T*> *tree);
	void	remove_index(Btree<T*> *tree);

};
