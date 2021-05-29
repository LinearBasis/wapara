#include "fabric.hpp"
#include <set>

ticket_fabric_6_49::ticket_fabric_6_49()
{

}

ticket_fabric_6_49::~ticket_fabric_6_49()
{

}

std::shared_ptr<ticket>	ticket_fabric_6_49::create_ticket(int number)
{
	std::shared_ptr<ticket_6_49> ans(new ticket_6_49());
	std::set <unsigned char>	set;

	unsigned char	a;
	static std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<unsigned char> field(1, 49);
	std::uniform_int_distribution<unsigned char> num_generator(6, 17);

	ans->size = num_generator(gen);
	ans->numbers = new unsigned char[(int)ans->size];

	while (set.size() < ans->size)
	{
		a = field(gen);
		if (!set.count(a))
		{
			ans->numbers[set.size()] = a;
			set.insert(a);
		}
	}
	ans->id = number;
	return (ans);
}

std::shared_ptr<ticket> ticket_fabric_6_49::create_win_ticket(int number)
{
	std::shared_ptr<ticket_6_49> ans(new ticket_6_49());
	std::unordered_set <unsigned char>	set;
	unsigned char	a;
	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<unsigned char> field(1, 49);

	ans->size = 6;
	ans->numbers = new unsigned char[ans->size];
	while (set.size() < ans->size)
	{
		a = field(gen);
		if (!set.count(a))
		{
			ans->numbers[set.size()] = a;
			set.insert(a);
		}
	}
	ans->id = number;
	return (ans);
}

//___________________________________________________
ticket_fabric_4_20::ticket_fabric_4_20()
{

}

ticket_fabric_4_20::~ticket_fabric_4_20()
{

}

std::shared_ptr<ticket>	ticket_fabric_4_20::create_ticket(int number)
{
	std::shared_ptr<ticket_4_20> ans(new ticket_4_20());
	std::set <unsigned char>	set;

	unsigned char	a;
	static std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<unsigned char> field(1, 20);
	std::uniform_int_distribution<unsigned char> num_generator(4, 7);

	ans->size = num_generator(gen);
	ans->numbers = new unsigned char[(int)ans->size];

	while (set.size() < ans->size)
	{
		a = field(gen);
		if (!set.count(a))
		{
			ans->numbers[set.size()] = a;
			set.insert(a);
		}
	}
	ans->id = number;
	return (ans);
}

std::shared_ptr<ticket> ticket_fabric_4_20::create_win_ticket(int number)
{
	std::shared_ptr<ticket_4_20> ans(new ticket_4_20());
	std::unordered_set <unsigned char>	set;
	unsigned char	a;
	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<unsigned char> field(1, 20);

	ans->size = 4;
	ans->numbers = new unsigned char[ans->size];
	while (set.size() < ans->size)
	{
		a = field(gen);
		if (!set.count(a))
		{
			ans->numbers[set.size()] = a;
			set.insert(a);
		}
	}
	ans->id = number;
	return (ans);
}