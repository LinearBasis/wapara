#pragma once
#include "../ticket/ticket.hpp"
#include <ctime>
#include <random>
#include <iostream>
#include <unordered_set>

class ticket_fabric
{
protected:
	ticket_fabric() {};

public:
	virtual std::shared_ptr<ticket>	create_ticket() = 0;
	virtual std::shared_ptr<ticket>	create_win_ticket() = 0;
	virtual ~ticket_fabric() {};
};

class ticket_fabric_6_49 : public ticket_fabric
{
private:
public:
	ticket_fabric_6_49();
	std::shared_ptr<ticket>	create_ticket() override;
	std::shared_ptr<ticket>	create_win_ticket() override;
	~ticket_fabric_6_49();
};

ticket_fabric_6_49::ticket_fabric_6_49()
{

}

ticket_fabric_6_49::~ticket_fabric_6_49()
{

}

std::shared_ptr<ticket>	ticket_fabric_6_49::create_ticket()
{
	std::shared_ptr<ticket_6_49> ans(new ticket_6_49());
	std::unordered_set <unsigned char>	set;

	unsigned char	a;
	static std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<unsigned char> field(1, 49);
	std::uniform_int_distribution<unsigned char> num_generator(6, 17);

	ans->size = num_generator(gen);
	ans->numbers = new unsigned char[(int)ans->size];
	std::cout << set.size() << std::endl;

	while (set.size() < ans->size)
	{
		a = field(gen);
		if (!set.count(a))
		{
			ans->numbers[set.size()] = a;
			set.insert(a);
		}
	}
	return (ans);
}

std::shared_ptr<ticket> ticket_fabric_6_49::create_win_ticket()
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
	return (ans);
}
