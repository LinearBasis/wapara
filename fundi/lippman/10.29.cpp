#include <vector>
#include <string>
#include <iostream>

std::vector <std::string>	read_vector()
{
	std::vector <std::string>	ans;
	std::string					tmp;
	std::istream_iterator<std::string> iter(std::cin), eof;

	while (iter != eof)
	{
		ans.push_back(*iter);
		iter++;
	}
	return (ans);
}

int	main()
{
	std::vector <std::string>	vec;

	vec = read_vector();
	for (auto &i : vec)
	{
		std::cout << i << std::endl;
	}
}