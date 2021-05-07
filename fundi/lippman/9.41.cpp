#include <vector>
#include <string>

std::string	vec_to_str(std::vector <char> vec)
{
	std::string	ans;

	for (auto c : vec)
	{
		ans += c;
	}
	return (ans);
}