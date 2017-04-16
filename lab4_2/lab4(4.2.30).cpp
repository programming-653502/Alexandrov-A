#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	vector <string> buff;
	string buffer = "";
	ifstream file("labin.txt");
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		do
		{
			getline(file, buffer);
			buff.push_back(buffer);

		} while (!file.eof());
		int vector_size = buff.size();
		for (int i = 0; i < vector_size; i++)
		{
			cout << buff[i] << endl;
		}
		int *massday = new int[vector_size];
		int *massmonth = new int[vector_size];
		int *massyear = new int[vector_size];
		for (int i = 0; i < vector_size; i++)
		{
			massday[i] = (buff[i][0] - '0') * 10 + (buff[i][1] - '0');
			massmonth[i] = (buff[i][3] - '0') * 10 + (buff[i][4] - '0');
			massyear[i] = (buff[i][6] - '0') * 1000 + (buff[i][7] - '0') * 100 + (buff[i][8] - '0') * 10 + (buff[i][9] - '0');
		}
		int maxyear = 0;
		int minyear = 9999;
		int countmaxyear = 0;
		int countminyear = 0;
		int maxmonth = 0;
		int minmonth = 9999;
		int countmaxmonth = 0;
		int countminmonth = 0;
		int maxday = 0;
		int minday = 9999;
		int countmaxday = 0;
		int countminday = 0;
		for (int k = 0; k < vector_size; k++)
		{
			if (massyear[k] > maxyear)
			{
				maxyear = massyear[k];
				countmaxyear = k;
			}
			if (massyear[k] < minyear)
			{
				minyear = massyear[k];
				countminyear = k;
			}
		}
		if (maxyear == minyear)
		{
			for (int l = 0; l < vector_size; l++)
			{
				if (massmonth[l] > maxmonth)
				{
					maxmonth = massmonth[l];
					countmaxyear = l;
					countmaxmonth = l;
				}

				if (massmonth[l] < minmonth)
				{
					minmonth = massmonth[l];
					countminyear = l;
					countminmonth = l;
				}
			}
			if (maxmonth == minmonth)
			{
				for (int h = 0; h < vector_size; h++)
				{
					if (massday[h] > maxday)
					{
						maxday = massday[h];
						countmaxyear = h;
						countmaxmonth = h;
						countmaxday = h;
					}
					if (massday[h] < minday)
					{
						minday = massday[h];
						countminyear = h;
					}
				}
			}
		}
		ofstream fout("labout.txt");
		fout << "Самая большая дата";
		fout << endl << massday[countmaxyear] << "." << massmonth[countmaxyear] << "." << massyear[countmaxyear] << endl;
		fout << "Самая маленькая дата";
		fout << endl<<massday[countminyear] << "." << massmonth[countminyear] << "." << massyear[countminyear] << endl;
		system("pause");
	}
	return 0;
}

