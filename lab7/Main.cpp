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

	std::vector <Flight *> all_flights(0);
	int counter = 0;


	while (!feof(timetable))
	{
		all_flights.push_back(NULL);
		all_flights[counter] = new Flight;
		fscanf(timetable, "%d %s %s %s %s %s %d %d %d %d %d %d %d %d %d %d\n", &(all_flights[counter]->flight_number), &(all_flights[counter]->airplane_type), &(all_flights[counter]->way.starting_point), &(all_flights[counter]->way.waypoint1), &(all_flights[counter]->way.waypoint2), &(all_flights[counter]->way.endpoint), &(all_flights[counter]->days.hours), &(all_flights[counter]->days.minutes), &(all_flights[counter]->days.days[0]), &(all_flights[counter]->days.days[1]), &(all_flights[counter]->days.days[2]), &(all_flights[counter]->days.days[3]), &(all_flights[counter]->days.days[4]), &(all_flights[counter]->days.days[5]), &(all_flights[counter]->days.days[6]), &(all_flights[counter]->seats_number));
		for (int j = 0; j < 7; j++)
		{
			all_flights[counter]->free_seats[j] = all_flights[counter]->seats_number;
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
		case 1: PrintSearchMenu(all_flights);
			break;
		case 2: PrintTimetable(all_flights);
			break;
		case 3: PrintTicketsMenu(orders, all_flights);
			break;
		case 4: OrdersSave(orders);
			return 0;
		}
	}
}
