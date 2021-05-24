#pragma once
#include <forward_list>
#include "../list/list.hpp"

template <class T>
class collection
{
protected:
	friend class		ticket_database;

	virtual void print() const = 0;
	collection();
	~collection();
public:
	virtual void			add(const T &data) = 0;
	virtual void			del(const T &data) = 0;
	virtual bool			find(const T &data) const = 0;
	virtual void			clear() = 0;

	virtual std::iterator<std::bidirectional_iterator_tag, T>	begin() = 0;
	virtual std::iterator<std::bidirectional_iterator_tag, T>	end() = 0;
};

template <class T>
collection<T>::collection(/* args */)
{
}

template <class T>
collection<T>::~collection()
{

}


template <class T>
class collection_forward_list : public collection<T>
{
private:
	std::forward_list<T>	lst;
public:
	class Iterator_forward_list : public std::iterator<std::bidirectional_iterator_tag, T>
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
	
	void			clear() override;
	void			print() const override;
	void			add(const T &data) override;
	void			del(const T &data) override;
	bool			find(const T &data) const override;



	std::iterator<std::bidirectional_iterator_tag, T>	begin() override;
	std::iterator<std::bidirectional_iterator_tag, T>	end() override;
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
std::iterator<std::bidirectional_iterator_tag, T>	collection_forward_list<T>::begin()
{
	return (static_cast<std::iterator<std::bidirectional_iterator_tag, T> >(Iterator_forward_list(lst.begin())));
}


template <class T>
std::iterator<std::bidirectional_iterator_tag, T>	collection_forward_list<T>::end()
{
	return (static_cast<std::iterator<std::bidirectional_iterator_tag, T> >(Iterator_forward_list(lst.end())));

}



template <class T>
class collection_list : public collection<T>
{
private:
	list<T>	lst;

public:
	void	clear() override;
	void	print() const override;
	void	add(const T &data) override;
	void	del(const T &data) override;
	bool	find(const T &data) const override;
	
	std::iterator<std::bidirectional_iterator_tag, T>	begin() override;
	std::iterator<std::bidirectional_iterator_tag, T>	end() override;
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
std::iterator<std::bidirectional_iterator_tag, T>	collection_list<T>::begin()
{
	return (lst.begin());
}


template <class T>
std::iterator<std::bidirectional_iterator_tag, T>	collection_list<T>::end()
{
	return (lst.end());
}

