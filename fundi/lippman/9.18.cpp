#include <deque>
#include <string>
#include <iostream>

std::deque <std::string>	read_deque()
{
	std::deque <std::string>	ans;
	std::string					tmp;
	std::istream_iterator<std::string> iter(std::cin), eof;

	while (iter != eof)
	{
		ans.push_back(*iter);
		iter++;
	}
	return (ans);
}