#pragma once
#include <string>
#include "degree.h"


using namespace std;

class Student {
public:
	
	Student();
	Student(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[3], DegreeProgram studentProgram);
	Student(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram studentProgram);
	
	~Student();

	string GetStudentId();
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int GetNumDaysClass1() const;
	int GetNumDaysClass2() const;
	int GetNumDaysClass3() const;
	DegreeProgram GetProgram() const;

	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string eMail);
	void SetAge(int age);
	void SetNumDaysClass1(int daysInCourse1);
	void SetNumDaysClass2(int daysInCourse2);
	void SetNumDaysClass3(int daysInCOurse3);
	void SetProgram(DegreeProgram studentProgram);

	void print();

	string studentId;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int daysInCourse[3];
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	int numDays = 0;
	DegreeProgram studentProgram;

};