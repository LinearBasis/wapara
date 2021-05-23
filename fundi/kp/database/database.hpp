#pragma once
#include "collection.hpp"
#include "../fabric/fabric.hpp"

class ticket_database
{
private:
	ticket_database() {};
public:
	void	print();
	void	generate(int n);

	std::shared_ptr<ticket>					winner;

	collection<std::shared_ptr<ticket> >	*col;
	ticket_fabric							*fabr;

	ticket_database(collection<std::shared_ptr<ticket> > *_col, ticket_fabric *_fabr)
		 : col(_col), fabr(_fabr) {};
	~ticket_database();
};

