#include "stdafx.h"
#include <cstdlib>
#include <iostream>
double vvod(double a) {
	
	scanf_s("%Lg", &a);
	return a;
}
double vsadlinafunc(double a) {
	return a * 6;
}
double ploshadfunc(double a) {
	return a*a*sqrt(3);
}
double vusotafunc(double a) {
	return a*sqrt(2.0/3.0);
}
double radiysfunc(double a) {
	return a / 12 * sqrt(6);
}
double volumefunc(double a) {
	return a*a*a / 12 * sqrt(2);
}
void infor() {
	printf("������ 1.0.0.\nby Alexandrov Anton\n");
}
int main()
{
	setlocale(0, "");
	double dlinarebra=0, vsadlina, ploshad, vusota, radiys, volume;
	int vubor=1;
	while (vubor != 8) {
		printf("\n1.������ ����� ����� ���������\n");
		printf("2.����� ����� ����� ���� ����� ���������\n");
		printf("3.����� ������� ���� ������ ���������\n");
		printf("4.����� ������ ���������\n");
		printf("5.����� ������ ���������\n");
		printf("6.����� ������� ���������� ����\n");
		printf("7.���������� � ������ � ������ ���������\n");
		printf("8.����� �� ���������\n");
		scanf_s("%d", &vubor);
		switch (vubor) {
		case 1:dlinarebra=vvod(dlinarebra);break;
		case 2:vsadlina=vsadlinafunc(dlinarebra);
			printf("%g\n", vsadlina); break;
		case 3:ploshad=ploshadfunc(dlinarebra);
			printf("%g\n",ploshad); break;
		case 4:volume=volumefunc(dlinarebra);
			printf("%g\n", volume); break;
		case 5:vusota=vusotafunc(dlinarebra);
			printf("%g\n", vusota); break;
		case 6:radiys=radiysfunc(dlinarebra);
			printf("%g\n", radiys); break;
		case 7:infor(); break;
		default: break;
		}
	}
	return 0;
}

