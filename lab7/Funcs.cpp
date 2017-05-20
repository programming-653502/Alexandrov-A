//---------------------------------------------------------------------------

#pragma hdrstop

#include "Funcs.h"
void SearchFlightNumber(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		bool found = false;
		std::cout << "Enter flight number: ";
		int number;
		std::cin >> number;
		while (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Enter flight number: ";
			std::cin >> number;
		}


		int k = 0;
                for (int i = 0; i < Flights.size(); i++)
		{
                        if (Flights[i]->flight_number == number)
			{
				if (found == false)
				{
					   found = true;
				}

				k++;


				std::cout << k << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';

				std::cout << '\n';
			}

		}

		if (found == false)
		std::cout << "Flight number " << number << " not found.\n";

		std::cout << "Do you want to continue search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void SearchAirplaneType(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		std::cout << "Enter airplane type: ";
		char type[20];
		std::cin >> type;
		while (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect input. Try again.\n";
			std::cout << "Enter airplane type: ";
			std::cin >> type;
		}

		bool found = false;
		int k = 0;
                for (int i = 0; i < Flights.size(); i++)
		{
                        if (!strcmp(Flights[i]->airplane_type, type))
			{
				if (found == false)
				{
					   found = true;
				}

				k++;


				std::cout << k << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';

				std::cout << '\n';
			}

		}

		if (found == false)
		 std::cout << "Airplane type " << type << " not found.\n";

		std::cout << "Do you want to continue your search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void SearchRoute(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		std::cout << "Enter route(From - To): ";
		char from[15];
		char to[15];
		while (scanf("%s - %s", &from, &to) != 2)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Try again.\n";
			std::cout << "Enter route(From - To): ";
		}

		bool found = false;
		int k = 0;
                for (int i = 0; i < Flights.size(); i++)
		{
			int suitable_from = 0;
			int suitable_to = 0;

                        if (!strcmp(Flights[i]->way.starting_point, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.waypoint1, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.waypoint2, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}
                        if (!strcmp(Flights[i]->way.waypoint1, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.waypoint2, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}

                        if (!strcmp(Flights[i]->way.waypoint2, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}

			if (suitable_from && suitable_to)
			{
				if (found == false)
				{
					   found = true;
				}

				k++;


				std::cout << k << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';

				std::cout << '\n';
			}

		}

		if (found == false)
		std::cout << "Route " << from << " - " << to << " not found.\n";


		std::cout << "Do you want to continue search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void SearchArrivalTime(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		std::cout << "Enter arrival time: ";
		int hours;
		int minutes;
		while (scanf("%d:%d", &hours, &minutes) != 2)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Incorrect time. Try again.\n";
			std::cout << "Enter arrival time(hh:mm): ";
		}

		bool found = false;
		int k = 0;
                for (int i = 0; i < Flights.size(); i++)
		{
                        if (Flights[i]->days.hours == hours && Flights[i]->days.minutes == minutes)
			{
				if (found == false)
				{
					   found = true;
				}

				k++;


				std::cout << k << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';

				std::cout << '\n';
			}

		}

		if (found == false)
		std::cout << "Arrival time " << hours << ":" << minutes << " not found.\n";


		std::cout << "Do you want to continue  search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void SearchArrivalDay(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		std::cout << "Choose day:\n";
		std::cout << "1. Monday\n";
		std::cout << "2. Tuesday\n";
		std::cout << "3. Wednesday\n";
		std::cout << "4. Thusday\n";
		std::cout << "5. Friday\n";
		std::cout << "6. Saturday\n";
		std::cout << "7. Sunday\n";

		char day;
		day = getch();
		while (day != '1' && day != '2' && day != '3' && day != '4' && day != '5' && day != '6' && day != '7')
		{
			std::cout << "\nTry again\n";
			day = getch();
		}

		bool found = false;
		int k = 0;
                for (int i = 0; i < Flights.size(); i++)
		{
                        if (Flights[i]->days.days[atoi(&day) - 1])
			{
			if (found == false)
				{
					   found = true;
				}

				k++;


				std::cout << k << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';

				std::cout << '\n';
			}

		}

		if (found == false)
		{
			std::cout << "Arrival day ";
			switch (day)
			{
			case '1': std::cout << "Monday";
				break;
			case '2': std::cout << "Tuesday";
				break;
			case '3': std::cout << "Wednesday";
				break;
			case '4': std::cout << "Thusday";
				break;
			case '5': std::cout << "Friday";
				break;
			case '6': std::cout << "Saturday";
				break;
			case '7': std::cout << "Sunday";
				break;
			}
			std::cout << " not found.\n";
		}

		std::cout << "Do you want to continue  search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void SearchClosestFlight(std::vector <Flight *> Flights)
{
	system("cls");

	for (;;)
	{
		std::cout << "Enter route(From - To): ";
		char from[15];
		char to[15];
		while (scanf("%s - %s", &from, &to) != 2)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Try again.\n";
			std::cout << "Enter route(From - To): ";
		}

		std::cout << "What day is it today?\n";
		std::cout << "1. Monday\n";
		std::cout << "2. Tuesday\n";
		std::cout << "3. Wednesday\n";
		std::cout << "4. Thusday\n";
		std::cout << "5. Friday\n";
		std::cout << "6. Saturday\n";
		std::cout << "7. Sunday\n";

		char day;
		day = getch();
		while (day != '1' && day != '2' && day != '3' && day != '4' && day != '5' && day != '6' && day != '7')
		{
			std::cout << "\nInvalid command. Try again\n";
			day = getch();
		}

		std::cout << "Enter current time(hh:mm): ";
		int hours;
		int minutes;
		while (scanf("%d:%d", &hours, &minutes) != 2)
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Try again.\n";
			std::cout << "Enter arrival time: ";
		}

		bool found = false;
                Flights.push_back(NULL);
                Flights.back() = new Flight;
		int min_closeness = 8;
                for (int i = 0; i < Flights.size(); i++)
		{
			int suitable_from = 0;
			int suitable_to = 0;

                        if (!strcmp(Flights[i]->way.starting_point, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.waypoint1, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.waypoint2, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}
                        if (!strcmp(Flights[i]->way.waypoint1, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.waypoint2, to)) suitable_to = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}

                        if (!strcmp(Flights[i]->way.waypoint2, from))
			{
				suitable_from = 1;
                                if (!strcmp(Flights[i]->way.endpoint, to)) suitable_to = 1;
			}

			int current_closeness = 9;
			if (suitable_from && suitable_to)
			{
				for (int j = 0; j < 7; j++)
				{
                                        if (Flights[i]->days.days[j])
					{
						if (atoi(&day) > j + 1) current_closeness = 8 - atoi(&day) + j;
						if (atoi(&day) < j + 1) current_closeness = j + 1 - atoi(&day);
						if (atoi(&day) == j + 1)
						{
                                                        if (Flights[i]->days.hours > hours) current_closeness = 0;
							else current_closeness = 7;
						}

						if (current_closeness < min_closeness)
						{
                                                        Flights.back() = Flights[i];
							found = true;
							min_closeness = current_closeness;
						}
                                                if ((current_closeness == min_closeness) && (Flights.back()->days.hours > Flights[i]->days.hours))
						{
                                                        Flights.back() = Flights[i];
							found = true;
							min_closeness = current_closeness;
						}
                                                if ((current_closeness == min_closeness) && (Flights.back()->days.hours = Flights[i]->days.hours) && (Flights.back()->days.minutes = Flights[i]->days.minutes))
						{
                                                        Flights.back() = Flights[i];
							found = true;
							min_closeness = current_closeness;
						}
					}
				}
			}
		}



		if (found == false)
		std::cout << "Route " << from << " - " << to << " not found.\n";

		else
		{

                                std::cout <<"Flight number: "<< Flights.back()->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights.back()->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights.back()->way.starting_point << " - ";
                                if (strcmp(Flights.back()->way.waypoint1, "NULL")) std::cout << Flights.back()->way.waypoint1 << " - ";
                                if (strcmp(Flights.back()->way.waypoint2, "NULL")) std::cout << Flights.back()->way.waypoint2 << " - ";
                                std::cout << Flights.back()->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights.back()->days.hours <<":";
                                std::cout << Flights.back()->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights.back()->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights.back()->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights.back()->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights.back()->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights.back()->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights.back()->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights.back()->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights.back()->seats_number << '\n';

				std::cout << '\n';
		}

                Flights.pop_back();
		std::cout << "Do you want to continue  search? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Invalid command. Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void OrderTickets(Orders &orders, std::vector <Flight *> Flights)
{

	system("cls");

        for (int i = 0; i < Flights.size(); i++)
	{
				std::cout << i+1 << "\n";
                                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                                std::cout << Flights[i]->way.endpoint<<"\n";
                                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                                std::cout << Flights[i]->days.minutes << "\n";
				std::cout <<"Days: ";
                                if (Flights[i]->days.days[0])
				{
					std::cout << "Monday ";
				}
                                if (Flights[i]->days.days[1])
				{
					std::cout << "Tuesday ";
				}
                                if (Flights[i]->days.days[2])
				{
					std::cout << "Wednesday ";
				}
                                if (Flights[i]->days.days[3])
				{
					std::cout << "Thusday ";
				}
                                if (Flights[i]->days.days[4])
				{
					std::cout << "Friday ";
				}
                                if (Flights[i]->days.days[5])
				{
					std::cout << "Saturday ";
				}
                                if (Flights[i]->days.days[6])
				{
					std::cout << "Sunday"<< "\n";
				}
                                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';
	}

	for (;;)
	{
		std::cout << "\nChoose flight\n";
		char number[4];
		std::cin >> number;
                while (atoi(number) < 1 || atoi(number) > Flights.size())
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Try again.\n";
			std::cin >> number;
		}

		std::cout << "\nChoose day:\n";
		std::cout << "1. Monday\n";
		std::cout << "2. Tuesday\n";
		std::cout << "3. Wednesday\n";
		std::cout << "4. Thusday\n";
		std::cout << "5. Friday\n";
		std::cout << "6. Saturday\n";
		std::cout << "7. Sunday\n";

		char day[2];
		day[0] = getche();
		for (;;)
		{
			while (day[0] != '1' && day[0] != '2' && day[0] != '3' && day[0] != '4' && day[0] != '5' && day[0] != '6' && day[0] != '7')
			{
				std::cout << "\nTry again\n";
				day[0] = getche();
			}
                        if (Flights.at(atoi(number) - 1)->days.days[(atoi(day) - 1)]) break;
			else
			{
				std::cout << "\nTry another one.\n";
				day[0] = getch();
			}
		}

                if (Flights.at(atoi(number) - 1)->free_seats[atoi(day) - 1])
		{
                        Flights.at(atoi(number) - 1)->free_seats[atoi(day) - 1] -= 1;
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
			std::cout << "\nEnter your  Name:\n";
			char str[16];
			std::cin >> str;
			strcpy(temp->name, str);
			std::cout << "Surname: ";
			std::cin >> str;
			strcpy(temp->surname, str);
			std::cout << "Passport: ";
			std::cin >> str;
			strcpy(temp->passport, str);
                        temp->flight_number = Flights.at(atoi(number) - 1)->flight_number;
			temp->day = atoi(day);
                        temp->hours = Flights.at(atoi(number) - 1)->days.hours;
                        temp->minutes = Flights.at(atoi(number) - 1)->days.minutes;
			std::cout << "\nTicket  ordered! \n";
		}
		else
		{
			std::cout << "No free seats available. \n";
		}

		std::cout << "Do you want to order one more ticket? (Y/N)\n";
		char choice;
		choice = getch();
		while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
		{
			std::cout << "Try again.\n";
			choice = getch();
		}
		if (choice == 'n'||choice == 'N') return;
	}
}
void ReturnTickets(Orders &orders)
{
	for (;;)
	{
		system("cls");
		Ticket *temp;
		temp = orders.head;
		int counter = 1;
		if (temp)
		{

			while (temp)
			{
				std::cout<<"Number: "<<counter<<"\n";
				std::cout<<"Name"<<temp->name<<"\n";
				std::cout<<"Surname"<<temp->surname<<"\n";
				std::cout<<"Flight Number"<<temp->flight_number<<"\n";
				std::cout<<"Time"<<temp->hours<<":"<<temp->minutes<<"\n";
				std::cout << "Nearest ";
				if (temp->day == 1)
				{
					std::cout << "Monday\n";
				}
				if (temp->day == 2)
				{
					std::cout << "Tuesday\n";
				}
				if (temp->day == 3)
				{
					std::cout << "Wednesday\n";
				}
				if (temp->day == 4)
				{
					std::cout << "Thusday\n";
				}
				if (temp->day == 5)
				{
					std::cout << "Friday\n";
				}
				if (temp->day == 6)
				{
					std::cout << "Saturday\n";
				}
				if (temp->day == 7)
				{
					std::cout << "Sunday\n";
				}

				temp = temp->next;
				counter++;
			}


			std::cout << "Which ticket you want to return? \n";
			char number[4];
			std::cin >> number;
			while (atoi(number) < 1 || atoi(number) > orders.amount)
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Try again.\n";
				std::cin >> number;
			}

			orders.amount -= 1;
			temp = orders.head;
			for (int j = 0; j < (atoi(number) - 2); j++)
			temp = temp->next;
			Ticket *for_delete;
			if (atoi(number) != 1)
			{
				for_delete = temp->next;
				if (temp->next->next == NULL) orders.last = temp;
				temp->next = temp->next->next;
				delete[] for_delete;
			}
			else
			{
				for_delete = temp;
				orders.head = temp->next;
				delete[] for_delete;
			}
			std::cout << "You ticket  returned\n";

			std::cout << "Do you want to return one more ticket? (Y/N)\n";
			char choice;
			choice = getch();
			while (choice != 'n' && choice != 'y'&& choice != 'N' && choice != 'Y')
			{
			   std::cout << "Try again.\n";
			   choice = getch();
			}
			if (choice == 'n'||choice == 'N') return;
		}
		else
		{
			std::cout << "You don't order any tickets.\n";
			std::cout << "Tap anywhere\n";
			getch();
			return;
		}
	}
}
void ShowTickets(Orders orders, std::vector <Flight *> Flights)
{
	system("cls");
	Ticket *temp;
	temp = orders.head;
	int counter = 1;
	if (!temp)
	std::cout << "You don't order any tickets.\n";

	while (temp)
	{
		std::cout<<"Number: "<<counter<<"\n";
		std::cout<<"Name"<<temp->name<<"\n";
		std::cout<<"Surname"<<temp->surname<<"\n";
		std::cout<<"Flight Number"<<temp->flight_number<<"\n";
		std::cout<<"Time"<<temp->hours<<":"<<temp->minutes<<"\n";
		std::cout << "Nearest ";
		if (temp->day == 1)
		{
			std::cout << "Monday\n";
		}
		if (temp->day == 2)
		{
			std::cout << "Tuesday\n";
		}
		if (temp->day == 3)
		{
			std::cout << "Wednesday\n";
		}
		if (temp->day == 4)
		{
			std::cout << "Thusday\n";
		}
		if (temp->day == 5)
		{
			std::cout << "Friday\n";
		}
		if (temp->day == 6)
		{
			std::cout << "Saturday\n";
		}
		if (temp->day == 7)
		{
			std::cout << "Sunday\n";
		}

		temp = temp->next;
		counter++;
	}

	std::cout << "Tap anywhere\n";

	getch();
}
void PrintSearchMenu(std::vector <Flight *> Flights)
{
	for (;;)
	{
		system("cls");
		std::cout << "1 Search flight number\n";
		std::cout << "2 Search airplane type\n";
		std::cout << "3 Search route\n";
		std::cout << "4 Search arrival time\n";
		std::cout << "5 Search arrival day\n";
		std::cout << "6 Search closest flight\n";
		std::cout << "7 Return\n";

		char choice;
		choice = getch();
		while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7')
		{
			std::cout << "\nInvalid command. Try again\n";
			choice = getch();
		}
		std::cout << '\n';

		switch (atoi(&choice))
		{
                case 1: SearchFlightNumber(Flights);
			break;
                case 2: SearchAirplaneType(Flights);
			break;
                case 3: SearchRoute(Flights);
			break;
                case 4: SearchArrivalTime(Flights);
			break;
                case 5: SearchArrivalDay(Flights);
			break;
                case 6: SearchClosestFlight(Flights);
			break;
		case 7: return;
		}
	}
}
void PrintTimetable(std::vector <Flight *> Flights)
{
	system("cls");
        for (int i = 0; i < Flights.size(); i++)
	{
                std::cout <<"Flight number: "<< Flights[i]->flight_number << "\n";
                std::cout <<"Airplane type: "<< Flights[i]->airplane_type << "\n";
                std::cout <<"Way: "<< Flights[i]->way.starting_point << " - ";
                if (strcmp(Flights[i]->way.waypoint1, "NULL")) std::cout << Flights[i]->way.waypoint1 << " - ";
                if (strcmp(Flights[i]->way.waypoint2, "NULL")) std::cout << Flights[i]->way.waypoint2 << " - ";
                std::cout << Flights[i]->way.endpoint<<"\n";
                std::cout <<"time: "<< Flights[i]->days.hours <<":";
                std::cout << Flights[i]->days.minutes << "\n";
		std::cout <<"Days: ";
                if (Flights[i]->days.days[0])
		{
		   std::cout << "Monday ";
		}
                if (Flights[i]->days.days[1])
		{
		   std::cout << "Tuesday ";
		}
                if (Flights[i]->days.days[2])
		{
		   std::cout << "Wednesday ";
		}
                if (Flights[i]->days.days[3])
		{
		   std::cout << "Thusday ";
		}
                if (Flights[i]->days.days[4])
		{
		   std::cout << "Friday ";
		}
                if (Flights[i]->days.days[5])
		{
		   std::cout << "Saturday ";
		}
                if (Flights[i]->days.days[6])
		{
		   std::cout << "Sunday"<< "\n";
		}
                std::cout <<"Seats: "<< Flights[i]->seats_number << '\n';
	}

	std::cout << "Tap any key";

	getch();
}
void PrintTicketsMenu(Orders &orders, std::vector <Flight *> Flights)
{
	for (;;)
	{
		system("cls");

		std::cout << "1 Order tickets\n";
		std::cout << "2 View my orders\n";
		std::cout << "3 Return tickets\n";
		std::cout << "4 Return\n";

		char choice;
		choice = getch();
		while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
		{
			std::cout << "\nTry again\n";
			choice = getch();
		}
		std::cout << '\n';

		switch (atoi(&choice))
		{
                case 1: OrderTickets(orders, Flights);
			break;
                case 2: ShowTickets(orders, Flights);
			break;
		case 3: ReturnTickets(orders);
			break;
		case 4: return;
		}
	}
}
int PrintMainMenu()
{
	system("cls");

	std::cout << "Choose one of the options : \n";
	std::cout << "1.Search\n";
	std::cout << "2.Timetable\n";
	std::cout << "3.Tickets\n";
	std::cout << "4.Quit\n";

	char choice;
	choice = getch();
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
	{
		std::cout << "\nTry again\n";
		choice = getch();
	}
	std::cout << '\n';

	return atoi(&choice);
}
void OrdersSave(Orders orders)
{
	Ticket *temp;
	temp = orders.head;
	FILE *tickets;
	tickets = fopen("tickets.txt", "w");

	while (temp)
	{
		fprintf(tickets, "%s %s %s %d %d %d %d\n", temp->name, temp->surname, temp->passport, temp->flight_number, temp->day, temp->hours, temp->minutes);
		temp = temp->next;
	}

	fclose(tickets);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
