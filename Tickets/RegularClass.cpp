#include "RegularClass.h"
#include <iostream>

RegularClass::RegularClass(std::string const &departureAirport,
                           std::string const &arrivalAirport,
                           Date const &departureDate,
                           int const &numOfHandBaggage,
                           std::vector<Person> people)
{
    this->departureAirport = departureAirport;
    this->arrivalAirport = arrivalAirport;
    this->departureDate = departureDate;
    this->price = 0;
    this->numOfHandBaggage = numOfHandBaggage;

    for (auto &person: people)
    {
        if (person.getTypeOfPerson() == CHILD)
        {
            this->price -= 100;
        }
        else if (person.getTypeOfPerson() == TODDLER)
        {
            this->price -= 200;
        }
    }
}

void RegularClass::addExtraHandBaggage(int const &numOfHandBaggage)
{
    if (this->numOfHandBaggage + numOfHandBaggage == 1)
    {
        this->numOfHandBaggage += numOfHandBaggage;
    }
    else
    {
        std::cout << "Maximum amount of hand baggage is 1." << std::endl;
    }
}

void RegularClass::cancelFlight()
{
    this->price /= 2;
}

void RegularClass::changeArrivalAirport(std::string const &airport)
{
    this->arrivalAirport = airport;
    this->price += 300;
}

void RegularClass::changeDepartureAirport(std::string const &airport)
{
    this->departureAirport = airport;
    this->price += 300;
}

void RegularClass::changeDepartureDate(Date const &date)
{
    this->departureDate = date;
    this->price += 250;
}

void RegularClass::setWifiPlan()
{
    this->price += 50;
}

std::string RegularClass::getArrivalAirport()
{
    return arrivalAirport;
}
