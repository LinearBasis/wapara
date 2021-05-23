#pragma once

#include <list>
#include <iostream>
#include <stdlib.h>


class Memory
{
public:
	class block
	{
	public:
		void	*addr;
		int		size;
		bool	is_filled;
		void	*prev;
		void	*next;

	public:
		block(void *_addr, int _size) : addr(_addr), size(_size){};
		block(void *_addr, int _size, bool _is_filled) : addr(_addr), size(_size), is_filled(_is_filled) {};
		block(void *_addr, int _size, bool _is_filled, void *_prev, void *_next):
						addr(_addr), size(_size), is_filled(_is_filled) , prev(_prev), next(_next)	{};

		int		get_size() const { return (size);};
		void	*get_addr() const { return (addr);};
		int		get_status() const { return (is_filled); };
		bool	operator==(const block &block) const
					{return (this->size == block.size && this->addr == block.addr);};
		block	*operator=(const block &block);
		friend bool		compare_blocks(const Memory::block &a, const Memory::block &b);
		~block() {};
	};
	
	void	print_mem(void *s, int n) const;

protected:
	void				*s;
	int					size;

	std::list<block>	memblocks;
	std::list<block>	available;
	std::list<block>	unavailable;

	void				sort_all();

	virtual void		heap_compact() = 0;
	virtual void		deallocate_algorithm(block *block) = 0;
	virtual block		*search(int n) const = 0;
	virtual block		*split_memblock(block *block, int n) = 0;

public:
	Memory(int n);
	virtual ~Memory();
	friend bool		compare_blocks(const Memory::block &a, const Memory::block &b);

	block	*allocate(int n);
	void	dealocate(block *block);
};

class unsorted_list_memory : public Memory
{
private:
	void	print_mem(void *s, size_t n) const;

protected:
	void			heap_compact() override;
	void			deallocate_algorithm(block *block) override;
	Memory::block	*search(int n) const override;
	Memory::block	*split_memblock(block *block, int n) override;
public:
	unsorted_list_memory(int n) ;
	~unsorted_list_memory();
};

bool	compare_blocks(const Memory::block &a, const Memory::block &b)
{
	// if (a.get_status() > b.get_status())
	// 	return (1);
	return (a.get_addr() < b.get_addr());
}


class second_memory : public Memory
{
private:
	void	print_mem(void *s, size_t n) const;

protected:
	void			heap_compact() override;
	void			deallocate_algorithm(block *block) override;
	block	*search(int n) const override;
	block	*split_memblock(block *block, int n) override;

public:
	second_memory(int n) ;
	~second_memory();
};


void	Memory::print_mem(void *s, int n) const
{
	std::list<Memory::block>				all;

	all.insert(all.end(), unavailable.begin(), unavailable.end());
	all.insert(all.end(), available.begin(), available.end());
	all.sort(compare_blocks);
	int i = 0;

	auto iter = all.begin();
	while (iter != all.end())
	{
		int j = 0;
		if (iter->get_status())
		{
			while (j < iter->size)
			{
				printf(" \x1b[30;41m %d\t:\t%p\x1b[0m\n", i + j, (char*)iter->addr + j);
				j++;
			}
		}
		else
		{
			while (j < iter->size)
			{
				printf(" \x1b[37;42m %d\t:\t%p\x1b[0m\n", i + j, (char*)iter->addr + j);
				j++;
			}
		}
		printf("\n");
		i += j;
		iter++;
	}
}

Memory::Memory(int n)
{
	this->size = n;
	this->s = malloc(n);
	if (!this->s)
		return ;
	block	new_block(s, size, false);
	std::cout << "MEM CREATED" << std::endl;
	memblocks.push_back(new_block);
	available.push_back(new_block);
}

Memory::~Memory()
{
	if (s)
		free(s);
}

void	Memory::sort_all()
{
	memblocks.sort([](const block &a, const block &b)
	 				{ return (a.addr < b.addr); });
	available.sort([](const block &a, const block &b)
	 				{ return (a.addr < b.addr); });
	unavailable.sort([](const block &a, const block &b)
	 				{ return (a.addr < b.addr); });
}

Memory::block	*Memory::allocate(int n) 
{
	block	*found_block = nullptr;

	found_block = search(n);
	if (!found_block)
	{
		heap_compact();
		found_block = search(n);
		if (!found_block)
			throw std::bad_alloc();
	}
	found_block->is_filled = true;
	return (split_memblock(found_block, n));
}

void	Memory::dealocate(Memory::block *block)
{
	if (!block)
		throw std::bad_alloc();
	deallocate_algorithm(block);
	sort_all();
}


unsorted_list_memory::unsorted_list_memory(int n) : Memory (n)
{
	
}

unsorted_list_memory::~unsorted_list_memory()
{
	print_mem(this->s, this->size);
}



void				unsorted_list_memory::heap_compact()
{
	std::list<Memory::block>				all;

	unavailable.sort(compare_blocks);
	available.clear();

	auto iter = unavailable.begin();
	char*		tmp_addr;
	int			red_size;

	tmp_addr = (char*)this->s;
	red_size = 0;
	while (iter != unavailable.end())
	{
		memmove(tmp_addr, iter->addr, iter->size);
		iter->addr = tmp_addr;
		red_size += iter->size;
		tmp_addr += iter->size;
		++iter;
	}
	available.push_back(Memory::block(tmp_addr, this->size - red_size, false));
}


void			unsorted_list_memory::deallocate_algorithm(block *block)
{
	std::list<Memory::block>				all;
	all.insert(all.end(), unavailable.begin(), unavailable.end());
	all.insert(all.end(), available.begin(), available.end());
	all.sort(compare_blocks);

	auto	iter_find = std::find(all.begin(), all.end(), *block);
	std::list<Memory::block>::iterator	temp_iter;

	if (iter_find == all.end())
		throw std::invalid_argument ("BAD BLOCK DELETED");

	void	*new_adress = iter_find->addr;
	int		new_size = iter_find->size;


	if (iter_find != all.begin())
	{
		std::cout << "HERE (begin)" << std::endl;
		temp_iter = std::prev(iter_find);
		temp_iter = std::find(available.begin(), available.end(), *temp_iter);
		if (temp_iter != available.end())
		{
			new_adress = temp_iter->addr;
			new_size += temp_iter->size;
			available.remove(*temp_iter);
		}
	}

	if (iter_find != --all.end())
	{
		std::cout << "HERE (end)" << std::endl;
		temp_iter = std::next(iter_find);
		temp_iter = std::find(available.begin(), available.end(), *temp_iter);
		if (temp_iter != available.end())
		{
			new_size += temp_iter->size;
			available.remove(*temp_iter);
		}
	}
	std::cout << "new block info:" << std::endl;
	printf("new size - %d, new addr - %p\n", new_size, new_adress);
	
	Memory::block	new_block(new_adress, new_size, false);
	unavailable.remove(*iter_find);
	available.push_back(new_block);
}

Memory::block	*unsorted_list_memory::search(int n) const
{
	for (auto &it : available)
		if (it.size >= n)
		{
			return (const_cast<Memory::block *>(&it));
		}
	return (nullptr);
}
void	unsorted_list_memory::print_mem(void *s, size_t n) const
{
	std::list<Memory::block>				all;

	all.insert(all.end(), unavailable.begin(), unavailable.end());
	all.insert(all.end(), available.begin(), available.end());
	all.sort(compare_blocks);
	int i = 0;
	std::cout << unavailable.size() << std::endl;
	std::cout << available.size() << std::endl;
	auto iter = all.begin();
	while (iter != all.end())
	{
		int j = 0;
		if (iter->get_status())
		{
			while (j < iter->size)
			{
				printf(" \x1b[30;41m %d\t:\t%p\x1b[0m\n", i + j, (char*)iter->addr + j);
				j++;
			}
		}
		else
		{
			while (j < iter->size)
			{
				printf(" \x1b[37;42m %d\t:\t%p\x1b[0m\n", i + j, (char*)iter->addr + j);
				j++;
			}
		}
		printf("\n");
		i += j;
		iter++;
	}
}


Memory::block	*unsorted_list_memory::split_memblock(Memory::block *block, int n)
{
	std::list<Memory::block>::iterator iter;

	if (block->size == n)
	{
		iter = std::find(available.begin(), available.end(), *block);
		available.erase(iter);
		unavailable.push_back(*iter);
		sort_all();
		return (&*iter);
	}
	
	unsigned char	*next_addr =
						static_cast<unsigned char *>(block->addr) + n;
	Memory::block		next(static_cast<void *>(next_addr),
						block->size - n, false);
	Memory::block		prev(block->addr, n, true);

	available.remove(*block);
	unavailable.push_back(prev);
	available.push_back(next);
	sort_all();
	iter = std::find(unavailable.begin(), unavailable.end(), prev);
	return (&*iter);
}

//	a:		_a_, ba_, _ab, bac, a_, ab, _a, ba, a