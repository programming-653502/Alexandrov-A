#include "stdafx.h"
#include <cstdlib>
#include <iostream>

int main()
{
	setlocale(0, "");
	int num = 0, otvet;
	L1: printf("Введите число\n");
	scanf_s("%d", &num);
	if (num < 100 || num >9999) {
		goto L1;
		}

	if (num >= 100 && num <= 9999) {
		int razrad1 = num - (num / 10) * 10;
		int razrad2 = (num / 10) % 10;
		int razrad3 = (num / 100) % 10;
		int razrad4 = (num / 1000) % 10;
		if (razrad4 > 0) {
			otvet = razrad1 + razrad2 + razrad3 + razrad4;
		}
		if (razrad4 == 0 && razrad3 > 0) {
			otvet = razrad1*razrad2*razrad3;
		}
		printf("Ответ: %d\n", otvet);
	}
	system("pause");
	return 0;
}

