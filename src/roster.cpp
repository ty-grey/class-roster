#include "roster.h"
#include <iostream>
#include <vector>

Roster::Roster()
{
	this->classRosterArray = nullptr;
	this->nextIndex = 0;
	this->amount = 0;
}

Roster::Roster(int nextIndex) {
	this->classRosterArray = new Student * [amount];
	this->nextIndex = nextIndex;
	this->amount = 0;
}

void Roster::parseLine(string line) {
	int daysInCourseArray[3];
	this->classRosterArray[amount] = new Student();
	size_t pos_start = 0, pos_end, delim_len = 1;
	string token, tempDegreeString;
	std::vector<string> res;

	// Split the string based on the delimiter ','
	while ((pos_end = line.find(",", pos_start)) != string::npos) {
		token = line.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}
	res.push_back(line.substr(pos_start));

	classRosterArray[amount]->setStudentID(res.at(0));
	classRosterArray[amount]->setFirstName(res.at(1));
	classRosterArray[amount]->setLastName(res.at(2));
	classRosterArray[amount]->setEmail(res.at(3));
	classRosterArray[amount]->setAge(stoi(res.at(4)));
	
	daysInCourseArray[0] = (stoi(res.at(5)));
	daysInCourseArray[1] = (stoi(res.at(6)));
	daysInCourseArray[2] = (stoi(res.at(7)));
	classRosterArray[amount]->setDaysInCourse(daysInCourseArray);

	tempDegreeString = res.at(8);
	std::cout << tempDegreeString;
	if (tempDegreeString == "SECURITY") classRosterArray[amount]->setProgram(SECURITY);
	else if (tempDegreeString == "NETWORK") classRosterArray[amount]->setProgram(NETWORK);
	else if (tempDegreeString == "SOFTWARE")classRosterArray[amount]->setProgram(SOFTWARE);
	else classRosterArray[amount]->setProgram(SECURITY);

	amount++;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, Degree degree) {

	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[amount]->setStudentID(studentID);
	classRosterArray[amount]->setFirstName(firstName);
	classRosterArray[amount]->setLastName(lastName);
	classRosterArray[amount]->setEmail(email);
	classRosterArray[amount]->setAge(age);
	classRosterArray[amount]->setDaysInCourse(daysInCourseArray);
	classRosterArray[amount]->setProgram(degree);

	this->amount++;
}

void Roster::remove(string studentID) {
	int matchingStudent = -1;
	for (int i = 0; i < nextIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				matchingStudent = i;
				break;
			}
		}
	}

	if (matchingStudent == -1) {
		std::cout << "A student with an ID " << studentID << " was not found.\n";
		return;
	}

	for (int i = 0; i < nextIndex; i++) {
		if (i == matchingStudent) {
			classRosterArray[i] = nullptr;
			std::cout << "A student with an ID " << studentID << " has been deleted.\n";
		}
	}
}

void Roster::printAll() {
	for (int i = 0; i < this->nextIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int total = 0;
	for (int i = 0; i < nextIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* temp = classRosterArray[i]->getDaysInCourse();
			total += temp[0] + temp[1] + temp[2];
			std::cout << studentID << " average amount of days is " << total / 3 << ".\n";
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < nextIndex; i++) {

		string temp = classRosterArray[i]->getEmail();
		if (temp.find("@") == string::npos || temp.find(".") == string::npos || temp.find(" ") != string::npos) {
			std::cout << "The email address " << temp << " is not valid.\n";
		}
	}
}

void Roster::printByDegreeProgram(Degree degree) {
	for (int i = 0; i < nextIndex; i++) {
		if (classRosterArray[i]->getProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < this->nextIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete this;
}