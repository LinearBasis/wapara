#include <vector>
#include <list>
#include <iostream>

bool	is_equal_vec_and_lst(std::vector <int> vec, std::list <int> lst)
{
	if (vec.size() != lst.size())
		return (false);
	std::vector <int> :: iterator	iter_vec;
	std::list<int>::iterator		iter_lst;

	iter_vec = vec.begin();
	iter_lst = lst.begin();
	while (iter_vec != vec.end() && iter_lst != lst.end())
	{
		if (*iter_vec != *iter_lst)
			return (false);
		iter_lst++;
		iter_vec++;
	}
	return (true);
}

int	main()
{
	std::vector <int>	vec{1, 2, 3, 5, 4};
	std::list <int>		lst{1, 2, 3, 4, 5};
	std::cout << is_equal_vec_and_lst(vec, lst) << std::endl;
}