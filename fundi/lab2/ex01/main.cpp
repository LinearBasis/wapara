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
	std::vector <int>	data = {7, 4, 8, 10, 2, 9, 8, 8, 8};
	for (auto i : data)
		asd.add(static_cast<int&&>(i));
	std::cout << asd.is_rbtree();
	std::cout << std::endl;
}