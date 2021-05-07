#include <vector>
#include <list>
#include <deque>
#include <iostream>

void	copy_vec(std::vector <int> vec)
{
	std::vector <int>	ans1;
	std::list <int>		ans2;
	std::deque <int>	ans3;

	copy(vec.begin(), vec.end(), std::inserter(ans1, ans1.begin()));
	copy(ans1.begin(), ans1.end(), std::back_inserter(ans2));
	copy(ans2.begin(), ans2.end(), std::front_inserter(ans3));
	
	std::cout << "vec:" << std::endl;
	for (auto &i : ans1)
		std::cout << i << std::endl;
	std::cout << "list:" << std::endl;
	for (auto &i : ans2)
		std::cout << i << std::endl;
	std::cout << "deque:" << std::endl;
	for (auto &i : ans3)
		std::cout << i << std::endl;
}

int	main()
{
	std::vector <int> a{1, 2, 3, 4, 5, 6};
	copy_vec(a);
}