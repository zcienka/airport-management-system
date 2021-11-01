#include <string>
#include "../Person.h"
#include "RegularClass.h"

#ifndef AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H

class BusinessClass : public RegularClass
{
protected:
    bool isDinnerRequested;
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

    void setSeat(std::string const &seat);

    void addExtraBaggage(int const &numOfBaggage);

    void orderDinner();

    void setDateOfCarParkingTime(Date const &dateOfCarPickup, Date const &dateOfCarDropOff);

    void extendValidityOfTicket(std::string const &validityOfTicket);
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_BUSINESSCLASS_H
