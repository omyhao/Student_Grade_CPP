#include"student_manage.h"
#include<iostream>
#include<utility>
#include<algorithm>
using std::pair;
using std::cout;
using std::endl;
Student_Manage::Student_Manage()
{
	all_student = student_factor.Get_All_Student();
}

void Student_Manage::ShowAllStudent()
{
	for (auto index = all_student.cbegin() ; index != all_student.cend(); index++)
	{
		cout << *(index->second) << endl;
	}
}

void Student_Manage::AddStudent(Temp_Student& temp)
{
	if (all_student.find(temp.id) != all_student.end())
	{
		cout << "学生信息已存在,无须添加" << endl;
		return;
	}

	Student* new_student;
	switch (temp.type)
	{
	case 1:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex,
			temp.age, temp.class_num, temp.chinese_grade, temp.math_grade,
			temp.english_grade);
		break;
	case 2:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex,
			temp.age, temp.class_num, temp.chinese_grade, temp.math_grade,
			temp.english_grade, temp.geography_grade, temp.history_grade);
		break;
	case 3:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex, temp.age, temp.class_num,
			temp.major_name, temp.english_grade, temp.program_designing_grade, temp.calculous_grade);
		break;
	}
	all_student.insert(std::make_pair(temp.id, new_student));
}

void Student_Manage::DeleteStudentById(string id)
{
	if (FindStudentById(id))
	{
		all_student.erase(id);
	}
}

void Student_Manage::EditStudentById(string id, Temp_Student & temp)
{
	delete all_student[id];
	Student* new_student;
	switch (temp.type)
	{
	case 1:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex,
			temp.age, temp.class_num, temp.chinese_grade, temp.math_grade,
			temp.english_grade);
		all_student[id] = new_student;
		break;
	case 2:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex,
			temp.age, temp.class_num, temp.chinese_grade, temp.math_grade,
			temp.english_grade, temp.geography_grade, temp.history_grade);
		all_student[id] = new_student;
		break;
	case 3:
		new_student = student_factor.New_Student(temp.id, temp.name, temp.sex, temp.age, temp.class_num,
			temp.major_name, temp.english_grade, temp.program_designing_grade, temp.calculous_grade);
		all_student[id] = new_student;
		break;
	}
	
}

void Student_Manage::SortByTtotalScore()
{
	vector<Junior_Student*> all_junior_student;
	vector<Senior_Student*> all_senior_student;
	vector<College_Student*> all_college_student;

	auto begin = all_student.begin();
	while (begin != all_student.end())
	{
		if (typeid(*(begin->second)) == typeid(Junior_Student))
		{
			all_junior_student.emplace_back(static_cast<Junior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(Senior_Student))
		{
			
			all_senior_student.emplace_back(static_cast<Senior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(College_Student))
		{
			all_college_student.emplace_back(static_cast<College_Student*> (begin->second));
		}
		begin++;
	}
	std::sort(all_junior_student.begin(), all_junior_student.end(),
		[](const Junior_Student* lhs, const Junior_Student* rhs)
		{
			return lhs->get_total_score() > rhs->get_total_score();
		}
	);
	std::sort(all_senior_student.begin(), all_senior_student.end(),
		[](const Senior_Student* lhs, const Senior_Student* rhs)
	{
		return lhs->get_total_score() > rhs->get_total_score();
	}
	);
	std::sort(all_college_student.begin(), all_college_student.end(),
		[](const College_Student* lhs, const College_Student* rhs)
	{
		return lhs->get_total_score() > rhs->get_total_score();
	}
	);
	cout << "小学生成绩排名(按总分)" << endl;
	for (auto single : all_junior_student)
	{
		cout << *single <<endl;
	}
	cout << "中学生成绩排名(按总分)" << endl;
	for (auto single : all_senior_student)
	{
		cout << *single <<endl;
	}
	cout << "大学生成绩排名(按总分)" << endl;
	for (auto single : all_college_student)
	{
		cout << *single <<endl;
	}
}

void Student_Manage::SortBySingleScore()
{
	vector<Junior_Student*> all_junior_student;
	vector<Senior_Student*> all_senior_student;
	vector<College_Student*> all_college_student;

	auto begin = all_student.begin();
	while (begin != all_student.end())
	{
		if (typeid(*(begin->second)) == typeid(Junior_Student))
		{
			all_junior_student.emplace_back(static_cast<Junior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(Senior_Student))
		{

			all_senior_student.emplace_back(static_cast<Senior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(College_Student))
		{
			all_college_student.emplace_back(static_cast<College_Student*> (begin->second));
		}
		begin++;
	}
	std::sort(all_junior_student.begin(), all_junior_student.end(),
		[](const Junior_Student* lhs, const Junior_Student* rhs)
	{
		return lhs->get_english_score() > rhs->get_english_score();
	}
	);
	std::sort(all_senior_student.begin(), all_senior_student.end(),
		[](const Senior_Student* lhs, const Senior_Student* rhs)
	{
		return lhs->get_english_score() > rhs->get_english_score();
	}
	);
	std::sort(all_college_student.begin(), all_college_student.end(),
		[](const College_Student* lhs, const College_Student* rhs)
	{
		return lhs->get_english_score() > rhs->get_english_score();
	}
	);
	cout << "小学生成绩排名(按英语成绩)" << endl;
	for (auto single : all_junior_student)
	{
		cout << *single << endl;
	}
	cout << "中学生成绩排名(按英语成绩)" << endl;
	for (auto single : all_senior_student)
	{
		cout << *single <<endl;
	}
	cout << "大学生成绩排名(按英语成绩)" << endl;
	for (auto single : all_college_student)
	{
		cout << *single <<endl;
	}
}

void Student_Manage::CountTotalScore()
{
	this->SortByTtotalScore();
}

void Student_Manage::CountAverageScore()
{
	vector<Junior_Student*> all_junior_student;
	vector<Senior_Student*> all_senior_student;
	vector<College_Student*> all_college_student;

	auto begin = all_student.begin();
	while (begin != all_student.end())
	{
		if (typeid(*(begin->second)) == typeid(Junior_Student))
		{
			all_junior_student.emplace_back(static_cast<Junior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(Senior_Student))
		{

			all_senior_student.emplace_back(static_cast<Senior_Student*> (begin->second));
		}
		if (typeid(*(begin->second)) == typeid(College_Student))
		{
			all_college_student.emplace_back(static_cast<College_Student*> (begin->second));
		}
		begin++;
	}
	cout << "小学生成绩统计" << endl;
	if (all_junior_student.size() != 0)
	{
		
		{
			double average_chinese_grade{ 0.0 }, average_math_grade{ 0.0 }, average_english_grade{ 0.0 };
			for (auto& single : all_junior_student)
			{
				average_chinese_grade += single->get_chinese_score();
				average_math_grade += single->get_math_grade();
				average_english_grade += single->get_english_score();
			}
			average_chinese_grade /= all_student.size();
			average_math_grade /= all_student.size();
			average_english_grade /= all_student.size();
			cout << "语文均分:" << average_chinese_grade << endl
				<< "数学均分:" << average_math_grade << endl
				<< "英语均分:" << average_english_grade << endl;
		}
	}
	cout << "中学生成绩统计" << endl;
	if (all_senior_student.size()!=0)
	{
		
		{
			double average_chinese_grade{ 0.0 }, average_math_grade{ 0.0 }, average_english_grade{ 0.0 },
				average_geography_grade{ 0.0 }, average_history_grade{ 0.0 };
			for (auto& single : all_senior_student)
			{
				average_chinese_grade += single->get_chinese_score();
				average_math_grade += single->get_math_grade();
				average_english_grade += single->get_english_score();
				average_geography_grade += single->get_geography_grade();
				average_history_grade += single->get_history_grade();
			}
			average_chinese_grade /= all_student.size();
			average_math_grade /= all_student.size();
			average_english_grade /= all_student.size();
			average_geography_grade /= all_student.size();
			average_history_grade /= all_student.size();
			cout << "语文均分:" << average_chinese_grade << endl
				<< "数学均分:" << average_math_grade << endl
				<< "英语均分:" << average_english_grade << endl
				<< "地理均分:" << average_geography_grade << endl
				<< "历史均分:" << average_history_grade << endl;
		}
	}
	cout << "大学生成绩统计" << endl;
	if (all_college_student.size()!=0)
	{
		
		{
			double average_english_grade{ 0.0 }, average_program_designing_grade{ 0.0 }, average_calculous_grade{ 0.0 };
			for (auto& single : all_college_student)
			{
				average_english_grade += single->get_english_score();
				average_program_designing_grade += single->get_program_designing_grade();
				average_calculous_grade += single->get_calculous_grade();
			}
			average_program_designing_grade /= all_student.size();
			average_calculous_grade /= all_student.size();
			average_english_grade /= all_student.size();
			cout << "英语均分:" << average_english_grade << endl
				<< "程序设计均分:" << average_program_designing_grade << endl
				<< "高数均分:" << average_calculous_grade << endl;
		}
	}
	
}

void Student_Manage::CountNumOfStudent()
{
	cout << "系统中共有: " << all_student.size() << "名学生" << endl;
}

Student* Student_Manage::FindStudentById(string id)
{
	auto result = all_student.find(id);
	if (result != all_student.end())
	{
		return result->second;
	}
	return nullptr;
}

void Student_Manage::ShowStudentInfo(const Student * stu)
{
	if (stu)
	{
		cout << *stu;
	}

}

void Student_Manage::FindStudentByName(string name)
{
	//vector<Student*> all_Student_With_Name;
	auto it = all_student.begin();
	while (it != all_student.end())
	{
		if ((it->second)->getName() == name)
		{
			cout << *(it->second) << endl;
		}
		it++;
	}
}

void Student_Manage::Up_To_File()
{
	student_factor.Update_Student_To_File(all_student);
	auto it = all_student.begin();
	while (it != all_student.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}
}

Student_Manage::~Student_Manage()
{
	
}