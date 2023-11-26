#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

class ArenaEvent {
protected:
	const int id = 0;
	string date = ""; //date format DD-MM-YY
	string time = ""; //time format 11:23
	char* name = nullptr;
	static int AVAILABLE_TICKETS;
	static int SOLD_TICKETS;

public:

	ArenaEvent() : id(0) { //default constructor
		this->name = new char[strlen("National Arena") + 1];
		strcpy(this->name, "National Arena");
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

	ArenaEvent(const ArenaEvent& m) : id(m.id) { //copy constructor
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(m.name) + 1];
		strcpy(this->name, m.name);
		this->date = m.date;
		this->time = m.date;
		this->AVAILABLE_TICKETS = m.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = m.SOLD_TICKETS;
	}

	ArenaEvent& operator=(const ArenaEvent& m) { //operator=
		if (this != &m) {
			if (this->name != nullptr)
				delete[] this->name;
			this->name = new char[strlen(m.name) + 1];
			strcpy(this->name, m.name);
		}
		this->date = m.date;
		this->time = m.date;
		this->AVAILABLE_TICKETS = m.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = m.SOLD_TICKETS;
	}

	void buyTicket(int noTickets) {
		AVAILABLE_TICKETS -= noTickets;
		SOLD_TICKETS += noTickets;
		cout << noTickets << " ticket(s) bought";
	}

	

	bool operator!=(ArenaEvent s) {
		if (this->date != s.date)
			return true;
		else return false;
	}

private:

	static void UnavailableSeats(int value) {
		AVAILABLE_TICKETS -= value;
	}

	void setName(const char* name) { //setter for name
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
		
	}

	void setTime(string time) {
		if (time.length() != 5)
			throw exception("Wrong time format. Date format must be similar to 15:47");
		this->time = time;

		
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
