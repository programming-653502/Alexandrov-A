//---------------------------------------------------------------------------

#ifndef NodesH
#define NodesH
struct Way
{
	char starting_point[15];
	char waypoint1[15];
	char waypoint2[15];
	char endpoint[15];
};

struct Days
{
	int hours;
	int minutes;
	int days[7];
};

struct Flight
{
	unsigned int flight_number;
	char airplane_type[20];
	Way way;
	Days days;
	int seats_number;
	int free_seats[7];
};

struct Ticket
{
	char name[15];
	char surname[15];
	char passport[15];
	int flight_number;
	int day;
	int hours;
	int minutes;
	Ticket *next;
};

struct Orders
{
	Ticket *head;
	Ticket *last;
	int amount;
};
//---------------------------------------------------------------------------
#endif
