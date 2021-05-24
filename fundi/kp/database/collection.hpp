#pragma once
#include <forward_list>
#include "../list/list.hpp"

template <class T>
class collection
{
protected:
	friend class ticket_database;

	virtual void print() const = 0;
	collection();
	~collection();
public:
	virtual void	add(const T &data) = 0;
	virtual void	del(const T &data) = 0;
	virtual bool	find(const T &data) const = 0;
	virtual void	clear() = 0;
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
	void	clear() override;
	void	print() const override;
	void	add(const T &data) override;
	void	del(const T &data) override;
	bool	find(const T &data) const override;
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
