#pragma once
#include "Movie.h"

using namespace std;

class Rental {

public:
	Rental(Movie *movie, int days);
	~Rental();
	int getDays() const { return days; }
	Movie* getMovie() const { return movie; }
	double getCharge();

private:
	int days;
	Movie *movie;

};