//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"
#include <iostream>
#include <fstream>

int		main()
{
	Matrix_square	a, b;
	std::string		asd;

	std::ifstream	f("in.txt");
	f >> a;
	std::cout << trace(a) << std::endl;
}