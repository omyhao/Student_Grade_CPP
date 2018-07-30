#pragma once
#ifndef __COLLEGE_STUDENT_H_
#define __COLLEGE_STUDENT_H_

#include"student.h"
class College_Student : public Student
{
	friend ostream& operator<<(ostream& out, const College_Student& stu);
public:
	explicit College_Student(string id, string name, string sex, int age, int class_num,
		string major_name, int english_grade, int program_designing_grade, int calculous_grade
	)
		: Student{ id, name, sex, age, class_num },
		major_name{ major_name }, english_grade{ english_grade },
		program_designing_grade{ program_designing_grade },
		calculous_grade{ calculous_grade } {}
	int get_total_score() const
	{
		return english_grade + program_designing_grade + calculous_grade;
	}
	int get_english_score()const
	{
		return english_grade;
	}
	int get_program_designing_grade()const
	{
		return program_designing_grade;
	}
	int get_calculous_grade()const
	{
		return calculous_grade;
	}
protected:
	void show_info(ostream& out) const
	{
		Student::show_info(out);
		out << setw(4) << major_name << setw(4) << english_grade << setw(4) << program_designing_grade << setw(20) << calculous_grade;
	}
	

private:
	string major_name;
	int english_grade;
	int program_designing_grade;
	int calculous_grade;
};
#endif // !__COLLEGE_STUDENT_H_