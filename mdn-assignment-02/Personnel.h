#pragma once

#include <iostream>
#include <list>

#include "Address.h"

using namespace std;

enum class Role { JAVA_PROG, SQL_PROG, C_PROG };

class Designation {
	public:
		enum DesignationEnum {
			Associate, Developer, SrDeveloper, Manager
		};
		int getBonusRate() const { return mBonusRate; }
		static const Designation ASSOCIATE, DEVELOPER, SRDEVELOPER, MANAGER;

	private:
		Designation(const DesignationEnum & desig, const int bonusRate)
			: mDesignEnum(desig)
			, mBonusRate(bonusRate)
		{}
		DesignationEnum mDesignEnum;
		int mBonusRate;
};

class EmployeeBase {

	public:
		EmployeeBase(const string name, const Role role, int salary, const Designation& desig);
		virtual ~EmployeeBase();

		void addAddress(Address *address);
		string getName() const { return mName; }
		Designation getDesignation() { return mDesig; }
		list<Address*> getAddresses() const { return addressList; }
		int getBonus();
	private: 
		string mName;
		Role mRole;
		int mSalary;
		Designation mDesig;
		list<Address*> addressList;
};

class Employee : public EmployeeBase {

	public:
		Employee(const string name, const Role role, int salary, const Designation& desig) 
			: EmployeeBase(name, role, salary, desig) { }
		~Employee();
};

class Manager : public EmployeeBase {

	public:
		Manager(const string name, const Role role, int salary) 
			: EmployeeBase(name, role, salary, Designation::MANAGER) { }
		~Manager();

		list<EmployeeBase *> getEmployees() const { return employeeList; }
		void addEmployee(EmployeeBase *emp);
	
	private:
		list<EmployeeBase *> employeeList;
};