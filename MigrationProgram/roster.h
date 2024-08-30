#pragma once
#include "student.h"
#include "degree.h"

class Roster {

public:

	~Roster();

	Student* classRosterArray[5];

	void parse(string studentData);

	void add(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram studentProgram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentId);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram studentProgram);

};