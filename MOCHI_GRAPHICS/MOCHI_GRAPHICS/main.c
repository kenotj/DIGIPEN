#include <stdio.h>
#include <Windows.h>

int main() {
	for ( int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("%.3d. Text color in use : %.3d\n", i, i);
	}
	getchar();
	return 0;
}