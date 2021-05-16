#include "RB/RBtree.hpp"
#include <iostream>

class Comparator_int : public Comparator<int>
{
	int compare(const int &a, const int &b) const override {return (a - b);};
};


int	main()
{
	Comparator_int		bef;
	RBtree<int>			asd(&bef);
	std::vector <int>	data;



	for (int i = 0; i < 20; i++)
	{
		data.push_back(i);
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;
	
	for (auto i : data)
	{
		asd.add(static_cast<int &&>(i));
	}

	for (int i = 0; i < 8; i++)
	{
		asd.del(static_cast<int &&>(data[rand() % data.size()]));
	}


	asd.print();
	if (asd.is_rbtree())
		std::cout << "IS RBTREE" << std::endl;
	else
		std::cout << "IS NOT RBTREE" << std::endl;
	std::cout << std::endl;
}