#pragma once
#ifndef __STUDENT_MANAGE_H_
#define __STUDENT_MANAGE_H_
#include"student.h"
#include"student_factor.h"
#include"temp_student.h"
#include"junior_student.h"
#include"senior_student.h"
#include"college_student.h"
#include<vector>
#include<map>
#include<tuple>
#include<string>
using std::string;
using std::vector;
using std::map;
using std::tuple;
class Student_Manage
{
public:
	explicit Student_Manage();
	void ShowAllStudent();
	void AddStudent(Temp_Student& temp);
	void DeleteStudentById(string id);
	void EditStudentById(string id, Temp_Student& temp);
	void SortByTtotalScore();
	void SortBySingleScore();
	void CountTotalScore();
	void CountAverageScore();
	void CountNumOfStudent();
	Student* FindStudentById(string id);
	void ShowStudentInfo(const Student*);
	void FindStudentByName(string name);
	void Up_To_File();
	~Student_Manage();

private:
	map<string, Student*> all_student;
	Student_Factor student_factor;
};

#endif // !__STUDENT_MANAGE_H_