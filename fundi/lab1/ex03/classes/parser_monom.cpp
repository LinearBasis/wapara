#include "monom.h"
#include <ctype.h>

std::string					read_number(std::string str, int &i)
{
	std::string s;

	if (str[i] == '-')
	{
		if (!isdigit(str[i + 1]))
			throw std::invalid_argument("bad string, minus without number");
		s += str[i];
		i++;
	}
	while (isdigit(str[i]))
	{
		s += str[i];
		i++;
	}
	return (s);
}

static std::string			get_token_from_i(std::string str, int &i)
{
	std::string	ans;

	if (i >= (int)str.size())
		return (ans);
	ans += read_number(str, i);
	if (islower(str[i]) && !islower(str[i + 1]))
		ans += str[i];
	else
		throw std::invalid_argument("bad string, first symb (may be after number) of token isn't lowcase alpha or second symb is lowcase alpha");
	i++;
	if (str[i] == ' ' && str[i + 1] == '*' && str[i + 2] == ' ')
	{
		i += 3;
		return (ans);
	}
	if (str[i] == '^' && !(isdigit(str[i + 1]) || str[i + 1] == '-'))
		throw std::invalid_argument("bad string, ^ without number");
	ans += str[i++];
	ans += read_number(str, i);
	if ((str[i] == ' ' && str[i + 1] == '*' && str[i + 2] == ' '))
	{
		i += 3;
		return (ans);
	}
	if (i >= (int)str.size())
		return (ans);
	throw std::invalid_argument("bad string, it can't be parsed");
}

std::vector <std::string>	tokenize_this_string(const std::string &str)
{
	int							i;
	std::string					tmp;
	std::vector <std::string>	ans;

	i = 0;
	while ((tmp = get_token_from_i(str, i)).size() > 0)
	{
		ans.push_back(tmp);
		while (str[i] == ' ')
			i++;
	}
	if (i >= (int)str.size())
		return (ans);
	else
		throw std::invalid_argument("bad string, it can't be parsed");
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

void			Monomial::add(std::string str)
{
	int		tmp_n;
	char	c;
	int		p;
	int		i;
 
	i = 0;
	tmp_n = atoi(str.c_str());
	if (str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		tmp_n = 1;
	while (isdigit(str[i]))
		i++;
	c = str[i];
	i++;
	if (str[i] == '^')
		i++;
	p = atoi(str.c_str() + i);
	if (!isdigit(str[i]) && str[i] != '-')
		p = 1;
	if (this->pows.find(c) == this->pows.end() && p >= 0)
		this->pows.insert(std::make_pair(c, p));
	else if (p < 0)
		throw std::invalid_argument("negative pow");
	else
		throw std::invalid_argument("bad string, repeating of variables");

	this->n *= tmp_n;
}

Monomial		create_monom_from_tokens(std::vector <std::string> monoms)
{
	Monomial							mon;
	std::vector <std::string>::iterator	str_iter;
	std::map<char, int>::iterator		map_iter;

	str_iter = monoms.begin();
	while (str_iter != monoms.end())
	{
		mon.add(*str_iter);
		str_iter++;
	}
	if (mon.n == 0)
		mon.pows.clear();
	return (mon);
}

std::istream&	operator>>(std::istream& fin, Monomial& monom)
{
	std::string	str;
	getline(fin, str);
	if (str[0] == 0)
		throw std::invalid_argument("empty string");
	monom = create_monom_from_tokens(tokenize_this_string(str));
	return (fin);
}
