#include <iostream>

class BEAST
{
public:
	BEAST() { std::cout << "BEAST CREATED" << std::endl;}
	virtual ~BEAST() { std::cout << "BEAST DELETED" << std::endl;}
	void f_beast() {};
};
 
class cat: public BEAST
{
public:
	cat() { std::cout << "CAT CREATED" << std::endl;}
	virtual ~cat() { std::cout << "CAT DELETED" << std::endl;}
	void f_cat() {};
};

void	delete_all_cats(BEAST *parent1, BEAST *parent2)
{
	std::cout << "______________" << std::endl;
	delete parent1;
	std::cout << "______________" << std::endl;
	delete parent2;
}

void	f()
{
	cat *child = new cat;
	BEAST *parent1 = new BEAST;
	BEAST *parent2 = child;

	delete_all_cats(parent1, parent2);
}

int	main()
{
	f();
}