#include "Matrix_square.h"
#include <cmath>

static void			swap(double *arr1, double *arr2, int size)
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
	Matrix_square	copy(matr);
	double			index;
	int				sign;
	double			det;

	sign = 1;
	det = 1;
	if (matr.size == 0)
		return (NAN);
	for (int i = 0; i < matr.size; i++)
		for (int j = i + 1; j < matr.size; j++)
		{
			if (copy[i][i] == 0)
				for (int l = i + 1; l < matr.size; l++)
					if (copy[l][i] != 0)
					{
						swap(copy[l], copy[i], matr.size);
						sign *= -1;
						break ;
					}
			if (copy[i][i] == 0)
				return (0);
			index = copy[j][i] / copy[i][i];
			for (int k = 0; k < matr.size; k++)
				copy[j][k] -= index * copy[i][k];
		}
	for (int i = 0; i < matr.size; i++)
		det *= copy[i][i];
	return (det * sign);
}

Matrix_square	trans(const Matrix_square &matr)
{
	Matrix_square   ans = matr;

	for (int i = 0; i < matr.size; i++)
		for (int j = i; j < matr.size; j++)
			std::swap(ans.arr[i][j], ans.arr[j][i]);
	std::cout << ans;
	return (ans);
}

double			trace(const Matrix_square &matr)
{
	double ans;
	
	ans = 0;
	for (int i = 0; i < matr.size; i++)
		ans += matr[i][i];
	return (ans);
}


Matrix_square	inv(const Matrix_square &matr)
{
	Matrix_square cf(matr);
	Matrix_square E;
	
	E.E(matr.size);

	return (E);
}