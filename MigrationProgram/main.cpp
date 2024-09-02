#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"


int main()
{
    using namespace std;

    cout << "c867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010929232" << endl;
    cout << "Name: Dane Herbert" << endl;

    //Declare array information
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Dane,Herbert,dherb20@wgu.edu,24,30,30,30,SOFTWARE" };

    Roster classRoster;

    //Seperate student data
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }
   
    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentId());
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
