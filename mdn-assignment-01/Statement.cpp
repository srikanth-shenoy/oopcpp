#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Statement.h"
#include "Customer.h"

using namespace std;

const StatementType StatementType::TXT(StatementType::text, "text");
const StatementType StatementType::HTML(StatementType::html, "html");
const StatementType StatementType::JSON(StatementType::json, "json");
const StatementType StatementType::XML(StatementType::html, "xml");

StatementGenerator::StatementGenerator() { }

StatementGenerator::~StatementGenerator() { }

string StatementGenerator::generate(Customer *customer)
{
	stringstream ss;
	list<string> rentalHeaders;
	rentalHeaders.push_back("Movie");
	rentalHeaders.push_back("Type");
	rentalHeaders.push_back("Days Rented");
	rentalHeaders.push_back("Charge");
	ss << generateCustHeader(customer->getName()) << generateRentalHeader(rentalHeaders)
		<< generateMovieRentals(customer->getRentals())
		<< generateFooter(customer->getTotalCharge());
	return ss.str();
}

StatementGenerator* StatementGenerator::getStatementGenerator(StatementType stmtType) throw (NotYetImplementedException) {
	StatementGenerator* generator;
	switch (stmtType.getValue()) {
	case StatementType::text:
		generator = new TextStatementGenerator();
		break;
	case StatementType::html:
		generator = new HtmlStatementGenerator();
		break;
	default:
		throw NotYetImplementedException();
		break;
	}
	return generator;
}

TextStatementGenerator::TextStatementGenerator() { }

TextStatementGenerator::~TextStatementGenerator() { }

string TextStatementGenerator::generateCustHeader(string custName)
{
	stringstream ss;
	ss << "Customer: " << custName << "\n";
	return ss.str();
}

string TextStatementGenerator::generateRentalHeader(list<string> headerNames)
{
	stringstream ss;
	for (list<string>::iterator iter = headerNames.begin(); iter != headerNames.end();) {
		ss << *iter << "\t\t";
		iter++;
	}
	//add a line of code here to erase last two tab characters
	ss << "\n";
	return ss.str();
}

string TextStatementGenerator::generateMovieRentals(list<Rental*> rentals)
{
	stringstream ss;
	for (list<Rental*>::iterator iter = rentals.begin(); iter != rentals.end();) {
		Rental *rental = (*iter);
		Movie *movie = rental->getMovie();
		ss << movie->getName() << "\t\t"
			<< movie->getPrice()->getPriceType() << "\t\t"
			<< rental->getDays() << "\t\t"
			<< rental->getCharge() << "\n";
		iter++;
	}
	ss << "\n";
	return ss.str();
}

string TextStatementGenerator::generateFooter(double grandTotal)
{
	stringstream ss;
	ss << "TOTAL" << "\t\t\t\t\t" << grandTotal;
	ss << "\n";
	return ss.str();
}


HtmlStatementGenerator::HtmlStatementGenerator() { }

HtmlStatementGenerator::~HtmlStatementGenerator() { }

string HtmlStatementGenerator::generateCustHeader(string custName)
{
	stringstream ss;
	ss << "<html>\n\t<head><title>Statement for " << custName << "</title></head>\n\t<body>\n";
	ss << "\t\t<h2>Customer: <i>" << custName << "</i></h2>\n";
	return ss.str();
}

string HtmlStatementGenerator::generateRentalHeader(list<string> headerNames)
{
	stringstream ss;
	ss << "\t\t<table>\n\t\t\t<tr>";
	for (list<string>::iterator iter = headerNames.begin(); iter != headerNames.end();) {
		ss << "<th>" << *iter << "</th>";
		iter++;
	}

	ss << "</tr>\n";
	return ss.str();
}

string HtmlStatementGenerator::generateMovieRentals(list<Rental*> rentals)
{
	stringstream ss;
	for (list<Rental*>::iterator iter = rentals.begin(); iter != rentals.end();) {
		Rental *rental = (*iter);
		Movie *movie = rental->getMovie();
		ss << "\t\t\t<tr><td>" << movie->getName() << "</td><td>"
			<< movie->getPrice()->getPriceType() << "</td><td>"
			<< rental->getDays() << "</td><td>"
			<< rental->getCharge() << "</td></tr>\n";
		iter++;
	}
	return ss.str();
}

string HtmlStatementGenerator::generateFooter(double grandTotal)
{
	stringstream ss;
	ss << "\t\t\t<tr><td colspan=\"3\">TOTAL</td><td>" << grandTotal << "</td>\n";
	ss << "\t\t</table>\n";
	ss << "\t</body>\n</html>";
	return ss.str();
}

