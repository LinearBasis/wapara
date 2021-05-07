#include <vector>

std::vector <int> ::iterator	find_int_between_vector(
		std::vector <int>::iterator begin, std::vector <int>::iterator end,
														int i)
{
	while (begin != end)
	{
		if (*begin == i)
			return (begin);
		begin++;
	}
	return (begin);
}