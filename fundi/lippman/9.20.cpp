#include <deque>
#include <list>
#include <string>
#include <iostream>

void	read_deque(std::list <int> lst)
{
	std::deque <int>			odd;
	std::deque <int>			even;
	std::list<int>::iterator	iter;

	iter = lst.begin();
	while (iter != lst.end())
	{
		if (*iter % 2)
			odd.push_back(*iter);
		else
			even.push_back(*iter);
		iter++;
	}
}