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

std::vector <std::string>	tokenize_this_string(const std::string str)
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

void			Monomial::add(std::string str)
{
	int		n;
	char	c;
	int		p;
	int		i;
 
	i = 0;
	n = atoi(str.c_str());
	if (str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		n = 1;
	while (isdigit(str[i]))
		i++;
	c = str[i];
	i++;
	if (str[i] == '^')
		i++;
	p = atoi(str.c_str() + i);
	if (!isdigit(str[i]))
		p = 1;
	if (this->pows.find(c) == this->pows.end())
		this->pows.insert(std::make_pair(c, p));
	else
		throw std::invalid_argument("bad string, repeating of variables");
	this->n *= n;
}

Monomial		create_monom_from_tokens(std::vector <std::string> monoms)
{
	Monomial mon;
	std::vector <std::string>::iterator iter = monoms.begin();


	while (iter != monoms.end())
	{
		mon.add(*iter);
		iter++;
	}
	std::cout << mon.get_str() << std::endl;
	return (mon);
}

Monomial::Monomial(const std::string &monom_str)
{
	Monomial mon;

	mon = create_monom_from_tokens(tokenize_this_string(monom_str));
}