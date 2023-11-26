#pragma once
#include <iostream>
#include <cstring>

class StadiumDetails {
private:
    char* name;
    int noGates;
    int noToilets;
    int noSeats;

public:
    // Default Constructor
    StadiumDetails() : name(nullptr), noGates(0), noToilets(0), noSeats(0) {}

    // Constructor with Parameters
    StadiumDetails(const char* newName, int newNoGates, int newNoToilets, int newNoSeats)
        : noGates(newNoGates), noToilets(newNoToilets), noSeats(newNoSeats) {
        this->name = new char[strlen(newName) + 1];
        strcpy(this->name, newName);
    }

    // Copy Constructor
    StadiumDetails(const StadiumDetails& other) : noGates(other.noGates), noToilets(other.noToilets), noSeats(other.noSeats) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    // operator=
    StadiumDetails& operator=(const StadiumDetails& other) {
        if (this != &other) {
            delete[] this->name;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->noGates = other.noGates;
            this->noToilets = other.noToilets;
            this->noSeats = other.noSeats;
        }
        return *this;
    }

    // Destructor
    ~StadiumDetails() {
        delete[] this->name;
    }

    // Getters
    const char* getName()  { return this->name; }
    int getNoGates()  { return this->noGates; }
    int getNoToilets()  { return this->noToilets; }
    int getNoSeats()  { return this->noSeats; }

    // Setters
    void setName(const char* newName) {
        delete[] this->name;
        this->name = new char[strlen(newName) + 1];
        strcpy(this->name, newName);
    }

    void setNoGates(int newNoGates) { this->noGates = newNoGates; }
    void setNoToilets(int newNoToilets) { this->noToilets = newNoToilets; }
    void setNoSeats(int newNoSeats) { this->noSeats = newNoSeats; }

    // Operator[]
    char operator[](int index) const {
        if (index >= 0 && index < static_cast<int>(strlen(this->name))) {
            return this->name[index];
        }
        else {
            std::cerr << "Index out of bounds.\n";
            return '\0';
        }
    }
};


