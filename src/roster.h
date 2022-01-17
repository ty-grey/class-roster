#pragma once
#include "student.h"

class Roster {
public:
	Student** classRosterArray;
	int nextIndex;
	int amount;

	Roster();
	Roster(int amount);
	~Roster();

	string studentByIndex(int index) { return classRosterArray[index]->getStudentID(); };
	void parseLine(string line);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, Degree degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degree);
};