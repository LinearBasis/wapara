#include "polynom.hpp"

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

std::string		parse_poly_expression_to_str(std::istream &fin)
{
	Polynomial poly = parse_poly_expression(fin);
	return (poly.get_poly_str());
}


Polynomial		parse_poly_expression(std::istream &fin)
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
	return (pol3);
}

Polynomial	do_operation(Polynomial &pol1, char oper, Polynomial &pol2)
{
	Polynomial	poly(pol1);

	if (oper == '+')
	{
		poly += pol2;
	}
	else if (oper == '*')
	{
		poly *= pol2;
	}
	else if (oper == '-')
	{
		poly -= pol2;
	}
	else if (oper == '/')
	{
		if (pol2.get_size_of_first_list_element() != 1 || pol2.monoms.size() != 1
			|| !islower(pol2.get_first_char_from_first_list_element()))
			throw std::invalid_argument("BAD CHAR TO DO DY/DC");
		poly /= pol2.get_first_char_from_first_list_element();
	}
	else
	{
		throw std::invalid_argument("BAD OPERATION");
	}
	return (poly);
}

std::vector <std::vector <std::string> > parse_all_file_to_tex(std::istream &fin)
{
	std::vector <std::vector <std::string> >	ans;
	std::vector <std::string> 		tmp(4);
	Polynomial						pol1;
	Polynomial						pol2;
	Polynomial						pol3;
	std::string						oper;

	while (1)
	{
		fin >> pol1;
		std::getline(fin, oper);
		fin >> pol2;
		if (oper.size() != 1)
			throw std::invalid_argument("BAD CHAR TO DO DY/DC");
		pol3 = do_operation(pol1, oper[0], pol2);
		tmp[0] = pol1.convert();
		tmp[1] = oper;
		tmp[2] = pol2.convert();
		tmp[3] = pol3.convert();
		ans.push_back(tmp);
		std::getline(fin, oper);
		if (fin.eof() || (oper[0] != 0 && !isspace(oper[0])))
			break;
	}
	return (ans);
}