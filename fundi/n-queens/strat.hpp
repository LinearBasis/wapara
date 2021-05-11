#pragma once
#include <vector>
#include <fstream>
#include <iostream>

class Solve
{
private:
	std::vector <int>	solve;
	Solve();
public:
	friend std::vector <Solve>	create_all_solve(std::vector <Solve> vec);
	friend void	print_all_solve(std::vector <Solve> vec);

	void	print();
	void	print_deck();
	Solve	rotate_90();
	Solve	rotate_180();
	Solve	rotate_270();
	Solve	flip_x();
	Solve	flip_y();
	Solve(std::vector <int> vec) {solve = vec;};
	~Solve() {};
};

class Solver
{
public:
	virtual ~Solver() {};
	virtual std::vector <Solve> solve(int n) = 0;
public:
};

class Solver_recursive : public Solver
{
public:
	virtual ~Solver_recursive() {};
	std::vector <Solve> solve(int n) override;
};


class Solver_iterative : public Solver
{
public:
	std::vector <Solve> solve(int n) override;
};