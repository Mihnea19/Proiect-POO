#include <iostream>
#include "Ticket.h"
#include "ArenaEvent.h"
#include "StadiumDetails.h"
using namespace std;



int main()
{
	int option;
	
	do {
		Ticket ticket1;
		cout << "Please choose what do you want to do: ";
		cout << endl << "1. Get stadium details:";
		cout << endl << "2. Select event on the arena";
		cout << endl << "3. Buy a ticket";
		cout << endl << "4. Exit\n";
		cin >> option;




		switch (option) {
		case 1:
			cout << "Work in progress\n";
			break;
		case 2:
			cout << "Work in progress\n";
			break;
		case 3:
			cout << "Work in progress\n";
			break;
		case 4:
			cout << "Quitting...\n";
			break;
		default:
			cout << "Choose a different choice between 1-4\n";
		}




	} while (option!=4);

	return 0;
}