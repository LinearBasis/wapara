#include <iostream>
#include <vector>
#include <string>

std::string	vec_to_str(std::vector <char> vec)
{
	std::string	ans;

	for (auto c : vec)
	{
		ans += c;
	}
	return (ans);
}

int		main()
{
	std::vector <char>	str = {'H', 'E', 'L', 'L', 'O', '!'};
	std::cout << vec_to_str(str) << std::endl;
}