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

	if (isdigit(operations[0][0]))
		types[0] = 0;
	if (isdigit(operations[2][0]))
		types[1] = 0;
	if (!types[0] && !types[1])
		throw std::invalid_argument("bad matrix in input");
	if ((!types[0] && !is_number(operations[0])) ||
		 (!types[1] && !is_number(operations[2])))
		throw std::invalid_argument("number in wrong format");
	if (types[0] == 0)
	{
		d = atof(operations[0].c_str());
		matr1 = get_matrix_from_string(operations[2]);
	}
	else if (types[1] == 0)
	{
		d = atof(operations[2].c_str());
		matr1 = get_matrix_from_string(operations[0]);
	}
	else
	{
		matr1 = get_matrix_from_string(operations[0]);
		matr2 = get_matrix_from_string(operations[2]);
	}
	bool is_num = !types[1] || !types[0];
	if ((operations[1][0] == '+' || operations[1][0] == '-') && (is_num))
		throw std::invalid_argument("operations error, matrix and number can only mult");
	if (types[0] && operations[1][0] == '/')
		throw std::invalid_argument("operations error, (number / matrix) is UB");
	if (is_num && operations[1][0] == '/')
		return (get_string_from_matrix(matr1 / d));
	else if (is_num && operations[1][0] == '*')
		return (get_string_from_matrix(matr1 * d));

	else if (!is_num && operations[1][0] == '*')
		return (get_string_from_matrix(matr1 * matr2));
	else if (!is_num && operations[1][0] == '+')
		return (get_string_from_matrix(matr1 + matr2));
	else if (!is_num && operations[1][0] == '-')
		return (get_string_from_matrix(matr1 - matr2));
	else if (!is_num && operations[1][0] == '/')
		throw std::invalid_argument("operations error, (matrix / matrix) is UB");
	else
		throw std::invalid_argument("i don't know wat did u do");
}


/*
** тут прикол, она вернет -1 в случае ошибки либо длину слова-операции над матрицей
*/
int							check_is_binary(std::string str)
{
	int ans;
	if (str.find("det(") != (size_t)-1 || str.find("inv(") != (size_t)-1 || str.find("exp(") != (size_t)-1)
		ans = 3;
	else if(str.find("trace(") != (size_t)-1 || str.find("trans(") != (size_t)-1)
		ans = 5;
	else
		return (0);
	if (str[ans + 1] == '[' && str[str.size() - 1] == ')')
		return (ans);
	return (0);
}

std::string		get_operator_string_from_unary(std::string str)
{
	std::string	ans;
	int			sub_begin;

	sub_begin = check_is_binary(str);
	if (!sub_begin)
		throw std::invalid_argument("Bad string");
	ans = str.substr(0, sub_begin);
	return (ans);
}

std::string		get_matrix_string_from_unary(std::string str)
{
	std::string	ans;
	int			sub_begin;

	sub_begin = check_is_binary(str);
	if (!sub_begin)
		throw std::invalid_argument("Bad string");
	ans = str.substr(sub_begin + 1, str.size() - sub_begin - 2);
	return (ans);
}


std::string		get_unary(std::string str)
{
	Matrix_square	matr;
	std::string		parsed;


	parsed = get_matrix_string_from_unary(str);
	std::cout << parsed << std::endl;
	if (str.find("det(") != (size_t)-1)
		return (good_double_to_string(det(get_matrix_from_string(parsed))));
	else if (str.find("trace(") != (size_t)-1)
		return (good_double_to_string(trace(get_matrix_from_string(parsed))));
	else if (str.find("inv(") != (size_t)-1)
		return (get_string_from_matrix(inv(get_matrix_from_string(parsed))));
	else if (str.find("trans(") != (size_t)-1)
		return (get_string_from_matrix(trans(get_matrix_from_string(parsed))));
	else if (str.find("exp(") != (size_t)-1)
		return (get_string_from_matrix(exp(get_matrix_from_string(parsed))));
	return (get_string_from_matrix(matr));
}

std::vector <std::string>	parse_expression(std::istream &fin)
{
	std::vector <std::string> answer;
	std::string str;

	while (!fin.eof() && str.size()  == 0)
		std::getline(fin, str);
	if (fin.eof() && str.size() == 0)
		return (answer);
	answer.push_back(str);
	if (str.find("det(") != (size_t)-1 || str.find("trans(") != (size_t)-1
	|| str.find("inv(") != (size_t)-1 || str.find("trace(") != (size_t)-1 ||
	str.find("exp(") != (size_t)-1)
	{
			answer.push_back(get_unary(str));
			std::getline(fin, str);
			if (str[0] != 0 && !fin.eof())
				throw std::invalid_argument("Need indent after expr");
			return (answer);
	}
	std::getline(fin, str);
	if (str[0] == 0)
	{
		throw std::invalid_argument("Empty string");
	}
	answer.push_back(str);
	if (!(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
						|| str.size() != 1)
	{
		throw std::invalid_argument("bad operations in parse string");
	}
	std::getline(fin, str);
	if (str[0] == 0)
	{
		throw std::invalid_argument("Empty string");
	}
	answer.push_back(str);
	answer.push_back(get_binary(answer));
	std::getline(fin, str);
	if (str[0] != 0 && !fin.eof())
		throw std::invalid_argument("Need indent after expr");
	return (answer);
}

std::string		mult_str(const std::string &str, int n)
{
	std::string ans;

	while (n--)
		ans += str;
	return (ans);
}

std::string	Matrix_square::convert() const
{
	std::string	ans;

	if (size <= 0)
		return (std::string("error"));
	ans += "\\begin{equation*}\n";
	ans += "\t\\left(\n";
	ans += "\t\t\\begin{array}{" + mult_str(std::string("c"), size) + "}\n";
	for (int i = 0, j = 0; i < size; i++, j = 0)
	{
		ans += "\t\t\t";
		while (j < size) //ИЗОБРЕЛ СЕЛЕКЦИЮ (не бейте, я поржать)
		{
			ans += good_double_to_string(arr[i][j++]);
			if (j < size)
				ans += " & ";
			else if (i < size - 1)
				ans += "\\\\\n";
			else
				ans += "\n";
		}
	}
	ans += "\t\t\\end{array}\n";
	ans += "\t\\right)\n";
	ans += "\\end{equation*}\n";
	return (ans);
}


std::string	get_string_of_tex_expressions(std::vector <std::vector <std::string> > expressions)
{
	std::string ans;

	for (int i = 0; i < (int)expressions.size(); i++)
	{
		if (expressions[i].size() == 1)
			continue ;
		for (int j = 0; j < (int)expressions[i].size(); j++)
		{
			std::cout << expressions[i][j] << std::endl;
		}
		if (expressions[i].size() == 2)
		{
			ans += get_operator_string_from_unary(expressions[i][0]);
			ans += get_matrix_from_string(get_matrix_string_from_unary(expressions[i][0])).convert();
			ans += " = ";
			if (expressions[i][1][0] == '[')
				ans += get_matrix_from_string(expressions[i][1]).convert();
			else
				ans += expressions[i][1];
		}
		else if (expressions[i].size() == 4)
		{
			if (expressions[i][0][0] == '[')
				ans += get_matrix_from_string(expressions[i][0]).convert();
			else
				ans += expressions[i][0];
			ans += " " + expressions[i][1] + " ";
			if (expressions[i][2][0] == '[')
				ans += get_matrix_from_string(expressions[i][2]).convert() + " ";
			else
				ans += expressions[i][2];
			ans += " = ";
			ans += get_matrix_from_string(expressions[i][3]).convert();
		}
		ans += "\n\n";
	}
	return (ans);
}
