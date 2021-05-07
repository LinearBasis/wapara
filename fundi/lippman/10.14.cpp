#include <iostream>

int		main()
{
	auto lambda = [](int a, int b){ return (a - b);};

	std::cout << lambda(2, 3) << std::endl;
}