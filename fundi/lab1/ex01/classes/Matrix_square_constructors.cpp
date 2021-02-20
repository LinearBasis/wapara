#include "Matrix_square.h"
#include <stdlib.h>
#include <exception>
#include <string>

Matrix_square::Matrix_square()
{
	arr = NULL;
	size = 0;
}

Matrix_square::Matrix_square(Matrix_square &matr)
{
	size = matr.size;
	alloc_mem();
	if (!arr)
		return;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = matr[i][j];
}

Matrix_square::Matrix_square(const double **arr_, unsigned int size_)
{
	if (arr_ == NULL)
	{
		size = 0;
		arr = NULL;
		return ;
	}
	size = size_;
	alloc_mem();
	if (arr)
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				arr[i][j] = arr_[i][j];
}

Matrix_square::Matrix_square(unsigned int size_)
{
	size = size_;
	alloc_mem();
}

Matrix_square::Matrix_square(std::vector <std::vector <double> > vec)
{
	for (int i = 0; i < size; i++)
	{
		if (vec[i].size() != vec.size())
		{
			size = 0;
			arr = 0;
			return ;
		}
	}
    size = vec.size();
    alloc_mem();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            arr[i][j] = vec[i][j];
    }
}

Matrix_square::~Matrix_square()
{
	free_mem();
}




