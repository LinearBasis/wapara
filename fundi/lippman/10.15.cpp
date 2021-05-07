#include <iostream>

int		main()
{
	int		a;

	a = 5;
	auto lambda = [a](int b){ return (a < b);};
	std::cout << lambda(1) << std::endl;
	std::cout << lambda(7) << std::endl;
}