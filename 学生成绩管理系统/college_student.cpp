#include"college_student.h"

ostream& operator<<(ostream& out, const College_Student& stu)
{
	stu.show_info(out);
	return out;
}