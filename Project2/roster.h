#include "student.h"
using namespace std;


class Roster
{
public:
	int lastIndex = 0;
	const static int studentDataTableLength = 5; //Number of students in table
	Student* classRosterArray[studentDataTableLength];

public:
	void parse(string studentDataTable);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll(); // calls print function for each student
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails(); // Must have '.', must not have ' ', must have '@'
	void printByDegreeProgram(DegreeProgram DegreeProgram);
	
	
	~Roster(); //deconstructor


};
