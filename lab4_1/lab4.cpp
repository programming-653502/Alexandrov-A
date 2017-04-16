#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <iostream>
#include "locale.h"
#include <windows.h>

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Введите количество строк  ");
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
			if (((str[i][j] == 'ж') || (str[i][j] == 'Ж')) && ((str[i][j + 1] == 'ы') || (str[i][j + 1] == 'Ы'))) {
				(str[i][j + 1] = 'и');
							}
			if (((str[i][j] == 'ш') || (str[i][j] == 'Ш')) && ((str[i][j + 1] == 'ы') || (str[i][j + 1] == 'Ы'))) {
				(str[i][j + 1] = 'и');
							}
			if (((str[i][j] == 'ч') || (str[i][j] == 'Ч')) && ((str[i][j + 1] == 'ю') || (str[i][j + 1] == 'Ю'))) {
				(str[i][j + 1] = 'у');
							}
			if (((str[i][j] == 'щ') || (str[i][j] == 'Щ')) && ((str[i][j + 1] == 'ю') || (str[i][j + 1] == 'Ю'))) {
				(str[i][j + 1] = 'у');
				}
		}
	
			
	}
	std::cout << std::endl << "полученные строки" << std::endl;
	for (int i = 1; i <= n; i++) {
		puts(str[i]);
	}
	
	_getch();
	return 0;
}