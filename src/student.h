#pragma once
#include "degree.h"

using std::string;


class Student {
	public:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int* daysInCourse;
		Degree program;

		Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], Degree program);
		Student();

		~Student();

		void print();
		string programString();

		string getStudentID() { return this->studentID; };
		string getFirstName() { return this->firstName; };
		string getLastName() { return this->lastName; };
		string getEmail() { return this->email; };
		int getAge() { return this->age; };
		int* getDaysInCourse() { return this->daysInCourse; };
		Degree getProgram() { return this->program; };

		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDaysInCourse(int daysInCourse[]);
		void setProgram(Degree program);

};