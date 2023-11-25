#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

enum Sections { LAWN, TRIBUNE, VIP, PRESS };

class Ticket {
private:
	char* nameOfEvent = nullptr;
	int price = 50;
	int seat = 0; //column of the position in the stand
	int row = 0;
	Sections section = LAWN;
	int zone = 1;
	string date = ""; //date format DD-MM-YY
	string time = ""; //time format 15:47
	const string ID; //nominal ticket, corresponds with a unique identification string of 10 characters

public:
	Ticket() { //default constructor
		this->nameOfEvent = new char[strlen("Unknown") + 1];
		strcpy(this->nameOfEvent, "Unknown");
		this->price = 50;
		this->seat = 0;
		this->row = 0;
		this->section = LAWN;
		this->time = "";
		this->zone = 100;
		this->date = "";
	}

	Ticket(int price, int seat, int row, int stand, Sections section, int zone, string date, string time, string ID) //ctor with param
		:ID(ID) { //constructor with param
		this->price = price;
		this->seat = seat;
		this->row = row;
		this->section = section;
		this->time = time;
		this->zone = zone;
		this->date = date;
	}

	string getNameOfEvent() {
		return string(this->nameOfEvent);
	}

	int getPrice() {
		return this->price;
	}

	int getSeat() {
		return this->seat;
	}

	int getRow() {
		return this->row;
	}

	string getSection() { 
		if (this->section == LAWN)
			return string("LAWN");
		if (this->section == VIP)
			return string("VIP");
		if (this->section == TRIBUNE)
			return string("TRIBUNE");
		if (this->section == PRESS)
			return string("PRESS");
	}

	int getZone() {
		return this->zone;
	}

	string getDate() { 
		return string(this->date);
	}

	string getTime() { 
		return string(this->time);
	}

	string getID() { 
		return string(this->ID);
	}

	Ticket(const Ticket& tick) : ID(tick.ID) { //copy constructor
		this->nameOfEvent = new char[strlen(tick.nameOfEvent) + 1];
		strcpy(this->nameOfEvent, tick.nameOfEvent);
		this->price = tick.price;
		this->seat = tick.seat;
		this->row = tick.row;
		this->section = tick.section;
		this->time = tick.time;
		this->zone = tick.zone;
		this->date = tick.date;
	}

	void updateTime(string time) {
		if (time.length() == 5)
			this->time = time;
		else
			throw exception("Wrong time format");
	}

	void updateDate(string date) {
		if (time.length() == 10)
			this->date = date;
		else
			throw exception("Wrong date format");
	}

	float priceCalculator(int noOfTickets, string section) {
		if (section == "LAWN")
			return (float)noOfTickets * (float)price;
		if (section == "TRIBUNE")
			return (float)noOfTickets * (float)price * 1.5;
		if (section == "VIP")
			return (float)noOfTickets * (float)price * 3;
		if (section == "PRESS")
			return 0;
	}

	~Ticket() { //destructor
		if (this->nameOfEvent != nullptr)
			delete[] this->nameOfEvent;
	}

	Ticket& operator=(const Ticket& tick) { //overload for = operator 
		if (this != &tick) {
			if (this->nameOfEvent != nullptr)
				delete[] this->nameOfEvent;
			this->nameOfEvent = new char[strlen(tick.nameOfEvent) + 1];
			strcpy(this->nameOfEvent, tick.nameOfEvent);
			this->seat = tick.seat;
			this->row = tick.row;
			this->section = tick.section;
			this->time = tick.time;
			this->zone = tick.zone;
			this->date = tick.date;
		}
		return *this;
	}

	Ticket& operator++() {
		this->price++;
		return *this;
	}

	Ticket operator++(int) {
		Ticket tick = *this;
		++this->price;
		return *this;
	}

	explicit operator float() {
		if (this->section == LAWN)
			float a = (float)this->priceCalculator(1, "LAWN");
		else if (this->section == VIP)
			float a = (float)this->priceCalculator(1, "VIP");
		else if (this->section == TRIBUNE)
			float a = (float)this->priceCalculator(1, "TRIBUNE");
		else if (this->section == PRESS)
			float a = (float)this->priceCalculator(1, "PRESS");
	}

private:

	void setPrice(int price) {
		if (price > 0)
			this->price = price;
		else
			throw exception("Value of price can not be negative or null");
	}

	void setSeat(int seat) {
		if (seat > 0)
			this->seat = seat;
		else
			throw exception("Value of seat can not be negative or null");
	}

	void setRow(int row) {
		if (row > 0)
			this->row = row;
		else
			throw exception("Value of rows can not be negative or null");
	}

	void setSection(string section) {
		if (section == "LAWN")
			this->section = LAWN;
		else if (section == "VIP")
			this->section = VIP;
		else if (section == "TRIBUNE")
			this->section = TRIBUNE;
		else if (section == "PRESS")
			this->section = PRESS;
		else throw exception("Section must be one of LAWN, TRIBUNE, VIP, PRESS.");
	}

	void setZone(int zone) {
		if (zone > 0)
			this->zone = zone;
		else
			throw exception("Wrong value of zone.");
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

	friend istream& operator>>(istream& in, Ticket tick);

};

ostream& operator<<(ostream& out, Ticket& tick) { //cout operator for TICKET class
	out << "The seat is: " << tick.getSeat() << endl;
	out << "The row is: " << tick.getRow() << endl;
	out << "The section is: " << tick.getSection() << endl;
	out << "The zone is: " << tick.getZone() << endl;
	out << "The date is: " << tick.getDate() << endl;
	out << "The time is: " << tick.getTime() << endl;
	out << "The ticket ID is: " << tick.getID() << endl;
	return out;
}

istream& operator>>(istream& in, Ticket tick) { //cin operator for TICKET class
	cout << "The seat is: " << endl;
	int value;
	in >> value;
	tick.setSeat(value);
	cout << "The row is: " << endl;
	in >> value;
	tick.setRow(value);
	cout << "The section is: " << endl;
	string str;
	in >> str;
	tick.setSection(str);
	cout << "The zone is: " << endl;
	in >> value;
	tick.setZone(value);
	cout << "The date is: " << endl;
	in >> str;
	tick.setDate(str);
	cout << "The time is: " << endl;
	in >> str;
	tick.setTime(str);
	return in;
}