#include <list>
#include <string>
#include <iostream>

std::list	<std::string>	read_list()	// НЕОБХОДИМОЕ ИЗМЕНЕНИЕ ЛОЛ
{
	std::list <std::string>	ans;	// НЕОБХОДИМОЕ ИЗМЕНЕНИЕ ЛОЛ
	std::string					tmp;
	std::istream_iterator<std::string> iter(std::cin), eof;

	while (iter != eof)
	{
		ans.push_back(*iter);
		iter++;
	}
	return (ans);
}