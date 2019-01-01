#ifndef HOMEWORK4_HOMEWORK4_STUDENT_H_
#define HOMEWORK4_HOMEWORK4_STUDENT_H_
#include <iostream>
#include <string>
using namespace std;

class Student {
	unsigned long long fac_num_;
	string first_name_;
	string last_name_;

public:
	Student(unsigned long long = 0, string = "", string = "");
	Student(const Student&);
	Student& operator=(const Student&);
	unsigned long long getFacNum() const;
	string getFirstName() const;
	string getLastName() const;
	bool operator==(const Student&) const;
	bool operator<(Student&) const;
	bool operator>(Student&) const;
	friend istream& operator>>(istream& is, Student& st);
	friend ostream& operator<<(ostream& os, Student& st);
};


#endif