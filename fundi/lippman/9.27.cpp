#include <forward_list>
#include <iostream>

std::forward_list<int>	find_odd_and_delete(std::forward_list<int> lst)
{
	std::forward_list<int>::iterator	prev;
	std::forward_list<int>::iterator	curr;

	if (lst.empty())
		return lst;
	prev = lst.before_begin();
	curr = lst.begin();
	while (curr != lst.end())
	{
		if (*curr % 2 != 0)
			curr = lst.erase_after(prev);
		else
		{
			prev = curr;
			curr++;	
		}
	}
	for (auto &i : lst)
	{
		std::cout << i << std::endl;
	}
	return (lst);
}

int		main()
{
	std::forward_list<int> lst {1, 2, 3, 4, 5, 6};
	find_odd_and_delete(lst);
}