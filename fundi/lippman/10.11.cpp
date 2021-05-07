#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool	isShorter(std::string a, std::string b)
{
	return (strcmp(a.c_str(), b.c_str()) < 0);
}

void	elimDups(std::vector <std::string> &strs)
{
	std::stable_sort(strs.begin(), strs.end(), isShorter);
	for (int i = 0; i < strs.size() - 1; i++)
	{
		std::cout << strs[i] << ":" << strs[i + 1] << std::endl;
		if (isShorter(strs[i], strs[i + 1]) == isShorter(strs[i + 1], strs[i]))
		{
			strs.erase(strs.begin() + i, strs.begin() + i + 1);
			i--;
		}
	}
	for (auto &i : strs)
	{
		std::cout << i << std::endl;
	}
}

int		main()
{
	std::vector <std::string> strs{"a", "b", "c", "d", "a", "c", "d", "a"};
	elimDups(strs);
}