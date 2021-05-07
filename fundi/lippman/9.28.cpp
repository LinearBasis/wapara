#include <iostream>
#include <forward_list>
#include <string>

std::forward_list <std::string>	f(std::forward_list <std::string> lst, std::string str1, std::string str2)
{
	std::forward_list <std::string>::iterator	iter;
	std::forward_list <std::string>::iterator	before_end;

	iter = lst.begin();
	if (iter == lst.end())
	{
		lst.push_front(str2);
		return (lst);
	}
	while (iter != lst.end())
	{
		if (*iter == str1)
		{
			lst.insert_after(iter, str2);
			return (lst);
		}
		before_end = iter;
		iter++;
	}
	lst.insert_after(before_end, str2);
	iter = lst.begin();
	
	return (lst);
}

int		main()
{
	std::forward_list <std::string> lst = {};
	lst = f(lst, "abb", "45");
	for (auto &i : lst)
	{
		std::cout << i << std::endl;
	}
}