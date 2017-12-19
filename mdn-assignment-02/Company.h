#pragma once

#include <iostream>
#include "Address.h"
#include "Personnel.h"

class Company {

	public:
		~Company();

		static Company* getInstance();

		Company* withEmployee(EmployeeBase* emp);
		list<EmployeeBase*> getEmployees() const { return employeeList; }
		list<Manager*> getManagers();

	private:
		Company();
		list<EmployeeBase *> employeeList;
		
};
