#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Parameterless constructor
Student::Student()
{
	this->studentId = ""; // TODO: Learn about references and pointers
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) this->numDaysArray[i] = 0; //TODO: learn about for loop
	this->program = DegreeProgram::SECURITY;//taken from degree.h
}

// Constructor with parameters
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numDaysArray[3], DegreeProgram program) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) this->numDaysArray[i] = numDaysArray[i];
	this->program = program;
}

//Getters
string Student::getStudentId() const {return this->studentId; }
string Student::getFirstName() const {return this->firstName;}
string Student::getLastName() const {return this->lastName;}
string Student::getEmailAddress() const {return this->emailAddress;}
int Student::getAge() const {return this->age;}
const int* Student::getNumDaysArray() const {return this->numDaysArray;}
DegreeProgram Student::getProgram() const {return this->program;}

//Setters
	void Student::setStudentId(string stdId) {this->studentId = stdId;}
	void Student::setFirstName(string fName) {this->firstName = fName;}
	void Student::setLastName(string lName) {this->lastName = lName;}
	void Student::setEmailAddress(string email) {this->emailAddress = email;}
	void Student::setAge(int age) {this->age = age;}
	void Student::setNumDaysArray(int numDaysArr[3]) {
		for (int i = 0; i < 3; i++) this->numDaysArray[i] = numDaysArr[i];
	}
	void Student::setDegreeProgram(DegreeProgram program) {this->program = program;}

	//print header needs other stuff
	void Student::print()
	{		
		cout << "StudentId: " << this->getStudentId() << '\t';
		cout << "First Name: " << this->getFirstName() << '\t';
		cout << "Last Name: " << this->getLastName() << '\t';
		cout << "EmailAddress: " << this->getEmailAddress() << '\t';
		cout << "Age: " << this->getAge() << '\t';
		cout << "Days in Course: " << this->getNumDaysArray()[0] << ',';
		cout << this->getNumDaysArray()[1] << ',';
		cout << this->getNumDaysArray()[2] << '\t';
		cout << "Degree Program: " << this->getProgram() << '\n';
	}