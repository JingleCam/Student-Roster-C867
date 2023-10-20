#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

student::student(string inputtedID, string inputtedFirst, string inputtedLast, string inputtedEmail, int inputtedAge, 
	int courseOne, int courseTwo, int courseThree, DegreeProgram inputtedDegree) {
		this->studentID = inputtedID;
		this->firstName = inputtedFirst;
		this->lastName = inputtedLast;
		this->studentEmail = inputtedEmail;
		this->studentAge = inputtedAge;
		this->numDays[0] = courseOne;
		this->numDays[1] = courseTwo;
		this->numDays[2] = courseThree;
		this->studentDegree = inputtedDegree;
}     

string student::getStudentID() { return this->studentID; }
string student::getFirstName() { return this->firstName; }
string student::getLastName() { return this->lastName; }
string student::getStudentEmail() { return this->studentEmail; }
int student::getStudentAge() { return this->studentAge; }
int student::getNumDays(int x) { return this->numDays[x]; }
DegreeProgram student::getDegreeType() { return this->studentDegree; }

void student::setStudentID(string inputtedID) { this->studentID = inputtedID; }
void student::setFirstName(string inputtedFirst) { this->firstName = inputtedFirst; }
void student::setLastName(string inputtedLast) { this->lastName = inputtedLast; }
void student::setStudentEmail(string inputtedEmail) { this->studentEmail = inputtedEmail; }
void student::setStudentAge(int inputtedAge) { this->studentAge = inputtedAge; }
void student::setNumDays(int days, int x) {
	this->numDays[x] = days;
}
void student::setDegreeType(DegreeProgram inputtedDegree) { this->studentDegree = inputtedDegree; }


void student::Print() {
	string DegreeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };  //array of strings corresponding to the enum values
	cout << this->studentID << "\t" << this->firstName << "\t";
	cout << left << setw(8) << this->lastName << "\t";   
	cout << setw(26) << this->studentEmail << "\t";       //setw() for neater alignment
	cout << this->studentAge << "\t";
	cout << "{" << this->numDays[0] << "," << this->numDays[1] << "," << this->numDays[2] << "}";
	cout << "\t" << DegreeStrings[this->studentDegree] << endl;   
}