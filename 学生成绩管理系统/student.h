#pragma once
#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<string>
#include<iostream>
#include<string>
#include<iomanip>
using std::setw;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

class Student
{
	friend ostream& operator<<(ostream& out, const Student& stu);
public:
	explicit Student(string id, string name, string sex, int age, int class_num)
		:id{ id }, name{ name }, sex{ sex }, age{ age }, class_num{ class_num }
	{

	}
	const string& getName() const
	{
		return name;
	}
	virtual int get_total_score() { return 0; }
	virtual int get_english_score() { return 0; }
protected:
	virtual void show_info(ostream& out) const
	{
		out << id << setw(10) << name << setw(4) << sex << setw(4) << age << setw(10) << class_num;
	}
	
private:
	string id;
	string name;
	string sex;
	int age;
	int class_num;
};


#endif // !__STUDENT_H_