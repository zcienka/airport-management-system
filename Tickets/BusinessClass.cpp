#include <iostream>
#include "BusinessClass.h"

BusinessClass::BusinessClass(Date const &departureDate,
                             int const &numOfBaggage,
                             std::vector<Passenger> const &people,
                             FlightConnection const &flightConnection) : RegularClass(departureDate,
                                                                                      numOfBaggage,
                                                                                      people,
                                                                                      flightConnection) {}

void BusinessClass::addExtraBaggage()
{
    std::cout << "Enter number of extra baggage:";

    std::string numOfBaggage;
    while (std::cin >> numOfBaggage)
    {
        if (std::all_of(numOfBaggage.begin(), numOfBaggage.end(), ::isdigit))
        {
            if (this->numOfBaggage + std::stoi(numOfBaggage) <= 10)
            {
                this->totalPrice += (float) (230 * std::stoi(numOfBaggage));
                this->numOfBaggage += std::stoi(numOfBaggage);
                break;
            }
            else
            {
                std::cout << "Maximum amount of baggage is 10." << std::endl;
            }
        }
        else
        {
            std::cout << "Number is invalid" << std::endl;
        }
        std::cout << "Enter number of extra baggage:";
    }
}

void BusinessClass::addExtraHandBaggage()
{
    std::cout << "Enter number of extra hand baggage:";

    std::string numberOfHandBaggage;
    while (std::cin >> numberOfHandBaggage)
    {
        if (std::all_of(numberOfHandBaggage.begin(), numberOfHandBaggage.end(), ::isdigit))
        {
            this->numOfHandBaggage = std::stoi(numberOfHandBaggage);
            break;
        }
        std::cout << "Number is invalid." << std::endl;
        std::cout << "Enter number of extra hand baggage:";
    }
}

void BusinessClass::changeDepartureDate()
{
    std::cout << "Enter changed departure date:";
    std::string date;

    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            Date departureDate = getDate(date);
            if (isFutureDateValid(departureDate))
            {
                this->departureDate = departureDate;
                break;
            }
            std::cout << "Entered date is incorrect." << std::endl;
            std::cout << "Enter changed departure date:";
        }
    }
}

void BusinessClass::setDateOfCarParkingTime()
{
    std::string dateOfCarPickup;
    std::string dateOfCarDropOff;

    std::cout << "Enter date of car drop-off:";

    while (std::cin >> dateOfCarDropOff)
    {
        if (isDateValid(dateOfCarDropOff))
        {
            Date date = getDate(dateOfCarDropOff);
            if (isFutureDateValid(date))
            {
                this->dateOfCarDropOff = date;
                break;
            }
        }
        std::cout << "Entered date is invalid" << std::endl;
        std::cout << "Enter date of car drop-off:";
    }

    std::cout << "Enter date of car pick-up:";
    while (std::cin >> dateOfCarPickup)
    {
        if (isDateValid(dateOfCarPickup))
        {
            Date date = getDate(dateOfCarPickup);
            if (isFutureDateValid(date) && isPastTheDate(this->dateOfCarPickup, this->dateOfCarDropOff))
            {
                this->dateOfCarPickup = date;
                break;
            }
        }
        std::cout << "Entered date is invalid. "
                     "Date of pickup needs to be an integer and it needs to take place after the drop-off date"
                  << std::endl;
        std::cout << "Enter date of car pick-up:";
    }
}

void BusinessClass::printTicketInformation()
{
    std::cout << "Requested tickets information." << std::endl;
    std::cout << "Total price: " << this->totalPrice << "PLN" << std::endl;
    std::cout << "Departure date: " <<
              this->departureDate.day << "-" <<
              this->departureDate.month << "-" <<
              this->departureDate.year << std::endl;

    std::cout << "Number of hand baggage: " << this->numOfHandBaggage << std::endl;
    std::cout << "Number of baggage: " << this->numOfBaggage << std::endl;
    std::cout << "Validity of tickets: " << this->validityOfTickets << std::endl;
    std::cout << "Date of car pick-up:"
              << this->dateOfCarPickup.day
              << this->dateOfCarPickup.month
              << this->dateOfCarPickup.year << std::endl;
    std::cout << "Date of car pick-up:"
              << this->dateOfCarDropOff.day
              << this->dateOfCarDropOff.month
              << this->dateOfCarDropOff.year << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Passengers:" << std::endl;

    for (auto &passenger: this->passengers)
    {
        std::cout << "Name: " << passenger.getName() << "Last name: " << passenger.getLastName() <<
                  "Seat number: " << passenger.getSeatNumber() <<
                  ". Ticket price: " << passenger.getTicketPrice() << "PLN" << std::endl;
    }
}
