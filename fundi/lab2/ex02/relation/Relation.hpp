#pragma once

# include "Relation_.hpp"

template <class T>
bool Relation<T>::search_data(const T &val)
{
	typename std::forward_list<Btree<T*> *>::iterator	iter;

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
	auto iter = data.begin();
	while (iter != data.end())
	{
		std::cout << *iter << " ";
		iter++;
	}
	std::cout << std::endl;
}	

template <class T>
void	Relation<T>::insert_data(const T &val)
{
	auto iter = trees.begin();
	data.push_front(new T(val));
	std::cout << val << "|";
	while (iter != trees.end())
	{
		std::cout << val << "|";
		(*iter)->add(static_cast<T *&&>(data.front()));
		iter++;	
	}
}

template <class T>
void	Relation<T>::remove_data(const T &val)
{
	auto iter = data.begin();
	while (iter != data.end() || **iter != val)
	{
		iter++;
	}
	if (iter == data.end())
		return ;

	for (auto &i : trees)
	{
		i->del(*iter);
	}
	delete *iter;
	data.remove(iter);
}

template <class T>
void	Relation<T>::insert_index(Btree<T*> *tree)
{	
	auto iter = data.begin();
	while (iter != data.end())
	{
		tree->add(static_cast<T *&&>(*iter));
		iter++;
	}
	trees.push_front(tree);
}


template <class T>
void	Relation<T>::remove_index(Btree<T*> *tree)
{
	trees.remove(tree);
}
