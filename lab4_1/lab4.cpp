#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <iostream>
#include "locale.h"
#include <windows.h>

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("������� ���������� �����  ");
	int n=0;
	scanf_s("%d", &n);
	char str[256][256];
	for (int i = 0; i <= n; i++) {
		fgets(str[i], 256, stdin);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int len = strlen(str[i]);
		for (int j = 0; j < len; j++) {
			if (((str[i][j] == '�') || (str[i][j] == '�')) && ((str[i][j + 1] == '�') || (str[i][j + 1] == '�'))) {
				(str[i][j + 1] = '�');
							}
			if (((str[i][j] == '�') || (str[i][j] == '�')) && ((str[i][j + 1] == '�') || (str[i][j + 1] == '�'))) {
				(str[i][j + 1] = '�');
							}
			if (((str[i][j] == '�') || (str[i][j] == '�')) && ((str[i][j + 1] == '�') || (str[i][j + 1] == '�'))) {
				(str[i][j + 1] = '�');
							}
			if (((str[i][j] == '�') || (str[i][j] == '�')) && ((str[i][j + 1] == '�') || (str[i][j + 1] == '�'))) {
				(str[i][j + 1] = '�');
				}
		}
	
			
	}
	std::cout << std::endl << "���������� ������" << std::endl;
	for (int i = 1; i <= n; i++) {
		puts(str[i]);
	}
	
	_getch();
	return 0;
}