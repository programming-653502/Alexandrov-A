#include "stdafx.h"
#include <iostream>
#include <math.h>
int factorial(int a) {
	if (a == 1 || a == 0)
		return 1;
	else return  a * factorial(a - 1);
}
int main()
{
	setlocale(0, "");
	int vubor = 1;
	float x = 0, e = 0;
	while (vubor != 0) {
		printf("\n1.Ввести x\n");
		printf("2.Ввести точность\n");
		printf("3.При каком n исследуемое выражение отличается от sin x менее, чем на заданную погрешность e \n");
		printf("0.Выход\n");
		scanf_s("%d", &vubor);
		switch (vubor) {
		case 1:scanf_s("%f", &x); break;
		case 2:scanf_s("%f", &e); break;
		case 3: {float left ;
			     long double right = 0;
			      int n;
			      for (n = 1;; n++) 
				  {
					  left = sin(x);
				      right = right + powl((-1), (n - 1))*powl(x, (2 * n - 1)) / factorial(2 * n - 1);
				      printf("%Lg\n", right);
				      printf("%f\n\n", left);
				      if (right < (-500)) {
					     printf("Для данной погрешности невозможно"); break;
				      }
				      if ((abs(left - right)) < e){
					     printf("%d", n);  break;
			          }
			      }
			    }break;
		default:break;
		}
	}
	return 0;
}

