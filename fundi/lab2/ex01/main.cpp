# include "RB/RBtree.hpp"
# include <iostream>
# include "AVL/AVLtree.hpp"
# include <vector>

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

// int		main()
// {
// 	Comparator_int		cmp;
// 	AVLtree<int>		avl(&cmp);

// 	std::vector <int>	data;

// 	for (int i = 0; i < 800; i++)
// 	{
// 		data.push_back(rand() % 700);
// 	}
// 	for (auto i : data)
// 	{
// 		std::cout << i << " ";
// 		avl.add(static_cast<int &&>(i));
// 	}
// 	for (auto i : data)
// 	{
// 		if (rand() % 10 > 7)
// 			avl.del(static_cast<int &&>(i));
// 	}
// 	std::cout << std::endl;


// 	avl.print();
// 	avl.print_rotates();
// 	if (avl.is_avltree())
// 		printf("\x1b[32;45mIT IS AVLTREE\x1b[0m\n");
// 	else
// 		printf("\x1b[30;41mIT IS NOT AVLTREE\x1b[0m\n");
	
// }