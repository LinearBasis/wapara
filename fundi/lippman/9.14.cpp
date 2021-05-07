#include <vector>
#include <string>
#include <list>
#include <iostream>

std::vector <std::string> vector_to_lst(std::list<std::string> strs)
{
	std::vector <std::string> ans;

	for (auto &i : strs)
		ans.push_back(i);
	for (auto &i : strs)
		std::cout << i << " ";
	std::cout << std::endl; 
	return (ans);
}

int main()
{
	std::list <std::string>		lst{"1", "2", "3", "4", "5"};
	vector_to_lst(lst);
}