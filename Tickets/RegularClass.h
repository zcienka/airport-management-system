#ifndef AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H

#include <string>
#include "../Passenger.h"
#include "../constants.h"
#include <vector>
#include "../constants.h"
#include "../Date.h"

class RegularClass
{
protected:
    Date departureDate;
    int numOfHandBaggage;
    std::vector<Passenger> passengers;
    float basicPrice;
    FlightConnection flightConnection;
    float totalPrice;
    std::string validityOfTickets;
public:
    RegularClass(Date const &departureDate,
                 int const &numOfHandBaggage,
                 std::vector<Passenger> people,
                 FlightConnection const &flightConnection);

    virtual void addExtraHandBaggage();

    void cancelFlight();

    virtual void changeDepartureDate();

    virtual void changeSeat();

    virtual void printTicketInformation();

    void extendValidityOfTicket();
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
