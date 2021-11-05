#ifndef AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H

#include <string>
#include "../Passenger.h"
#include "RegularClass.h"

class BusinessClass : public RegularClass
{
    int numOfBaggage;
    int maxNumOfBaggage;
    Date dateOfCarPickup;
    Date dateOfCarDropOff;
    bool isParkingRequested;
public:
    BusinessClass(Date const &departureDate,
                  int numOfHandBaggage,
                  std::vector<Passenger> const &passengers,
                  FlightConnection const &flightConnection,
                  int numOfBaggage,
                  int maxNumOfHandBaggage,
                  int maxNumOfBaggage);

    void addExtraBaggage();
    // the difference between this method and parent method is that in the parent method you need to pay money and here
    // you don't pay money
    void changeDepartureDate() override;

    void setDateOfCarParkingTime();

    void printTicketInformation() override;
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
