#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

int index = -1;


Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
} 

void Roster::parse(string studentData) {

	size_t rhs = studentData.find(",");
	string studentId = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string eMail = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
	

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(lhs);
    string studProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram studentProgram = DegreeProgram::SOFTWARE;
	if (studProgram == "SOFTWARE") {
		studentProgram = DegreeProgram::SOFTWARE;
	}
	else if (studProgram == "SECURITY") {
		studentProgram = DegreeProgram::SECURITY;
	}
	else if (studProgram == "NETWORK") {
		studentProgram = DegreeProgram::NETWORK;
	}

	Roster::add(studentId, firstName, lastName, eMail, age, daysInCourse1, daysInCourse2, daysInCourse3, studentProgram);

}

void Roster::add(string studentId, string firstName, string lastName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram studentProgram) {
	
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++index] = new Student(studentId, firstName, lastName, eMail, age, daysInCourse, studentProgram);
	
	
}


void Roster::remove(string studentId) {
	int count = 0;
	
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			count++;
			classRosterArray[i]->SetStudentId("NULL");
		}
	}
	if (count == 0) {
		cout << "The student with the ID: " << studentId << " was not found." << endl;
	}
}


void Roster::printAll() {
	for (int i = 0; i < 5; ++i) {
		if (!(classRosterArray[i]->GetStudentId() == "NULL")) {
			classRosterArray[i]->print();
		}
	}
}


void Roster::printAverageDaysInCourse(string studentId) {
	int averageDaysInCourse = 0;
	
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			averageDaysInCourse = (classRosterArray[i]->GetNumDaysClass1() + classRosterArray[i]->GetNumDaysClass2() + classRosterArray[i]->GetNumDaysClass3()) / 3;
			cout << "Student ID: " << studentId << ", average days in course is: " << averageDaysInCourse << endl;
		}
	}
}


void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		size_t found1 = classRosterArray[i]->GetEmail().find('@');
		size_t found2 = classRosterArray[i]->GetEmail().find('.');
		size_t found3 = classRosterArray[i]->GetEmail().find(' ');

		if ((found1 != std::string::npos) && (found2 != std::string::npos) && (!(found3 != std::string::npos))) {
			break;
		}
		else {
			cout << classRosterArray[i]->GetEmail() << " - is invlaid." << endl;
		}

	}
}


void Roster::printByDegreeProgram(DegreeProgram studentProgram) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetProgram() == studentProgram) {
			classRosterArray[i]->print();
		}
	}
}