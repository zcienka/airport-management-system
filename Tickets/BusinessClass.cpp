#include <iostream>
#include "BusinessClass.h"

BusinessClass::BusinessClass(std::string const &departureAirport,
                             std::string const &arrivalAirport,
                             Date const &departureDate,
                             int const &numOfBaggage,
                             std::vector<Person> people) : RegularClass(arrivalAirport,
                                                                        departureAirport,
                                                                        departureDate,
                                                                        numOfBaggage,
                                                                        people)
{

}

void BusinessClass::addExtraBaggage(int const &numOfBaggage)
{
    if (this->numOfBaggage + numOfBaggage <= 10)
    {
        this->price += 230 * numOfBaggage;
        this->numOfBaggage += numOfBaggage;
    }
    else
    {
        std::cout << "Maximum amount of baggage is 10." << std::endl;
    }
}

void BusinessClass::setSeat(std::string const &seat)
{
    this->seat = seat;
    this->price += 10;
}


void BusinessClass::orderDinner()
{
    this->isDinnerRequested = true;
    this->price += 50;
}

void BusinessClass::setDateOfCarParkingTime(Date const &dateOfCarPickup, Date const &dateOfCarDropOff)
{
    this->dateOfCarPickup = dateOfCarPickup;
    this->dateOfCarDropOff = dateOfCarDropOff;
}

void BusinessClass::extendValidityOfTicket(std::string const &validityOfTicket)
{

}

