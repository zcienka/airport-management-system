#include "RegularClass.h"
#include <iostream>
#include <cstring>

RegularClass::RegularClass(Date const &departureDate,
                           int const &numOfHandBaggage,
                           std::vector<Person> people)
{
    this->departureDate = departureDate;
    this->price == == == == == == == == == == == == == == price;
    this->numOfHandBaggage = numOfHandBaggage;
    this->people = people;

    int id = 1;
    for (auto &person: people)
    {
        person.setId(id);
        ++id;
        this->price -= price * ((float) person.getDiscountValue() / 100);
    }
}

void RegularClass::addExtraHandBaggage()
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
    std::cout << "[a] Cancel all tickets." << std::endl;
    std::cout << "[b] Cancel some tickets." << std::endl;

    std::string option;
    while (std::cin >> option)
    {

        if (option == "a")
        {
            this->price /= 2;
            break;
        }
        else if (option == "b")
        {
            std::cout << "Choose tickets to cancel" << std::endl;
            for (auto &person: people)
            {
                std::cout << "[" << person.getId() << "] " <<
                          person.getName() << " " <<
                          person.getLastName() <<
                          "ticket from " << departureAirport <<
                          "to " << arrivalAirport <<
                          "price: " << basicPrice + basicPrice * ((float) person.getDiscountValue() / 100)
                          << "PLN" << std::endl;
            }
        }
        std::cout << "Chosen option is invalid." << std::endl;
        std::cout << "[a] Cancel all tickets." << std::endl;
        std::cout << "[b] Cancel some tickets." << std::endl;
    }
}

void RegularClass::changeDepartureDate()
{
    std::cout << "Pass changed departure date" << std::endl;

    std::string date;
    Date changedDate;

    while (std::cin >> date)
    {

    }

    this->departureDate = changedDate;
    this->price += 250;
}
