#include <iostream>
#include <string>

std::string		replace_substr_index(std::string str, std::string from, std::string to)
{
	for (int i = 0; i < str.size(); i++)
	{
		std::cout << "str[" << i << "] = " << str[i] << std::endl;
		if (str[i] == from[0])
		{
			if (!strncmp(str.c_str() + i, from.c_str(), from.size()))
			{
				str.replace(i, from.size(), to);
				i += to.size() - 1;
			}
		}
	}
	return (str);
}

int	main()
{
	std::cout << replace_substr_index("abc 123 abcabc", "abc", "aabc123") << std::endl;
}