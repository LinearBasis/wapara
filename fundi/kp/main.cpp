#include "all_headers.hpp"
#include <unistd.h>

int	main()
{
	list<int>	asd;

	ticket_fabric_6_49	fabr;

	collection_forward_list<std::shared_ptr<ticket> >	col;

	ticket_database 	base(&col, &fabr);

	base.generate(20);
	base.generate(10);
	base.print();
	std::cout << sizeof(ticket) << std::endl;

}