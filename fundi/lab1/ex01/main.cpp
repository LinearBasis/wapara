//#include "classes/TeX_convertible.h"
#include "classes/Matrix_square.h"
#include <iostream>
#include <fstream>

std::vector <std::vector <std::string> >	parse_all_expressions()
{
	std::vector <std::string> parse_result;
	std::vector <std::vector <std::string> > ans;

	Matrix_square	a, b;
	std::string		asd;
	std::ifstream	f("in.txt");
	std::ofstream	o("out.txt");
	while (1)
	{
		try
		{
			parse_result = parse_expression(f);
			if (parse_result.size() == 0)
				break;
			ans.push_back(parse_result);
			for (int i = 0; i < (int)parse_result.size(); i++)
				std::cout << parse_result[i] << std::endl;
			std::cout << "******" << std::endl;
			std::cout << get_matrix_from_string(parse_result[parse_result.size() - 1]).convert() << std::endl;
			std::cout << "______" << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl << "________" << std::endl;
		}
	}
	std::cout << "good" << std::endl;
	return (ans);
}


int		main()
{
	std::cout << get_string_of_tex_expressions(parse_all_expressions());
}