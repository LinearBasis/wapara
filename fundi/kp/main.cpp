#include "all_headers.hpp"

int	main()
{
	list<int>	asd;

	ticket_fabric_6_49	fabr;

	collection_forward_list<std::shared_ptr<ticket> >	col;

	ticket_database 	base(&col, &fabr);

	base.generate(20);
	base.print();
}