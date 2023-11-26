#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

class ArenaEvent {
	//this class is for the user to select an event on Arena Nationala, either it beign a football match or Saga festival.
	//The ticket class has all the details if the user wants to go to a football match.
protected:
	const int id = 0;
	string date = ""; //date format DD-MM-YY
	string time = ""; //time format 22:43
	char* name = nullptr;
	static int AVAILABLE_TICKETS;
	static int SOLD_TICKETS;

public:

	ArenaEvent() : id(0) { //default constructor
		this->name = new char[strlen("Football Match") + 1];
		strcpy(this->name, "Football Match");
	}

	ArenaEvent(const int id, const char* name, string date, string time) : id(id) { //constructor with parameters
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->date = date;
		this->time = time;
	}

	int getId() {
		return this->id;
	}

	string getName() { 
		return string(this->name);
	}

	string getDate() { 
		return string(this->date);
	}

	string getTime() { 
		return string(this->time);
	}

	int getAvailableTickets() {
		return AVAILABLE_TICKETS;
	}

	int getSoldTickets() {
		return SOLD_TICKETS;
	}

	~ArenaEvent() { //destructor
		if (this->name != nullptr)
			delete[] this->name;
	}

	ArenaEvent(const ArenaEvent& ev) : id(ev.id) { //copy constructor
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(ev.name) + 1];
		strcpy(this->name, ev.name);
		this->date = ev.date;
		this->time = ev.date;
		this->AVAILABLE_TICKETS = ev.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = ev.SOLD_TICKETS;
	}

	ArenaEvent& operator=(const ArenaEvent& ev) { //overload for = operator
		if (this != &ev) {
			if (this->name != nullptr)
				delete[] this->name;
			this->name = new char[strlen(ev.name) + 1];
			strcpy(this->name, ev.name);
		}
		this->date = ev.date;
		this->time = ev.date;
		this->AVAILABLE_TICKETS = ev.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = ev.SOLD_TICKETS;
	}

	void buyTicket(int noTickets) {
		AVAILABLE_TICKETS -= noTickets;
		SOLD_TICKETS += noTickets;
		cout << noTickets << " ticket(s) bought";
	}

	

	bool operator!=(ArenaEvent ev) {
		if (this->date != ev.date)
			return true;
		else return false;
	}

private:

	static void markUnavailableSeats(int value) {
		AVAILABLE_TICKETS -= value;
	}

	void setName(const char* name) { //setter for name
		//validating the input
		if (strlen(name) > 99)
			throw exception("Name over 100 characters");
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setDate(string date) {
		if (date.length() != 8)
			throw exception("Wrong date format. Date format must be DD-MM-YY");
		this->date = date;
		//to be added more checks
	}

	void setTime(string time) {
		if (time.length() != 5)
			throw exception("Wrong time format. Date format must be similar to 17:30");
		this->time = time;

		//to be added more checks
	}


	friend istream& operator>>(istream& in, ArenaEvent ev);
};

ostream& operator<<(ostream& out, ArenaEvent& ev) { //cout operator for ArenaEvent class
	out << "The name is: " << ev.getName() << endl;
	out << "The date is: " << ev.getDate() << endl;
	out << "The time is: " << ev.getTime() << endl;
	out << "No. of available tickets: " << ev.getAvailableTickets() << endl;
	out << "No. of sold tickets:" << ev.getSoldTickets() << endl;
	return out;
}

istream& operator>>(istream& in, ArenaEvent ev) {  //cin operator for ArenaEvent class
	cout << "The date is: " << endl;
	string str;
	in >> str;
	ev.setDate(str);
	cout << "The time is: " << endl;
	in >> str;
	ev.setTime(str);
	cout << "The name is: " << endl;
	in >> str;
	ev.setName(str.c_str());
	return in;
}

int ArenaEvent::AVAILABLE_TICKETS = 300;
int ArenaEvent::SOLD_TICKETS = 0;