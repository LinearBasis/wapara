#include <string>
#include <iostream>
#include <vector>

class Sales_data
{
private:
	std::string	name;
	int			profit;
	int			price;
public:
	Sales_data();
	Sales_data(std::string _name, int _profit, int _price) :name(_name), profit(_profit), price(_price) {};
	friend bool	operator<(const Sales_data &a, const Sales_data &b);
	void print(){std::cout << name << ":" << profit << ":" << price << std::endl;}
};


bool	operator<(const Sales_data &a, const Sales_data &b)
{
	if (a.profit > b.profit)
		return (false);
	if (a.profit < b.profit)
		return (true);
	if (a.price > b.price)
		return (false);
	if (a.price < b.price)
		return (true);
	return (false);
}

bool	compareIsbn(const Sales_data &a, const Sales_data &b)
{
	return (a < b);
}

int		main()
{
	std::vector <Sales_data> sales= {Sales_data("a", 12, 5), Sales_data("b", 12, 2), Sales_data("c", 13, 5), Sales_data("d", 11, 4)};
	std::stable_sort(sales.begin(), sales.end(), compareIsbn);
	for (auto &i : sales)
	{
		i.print();
	}
}