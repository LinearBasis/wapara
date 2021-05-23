#pragma once
#include "../fabric/fabric.hpp"
#include "collection.hpp"

class database
{
private:
	database() {};
public:
	void	print();
	void	generate(int n);
	std::shared_ptr<ticket>					winner;
	collection<std::shared_ptr<ticket> >	*col;
	ticket_fabric							*fabr;

	database(collection<std::shared_ptr<ticket> > *_col, ticket_fabric *_fabr)
		 : col(_col), fabr(_fabr) {};
	~database();
};

