#pragma once
#ifndef __SENIOR_STUDENT_H_
#define __SENIOR_STUDENT_H_

#include "junior_student.h"
class Senior_Student : public Junior_Student
{
	friend ostream& operator<<(ostream& out, const Senior_Student& stu);
public:
	explicit Senior_Student(string id, string name, string sex,
		int age, int class_num, int chinese_grade, int math_grade,
		int english_grade, int geography_grade, int history_grade)

		:Junior_Student{ id,name, sex,age,class_num, chinese_grade,math_grade, english_grade },
		geography_grade{ geography_grade }, history_grade{ history_grade }
	{

	}
	int get_total_score() const
	{
		return this->Senior_Student::get_total_score() + geography_grade + history_grade;
	}
	int get_english_score()const
	{
		return english_grade;
	}
	int get_geography_grade()const
	{
		return geography_grade;
	}
	int get_history_grade()const
	{
		return history_grade;
	}
protected:
	void show_info(ostream& out) const
	{
		Junior_Student::show_info(out);
		out << setw(4) << geography_grade << setw(4) << history_grade;
	}

private:
	int geography_grade;
	int history_grade;
};
#endif // !__SENIOR_STUDENT_H_

