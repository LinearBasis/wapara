#include "monom.hpp"
#include <ctype.h>

void						skip_spaces(std::string str, int &i)
{
	while (isspace(str[i]))
		i++;
}

int read_number(std::string str, int &i)
{
	int	n;

	if (islower(str[i]))
		return (1);
	n = atoi(str.c_str() + i);
	if (str[i] == '-')
	{
		if (!isdigit(str[i + 1]))
			throw std::invalid_argument("bad string, minus without number");
		i++;
	}
	while (isdigit(str[i]))
		i++;
	return (n);
}

char					read_var_name(std::string str, int &i)
{
	if (islower(str[i]))
	{
		i++;
		return (str[i - 1]);
	}
	else
		throw std::invalid_argument("expected variable name");
}

int						read_pow(std::string str, int &i)
{
	int	n;

	if (str[i] == '^')
		i++;
	else if (isspace(str[i]) || str[i] == 0)
		return (1);
	else
		throw std::invalid_argument("excepted ^ or space");
	n = atoi(str.c_str() + i);
	if (str[i] == '-')
		i++;
	if (!isdigit(str[i]))	//если после ^ или ^- нет числа
		throw std::invalid_argument("excepted number after ^");
	while (isdigit(str[i]))
		i++;
	if (!isspace(str[i]) && str[i] != 0)
		throw std::invalid_argument("bad space after number");
	return (n);
}

static bool			is_char_between_space(const std::string &str, int i, char c)
{
	if (str[i] == ' ' && str[i + 1] == c && str[i + 2] == ' ')
		return (true);
	return (false);
}

int				Monomial::add_one_variable(std::string str, int &i) //part of monom is a * (name^k)
{
	int		a;
	char	name;
	int		k;
	
	a = read_number(str, i);
	if (str[i] == 0)
	{
		n *= a;
		return (1);
	}
	name = read_var_name(str, i);
	k = read_pow(str, i);

	if (pows.find(name) == pows.end())
	{
		pows.insert(std::make_pair(name, k));
	}
	else if (k < 0)
		throw std::invalid_argument("negative pow");
	else if (k == 0)
		throw std::invalid_argument("zero pow");
	else
		throw std::invalid_argument("bad string, repeating of variables");
	n *= a;
	if (str[i] == 0)
		return (0);
	return (1);
}

std::string		Monomial::create_monom(std::string str)
{
	Monomial	ans;
	int			i;

	i = 0;
	while (1)
	{
		if (!add_one_variable(str, i)) // ЭТОТ ВАРИАНТ ПРОИСХОДИТ ПРИ КОНЦЕ СТРОКИ
			return (std::string(""));
		if (is_char_between_space(str, i, '*'))
			i += 3;
		else
			return (str.substr(i, str.size()));
	}
}