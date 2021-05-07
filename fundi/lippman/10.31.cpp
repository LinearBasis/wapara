#include <vector>
#include <iostream>
// -std=c++99
void	read_and_sort_vector()
{
	std::vector <int>			vec;
	std::vector <int>			sorted_vec;
	std::istream_iterator<int>	iter(std::cin), eof;

	while (iter != eof)
	{
		vec.push_back(*iter);
		iter++;
	}
	copy(vec.begin(), vec.end(), std::inserter(sorted_vec, sorted_vec.begin()));


	sort(sorted_vec.begin(), sorted_vec.end(), ([](int a, int b) { return a > b;}));
	
	
	auto it = std::unique(sorted_vec.begin(), sorted_vec.end());
	sorted_vec.erase(it, sorted_vec.end());

	for (auto &i : sorted_vec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int		main()
{
	read_and_sort_vector();
}