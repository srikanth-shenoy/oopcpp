// mdn-assignment-01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "Customer.h"
#include "Price.h"
#include "Movie.h"
#include "Rental.h"
#include "Statement.h"

using namespace std;

Price *newRelPrice = new NewReleasePrice();
Price *regPrice = new RegularMoviePrice();
Price *childrenPrice = new ChildrensMoviePrice();

Movie *toilet = new Movie("Toilet - Ek Prem Katha", newRelPrice);
Movie *tubelight = new Movie("Tubelight", regPrice);
Movie *padmavathi = new Movie("Padmavathi", newRelPrice);
Movie *iceage = new Movie("Ice Age 5", childrenPrice);

Customer* createCustomerWithMovieRentals() {
	Customer *cust = new Customer("John Smith");
	cust->rentMovie(toilet, 5);
	cust->rentMovie(tubelight, 3);
	cust->rentMovie(padmavathi, 1);
	cust->rentMovie(iceage, 2);
	return cust;
}

string generateTextStatement(Customer *cust) {
	StatementGenerator *stmtGen = StatementGenerator::getStatementGenerator(StatementType::TXT);
	string statementStr = stmtGen->generate(cust);
	return statementStr;
}

string generateHtmlStatement(Customer *cust) {
	StatementGenerator *stmtGen = StatementGenerator::getStatementGenerator(StatementType::HTML);
	string statementStr = stmtGen->generate(cust);
	return statementStr;
}

string generateJsonStatement(Customer *cust) throw (NotYetImplementedException) {
	StatementGenerator *stmtGen = StatementGenerator::getStatementGenerator(StatementType::JSON);
	string statementStr = stmtGen->generate(cust);
	return statementStr;
}

int main()
{
	//ARRANGE
	Customer *cust = createCustomerWithMovieRentals();

	//ACT
	cout << "\n\nT E X T    S T A T E M E N T" << endl;
	string statementStr = generateTextStatement(cust);

	//ASSERT
	cout << statementStr << endl;

	//ACT
	cout << "\n\nH T M L   S T A T E M E N T" << endl;
	string statementStr2 = generateHtmlStatement(cust);

	//ASSERT
	cout << statementStr2 << endl;

	try
	{
		//ACT
		cout << "\n\n A T T E M P T    T O    J S O N    S T A T E M E N T   F A I L S" << endl;
		string statementStr3 = generateJsonStatement(cust);
		
		//Will never happen
		cout << statementStr3 << endl;
	}
	catch (const NotYetImplementedException& e)
	{
		//ASSERT
		cerr << e.what();
		cout << endl << endl;
	}
	catch (...) // catch all
	{
		cout << "Exception occurred: exiting " << endl;
		return 1;
	}
	return 0;
}

