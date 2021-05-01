#include "polynom.h"

static bool			is_char_between_space(const std::string &str, int i, char c)
{
	if (str[i] == ' ' && str[i + 1] == c && str[i + 2] == ' ')
		return (true);
	return (false);
}

std::string	Polynomial::add_monom_and_return_poly_str(std::string str, int sign)
{
	Monomial	mon;

	str = mon.create_monom(str);
	monoms.push_back(mon * sign);
	return (str);
}

Polynomial	Polynomial::create_from_str(std::string str)
{
	int			sign;

	sign = 1;
	while (1)
	{
		str = add_monom_and_return_poly_str(str, sign);
		if (is_char_between_space(str, 0, '+'))
			sign = 1;
		else if (is_char_between_space(str, 0, '-'))
			sign = -1;
		else
			sign = 0;
		if (sign != 0)
			str = str.substr(3, str.size());
		if (sign == 0 && str[0] == 0)
			return (*this);
		else if (sign == 0)
			throw std::invalid_argument("BAD STRING, IT CAN'T BE PARSED");
	}
}

int		Polynomial::get_size_of_first_list_element()
{
	return (this->monoms.begin()->pows.size());
}

char		Polynomial::get_first_char_from_first_list_element()
{
	return (this->monoms.begin()->pows.begin()->first);
}

std::istream&	operator>>(std::istream& fin, Polynomial& poly)
{
	std::string						str;
	Monomial						mon;

	poly.monoms.clear();
	std::getline(fin, str);

	poly.create_from_str(str);
	poly.compress();
	return (fin);
}


std::string		parse_expression(std::istream &fin)
{
	Polynomial	pol1;
	Polynomial	pol2;
	Polynomial	pol3;
	std::string	ans;

	std::string	oper;

	fin >> pol1;
	std::getline(fin, oper);
	fin >> pol2;

	if (oper.size() != 1)
		throw std::invalid_argument("BAD CHAR TO DO DY/DC");
	pol3 = do_operation(pol1, oper[0], pol2);
	return (ans);
}


Polynomial	do_operation(Polynomial &pol1, char oper, Polynomial &pol2)
{
	Polynomial	poly(pol1);

	if (oper == '+')
	{
		pol1 += pol2;
	}
	else if (oper == '*')
	{
		pol1 *= pol2;
	}
	else if (oper == '-')
	{
		pol1 -= pol2;
	}
	else if (oper == '/')
	{
		if (pol2.get_size_of_first_list_element() != 1 || pol2.monoms.size() != 1 || pol2.)
			throw std::invalid_argument("BAD CHAR TO DO DY/DC");
		pol1 /= pol2.get_first_char_from_first_list_element();
	}
	else
	{
		throw std::invalid_argument("BAD OPERATION");
	}

}