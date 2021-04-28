#include "polynom.h"

std::istream&	operator>>(std::istream& fin, Polynomial& poly)
{
	std::string					str;
	std::vector<std::string>	mon_strs;

	poly.monoms.clear();
	std::getline(fin, str);
	mon_strs = tokenize_this_string(str, "+-");
	for (const auto &i : mon_strs)
	{
		std::cout << i << std::endl;
	}
	return (fin);
}
