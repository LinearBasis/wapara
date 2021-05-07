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
	std::cout << "ODD:" << std::endl;
	for (auto i : odd)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "EVEN:" << std::endl;
	for (auto i : even)
		std::cout << i << " ";
	std::cout << std::endl;
}

int	main()
{
	std::list <int> lst {1, 2, 3, 4, 5, 6, 7};
	read_deque(lst);
}