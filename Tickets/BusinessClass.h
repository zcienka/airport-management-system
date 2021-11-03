#ifndef AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H

#include <string>
#include "../Person.h"
#include "RegularClass.h"

class BusinessClass : public RegularClass
{
    int numOfBaggage;
    Date dateOfCarPickup;
    Date dateOfCarDropOff;
    std::string validityOfTicket;
public:
    BusinessClass(std::string const &departureAirport,
                  std::string const &arrivalAirport,
                  Date const &departureDate,
                  int const &numOfBaggage,
                  std::vector<Person> people);

    void addExtraBaggage();

    void addExtraHandBaggage() override;

    void cancelFlight() override;

    void changeDepartureDate() override;

    void changeSeat() override;

    void extendValidityOfTicket();

    void setDateOfCarParkingTime();
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
