#include "stdafx.h"
#include "Movie.h"

#include <assert.h>

Movie::Movie(string movieName, Price *moviePrice)
{
	name = movieName;
	price = moviePrice;
}

Movie::~Movie()
{
	delete(price);
}

double Movie::getCharge(int days)
{
	assert(days > 0);
	return price->getCharge(days);
}
