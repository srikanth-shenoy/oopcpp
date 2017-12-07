#include "stdafx.h"
#include <iostream>
#include "Price.h"
#include <assert.h>

using namespace std;

Price::Price() { }

Price::~Price() { }

NewReleasePrice::NewReleasePrice() { }

NewReleasePrice::~NewReleasePrice() { }

string NewReleasePrice::getPriceType()
{
	return "New Release";
}

double NewReleasePrice::getCharge(int days)
{
	double charge = 0;
	if (days <= 2) {
		charge = 30 * days;
	}
	else {
		charge = 30 * 2 + 25 * (days - 2);
	}
	return charge;
}


RegularMoviePrice::RegularMoviePrice() { }

RegularMoviePrice::~RegularMoviePrice() { }

string RegularMoviePrice::getPriceType()
{
	return "Regular";
}

double RegularMoviePrice::getCharge(int days)
{
	double charge = 5 * days;
	return charge;
}

ChildrensMoviePrice::ChildrensMoviePrice() { }

ChildrensMoviePrice::~ChildrensMoviePrice() { }

string ChildrensMoviePrice::getPriceType()
{
	return "Childrens";
}

double ChildrensMoviePrice::getCharge(int days)
{
	double charge = 5 * days;
	return charge;
}
