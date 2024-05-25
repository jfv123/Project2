#include "degree.h"

using namespace std;

class Student {
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDaysArray[3];
	DegreeProgram program;

public:
	// Constructor
	Student(); //Always include
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int numDaysArray[3], DegreeProgram program); //Everything in constructor

	// Getters
	string getStudentId() const;
	string getFirstName() const; // TODO: Learn why you need const for getters
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	const int* getNumDaysArray() const; // TODO: Learn about this
	DegreeProgram getProgram() const;

	// Setters
	void setStudentId(string stdId);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setNumDaysArray(int numDaysArr[3]);
	void setDegreeProgram(DegreeProgram program);

	// Other
	void print();

};
