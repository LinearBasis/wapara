#include <string>
#include <iostream>

std::string		replace_substr(std::string str, std::string from, std::string to)
{
	std::string::iterator	iter_str;
	std::string::iterator	iter1;
	std::string::iterator	iter2;

	iter_str = str.begin();
	while (iter_str != str.end())
	{
		if (*iter_str == *from.begin())
		{
			iter1 = iter_str;
			iter2 = from.begin();
			while (iter1 != str.end() && iter2 != from.end() && *iter1 == *iter2)
			{
				iter1++;
				iter2++;
			}
			if (iter2 == from.end())
			{
				str.erase(iter_str, iter_str + from.size());
				str.insert(iter_str, to.begin(), to.end());
				iter_str += to.size();
			}
			else
				iter_str++;
		}
		else
			iter_str++;
	}
	return (str);
}

int	main()
{
	std::cout << replace_substr("abc 123 abcabc", "abc", "aabc") << std::endl;
}