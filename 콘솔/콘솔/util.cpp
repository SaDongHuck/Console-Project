#include "util.h"
#include "Windows.h"
void setColoer(int forground, int background)
{
	int color = forground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
