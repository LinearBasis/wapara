#include <vector>
#include <list>
#include <iostream>

void	copy_arr_to_vec_and_list()
{
	int ia[] = {0, 1, 1, 2, 3, 4, 8, 13, 21, 55, 89};
	std::list<int>				lst;
	std::vector<int>			vec;
	std::list<int>::iterator	lst_iter;
	std::vector<int>::iterator	vec_iter;

	for (int i = 0; i < 11; i++)
	{
		lst.push_back(ia[i]);
		vec.push_back(ia[i]);
	}
	lst_iter = lst.begin();
	vec_iter = vec.begin();	

	while (lst_iter != lst.end())
	{
		if (*lst_iter % 2)
			lst_iter = lst.erase(lst_iter);
		else
			lst_iter++;
	}
	while (vec_iter != vec.end())
	{
		if ((*vec_iter) % 2 == 0)
			vec_iter = vec.erase(vec_iter);
		else
			vec_iter++;
	}
	std::cout << "LST (EVEN)" << std::endl;
	for (auto &i : lst)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "VEC (ODD)" << std::endl;
	for (auto &i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int	main()
{
	copy_arr_to_vec_and_list();
}