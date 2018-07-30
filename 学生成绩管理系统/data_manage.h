#pragma once
#ifndef __DATA_MANAGE_H_
#define __DATA_MANAGE_H_

#include<string>
#include<fstream>
#include<vector>
using std::fstream;
using std::string;
using std::vector;
class Data_Manage
{
public:
	explicit Data_Manage(string file_path);
	bool open_file();
	vector<string> get_all_line();
	void save_all(const vector<string>& all_line);

private:
	string file_path;
	fstream file_stream;
};

#endif // !__DATA_MANAGE_H_