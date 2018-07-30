#include"senior_student.h"

ostream& operator<<(ostream& out, const Senior_Student& stu)
{
	stu.show_info(out);
	return out;
}