#pragma once
#ifndef __JUNIOR_STUDENT_H_
#define __JUNIOR_STUDENT_H_

#include"student.h"

class Junior_Student : public Student
{
	friend ostream& operator<<(ostream& out, const Junior_Student& stu);
public:
	explicit Junior_Student(string id, string name, string sex,
		int age, int class_num, int chinese_grade, int math_grade,
		int english_grade
	) : Student{ id, name, sex, age, class_num },
		chinese_grade{ chinese_grade },
		math_grade{ math_grade },
		english_grade{ english_grade }
	{	}
	int get_total_score() const
	{
		return chinese_grade + math_grade + english_grade;
	}
	int get_english_score()const
	{
		return english_grade;
	}
	int get_chinese_score()const
	{
		return chinese_grade;
	}
	int get_math_grade()const
	{
		return math_grade;
	}
protected:
	void show_info(ostream& out) const
	{
		Student::show_info(out);
		out << setw(4) << chinese_grade << setw(4) << math_grade << setw(4) << english_grade;
	}
	int english_grade;
private:
	int chinese_grade;
	int math_grade;
	
};
#endif // !__JUNIOR_STUDENT_H_