#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

void Roster::parse(string studentData)//parses each row
{

	int rhs = studentData.find(',');//find the comma, return index
	string studentID = studentData.substr(0, rhs);//extract substring in front of comma

	int lhs = rhs + 1;//move past previous comma
	rhs = studentData.find(',', lhs);
	string studentFirstName = studentData.substr(lhs, rhs - lhs);//first name

	lhs = rhs + 1;//continue
	rhs = studentData.find(',', lhs);
	string studentLastName = studentData.substr(lhs, rhs - lhs);//last name

	lhs = rhs + 1; //continue
	rhs = studentData.find(",", lhs);
	string studentEmail = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1; //continue
	rhs = studentData.find(",", lhs);
	int studentAge = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1; //continue
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));//first number of days

	lhs = rhs + 1; //continue
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1; //continue
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);

	DegreeProgram degreeProgram = SECURITY;

	if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') degreeProgram = SECURITY;
	else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') degreeProgram = SOFTWARE;
	else if (studentData.at(lhs) == 'N') degreeProgram = NETWORK;
	add(studentID, studentFirstName, studentLastName, studentEmail, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);
}

void Roster::remove(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentID)
		{
			success = true;
			if (i < studentDataTableLength - 1)
			{
				// If this is not the last student, swap the removed student with the last one
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[studentDataTableLength - 1];
				classRosterArray[studentDataTableLength - 1] = temp;
			}
		}
		if (success)
		{
			cout << studentID << " removed from roster." << std::endl;
			return;
		}
	}
	if (success = false) {
		cout << studentID << " was not found in roster." << std::endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < Roster::lastIndex; i++) {
		Roster::classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getNumDaysArray()[0] +
					classRosterArray[i]->getNumDaysArray()[1] +
					classRosterArray[i]->getNumDaysArray()[2]) / 3 << std::endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = (classRosterArray[i]->getEmailAddress());
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
		{
			any = true;
			cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!any) cout << "None" << std::endl;


}

void Roster::printByDegreeProgram(DegreeProgram DegreeProgram)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getProgram() == DegreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

Roster::~Roster()
//removes objects that are dynamically allocated; the repo creates book objects dynamically and must be used to destroy
{
	cout << "Destructor called!" << std::endl << std::endl;
	for (int i = 0; i < studentDataTableLength; i++)
		//size of numBooks stays the same unlike lastIndex
	{
		cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
		//set to nullptr so it is no longer pointed at that address otherwise could crash
	}
}