#include <iostream>
#include "roster.h"
#include "student.h"

using std::string;

int main()
{
   
    string studentData[5] =
    {
        "A1,John,Smith,John.smith23133@gm ail.com,20,25,35,30,SECURITY",
        "A2,Elliot,Anderson,Anderson_2003@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Black,The_panda98yahoo.com,19,20,35,33,SOFTWARE",
        "A4,Erin,Grey,Erin.grey@gmail.com,22,50,58,40,SECURITY",
        "A5,Sarah,Wish,sarahw@yahoo.com,21,7,5,8,SOFTWARE"
    };
    
    // STEP: parse info
    int arrSize = sizeof(studentData) / sizeof(studentData[0]);
    Roster* classRoster = new Roster(arrSize);
    for (int i = 0; i < arrSize; i++) {
        classRoster->parseLine(studentData[i]);
    }

    // STEP: Student info
    std::cout << "All Student Information: \n";
    classRoster->printAll();
    std::cout << "\n";

    // STEP: Invalid emails
    std::cout << "Invalid Emails: \n";
    classRoster->printInvalidEmails();
    std::cout << "\n";

    // STEP: Avg days
    std::cout << "Average Days In Each Course: \n";
    for (int i = 0; i < arrSize; i++) {
        classRoster->printAverageDaysInCourse(classRoster->studentByIndex(i));
    }
    std::cout << "\n";

    // STEP: Students based on their program
    std::cout << "Students In The Software Program: \n";
    classRoster->printByDegreeProgram(SOFTWARE);
    std::cout << "\n";

    // STEP: Remove student and print
    std::cout << "Demonstration Removing a Student: \n";
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3"); 
    return -1;
}