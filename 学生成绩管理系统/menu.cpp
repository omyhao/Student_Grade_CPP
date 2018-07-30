#include "menu.h"
#include"student_manage.h"
#include"temp_student.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::ifstream;
using std::istream;
using std::ios;
Student_Manage student_manage;
void ShowMenu();
void ShowSubMenu1();
void ShowSubMenu2();
void ShowSubMenu3();
void ShowSubMenu4();
void ShowSubMenu5();
void ShowSubMenu6();
void ShowSubMenu7();

void GetMenuIndex()
{
	string index;
	cin >> index;
	int i{ 0 };
	try
	{
		i = std::stoi(index);
	}
	catch (const std::exception&)
	{
		cout << endl << "请重新选择" << endl << endl;
		Sleep(300);
		system("cls");
		ShowMenu();
	}
	
	switch (i)
	{
	case 1:
		ShowSubMenu1();
		break;
	case 2:
		ShowSubMenu2();
		break;
	case 3:
		ShowSubMenu3();
		break;
	case 4:
		ShowSubMenu4();
		break;
	case 5:
		ShowSubMenu5();
		break;
	case 6:
		ShowSubMenu6();
		break;
	case 7:
		ShowSubMenu7();
		break;
	case 8:
		student_manage.Up_To_File();
		return;
	default:
		system("cls");
		ShowMenu();
		break;
	}
}

void ShowMenu()
{
	system("cls");
	cout << "------------学生成绩管理系统------------" << endl;
	cout << "   1.添加学生记录.    2.查询学生信息.    " << endl;
	cout << "   3.显示所有信息.    4.编辑学生信息.    " << endl;
	cout << "   5.删除学生记录.    6.统计相关信息.    " << endl;
	cout << "   7.排序显示.        8.退出.           " << endl;
	cout << endl << "请选择功能(1-8): ";
	GetMenuIndex();
}

void ShowSubMenu1()
{
	system("cls");
	cout << "------------学生成绩管理系统:添加学生记录------------" << endl;
	cout << "    1.添加小学生记录." << endl;
	cout << "    2.添加中学生记录." << endl;
	cout << "    3.添加大学生记录." << endl;
	cout << "    4.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	{
		Temp_Student temp_student;
		switch (i)
		{
		case 1:
			system("cls");
			cout << "------------学生成绩管理系统:添加小学生记录------------" << endl;
			cout << endl;
			cout << "学号: ";
			temp_student.type = 1;
			cin >> temp_student.id;
			if (student_manage.FindStudentById(temp_student.id))
			{
				cout << "该学生记录已存在，请重新输入" << endl;
				Sleep(1000);
				ShowSubMenu1();
			}
			cout << "姓名: "; cin >> temp_student.name;
			cout << "性别: "; cin >> temp_student.sex;
			cout << "年龄: "; cin >> temp_student.age;
			cout << "班级: "; cin >> temp_student.class_num;
			cout << "语文: "; cin >> temp_student.chinese_grade;
			cout << "数学: "; cin >> temp_student.math_grade;
			cout << "英语: "; cin >> temp_student.english_grade;
			student_manage.AddStudent(temp_student);
			ShowSubMenu1();
			break;
		case 2:
			system("cls");
			cout << "------------学生成绩管理系统:添加中学生记录------------" << endl;
			cout << endl;
			cout << "学号: ";
			temp_student.type = 2;
			cin >> temp_student.id;
			if (student_manage.FindStudentById(temp_student.id))
			{
				cout << "该学生记录已存在，请重新输入" << endl;
				Sleep(1000);
				ShowSubMenu1();
			}
			cout << "姓名: "; cin >> temp_student.name;
			cout << "性别: "; cin >> temp_student.sex;
			cout << "年龄: "; cin >> temp_student.age;
			cout << "班级: "; cin >> temp_student.class_num;
			cout << "语文: "; cin >> temp_student.chinese_grade;
			cout << "数学: "; cin >> temp_student.math_grade;
			cout << "英语: "; cin >> temp_student.english_grade;
			cout << "地理: "; cin >> temp_student.geography_grade;
			cout << "历史: "; cin >> temp_student.history_grade;
			student_manage.AddStudent(temp_student);
			ShowSubMenu1();
			break;
		case 3:
			system("cls");
			cout << "------------学生成绩管理系统:添加大学生记录------------" << endl;
			cout << endl;
			cout << "学号: ";
			temp_student.type = 3;
			cin >> temp_student.id;
			if (student_manage.FindStudentById(temp_student.id))
			{
				cout << "该学生记录已存在，请重新输入" << endl;
				Sleep(1000);
				ShowSubMenu1();
			}
			cout << "姓名: "; cin >> temp_student.name;
			cout << "性别: "; cin >> temp_student.sex;
			cout << "年龄: "; cin >> temp_student.age;
			cout << "班级: "; cin >> temp_student.class_num;
			cout << "专业: "; cin >> temp_student.major_name;
			cout << "英语: "; cin >> temp_student.english_grade;
			cout << "程序设计: "; cin >> temp_student.program_designing_grade;
			cout << "高数: "; cin >> temp_student.calculous_grade;
			student_manage.AddStudent(temp_student);
			ShowSubMenu1();
			break;
		case 4:
			ShowMenu();
			break;
		default:
			ShowMenu();
			break;
		}
	}
	
}

void ShowSubMenu2()
{
	system("cls");
	cout << "------------学生成绩管理系统:查询学生信息------------" << endl;
	cout << "    1.根据学号查询." << endl;
	cout << "    2.根据姓名查询." << endl;
	cout << "    3.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	{
		Temp_Student temp_student;
		Student* find;
		switch (i)
		{
		case 1:
			system("cls");
			cout << "------------学生成绩管理系统:根据学号查询------------" << endl;
			cout << "输入学号: ";
			cin >> temp_student.id;
			find = student_manage.FindStudentById(temp_student.id);
			if (find)
			{
				cout << *find;
				Sleep(2000);
				getchar();
			}
			else
			{
				cout << "无此学生存在";
				getchar();
			}
			ShowSubMenu2();
			break;
		case 2:
			system("cls");
			cout << "------------学生成绩管理系统:根据姓名查询------------" << endl;
			cout << "输入姓名: ";
			cin >> temp_student.name;
			student_manage.FindStudentByName(temp_student.name);
			Sleep(2000);
			getchar();
			ShowSubMenu2();
			break;
		case 3:
			ShowMenu();
			break;
		default:
			ShowMenu();
			break;
		}
	}
	
}

void ShowSubMenu3()
{
	system("cls");
	cout << "------------学生成绩管理系统:显示所有信息------------" << endl;
	student_manage.ShowAllStudent();
	cout << "    1.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	switch (i)
	{
	case 1:
		ShowMenu();
		break;
	default:
		ShowMenu();
		break;
	}
}
//暂未写完
void ShowSubMenu4()
{
	system("cls");
	cout << "------------学生成绩管理系统:编辑学生信息------------" << endl;
	cout << "输入学号: ";
	{
		Temp_Student temp_student;
		cin >> temp_student.id;
		Student* find;
		if (!(find = student_manage.FindStudentById(temp_student.id)))
		{
			cout << "无此学生学号" << endl;
			ShowMenu();
		}
		else
		{
			if (typeid(*(find)) == typeid(Junior_Student))
			{
				cout << "修改的是小学生" << endl;
				temp_student.type = 1;
				cout << "姓名: "; cin >> temp_student.name;
				cout << "性别: "; cin >> temp_student.sex;
				cout << "年龄: "; cin >> temp_student.age;
				cout << "班级: "; cin >> temp_student.class_num;
				cout << "语文: "; cin >> temp_student.chinese_grade;
				cout << "数学: "; cin >> temp_student.math_grade;
				cout << "英语: "; cin >> temp_student.english_grade;
				student_manage.EditStudentById(temp_student.id, temp_student);
				cout << "修改成功" << endl;
			}
			if (typeid(*(find)) == typeid(Senior_Student))
			{
				temp_student.type = 2;
				cout << "姓名: "; cin >> temp_student.name;
				cout << "性别: "; cin >> temp_student.sex;
				cout << "年龄: "; cin >> temp_student.age;
				cout << "班级: "; cin >> temp_student.class_num;
				cout << "语文: "; cin >> temp_student.chinese_grade;
				cout << "数学: "; cin >> temp_student.math_grade;
				cout << "英语: "; cin >> temp_student.english_grade;
				cout << "地理: "; cin >> temp_student.geography_grade;
				cout << "历史: "; cin >> temp_student.history_grade;
				student_manage.EditStudentById(temp_student.id, temp_student);
				
			}
			if (typeid(*(find)) == typeid(College_Student))
			{
				cout << "姓名: "; cin >> temp_student.name;
				cout << "性别: "; cin >> temp_student.sex;
				cout << "年龄: "; cin >> temp_student.age;
				cout << "班级: "; cin >> temp_student.class_num;
				cout << "专业: "; cin >> temp_student.major_name;
				cout << "英语: "; cin >> temp_student.english_grade;
				cout << "程序设计: "; cin >> temp_student.program_designing_grade;
				cout << "高数: "; cin >> temp_student.calculous_grade;
				student_manage.EditStudentById(temp_student.id, temp_student);
			}
		}
	}
	ShowMenu();	
}

void ShowSubMenu5()
{
	system("cls");
	cout << "------------学生成绩管理系统:删除学生记录------------" << endl;
	cout << "    1.输入学号." << endl;
	cout << "    2.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	{
		string id;
		Student* find;
		switch (i)
		{
		case 1:
			cin >> id;
			find = student_manage.FindStudentById(id);
			if (find)
			{
				student_manage.DeleteStudentById(id);

			}
			else
			{
				cout << "无此学号" << endl;
				Sleep(1000);
				ShowSubMenu5();
			}
			Sleep(1000);
			ShowSubMenu5();
			break;
		case 2:
			ShowMenu();
			break;
		default:
			ShowMenu();
			break;
		}
	}
	
}
void ShowSubMenu6()
{
	system("cls");
	cout << "------------学生成绩管理系统:统计相关信息------------" << endl;
	student_manage.CountNumOfStudent();
	student_manage.CountAverageScore();
	student_manage.CountTotalScore();
	cout << "    1.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	switch (i)
	{
	case 1:
		ShowMenu();
		break;
	default:
		ShowMenu();
		break;
	}
}
void ShowSubMenu7()
{
	system("cls");
	cout << "------------学生成绩管理系统:排序显示------------" << endl;
	student_manage.SortByTtotalScore();
	student_manage.SortBySingleScore();
	cout << "    1.返回主菜单." << endl;
	int i{ 0 };
	cin >> i;
	switch (i)
	{
	case 1:
		ShowMenu();
		break;
	default:
		ShowMenu();
		break;
	}
}