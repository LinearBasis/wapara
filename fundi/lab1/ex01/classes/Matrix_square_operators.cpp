#include "Matrix_square.h"
#include <cctype>
#include <math.h>

Matrix_square&	Matrix_square::operator=(const Matrix_square &matr)
{
	if (arr != NULL)
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

double*		Matrix_square::operator[](int i) const
{
	return (arr[i]);
}

void			Matrix_square::operator+=(const Matrix_square &matr)
{
	if (size != matr.size)
		throw std::logic_error("Size error");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] += matr[i][j];
}

void			Matrix_square::operator-=(const Matrix_square &matr)
{
	if (size != matr.size)
		throw std::logic_error("Size error");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] -= matr[i][j];
}

void			Matrix_square::operator*=(const Matrix_square &matr)
{
	Matrix_square	c;

	c.size = size;
	c.alloc_mem();
	if (!c.arr && matr.arr)
		throw std::bad_alloc();
	if (size != matr.size)
		throw std::logic_error("Sizes aren't same");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < size; k++)
				c[i][j] += arr[i][k] * matr[k][j];
		}
	*this = c;
}

void			Matrix_square::operator*=(double num)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] *= num;
}

void			Matrix_square::operator/=(double num)
{
	if (abs(num) < 1E-8)
		throw std::logic_error("Zero division");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] /= num;
}

Matrix_square	Matrix_square::operator+(const Matrix_square &matr) const
{
	Matrix_square c(*this);

	if (c.arr == NULL && this->arr != NULL)
		throw std::bad_alloc();

	c += matr;
	return (c);
}

Matrix_square	Matrix_square::operator-(const Matrix_square &matr) const
{
	Matrix_square c(*this);

	if (c.arr == NULL && this->arr != NULL)
		throw std::bad_alloc();
	c -= matr;
	return (c);
}

Matrix_square	Matrix_square::operator-() const
{
	Matrix_square c;

	if (size == 0)
		throw std::logic_error("Can't negate empty matrix");
	c.size = size;
	c.alloc_mem();
	if (!c.arr)
		throw std::bad_alloc();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			c[i][j] = -arr[i][j];
	return (c);
}

Matrix_square	Matrix_square::operator*(const Matrix_square &matr) const
{
	Matrix_square	c(*this);

	if (c.arr == NULL && this->arr != NULL)
	{
		throw std::bad_alloc();
	}
	c *= matr;
	return (c);
}

Matrix_square	operator*(double num, const Matrix_square &matr)
{
	Matrix_square	c(matr);

	if (c.arr == NULL && matr.arr != NULL )
		throw std::bad_alloc();
	c *= num;
	return (c);
}

Matrix_square	Matrix_square::operator*(double num) const
{
	Matrix_square	c(*this);

	if (c.arr == NULL && this->arr != NULL)
		throw std::bad_alloc();
	c *= num;
	return (c);
}

Matrix_square	Matrix_square::operator/(double num) const
{
	Matrix_square						c(*this);

	if (c.arr == NULL && this->arr != NULL )
		throw std::bad_alloc();
	c /= num;
	return (c);
}

static	double	check_is_double(std::string	str, int &i)
{
	using namespace std;

	int ind;

	ind = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		throw std::invalid_argument("Reading matrix error");
	while (isdigit(str[i]))
		i++;
	if (str[i] == ' ' || str[i] == ']')
	{
		return atof(str.c_str() + ind);
	}
	else if (str[i] == '.' && isdigit(str[i + 1]))
		i++;
	else
		throw std::invalid_argument("Reading matrix error");
	while (isdigit(str[i]))
		i++;
	if (str[i] == ' ' || str[i] == ']')
		return atof(str.c_str() + ind);
	throw std::invalid_argument("Reading matrix error");
}

Matrix_square	get_matrix_from_string(std::string readed)
{
	std::vector <std::vector <double> > matrix;
	int i;
	int row;
	int col;

	i = 1;
	col = -1;
	row = 0;

	if (readed[0] != '[' || readed[readed.size() - 1] != ']')
		throw std::invalid_argument("error, open-bracket (or close-bracket) is missed");
	while (readed[i])
	{
		std::vector	<double>				tmp;
		if (readed[i] == '[')
			i++;
		else if(readed[i] == ']')
			break;
		else
			throw std::invalid_argument("undefined symb");
		while (readed[i] != ']')
		{
			tmp.push_back(check_is_double(readed, i));
			if (readed[i] != ' ' && readed[i] != ']')
				throw std::invalid_argument("format error");
			if (readed[i] == ' ' && isdigit(readed[i + 1]))
				i++;
		}
		if (col == -1)
			col = tmp.size();
		else if (col != (int)tmp.size())
			throw std::invalid_argument("len of rows aren't equal");
		matrix.push_back(tmp);
		i++;
		row++;
	}
	if (col != row)
		throw std::invalid_argument("cols aren't equal rows");
	Matrix_square m(matrix);

	return (m);
}

std::istream&	operator>>(std::istream& fin, Matrix_square &matr)
{
	std::string readed;
	std::getline(fin, readed);

	matr = get_matrix_from_string(readed);

	return (fin);
}

std::string	good_double_to_string(double d)
{
	std::string to_str;

	to_str = std::to_string(d);
	if (to_str.find(".") == (size_t)-1)
		return (to_str);
	else
		while (to_str[to_str.size() - 1] == '0')
			to_str = to_str.substr(0, to_str.size() -1 );
	if (to_str[to_str.size() - 1] == '.')
		to_str = to_str.substr(0, to_str.size() -1 );
	return (to_str);
}

std::string		get_string_from_matrix(const Matrix_square &matr)
{
	std::string ans = "";
	ans += std::string("[");
	for (int i = 0; i < matr.size; i++)
	{
		ans += std::string("[");
		for (int j = 0; j < matr.size; j++)
		{
			ans += good_double_to_string(matr[i][j]);
			if (j != matr.size - 1)
				ans += std::string(" ");
		}
		ans += std::string("]");
	}
	ans += std::string("]");
	return (ans);
}

std::ostream&	operator<<(std::ostream& fout, const Matrix_square &matr)
{
	fout << get_string_from_matrix(matr);
	return (fout);
}

bool			Matrix_square::operator==(const Matrix_square &matr) const
{
	if (matr.size != size)
		return (false);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (abs(matr[i][j] - arr[i][j]) < EPS)
				return (false);
	return (true);
}

bool			Matrix_square::operator!=(const Matrix_square &matr) const
{
	return (!(matr == *this));
}
