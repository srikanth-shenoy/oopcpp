// mdn-assignment-02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

#include "Address.h"
#include "Personnel.h"
#include "Company.h"

Manager* addAkshay() {
	Address *prmAdd1 = Address::newPermanentAddress()
		->withDoorNumber("1-141(c)")
		->withStreet2("DashrathNagar Moorkai")
		->withStreet1("Industrial Area Street")
		->withCity("DashrathNagar")
		->withPin("576102");
	Address *ofcAdd1 = Address::newOfficeAddress()
		->withDoorNumber("1/90(c)")
		->withStreet2("Commercial Street")
		->withStreet1("Shivalli Industrial Area")
		->withCity("HazratNagar")
		->withPin("576103");

	Manager *m = new Manager("Akshaya", Role::JAVA_PROG, 1000000);
	m->addAddress(prmAdd1);
	m->addAddress(ofcAdd1);

	Company* company = Company::getInstance();
	company->withEmployee(m);

	return m;
}

Employee* addSanthosh() {
	Address *prmAdd1 = Address::newPermanentAddress()
		->withDoorNumber("1-141(a)")
		->withStreet2("DashrathNagar Cross Road")
		->withStreet1("Industrial Ave")
		->withCity("Navagruha Colony")
		->withPin("576103");
	Address *ofcAdd1 = Address::newOfficeAddress()
		->withDoorNumber("2/95(c)")
		->withStreet2("Downtown Lane")
		->withStreet1("2nd cross")
		->withCity("RajeevNagar")
		->withPin("576104");

	Employee *c = new Employee("Santhosh", Role::SQL_PROG, 5000000, Designation::SRDEVELOPER);
	c->addAddress(prmAdd1);
	c->addAddress(ofcAdd1);

	Company* company = Company::getInstance();
	company->withEmployee(c);
	return c;
}

int main()
{
	Manager* aks = addAkshay();
	Employee* san = addSanthosh();
	aks->addEmployee(san);

	list<Manager*> mgrList = Company::getInstance()->getManagers();

	stringstream ss;
	for (list<Manager*>::iterator iter = mgrList.begin(); iter != mgrList.end();) {
		cout << (*iter)->getName() << "\t\t";
		iter++;
	}
	
    return 0;
}

