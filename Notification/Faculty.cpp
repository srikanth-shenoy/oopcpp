#include <iostream>
#include <string>
#include "Notice.h"
#include "Faculty.h"

using namespace std;

Faculty::Faculty(string aName, string aSubject, bool interestedInNotification)
{
	name = aName;
	subject = aSubject;
	interestedInNotice = interestedInNotification;
}

Faculty::~Faculty() { }

bool Faculty::isInterestedInNotice() {
	return interestedInNotice;
}

void Faculty::notify(string message) {
	cout << "I am Faculty " << name << " and I got the notice." << endl;
}
