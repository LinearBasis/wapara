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
#include <stdlib.h>
#include <exception>
#include <string>
#include <iostream>

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
		return ;
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
