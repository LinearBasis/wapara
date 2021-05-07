#include <vector>

bool	is_int_between_iters(std::vector <int>::iterator begin, 
			std::vector <int>::iterator end, int i)
{
	while (begin != end)
	{
		if (*begin == i)
			return (true);
		begin++;
	}
	return (false);
}