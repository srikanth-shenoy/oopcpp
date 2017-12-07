#include "stdafx.h"
#include <assert.h>

#include "Movie.h"
#include "Customer.h"
#include "Rental.h"
#include "Statement.h"

Customer::Customer(string aName)
{
	name = aName;
}

Customer::~Customer() { }

void Customer::rentMovie(Movie *movie, int mDays)
{
	Rental *rental = new Rental(movie, mDays);
	//rentals.insert(rentals.end(), rental);
	rentals.push_back(rental);
}

double Customer::getTotalCharge() {
	double total = 0;
	for (list<Rental*>::iterator iter = rentals.begin(); iter != rentals.end(); iter++) {
		total += (*iter)->getCharge();
		//iter++;
	}
	return total;
}

/*
string Customer::statement(StatementType stmtType) {
StatementGenerator *stmtGen = StatementGenerator::getStatementGenerator(StatementType::TXT);
string statementStr = stmtGen->generate(this);
return statementStr;
}
*/