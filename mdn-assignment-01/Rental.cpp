#include "stdafx.h"
#include "Rental.h"

#include <assert.h>

Rental::Rental(Movie *aMovie, int aDays)
{
	assert(aDays > 0);
	movie = aMovie;
	days = aDays;
}

Rental::~Rental()
{
	delete(movie);
}

double Rental::getCharge()
{
	return movie->getCharge(days);
}
