#include <string>
#include "../Person.h"
#include "../constants.h"
#include "../Date.h"
#include <vector>
#include "../constants.h"

#ifndef AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H

class RegularClass
{
protected:
    std::string departureAirport;
    std::string arrivalAirport;
    Date departureDate;
    double price;
    int numOfHandBaggage;
    std::string seat;
public:
    RegularClass(std::string const &departureAirport,
                 std::string const &arrivalAirport,
                 Date const &departureDate,
                 int const &numOfHandBaggage,
                 std::vector<Person> people);

    virtual void addExtraHandBaggage(int const &numOfBaggage);

    virtual void cancelFlight();

    virtual void changeArrivalAirport(std::string const &airport);

    virtual void changeDepartureAirport(std::string const &airport);

    virtual void changeDepartureDate(Date const &date);

    std::string getArrivalAirport();

    virtual void setWifiPlan();

};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
