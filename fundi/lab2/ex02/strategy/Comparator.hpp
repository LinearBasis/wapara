#pragma once

template <class T>
class Comparator
{
private:
public:
	virtual ~Comparator() {};
	virtual int compare(const T &a, const T &b) const = 0;
};