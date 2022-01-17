#include "student.h"
#include <iostream>

Student::Student(string studentID, string firstName, string lastName, 
	string email, int age, int daysInCourse[], Degree program) {
	
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysInCourse = new int[3];
	this->setDaysInCourse(daysInCourse);
	this->program = program;
}

Student::Student() {
	int daysInCourseArray[3] = { 1,2,3 };

	this->studentID = "Default";
	this->firstName = "Default";
	this->lastName = "Default";
	this->email = "Default";
	this->age = 0;
	this->daysInCourse = new int[3];
	this->setDaysInCourse(daysInCourseArray);
	this->program = SOFTWARE;
}

void Student::print() {
	std::cout << "ID: " << getStudentID() << "\t";
	std::cout << "First Name: " << getStudentID() << "\t";
	std::cout << "Last Name: " << getStudentID() << "\t";
	std::cout << "Email: " << getStudentID() << "\t";
	std::cout << "Age: " << getStudentID() << "\t";
	std::cout << "Course Days: " << this->daysInCourse[0] 
		<< ", "<< this->daysInCourse[1] 
		<< ", " << this->daysInCourse[2] << "\t";
	std::cout << "Degree: " << programString() << "\t\n";
}

string Student::programString() {
	switch (this->program) {
	case SECURITY:
		return "SECURITY";
		break;
	case NETWORK:
		return "NETWORK";
		break;
	case SOFTWARE:
		return "SOFTWARE";
		break;
	}
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setProgram(Degree program) {
	this->program = program;
}

Student::~Student()
{
	if (this->daysInCourse != nullptr)
	{
		delete[] this->daysInCourse;
		this->daysInCourse = nullptr;
	}
}