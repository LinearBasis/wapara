#include "Matrix_square.h"
#include <stdlib.h>
#include <exception>
#include <string>
#include <iostream>

Matrix_square&	Matrix_square::operator=(Matrix_square &matr)
{	
	if (arr == NULL)
		free_mem();
	size = matr.size;
	alloc_mem();
	if (arr == NULL && matr.size != 0)
		throw	std::bad_alloc();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = matr[i][j];
	return (*this);
}

double*		Matrix_square::operator[](int i)
{
	return (arr[i]);
}

Matrix_square	Matrix_square::operator+(Matrix_square &matr)
{
	Matrix_square c;

	if (size != matr.size)
		throw std::logic_error("Size error");
	c.size = size;
	c.alloc_mem();
	if (!c.arr)
		return c;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = arr[i][j] + matr[i][j];
	return (c);
}

Matrix_square	Matrix_square::operator-(Matrix_square &matr)
{	
	Matrix_square c;

	if (size != matr.size)
		throw std::logic_error("Size error");
	c.size = size;
	c.alloc_mem();
	if (!c.arr)
	{
		throw std::bad_alloc();
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = arr[i][j] - matr[i][j];
	return (c);
}

Matrix_square	Matrix_square::operator-()
{
	Matrix_square c;

	c.size = size;
	c.alloc_mem();
	if (!c.arr)
	{
		throw std::bad_alloc();
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = -arr[i][j];
	return (c);
}

Matrix_square			Matrix_square::operator*(Matrix_square &matr)
{
	Matrix_square						c;

	c.size = size;
	c.alloc_mem();
	if (!c.arr)
		throw std::bad_alloc();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < size; k++)
				c[i][j] += arr[i][k] * matr[k][j];
		}
	return (c);
}

Matrix_square			Matrix_square::operator*(double num)
{
	Matrix_square						c;

	c.size = size;
	c.alloc_mem();
	if (!c.arr)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = arr[i][j] * num;
	return (c);
}

Matrix_square	operator*(double num, Matrix_square &matr)
{
	Matrix_square	c(matr);

	if (!c.arr)
		throw std::bad_alloc();
	for (int i = 0; i < matr.size; i++)
		for (int j = 0; j < matr.size; j++)
			c[i][j] *= num;
	return (c);
}

Matrix_square			Matrix_square::operator/(double num)
{
	Matrix_square						c;

	if (num == 0)
		throw std::logic_error("Zero division");
	c.size = size;
	c.alloc_mem();
	if (!c.arr)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = arr[i][j] / num;
	return (c);
}

static int		is_good_input(std::istream& fin)
{
	int						nums;
	int						tmp_n;
	int						rows;
	std::string				tmp;

	nums = -1;
	rows = 0;
	while (true)
	{
		tmp_n = 0;
		std::getline(fin, tmp);
		if (tmp[0] == 0)
			break ;
		if (tmp[tmp.size() - 1] == ' ')
			throw	std::invalid_argument("Wrong matrix format in fin");
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i] == ' ')
			{
				tmp_n++;
				while (tmp[i] == ' ')
					i++;
			}
		if (nums == -1)
			nums = tmp_n;
		else if (nums != tmp_n)
			throw	std::invalid_argument("Wrong matrix format in fin");
		rows++;
	}
	nums++;
	if (rows != nums)
		throw std::invalid_argument("Wrong matrix format in fin");
	fin.seekg(0, std::ios::beg);
    fin.clear();
    return (rows);
}

std::istream&	operator>>(std::istream& fin, Matrix_square &matr)
{
	std::vector <std::vector <double> >	matrix;
	int									rows;

	rows = is_good_input(fin);
	double tmp_d;
	for (int i = 0; i < rows; i++)
	{
		std::vector <double>	tmp_vec(rows);
        for (int j = 0; j < rows; j++)
        {
			fin >> tmp_vec[j];
            std::cout << tmp_vec[j];
        }
		matrix.push_back(tmp_vec);
	}
	matr = Matrix_square(matrix);
	return (fin);
}

std::ostream&	operator<<(std::ostream& fout, Matrix_square &matr)
{
	for (int i = 0; i < matr.size; i++)
	{
		for (int j = 0; j < matr.size; j++)
		{
			fout << matr[i][j];
			if (j != matr.size - 1)
				fout << " ";
		}
		fout << std::endl;
	}
	fout << std::endl;
	return (fout);
}