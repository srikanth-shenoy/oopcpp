#include <iostream>
#include <string>
#include "Notice.h"
#include "Student.h"

using namespace std;

Student::Student(string aName, bool interestedInNotification) 
{
	name = aName;
	interestedInNotice = interestedInNotification;
}

Student::~Student() { }

bool Student::isInterestedInNotice() {
	return interestedInNotice;
}

void Student::notify(string message) {
	cout << "I am Student " << name << " and I got the notice." << endl ;
}
