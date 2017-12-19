#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Address.h"
#include "Personnel.h"

const Designation Designation::ASSOCIATE(DesignationEnum::Associate, 1);
const Designation Designation::DEVELOPER(DesignationEnum::Developer, 2);
const Designation Designation::SRDEVELOPER(DesignationEnum::SrDeveloper, 3);
const Designation Designation::MANAGER(DesignationEnum::Manager, 4);


EmployeeBase::EmployeeBase(const string name, const Role role, const int salary, const Designation& desig) :
	mName(name), mRole(role), mSalary(salary), mDesig(desig)
{
}

EmployeeBase::~EmployeeBase()
{
	list<Address*>::iterator it;

	for (it = addressList.begin(); it != addressList.end(); it++) {
		delete *it;
	}
}

void EmployeeBase::addAddress(Address *address) {
	addressList.push_back(address);
}

int EmployeeBase::getBonus() {
	return mSalary * mDesig.getBonusRate();
}

void Manager::addEmployee(EmployeeBase *emp) {
	employeeList.push_back(emp);
}

Employee::~Employee()
{

}

Manager::~Manager()
{

}