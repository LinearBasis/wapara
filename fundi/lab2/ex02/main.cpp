# include "RB/RBtree.hpp"
# include <iostream>
# include "AVL/AVLtree.hpp"
# include <vector>
# include "relation/Relation.hpp"

class Comparator_int : public Comparator<int*>
{
	int compare(int* const &a, int* const &b) const override {return (*a - *b);};
};


class Comparator_int2 : public Comparator<int*>
{
	int compare(int* const &a, int* const &b) const override {return (*b);};
};

int	main()
{
	Comparator_int		bef1;
	Comparator_int2		bef2;
	RBtree<int*>		asd1(&bef1);
	AVLtree<int*>		asd2(&bef1);
	std::vector <int>	data;


	for (int i = 0; i < 20; i++)
	{
		data.push_back(i);
		std::cout << data[i] << " ";
	}

	std::cout << std::endl;

	Relation<int>		rel;

	for (int i = 0; i < 5; i++)
		rel.insert_data(static_cast<int &&>(data[i]));
	rel.print_data();
	rel.insert_index(&asd1);
	rel.insert_index(&asd2);
	for (int i = 5; i < 20; i++)
	{
		std::cout << data[i] << " ";
		rel.insert_data(static_cast<int &&>(data[i]));
	}
	std::cout << std::endl;
	asd2.print();
	asd1.print();


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