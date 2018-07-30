#include"student.h"
//下面的函数因为在头文件中定义，导致了LNK2005的错误
ostream& operator<<(ostream& out, const Student& stu)
{
	stu.show_info(out);
	return out;
}