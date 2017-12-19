#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Address.h"
#include "Personnel.h"
#include "Company.h"

using namespace std;

Company::Company() { }

Company::~Company() { 
	//add code here
}

static Company* s_instance;

Company* Company::getInstance() {
	if (!s_instance) {
		s_instance = new Company();
	}

	return s_instance;
}

Company* Company::withEmployee(EmployeeBase* emp) {
	employeeList.push_back(emp);
	return this;
}

list<Manager*> Company::getManagers() {
	list<Manager*> mgrList;
	for (list<EmployeeBase*>::iterator iter = employeeList.begin(); iter != employeeList.end();) {
		if (addressof((*iter)->getDesignation()) == addressof(Designation::MANAGER)) {
			Manager *mgr = (Manager*) *iter;
			mgrList.push_back(mgr);
		}
		iter++;
	}
	return mgrList;
}

