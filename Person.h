#include <string>
#include "Date.cpp"
#include <iostream>
#include <ctime>
#include "constants.h"

#ifndef AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H
#define AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H

class Person
{
    std::string name;
    std::string surname;
    std::string typeOfPerson;
    int discountValue; // in percentages
    int id;
public:
    Person(Date const &dateOfBirth,
           std::string const &name,
           std::string const &lastName);

    std::string getTypeOfPerson();

    std::string getName();

    std::string getLastName();

    void setTicketPrice(int const &ticketPrice);

    int getDiscountValue() const;

    void setId(int const &id);

    int getId() const;
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H
