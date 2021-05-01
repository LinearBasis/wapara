#include "monom.h"

std::string				Monomial::get_str() const
{
	std::string	ans;
	std::map <char, int>::const_iterator	iter;

	ans += std::to_string(n);
	if (n == 0)
		return (ans);
	iter = pows.begin();
	while (iter != pows.end())
	{
		ans += iter->first;
		if (iter->second != 1)
			ans += "^" + std::to_string(iter->second);
		iter++;
		if (iter == pows.end())
			break;
		ans += " * ";
	}
	return (ans);
}

bool			equal_pows(const Monomial& monom1, const Monomial& monom2)
{
	std::map<char, int>::const_iterator	iter1;
	std::map<char, int>::const_iterator	iter2;

	iter1 = monom1.pows.begin();
	iter2 = monom2.pows.begin();

	while (iter1 != monom1.pows.end() && iter2 != monom2.pows.end())
	{
		if (*iter1 != *iter2)
			return (false);
		iter1++;
		iter2++;
	}
	if (iter1 != monom1.pows.end() || iter2 != monom2.pows.end())
		return (false);
	return (true);
}

std::string				Monomial::convert() const
{
	std::string							ans;
	std::map<char, int>::const_iterator	iter;

	iter = pows.begin();
	ans += std::to_string(n);
	ans += "$";
	while (iter != pows.end())
	{
		ans += iter->first;
		if (iter->second > 1)
			ans += "^" + std::to_string(iter->second);
		iter++;
		if (iter != pows.end())
			ans += " * ";
	}
	ans += "$";
	return (ans);
}
