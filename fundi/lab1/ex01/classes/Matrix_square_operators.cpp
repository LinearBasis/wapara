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
	int						pos;

	pos = fin.tellg();
	nums = -1;
	rows = 0;
	while (std::getline(fin, tmp) && tmp[0] != 0)
	{
		tmp_n = 0;
		std::cout << tmp << std::endl;
		if (tmp[tmp.size() - 1] == ' ')
			throw	std::invalid_argument("Wrong matrix format in fin");
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i] == ' ')
			{
				tmp_n++;
				while (tmp[i] == ' ')
					i++;
				i--;
			}
		if (nums == -1)
			nums = tmp_n;
		else if (nums != tmp_n || rows > nums)
		{
			std::cout << rows << " " << nums << std::endl;
			throw	std::invalid_argument("Wrong matrix format in fin");
		}
		rows++;
	}
	fin.clear();
	fin.seekg(pos, std::ios_base::beg);
	std::cout << pos << " " << fin.tellg() << std::endl;

	nums++;
	if (rows != nums)
		throw std::invalid_argument("Wrong matrix format in fin");
	std::cout << rows << " " << nums << std::endl;
    return (rows);
}

std::istream&	operator>>(std::istream& fin, Matrix_square &matr)
{
	std::vector <std::vector <double> >	matrix;
	int									rows;
	std::string tmp;

	try
	{
		rows = is_good_input(fin);
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
		Matrix_square abc(matrix);
		matr = abc;
		return (fin);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return (fin);
	}
}

std::ostream&	operator<<(std::ostream& fout, Matrix_square &matr)
{
	if (matr.size == 0)
	{
		fout << "ZERO MATRIX" << std::endl;
	}
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

bool			Matrix_square::operator==(Matrix_square &matr)
{
	if (matr.size != size)
		return (false);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matr[i][j] != arr[i][j])
				return (false);
	return (true);
}

bool			Matrix_square::operator!=(Matrix_square &matr)
{
	return (!(matr == *this));
}

void			swap(double *arr1, double *arr2, int size)
{
	double	tmp1;
	
	for (int i = 0; i < size; i++)
	{
		tmp1 = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp1;
	}
}

double			det(Matrix_square &matr)
{
	Matrix_square	copy = matr;
	double			index;
	int				sign;
	double			det;

	sign = 1;
	det = 1;
	if (matr.size == 0)
		return (0);
	for (int i = 0; i < matr.size; i++)
		for (int j = i + 1; j < matr.size; j++)
		{
			if (copy[i][i] == 0)
				for (int l = i + 1; l < matr.size; l++)
					if (copy[l][i] != 0)
					{
						swap(copy[l], copy[i], matr.size);
						sign *= -1;
						break;
					}
			if (copy[i][i] == 0)
				return (0);
			index = copy[j][i] / copy[i][i];
			for (int k = 0; k < matr.size; k++)
				copy[j][k] -= index * copy[i][k];
		}
	for (int i = 0; i < matr.size; i++)
		det *= copy[i][i];
	std::cout << copy;
	return (det * sign);
}