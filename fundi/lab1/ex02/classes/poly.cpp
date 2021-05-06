#include "polynom.hpp"

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
	std::string							ans;
	std::list<Monomial>::const_iterator	iter;

	ans = "";
	iter = monoms.begin();
	if (iter == monoms.end())
		ans = "$0$";
	while (iter != monoms.end())
	{
		ans += iter->convert();
		iter++;
		if (iter == monoms.end())
			break;
		ans += " $+$ ";
	}
	return (ans);
}

bool				is_homogeneous(const Polynomial &pol)
{
	std::list<Monomial>::const_iterator	iter;
	std::map<char, int>::const_iterator iter2;
	Polynomial							ans;
	Monomial							tmp;
	std::map<char, bool>				used;

	iter = pol.monoms.begin();
	while (iter != pol.monoms.end())
	{
		iter2 = iter->pows.begin();
		while (iter2 != iter->pows.end())
		{
			if (!used[iter2->first])
			{
				ans += pol / iter2->first / iter2->first;
				used[iter2->first] = true;
			}
			iter2++;
		}
		iter++;
	}
	if (ans.monoms.size() == 0)
		return (true);
	return (false);
}
bool				is_harmonic(const Polynomial &pol)
{
	int		i;
	int		j;

	i = -1;
	for (auto &iter_list : pol.monoms)
	{
		j = 0;
		for (auto &map_list : iter_list.pows)
		{
			j += map_list.second;
		}
		if (i == -1)
			i = j;
		else if (j != i)
			return (false);
	}
	return (true);
}