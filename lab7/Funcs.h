//---------------------------------------------------------------------------

#ifndef FuncsH
#define FuncsH
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include "Nodes.h"

void OrdersSave(Orders orders);
int PrintMainMenu();
void PrintTicketsMenu(Orders &orders, std::vector <Flight *> all_flights);
void PrintTimetable(std::vector <Flight *> all_flights);
void PrintSearchMenu(std::vector <Flight *> all_flights);


//---------------------------------------------------------------------------
#endif
