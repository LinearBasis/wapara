#include <vector>
#include <string>
#include <list>

std::vector <std::string> vector_to_lst(std::list<std::string> strs)
{
	std::vector <std::string> ans;

	for (auto &i : strs)
		ans.push_back(i);
	return (ans);
}
//9.15	9.16	9.18	9.19	9.20	9.24	9.26	9.27	9.28	9.41	9.43	9.44	10.11	10.12	10.14	10.15	10.17	10.27	10.28	10.29	10.30	10.31