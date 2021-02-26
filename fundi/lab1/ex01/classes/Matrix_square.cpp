/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_square.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:19:34 by dnicki            #+#    #+#             */
/*   Updated: 2021/02/19 19:26:47 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix_square.h"


void	Matrix_square::free_mem()
{
	for (int i = 0; i < size && arr && arr[i]; i++)
		delete[] arr[i];
	if (arr)
		delete[] arr;
	arr = NULL;
	size = 0;
}

void	Matrix_square::alloc_mem()
{
	if (size == 0)
	{
		arr = NULL;
		return ;
	}
	arr = new double*[size];
	if (!arr)
		return;
	for (int i = 0; i < size; i++)
	{
		if (!(arr[i] = new double[size]))
		{
			free_mem();
			return;
		}				
	}
}

void			Matrix_square::E(int size_)
{
	size = size_;
	alloc_mem();
	if (!arr)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = (i == j);
}

static bool is_number(std::string asd)
{
	for (int i = 0; i < (int)asd.size(); i++)
	{
		if (!isdigit(asd[i]))
			return false;
	}
	return true;
}

std::string		get_binary(std::vector <std::string> &operations)
{
	int	types[2] = {1, 1}; //1 - matr, 0 - number
	Matrix_square	matr1, matr2;
	double			d;

	for (int i = 0; i < (int)operations.size(); i++)
		std::cout << operations[i] << std::endl;
	if (isdigit(operations[0][0]))
		types[0] = 0;
	if (isdigit(operations[2][0]))
		types[1] = 0;
	if (!types[0] && !types[1])
		throw std::invalid_argument("bad matrix in input");
	if ((!types[0] && !is_number(operations[0])) || (!types[1] && !is_number(operations[2])))
		throw std::invalid_argument("number in wrong format");
	if (types[0] == 0)
	{
		d = atof(operations[0].c_str());
		matr1 = parse_string(operations[2]);
	}
	else if (types[1] == 0)
	{
		d = atof(operations[2].c_str());
		matr1 = parse_string(operations[0]);
	}
	else
	{
		matr1 = parse_string(operations[0]);
		matr2 = parse_string(operations[2]);
	}
	bool is_num = !types[1] || !types[0];
	if ((operations[1][0] == '+' || operations[1][0] == '-')
			 && (is_num))
		throw std::invalid_argument("operations error, matrix and number can only mult");
	if (types[0] && operations[1][0] == '/')
		throw std::invalid_argument("operations error, (number / matrix) is UB");
	if (is_num && operations[1][0] == '/')
		return (get_string_to_out(matr1 / d));
	else if (is_num && operations[1][0] == '*')
		return (get_string_to_out(matr1 * d));

	else if (!is_num && operations[1][0] == '*')
		return (get_string_to_out(matr1 * matr2));
	else if (!is_num && operations[1][0] == '+')
		return (get_string_to_out(matr1 + matr2));
	else if (!is_num && operations[1][0] == '-')
		return (get_string_to_out(matr1 - matr2));
	else if (!is_num && operations[1][0] == '/')
		throw std::invalid_argument("operations error, (matrix / matrix) is UB");
	else
		throw std::invalid_argument("i don't know wat u do");
}

std::string		get_unary(std::string str)
{
	Matrix_square	matr;
	std::string		parsed;

	std::cout << str.find("[") << std::endl;
	if (str.find("det(") != (size_t)-1)
	{
		std::cout << str << std::endl;
		if (str[4] != '[' || str[str.size() - 1] != ')')
			throw std::invalid_argument("Bad string");
		parsed = str.substr(4, str.size() - 1 - 4);	//-1 по причине ), -4 по причине det(
		std::cout << parsed << std::endl;
		return (std::to_string(det(parse_string(parsed))));
	}
	return (get_string_to_out(matr));
}

std::vector<std::string>	parse_expression(std::istream &fin)
{
	std::vector <std::string> answer;
	std::string str;


	std::getline(fin, str);
	answer.push_back(str);
	if (str.find("det(") != (size_t)-1 || str.find("trans(") != (size_t)-1
	|| str.find("inv(") != (size_t)-1 || str.find("trace(") != (size_t)-1)
	{
			answer.push_back(get_unary(str));
			return (answer);
	}
	std::getline(fin, str);
	answer.push_back(str);
	if (!(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') || str.size() != 1)
	{
		throw std::invalid_argument("bad operations in parse string");
	}
	std::getline(fin, str);
	answer.push_back(str);
	answer.push_back(get_binary(answer));
	return (answer);
}