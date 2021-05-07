#include <vector>
#include <list>

bool	is_equal_vec(std::vector <int> vec1, std::list <int> vec2)
{
	if (vec1.size() != vec2.size())
		return (false);
	std::vector <int> :: iterator	iter_vec;
	std::list<int>::iterator		iter_lst;
	while (iter_vec != vec1.end())
	{
		if (*iter_vec != *iter_lst)
			return (false);
		iter_lst++;
		iter_vec++;
	}
	return (true);
}