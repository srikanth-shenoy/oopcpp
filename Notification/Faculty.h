#pragma once
#pragma once
#include <iostream>
#include "Notice.h"

using namespace std;

class Faculty : public NoticeObserver {

public:
	Faculty(string aName, string aSubject, bool interestedInNotification);
	~Faculty();
	bool isInterestedInNotice();
	void notify(string message);

private:
	string name;
	string subject;
	bool interestedInNotice;
};