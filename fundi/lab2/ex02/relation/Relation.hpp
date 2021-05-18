#pragma once

# include "Relation_.hpp"

template <class T>
bool Relation<T>::search_data(T &&val)
{
	std::forward_list<Btree<T*> *>::iterator	iter;

	iter = trees.begin();

	while (iter != trees.end())
	{
		if ((*iter)->find(val))
			return (true);
		iter++;
	}
	return (false);
}

template <class T>
void	Relation<T>::print_data()
{
	std::forward_list<T *>::iterator	iter;

	iter = data.begin();
	while (iter != data.end())
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << std::endl;
}	

template <class T>
void	Relation<T>::insert_data(T &&val)
{
	data.push_front(val);
	for (auto &i : trees)
	{
		i->add(&(data.front()));
	}
}

template <class T>
void	Relation<T>::remove_data(T &&val)
{
	data.remove(val);
	for (auto &i : trees)
	{
		i->del(val);
	}
}

template <class T>
void	Relation<T>::insert_index(Btree<T*> *tree)
{
	std::forward_list<T>::iterator	iter;
	
	iter = data.begin();
	while (iter != data.end())
	{
		tree->add(iter);
		iter++;
	}
}


template <class T>
void	Relation<T>::remove_index(Btree<T*> *tree)
{
	trees.remove(tree);
}
