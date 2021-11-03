#ifndef AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H

#include <string>
#include "../Passenger.h"
#include "RegularClass.h"

class BusinessClass : public RegularClass
{
    int numOfBaggage;
    Date dateOfCarPickup;
    Date dateOfCarDropOff;
public:
    BusinessClass(Date const &departureDate,
                  int const &numOfBaggage,
                  std::vector<Passenger> const &people,
                  FlightConnection const &flightConnection);

    void addExtraBaggage();

    void addExtraHandBaggage() override;

    void changeDepartureDate() override;

    void setDateOfCarParkingTime();

    void printTicketInformation() override;
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
