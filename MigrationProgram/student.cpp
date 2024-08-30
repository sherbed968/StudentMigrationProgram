#include "student.h"
#include "degree.h"
#include <iostream>


using namespace std;

/* SETTERS */

Student::Student() {
	studentId = "studentId";
	firstName = "firstName";
	lastName = "lastName";
	eMail = "eMail";
	age = 0;
	daysInCourse1 = 0;
	daysInCourse2 = 0;
	daysInCourse3 = 0;
	studentProgram = DegreeProgram::SOFTWARE;
}


Student::Student(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse[3], DegreeProgram studentProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->eMail = eMail;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->studentProgram = studentProgram;
}



Student::Student (string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram studentProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->eMail = eMail;
	this->age = age;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->studentProgram = studentProgram;

}


/* DESTRUCTORS */

Student::~Student() {

}
/* GETTERS */


string Student::GetStudentId() {
	return studentId;
}


string Student::GetFirstName() const {
	return firstName;
}


string Student::GetLastName() const {
	return lastName;
}


string Student::GetEmail() const {
	return eMail;
}


int Student::GetAge() const {
	return age;
}


int Student::GetNumDaysClass1() const {
	return daysInCourse[0];
}


int Student::GetNumDaysClass2() const {
	return daysInCourse[1];
}


int Student::GetNumDaysClass3() const {
	return daysInCourse[2];
}


DegreeProgram Student::GetProgram() const {
	return studentProgram;
}

/* SETTERS */

void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
}


void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}


void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}


void Student::SetEmail(string eMail) {
	this->eMail = eMail;
}


void Student::SetAge(int age) {
	this->age = age;
}


void Student::SetNumDaysClass1(int daysInCourse1) {
	this->daysInCourse1 = daysInCourse1;
}

void Student::SetNumDaysClass2(int daysInCourse2) {
	this->daysInCourse2 = daysInCourse2;
}

void Student::SetNumDaysClass3(int daysInCourse3) {
	this->daysInCourse3 = daysInCourse3;
}


void Student::SetProgram(DegreeProgram studentProgram) {
	this->studentProgram = studentProgram;
}

/* PRINT */

void Student::print() {
	string studProgram;

	if (GetProgram() == 0) {
		studProgram = "SECURITY";
	}
	else if (GetProgram() == 1) {
		studProgram = "NETWORK";
	}
	else {
		studProgram = "SOFTWARE";
	}

	cout << GetStudentId() << "	" << "First Name: " << GetFirstName() << "	" << "Last Name: " << GetLastName() << "		" << "Age: " << GetAge() << "		" << "daysInCourse: {" << GetNumDaysClass1() << ", " << GetNumDaysClass2() << ", " << GetNumDaysClass3() << "}		" << "Degree Program: " << studProgram << "." << endl;
}