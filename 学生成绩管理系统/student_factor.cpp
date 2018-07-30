#include"student_factor.h"
#include"junior_student.h"
#include"senior_student.h"
#include"college_student.h"
#include<Windows.h>
#include<sstream>
#include<utility>
using std::istringstream;
using std::stringstream;
using std::pair;
Student_Factor::Student_Factor()
{
	if (!junior_data_manage.open_file() ||
		!senior_data_manage.open_file() ||
		!college_data_manage.open_file()
		)
	{
		cout << "文件不存在，或无法访问，系统将退出" << endl;
		Sleep(1000);
		exit(EXIT_FAILURE);
	}	
}

map<string, Student*> Student_Factor::Get_All_Student()
{
	map<string, Student*> all_student;
	for (auto& single_line : junior_data_manage.get_all_line())
	{
		istringstream single_student{single_line};
		string id, name, sex;
		single_student >> id >> name >> sex;
		int age, class_num,
			chinese_grade,math_grade,english_grade;
		single_student >> age >> class_num
			>> chinese_grade >> math_grade >> english_grade;
		all_student.insert(
			std::make_pair(id,
				new Junior_Student{
					id, name,sex, age,
					class_num,chinese_grade,math_grade,english_grade }));

	}
	for (auto& single_line : senior_data_manage.get_all_line())
	{
		istringstream single_student{ single_line };
		string id, name, sex;
		single_student >> id >> name >> sex;
		int age, class_num,
			chinese_grade, math_grade, english_grade, geography_grade,history_grade;
		single_student >> age >> class_num
			>> chinese_grade >> math_grade >> english_grade
			>> geography_grade >> history_grade;
		all_student.insert(
			std::make_pair(id,
				new Senior_Student{
					id, name,sex, age,
					class_num,chinese_grade,math_grade,english_grade,
					geography_grade, history_grade
				}));
	}
	for (auto& single_line : college_data_manage.get_all_line())
	{
		istringstream single_student{ single_line };
		string id, name, sex, major_name;
		single_student >> id >> name >> sex;
		int age, class_num, english_grade, program_designing_grade, calculous_grade;
		single_student >> age >> class_num
			>> major_name >> english_grade >> program_designing_grade
			>> calculous_grade;

		all_student.insert(
			std::make_pair(id,
				new College_Student{
					id, name,sex, age,
					class_num,major_name, english_grade, program_designing_grade,
					calculous_grade
				}));
	}
	return all_student;
}

vector<Junior_Student*> Student_Factor::Get_All_Junior_Student()
{
	
	return vector<Junior_Student*>();
}

vector<Senior_Student*> Student_Factor::Get_All_Senior_Student()
{
	return vector<Senior_Student*>();
}

vector<College_Student*> Student_Factor::Get_All_College_Student()
{
	return vector<College_Student*>();
}

Student * Student_Factor::New_Student(string id, string name, string sex,
	int age, int class_num, int chinese_grade, int math_grade,
	int english_grade)
{
	return new Junior_Student{ id, name, sex,
		age, class_num, chinese_grade, math_grade,
		english_grade };
}

Student * Student_Factor::New_Student(
	string id, string name, string sex, int age, int class_num, 
	int chinese_grade, int math_grade, int english_grade, 
	int geography_grade, int history_grade)
{
	return new Senior_Student{ id, name, sex,
		age, class_num, chinese_grade, math_grade,
		english_grade, geography_grade, history_grade };
}

Student * Student_Factor::New_Student(
	string id, string name, string sex, int age, int class_num, 
	string major_name, int english_grade, 
	int program_designing_grade, int calculous_grade)
{
	return new College_Student{ id, name, sex, age, class_num,
		major_name, english_grade, program_designing_grade,calculous_grade };
}

void Student_Factor::Update_Student_To_File(const map<string, Student*>& all_student)
{
	vector<string> all_junior_student;
	vector<string> all_senior_student;
	vector<string> all_college_student;
	auto begin = all_student.cbegin();
	while (begin!=all_student.cend())
	{
		if (typeid(*(begin->second)) == typeid(Junior_Student))
		{
			stringstream single_line;
			single_line << *(begin->second);
			all_junior_student.emplace_back(single_line.str());
		}
		if (typeid(*(begin->second)) == typeid(Senior_Student))
		{
			stringstream single_line;
			single_line << *(begin->second);
			all_senior_student.emplace_back(single_line.str());
		}
		if (typeid(*(begin->second)) == typeid(College_Student))
		{
			stringstream single_line;
			single_line << *(begin->second);
			all_college_student.emplace_back(single_line.str());
		}
		++begin;
	}
	junior_data_manage.save_all(all_junior_student);
	senior_data_manage.save_all(all_senior_student);
	college_data_manage.save_all(all_college_student);
}

Student_Factor::~Student_Factor()
{
}