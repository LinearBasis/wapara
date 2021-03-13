#include "monom.h"

std::string				Monomial::get_str()
{
	std::string	ans;
	std::map <char, int>::iterator iter;
	std::map <char, int>::iterator ender;

	if (this->pows.size() == 0)
		return (ans);
	iter = this->pows.begin();
	ender = this->pows.end();
	ans += std::to_string(this->n);
	while (1)
	{
		ans += iter->first;
		if (iter->second != 1)
			ans += "^" + std::to_string(iter->second);
		iter++;
		if (iter == ender)
		{
			break;
		}
		ans += " * ";
	}
	return (ans);
}