#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

std::list <int>	get_unique_list(std::vector <int> vec)
{
	std::list <int>	ans (vec.size());

	std::sort(vec.begin(), vec.end());
	auto it = std::unique_copy(vec.begin(), vec.end(), ans.begin());
	ans.erase(it, ans.end());
	for (auto &i : ans)
	{
		std::cout << i << std::endl;
	}
	return (ans);
}

int		main()
{
	std::vector <int>	vec(50);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = abs(rand()) % 10;
	}
	get_unique_list(vec);
}