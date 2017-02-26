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
	printf("Версия 1.0.0.\nby Alexandrov Anton\n");
}
int main()
{
	setlocale(0, "");
	double dlinarebra=0, vsadlina, ploshad, vusota, radiys, volume;
	int vubor=1;
	while (vubor != 8) {
		printf("\n1.Ввести длину ребра тетраэдра\n");
		printf("2.Вывод общей длины всех ребер тетраэдра\n");
		printf("3.Вывод площади всех граней тетраэдра\n");
		printf("4.Вывод объема тетраэдра\n");
		printf("5.Вывод высоты тетраэдра\n");
		printf("6.Вывод радиуса вписанного шара\n");
		printf("7.Информация о версии и авторе программы\n");
		printf("8.Выход из программы\n");
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

