#ifndef AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H

#include <string>
#include "../Passenger.h"
#include "../constants.h"
#include <vector>
#include "../Date.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <chrono>

class RegularClass
{
protected:
    Date departureDate;
    int numOfHandBaggage;
    std::vector<Passenger> passengers;
    float basicPrice;
    FlightConnection flightConnection;
    float totalPrice;
    bool isFlightCancelled;
    int maxNumberOfHandBaggage;
    std::string validityOfTickets;
    // validity of tickets is stored in string because of project requirements
    // (there needs to be one int and one string)
public:
    RegularClass(Date const &departureDate,
                 int numOfHandBaggage,
                 std::vector<Passenger> passengers,
                 FlightConnection const &flightConnection,
                 int maxNumOfHandBaggage);

    void addExtraHandBaggage();

    void cancelFlight();

    virtual void changeDepartureDate();

    void changeSeat();

    virtual void printTicketInformation();

    void extendValidityOfTicket();

    bool flightIsCancelled() const;
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
