#include "polynom.h"

void	Polynomial::clear_zeroes()
{
	std::list <Monomial>::iterator	iter;
	
	iter = monoms.begin();
	while (iter != monoms.end())
	{
		if (iter->n == 0)
			iter = monoms.erase(iter);
		else
			iter++;
	}
}

void	Polynomial::compress()						// O(nlogn)
{
	std::map <std::map<char, int>, int>				mons;
	std::map <std::map<char, int>, int>::iterator	iter_map;
	std::list<Monomial>::iterator					iter_list;

	iter_list = monoms.begin();
	while (iter_list != monoms.end())
	{
		mons[iter_list->pows] += iter_list->n;
		iter_list++;
	}
	monoms.clear();
	iter_map = mons.begin();
	while (iter_map != mons.end())
	{
		if (iter_map->second)
			monoms.push_back(Monomial(iter_map->first, iter_map->second));
		iter_map++;
	}
}

std::string	Polynomial::convert() const
{
	return ("");	
}
