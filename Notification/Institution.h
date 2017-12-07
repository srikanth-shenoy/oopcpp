#pragma once

#include "Notice.h"
#include "Student.h"
#include "Faculty.h"

class Department {

	public:
		Department(string name);
		~Department();
		void addFaculty(Faculty *faculty);
		void enroll(Student *student);
		void makeAnnouncement(string message);

	private:
		string name;
		NoticeBoard noticeBoard;
		list<Student*> students;
		list<Faculty*> staff;

};

class College {
	public:
		College(string name);
		~College();
		void addDepartment(Department *dept);
		void admit(Student *student, Department *dept);

	private:
		string name;
		list<Department*> departments;
		list<Student*> students;

};

