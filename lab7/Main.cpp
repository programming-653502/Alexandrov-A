#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include "Nodes.h"
#include "Funcs.h"

int main()
{
	FILE *timetable;
	timetable = fopen("timetable.txt", "r");

    FILE *tickets;
	tickets = fopen("tickets.txt", "r");

	if (timetable == NULL)
	{
		std::cout << "timetable == NULL.";
		getch();
		return 1;
	}

        std::vector <Flight *> Flights(0);
	int counter = 0;


	while (!feof(timetable))
	{
                Flights.push_back(NULL);
                Flights[counter] = new Flight;
                fscanf(timetable, "%d %s %s %s %s %s %d %d %d %d %d %d %d %d %d %d\n", &(Flights[counter]->flight_number), &(Flights[counter]->airplane_type), &(Flights[counter]->way.starting_point), &(Flights[counter]->way.waypoint1), &(Flights[counter]->way.waypoint2), &(Flights[counter]->way.endpoint), &(Flights[counter]->days.hours), &(Flights[counter]->days.minutes), &(Flights[counter]->days.days[0]), &(Flights[counter]->days.days[1]), &(Flights[counter]->days.days[2]), &(Flights[counter]->days.days[3]), &(Flights[counter]->days.days[4]), &(Flights[counter]->days.days[5]), &(Flights[counter]->days.days[6]), &(Flights[counter]->seats_number));
		for (int j = 0; j < 7; j++)
		{
                        Flights[counter]->free_seats[j] = Flights[counter]->seats_number;
		}
		counter++;
	}


	Orders orders;
	orders.head = NULL;
	orders.last = NULL;
	orders.amount = 0;
	if (tickets != NULL)
	{
		if (getc(tickets) != EOF)
		{
			rewind(tickets);
			while (!feof(tickets))
			{
				Ticket *temp;
				temp = new Ticket;
				orders.amount += 1;
				if (orders.head == NULL)
				{
					orders.head = temp;
					orders.last = temp;
					temp->next = NULL;
				}
				else
				{
					orders.last->next = temp;
					orders.last = temp;
					temp->next = NULL;
				}
				fscanf(tickets, "%s %s %s %d %d %d %d\n", temp->name, temp->surname, temp->passport, &(temp->flight_number), &(temp->day), &(temp->hours), &(temp->minutes));
			}
		}
	}

	fclose(timetable);
	fclose(tickets);

	system("cls");
	for (;;)
	{
		int choice;
		choice = PrintMainMenu();

		switch (choice)
		{
                case 1: PrintSearchMenu(Flights);
			break;
                case 2: PrintTimetable(Flights);
			break;
                case 3: PrintTicketsMenu(orders, Flights);
			break;
		case 4: OrdersSave(orders);
			return 0;
		}
	}
}
