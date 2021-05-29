#pragma once

#include <iterator>

template <class T>
class node
{
	template <class U> friend class list;
private:
	T		data;
	node<T>	*prev;
	node<T>	*next;

	node() {};

public:
	node(const T &_data);
	~node();
};

template <class T>
node<T>::node(const T &_data) : prev(nullptr), next(nullptr)
{
	data = _data;
}

template <class T>
node<T>::~node()
{
}



template <class T>
class list final
{
private:
	node<T>	*begin_node;
	node<T>	*end_node;
	int		_size;

public:
	class Iterator
	{
	private:
		node<T> *curr;
	public:
		Iterator(node<T> *node) {curr = node;};
		bool		operator==(Iterator iter)
		{
			return (iter.curr == this->curr);
		}
		bool		operator!=(Iterator iter)
		{
			return (iter.curr != this->curr);
		}
		Iterator&	operator++()
		{
			curr = curr->next;
			return (*this);
		}
		Iterator&	operator--()
		{
			curr = curr->prev;
			return (*this);
		}
		T&			operator*()
		{
			return (curr->data);
		}
	};

	Iterator	begin() { return Iterator(begin_node);}
	Iterator	end() { return Iterator(nullptr);}
	Iterator	before_end() { return Iterator(end_node);}

public:
	list(/* args */);
	~list();

	void	push_front(const T &data);
	void	push_back(const T& data);
	void	pop_front();
	void	pop_back();
	void	del(const T &data);
	int		size() {return (_size);};
	void	print() const;
	void	clear();
};

template <class T>
list<T>::list()
{
	begin_node = end_node = nullptr;
	_size = 0;
}

template <class T>
void	list<T>::push_front(const T &data)
{
	node<T>	*add = new node<T>(data);

	_size++;
	if (begin_node == nullptr)
	{
		begin_node = end_node = add;
		return ;
	}
	add->next = begin_node;
	begin_node->prev = add;
	begin_node = add;
}

template <class T>
void	list<T>::push_back(const T &data)
{
	node<T>	*add = new node<T>(data);

	_size++;
	if (end_node == nullptr)
	{
		begin_node = end_node = add;
		return ;
	}
	add->prev = end_node;
	end_node->next = add;
	end_node = add;
}

template <class T>
void	list<T>::pop_back()
{
	if (end_node == nullptr)
	{
		return ;
	}
	_size--;
	if (end_node->prev == nullptr)
	{
		delete end_node;
		end_node = nullptr;
		begin_node = nullptr;
	}
	else
	{
		end_node = end_node->prev;
		delete end_node->next;
		end_node->next = nullptr;

	}
}

template <class T>
void	list<T>::pop_front()
{
	if (begin_node == nullptr)
	{
		return ;
	}
	_size--;
	if (begin_node->next == nullptr)
	{
		delete begin_node;
		begin_node = nullptr;
		end_node = nullptr;
	}
	else
	{
		begin_node = begin_node->next;
		delete begin_node->prev;
		begin_node->prev = nullptr;
	}
}


template <class T>
void	list<T>::del(const T &data)
{
	node<T>	*cpy;

	cpy = begin_node;
	while (cpy && cpy->data != data)
	{
		cpy = cpy->next;
	}
	if (!cpy)
		return ;

	if (cpy == begin_node)
	{
		pop_front();
		return ;
	}
	if (cpy == end_node)
	{
		pop_back();
		return ;
	}
	_size--;
	cpy->prev->next = cpy->next;
	cpy->next->prev = cpy->prev;
}

template <class T>
void	list<T>::clear()
{
	_size = 0;

	node<T>	*cpy;
	node<T>	*prev;

	cpy = begin_node;
	while (cpy)
	{
		prev = cpy;
		cpy = cpy->next;
		delete prev;
	}
	begin_node = end_node = nullptr;
}


template <class T>
list<T>::~list()
{
	this->clear();
}

template <class T>
void	list<T>::print() const
{
	node<T>	*cpy;

	cpy = begin_node;
	while (cpy)
	{
		std::cout << cpy->data << " ";
		cpy = cpy->next;
	}
	std::cout << std::endl;
}
