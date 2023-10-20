
#include "roster.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "C867 Scripting and Programming - Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 010143431" << endl;
    cout << "Name: Robert Crooks" << endl << endl;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Robert,Crooks,bobbyc@jinglecamonline.xyz,19,42,30,56,SOFTWARE"
    };

    roster classRoster;

    for (int i = 0; i < 5; i++) { 
        classRoster.parse(studentData[i]); 
    }
    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; i++) { 
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID()); 
    }
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
 



