#include "Memory.hpp"

int		main()
{
	try
	{
		unsorted_list_memory mem(10);
		Memory::block *asd;
		asd = mem.allocate(2);
		mem.allocate(4);
		mem.dealocate(asd);
		mem.allocate(5);
		mem.allocate(6);
		printf("goodbye\n");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
