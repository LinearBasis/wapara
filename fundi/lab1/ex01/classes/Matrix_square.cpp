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

Matrix_square		print_unary(std::string str, std::ostream &fout)
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
		fout << det(parse_string(parsed));
		fout << "";
	}
	return (matr);
		
}

Matrix_square		parse_expression(std::istream &fin, std::ostream &fout)
{
	std::string str[3];
	Matrix_square matr;


	std::getline(fin, str[0]);
	if (str[0].find("det(") != (size_t)-1 || str[0].find("trans(") != (size_t)-1
	|| str[0].find("inv(") != (size_t)-1 || str[0].find("trace(") != (size_t)-1)
		return (print_unary(str[0], fout));
	std::getline(fin, str[1]);
	std::getline(fin, str[2]);
	return (matr);
}