#include "monom.h"

std::string				Monomial::get_str() const
{
	std::string	ans;
	std::map <char, int>::const_iterator	iter;

	iter = this->pows.begin();
	ans += std::to_string(this->n);
	while (n != 0)
	{
		ans += " ";
		ans += iter->first;
		if (iter->second != 1)
			ans += "^" + std::to_string(iter->second);
		iter++;
		if (iter == pows.end())
			break;
		ans += " *";
	}
	return (ans);
}