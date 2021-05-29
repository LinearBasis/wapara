#pragma once

#include "../ticket/ticket.hpp"
#include <ctime>
#include <random>
#include <iostream>
#include <unordered_set>
#include <memory>
#include <cmath>

class ticket_fabric
{
protected:
	ticket_fabric() {};

public:
	virtual typename std::shared_ptr<ticket>	create_ticket(int number) = 0;
	virtual std::shared_ptr<ticket>	create_win_ticket(int number) = 0;
	virtual ~ticket_fabric() {};
};

class ticket_fabric_6_49 : public ticket_fabric
{
private:
public:
	ticket_fabric_6_49();
	std::shared_ptr<ticket>	create_ticket(int number) override;
	std::shared_ptr<ticket>	create_win_ticket(int number) override;
	~ticket_fabric_6_49();
};

class ticket_fabric_4_20 : public ticket_fabric
{
private:
public:
	ticket_fabric_4_20();
	std::shared_ptr<ticket>	create_ticket(int number) override;
	std::shared_ptr<ticket>	create_win_ticket(int number) override;
	~ticket_fabric_4_20();
};