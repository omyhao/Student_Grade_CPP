#include"data_manage.h"
#include<iostream>

#include<sstream>

using std::stringstream;
using std::ios;
using std::cerr;
using std::endl;
using std::cout;
Data_Manage::Data_Manage(string file_path)
	:file_path{file_path}
{	
}

bool Data_Manage::open_file()
{
	file_stream.open(file_path, ios::in);
	if (!file_stream)
		return false;
	return true;
}

vector<string> Data_Manage::get_all_line()
{
	vector<string> all_line;
	string single_line;
	while (getline(file_stream, single_line))
	{
		all_line.emplace_back(single_line);
		single_line.clear();
	}
	file_stream.close();
	return all_line;
}

void Data_Manage::save_all(const vector<string>& all_line)
{
	file_stream.open(file_path, ios::out);
	for (auto& single : all_line)
	{
		file_stream << single << endl;
	}
	file_stream.close();
}