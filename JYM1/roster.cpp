#include "roster.h"
#include <string>
#include <iostream>
using namespace std;

roster::roster() {
	for (int i = 0; i < 5; i++) {
		this->classRosterArray[i] = nullptr;
	}
}

roster::~roster() {
	for (int i = 0; i < 5; i++) {
		delete this->classRosterArray[i];
		this->classRosterArray[i] = nullptr;
	}
}


void roster::parse(string studentAdd) {

	string stringArray[9];                              //save each parsed data member into an array of strings
	int startIdx = 0;
	int commaIndex = studentAdd.find(',', 0);           //starting at index 0, find first instance of ','

	for (int i = 0; i < 9; i++) {
		stringArray[i] = studentAdd.substr(startIdx, commaIndex - startIdx);     //save the substring to array of strings
		startIdx = commaIndex + 1;                     //now starting at the index after the last comma
		commaIndex = studentAdd.find(',', startIdx);   //find next instance of ','
	}

	DegreeProgram degreeprogram = SECURITY;
	if (stringArray[8] == "SECURITY") degreeprogram = SECURITY;
	else if (stringArray[8] == "NETWORK") degreeprogram = NETWORK;
	else if (stringArray[8] == "SOFTWARE") degreeprogram = SOFTWARE;
	

	string studentID = stringArray[0];
	string firstName = stringArray[1];
	string lastName = stringArray[2];
	string emailAddress = stringArray[3];
	int age = stoi(stringArray[4]);              //turn parsed strings into integers
	int daysInCourse1 = stoi(stringArray[5]);
	int daysInCourse2 = stoi(stringArray[6]);
	int daysInCourse3 = stoi(stringArray[7]);

	this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	student* newStudent = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] == nullptr) {
			this->classRosterArray[i] = newStudent;
			break;
		}
	}
}

void roster::remove(string studentID) {
	bool studentFound = false;
	cout << "Removing Student with ID " << studentID << "..." << endl;
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] == nullptr) continue;
		else if (this->classRosterArray[i]->getStudentID() == studentID) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = nullptr;
			studentFound = true;
			cout << "(i) Student with ID " << studentID << " successfully removed." << endl << endl;
			break;
		}
	}
	if (studentFound == false) cout << "(X) No student found with ID " << studentID << "." << endl << endl;
}

void roster::printAll() {
	cout << "Student Roster: " << endl;
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] != nullptr) this->classRosterArray[i]->Print();
	}
	cout << endl;
}

void roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] == nullptr) continue;                                 
		else if (this->classRosterArray[i]->getStudentID() == studentID) {
			int num1 = this->classRosterArray[i]->getNumDays(0);
			int num2 = this->classRosterArray[i]->getNumDays(1);
			int num3 = this->classRosterArray[i]->getNumDays(2);
			int average = (num1 + num2 + num3) / 3;
			cout << "Average number of days spent in courses for student with ID " << studentID << " is " << average << " days." << endl;
			break;
		}
	}
}

void roster::printInvalidEmails() {
	cout << "Checking for invalid emails..." << endl;
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] == nullptr) continue;
		else {
			string email = this->classRosterArray[i]->getStudentEmail();
			bool isValid = true;

			if ((email.find(' ', 0) != string::npos)) isValid = false;                          //invalid if any spaces found
			else if ((email.find('@', 0) == string::npos)) isValid = false;                     //invalid if no @ symbol found
			else if ((email.find('.', (email.find('@', 0))) == string::npos)) isValid = false;  //invalid if no period found after the @ symbol

			if (isValid == false) cout << "(!) The email " << email << " is not valid." << endl;

		}
	}
	cout << endl;
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string DegreeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << endl << "Students enrolled in the " << DegreeStrings[degreeProgram] << " degree program: " << endl;
	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i] == nullptr) continue;
		else if (this->classRosterArray[i]->getDegreeType() == degreeProgram) this->classRosterArray[i]->Print();
	}
	cout << endl;
}


