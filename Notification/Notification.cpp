// Notification.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Timer.h"

#include "Notice.h"
#include "Institution.h"
#include "Student.h"

using namespace std;

int main()
{
	College *c = new College("MIT");

	Department *cs = new Department("Computer Science");
	Department *ec = new Department("Electronics & Communication");
	Department *ee = new Department("Electrical & Electronics");

	cs->addFaculty(new Faculty("Nagaraj Kateel", "Project Management", true));
	cs->addFaculty(new Faculty("Prashanth Bhat", "Machine Learning", false));
	cs->addFaculty(new Faculty("Krishnaraj", "C++ 101", true));

	c->addDepartment(cs);
	c->addDepartment(ec);
	c->addDepartment(ee);

	Student *subbarao = new Student("Subbarao", true);
	Student *akshay = new Student("Akshay", true);
	Student *santhosh = new Student("Santhosh", false);
	Student *geethesh = new Student("Geethesh", false);

	c->admit(subbarao, cs);
	c->admit(akshay, cs);
	c->admit(santhosh, cs);
	c->admit(akshay, ec);
	c->admit(geethesh, ec);

	//cs->makeAnnouncement("Childrens day celebration");
	//ec->makeAnnouncement("Valentines Day Celebration");
	
	Timer tHello([&]()
	{
		//cout << "Hello!" << endl;
		cs->makeAnnouncement("No class today. Childrens Day celebration !!");
		ec->makeAnnouncement("Special class today. Valentines Day Celebration !!");
	});

	tHello.setSingleShot(false);
	tHello.setInterval(Timer::Interval(5000));
	tHello.start(true);

	Timer tStop([&]()
	{
		tHello.stop();
	});

	tStop.setSingleShot(true);
	tStop.setInterval(Timer::Interval(15000));
	tStop.start();
	

    return 0;
}

