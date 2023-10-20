#pragma once
#include "degree.h"         
#include <string>
using namespace std;


class student {
public:
	student(string inputtedID, string inputtedFirst, string inputtedLast, string inputtedEmail, int inputtedAge, 
		int courseOne, int courseTwo, int courseThree, DegreeProgram inputtedDegree);
	
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getStudentEmail();
	int getStudentAge();
	int getNumDays(int x);    //returns numDays[x], number of days for 1 of the 3 courses
	DegreeProgram getDegreeType();

	void setStudentID(string inputtedID);
	void setFirstName(string inputtedFirst);
	void setLastName(string inputtedLast);
	void setStudentEmail(string inputtedEmail);
	void setStudentAge(int inputtedAge);
	void setNumDays(int days, int x);           //sets numDays[x] with days
	void setDegreeType(DegreeProgram inputtedDegree);
	

	void Print();

private:
	string studentID;
	string firstName;
	string lastName;
	string studentEmail;
	int studentAge;
	int numDays[3];
	DegreeProgram studentDegree;
};