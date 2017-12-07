#include <iostream>
#include <string>
#include "Notice.h"
#include "Student.h"
#include "Institution.h"

using namespace std;

Department::Department(string aName)
{
	name = aName;
}

Department::~Department() { }

void Department::addFaculty(Faculty *faculty)
{
	staff.push_back(faculty);
	if (faculty->isInterestedInNotice())
	{
		noticeBoard.registerParty(faculty);
	}
}

void Department::enroll(Student *student) {
	students.push_back(student);
	if (student->isInterestedInNotice())
	{
		noticeBoard.registerParty(student);
	}
}

void Department::makeAnnouncement(string message) {
	cout << "**********************************************************************************" << endl;
	cout << name << " Department sending out Notification " << endl;
	noticeBoard.newNotice(message);
	cout << "**********************************************************************************" << endl << endl;
}

College::College(string aname)
{
	name = aname;
}

College::~College() { }

void College::addDepartment(Department *dept) 
{
	departments.push_back(dept);
}

void College::admit(Student *student, Department *dept)
{
	students.push_back(student);
	dept->enroll(student);
}
