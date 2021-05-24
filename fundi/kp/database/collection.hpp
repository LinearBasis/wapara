#pragma once
#include <forward_list>
#include "../list/list.hpp"

template <class T>
class collection_forward_list
{
private:
	std::forward_list<T>	lst;
public:
	class Iterator_forward_list
	{
	private:
		typename std::forward_list<T>::iterator	it;

	public:
		Iterator_forward_list(typename std::forward_list<T>::iterator iter)
		{
			it = iter;
		}
		bool		operator==(Iterator_forward_list iter)
		{
			return (iter.it == this->it);
		}
		bool		operator!=(Iterator_forward_list iter)
		{
			return (iter.it != this->it);
		}
		Iterator_forward_list	operator++()
		{
			++it;
			return (*this);
		}
		Iterator_forward_list	operator--()
		{
			// it--;
			return (*this);
		}
		T&						operator*()
		{
			return (*it);
		}
	};
 
	void			clear();
	void			print() const;
	void			add(const T &data);
	void			del(const T &data);
	bool			find(const T &data) const;



	Iterator_forward_list	begin();
	Iterator_forward_list	end();
};

template <class T>
void	collection_forward_list<T>::add(const T &data)
{
	lst.push_front(data);
}

template <class T>
void	collection_forward_list<T>::del(const T &data)
{
	auto iter = lst.begin();
	auto prev = lst.before_begin();
	while (iter != lst.end() && *iter != data)
	{
		iter++;
		prev++;
	}
	if (iter == lst.end())
		return ;
	lst.erase_after(prev);
}

template <class T>
bool	collection_forward_list<T>::find(const T &data) const
{
	for (const auto iter : lst)
		if (data == iter)
			return (true);
	return (false);
}

template <class T>
void	collection_forward_list<T>::print() const
{
	for (auto i : lst)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
void	collection_forward_list<T>::clear()
{
	lst.clear();
}


template <class T>
typename collection_forward_list<T>::Iterator_forward_list	collection_forward_list<T>::begin()
{
	return ((Iterator_forward_list(lst.begin())));
}


template <class T>
typename collection_forward_list<T>::Iterator_forward_list	collection_forward_list<T>::end()
{
	return ((Iterator_forward_list(lst.end())));

}



template <class T>
class collection_list
{
private:
	list<T>	lst;

public:
	void	clear();
	void	print() const;
	void	add(const T &data);
	void	del(const T &data);
	bool	find(const T &data) const;
	
	typename list<T>::Iterator	begin();
	typename list<T>::Iterator	end();
};

template <class T>
void	collection_list<T>::add(const T &data)
{
	lst.push_front(data);
}

template <class T>
void	collection_list<T>::del(const T &data)
{
	lst.del(data);
}

template <class T>
bool	collection_list<T>::find(const T &data) const
{
	return (lst.find(data));
}

template <class T>
void	collection_list<T>::print() const
{
	lst.print();
}

template <class T>
void	collection_list<T>::clear()
{
	lst.clear();
}

template <class T>
typename list<T>::Iterator	collection_list<T>::begin()
{
	return (lst.begin());
}


template <class T>
typename list<T>::Iterator	collection_list<T>::end()
{
	return (lst.end());
}

