#include"junior_student.h"

ostream& operator<<(ostream& out, const Junior_Student& stu)
{
	stu.show_info(out);
	return out;
}