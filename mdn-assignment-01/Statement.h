#pragma once

#include <iostream>
#include "Customer.h"

using namespace std;

//Trying to emulate Java Enum like functionality in C++
class StatementType {
public:
	enum Value {
		text, html, json, xml
	};
	Value getValue() const { return mValue; }
	static const StatementType TXT, HTML, JSON, XML;

private:
	StatementType(const Value& rValue, const std::string& rStringVal)
		: mValue(rValue)
		, mStringVal(rStringVal)
	{}
	Value mValue;
	std::string mStringVal;
};

struct NotYetImplementedException : public exception {
	const char * what() const throw () {
		return "Statement functionality is not yet implemented for XML and JSON";
	}
};

class StatementGenerator {

public:
	StatementGenerator();
	virtual ~StatementGenerator();

	string generate(Customer *customer);

	static StatementGenerator* getStatementGenerator(StatementType stmtType) throw (NotYetImplementedException);

protected:
	virtual string generateCustHeader(string custName) = 0;
	virtual string generateRentalHeader(list<string> headerNames) = 0;
	virtual string generateMovieRentals(list<Rental*> rentals) = 0;
	virtual string generateFooter(double grandTotal) = 0;

};

class TextStatementGenerator : public StatementGenerator {

public:
	TextStatementGenerator();
	~TextStatementGenerator();

protected:
	string generateCustHeader(string custName);
	string generateRentalHeader(list<string> headerNames);
	string generateMovieRentals(list<Rental*> rentals);
	string generateFooter(double grandTotal);

};

class HtmlStatementGenerator : public StatementGenerator {

public:
	HtmlStatementGenerator();
	~HtmlStatementGenerator();

protected:
	string generateCustHeader(string custName);
	string generateRentalHeader(list<string> headerNames);
	string generateMovieRentals(list<Rental*> rentals);
	string generateFooter(double grandTotal);

};
