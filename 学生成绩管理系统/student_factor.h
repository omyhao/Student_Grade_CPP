#pragma once
#ifndef __STUDENT_FACTOR_H_
#define __STUDENT_FACTOR_H_

#include"data_manage.h"
#include"junior_student.h"
#include"senior_student.h"
#include"college_student.h"
#include<vector>
#include<map>
#include"student.h"
using std::vector;
using std::map;
class Student_Factor
{
public:
	Student_Factor();
	map<string, Student*> Get_All_Student();
	vector<Junior_Student*> Get_All_Junior_Student();
	vector<Senior_Student*> Get_All_Senior_Student();
	vector<College_Student*> Get_All_College_Student();
	Student* New_Student(string id, string name, string sex,
		int age, int class_num, int chinese_grade, int math_grade,
		int english_grade);
	Student* New_Student(string id, string name, string sex,
		int age, int class_num, int chinese_grade, int math_grade,
		int english_grade, int geography_grade, int history_grade);
	Student* New_Student(string id, string name, string sex, int age, int class_num,
		string major_name, int english_grade, int program_designing_grade, int calculous_grade);
	void Update_Student_To_File(const map<string, Student*>& all_student);
	~Student_Factor();

private:
	Data_Manage junior_data_manage{ "junior_student.data" };
	Data_Manage senior_data_manage{ "senior_student.data" };
	Data_Manage college_data_manage{ "college_student.data" };
};

#endif // !__STUDENT_FACTOR_H_