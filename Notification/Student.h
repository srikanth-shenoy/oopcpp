#pragma once
#include <iostream>
#include "Notice.h"

using namespace std;

class Student : public NoticeObserver {

	public:
		Student(string aName, bool interestedInNotification);
		~Student();
		bool isInterestedInNotice();
		void notify(string message);

	private:
		string name;
		bool interestedInNotice;
};