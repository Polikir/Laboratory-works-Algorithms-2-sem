


#pragma once
#include <iostream>

class complex
{
public:
	complex(double real, double image);
	double real, image;
	void cin(double real, double image);
	void cout();
	bool operator < (const complex other);
	bool operator > (const complex other);
	bool operator >= (const complex other);
	bool operator <= (const complex other);
	bool operator == (const complex other);
    bool operator != (const complex other);
	complex operator +(const complex other);
	complex &operator ++();
};



