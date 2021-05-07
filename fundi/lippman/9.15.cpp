#include <vector>
#include <iostream>

bool	is_equal_vec(std::vector <int> vec1, std::vector <int> vec2)
{
	if (vec1.size() != vec2.size())
		return (false);
	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec1[i] != vec2[i])
			return (false);
	}
	return (true);
}

int	main()
{
	std::vector <int>	vec1{1, 2, 3, 5, 4};
	std::vector <int>	vec2{1, 2, 3, 4, 5};
	std::cout << is_equal_vec(vec1, vec2) << std::endl;
}