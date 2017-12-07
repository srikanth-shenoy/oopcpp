#pragma once

#include <iostream>
#include <list>

#include "Price.h"
#include "Movie.h"
#include "Rental.h"
//#include "Statement.h"

using namespace std;

class Customer {

public:
	Customer(string aname);
	~Customer();
	string getName() const { return name; }
	list<Rental*> getRentals() const { return rentals; }
	void rentMovie(Movie *movie, int mDays);
	double getTotalCharge();
	//string statement(StatementType stmtType);
private:
	string name;
	list<Rental*> rentals;
};