#ifndef AIRLINETICKETMANAGEMENTSYSTEM_PASSENGER_H
#define AIRLINETICKETMANAGEMENTSYSTEM_PASSENGER_H

#include <string>
#include "Date.cpp"
#include <iostream>
#include <ctime>
#include "constants.h"

class Passenger
{
    std::string name;
    std::string surname;
    std::string typeOfPerson;
    int discountValue; // in percentages
    int id;
    std::string seat;
    float ticketPrice;
public:
    Passenger(Date const &dateOfBirth,
              std::string const &name,
              std::string const &lastName);

    std::string getName();

    std::string getLastName();

    int getDiscountValue() const;

    void setId(int id);

    int getId() const;

    void setTicketPrice(float const &basicPrice);

    float getTicketPrice() const;

    std::string getSeatNumber();

    void setSeatNumber(std::string const &seatNumber);
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_PASSENGER_H
