#pragma once
#include <iostream>

using namespace std;

class Price {

public:
	Price();
	virtual ~Price();
	virtual string getPriceType() = 0; //pure virtual
	virtual double getCharge(int days) = 0; //pure virtual

};

class NewReleasePrice : public Price {

public:
	NewReleasePrice();
	~NewReleasePrice();
	string getPriceType();
	double getCharge(int days);

};


class ChildrensMoviePrice : public Price {

public:
	ChildrensMoviePrice();
	~ChildrensMoviePrice();
	string getPriceType();
	double getCharge(int days);
};

class RegularMoviePrice : public Price {

public:
	RegularMoviePrice();
	~RegularMoviePrice();
	string getPriceType();
	double getCharge(int days);

};
