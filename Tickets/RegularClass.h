#include <string>
#include "../Person.h"
#include "../constants.h"
#include <vector>
#include "../constants.h"

#ifndef AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H

class RegularClass
{
protected:
    Date departureDate;
    double price;
    int numOfHandBaggage;
    std::string seat;
    std::vector<Person> people;
    double basicPrice;
public:
    RegularClass(Date const &departureDate,
                 int const &numOfHandBaggage,
                 std::vector<Person> people);

    virtual void addExtraHandBaggage();

    virtual void cancelFlight();

    virtual void changeDepartureDate();

    virtual void changeSeat();
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_REGULARCLASS_H
