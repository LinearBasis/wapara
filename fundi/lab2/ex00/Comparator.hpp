#pragma once

template <class T>
class Comparator
{
private:
public:
	virtual ~Comparator() {};
	virtual bool compare(const T &a, const T &b) const = 0;
};