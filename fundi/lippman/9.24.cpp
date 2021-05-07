#include <vector>
#include <iostream>

void		try_to_access_to_elem(std::vector<int> vec) //зачем требуют тестить на пустом, тут очевидно сегается все
{
	try
	{
		std::cout << vec.at(2) << " - at 2" << std::endl;
		std::cout << *vec.begin() << " - begin" << std::endl;
		std::cout << vec.front() << " - front" << std::endl;
		std::cout << vec[1] << " - vec[1]" << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

int	main()
{
	std::vector <int> asd;
	try_to_access_to_elem(asd);
}