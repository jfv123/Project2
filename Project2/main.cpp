#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() 
{
    cout << "Scripting and Programming Applications C++ 011073829 Jason Vassallo" << endl;

	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Jason,Vassallo,jvassa5@wgu.edu,31,14,20,23,SOFTWARE"
	};
	
	
    const int studentDataTable = 5;
	Roster classRoster;

    
    // Parse each student
    for (int i = 0; i < studentDataTable; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    cout << std::endl;
    //display all students

    cout << "Displaying all software students:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;
    //display all students in the software degree program

    cout << "Displaying invalid email addess: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    //display all students with an incorrectly formatted email address

    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << std::endl;
    //display the average number of days each student spends in 3 classes

    cout << "Remove student A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    //remove student A3 and print all remaining students

    cout << "Remove student A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl << std::endl;

	return 0;
}