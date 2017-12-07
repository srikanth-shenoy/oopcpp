#pragma once

#include <iostream>
#include "Price.h"

using namespace std;

class Movie {

public:
	Movie(string name, Price *price);
	~Movie();
	string getName() const { return name; }
	Price* getPrice() const { return price; }
	double getCharge(int days);

private:
	string name;
	Price *price;
};
