//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"
#include <iostream>
#include <fstream>

int		main()
{
	try
	{
		
		Matrix_square	a, b;
		std::string		asd;

		std::ifstream	f("in.txt");
		std::ofstream	o("out.txt");
		parse_expression(f);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}