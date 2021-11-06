#include <iostream>
#include "BusinessClass.h"

BusinessClass::BusinessClass(Date const &departureDate,
                             int numOfHandBaggage,
                             std::vector<Passenger> const &passengers,
                             FlightConnection const &flightConnection,
                             int numOfBaggage,
                             int maxNumOfHandBaggage,
                             int maxNumOfBaggage) : RegularClass(departureDate,
                                                                 numOfHandBaggage,
                                                                 passengers,
                                                                 flightConnection,
                                                                 maxNumOfHandBaggage)
{
    this->maxNumOfBaggage = maxNumOfBaggage;
    this->numOfBaggage = numOfBaggage;
    this->isParkingRequested = false;
    this->totalPrice = 600;
}

void BusinessClass::addExtraBaggage()
{
    if (this->maxNumOfBaggage - this->numOfBaggage != 0)
    {
        std::cout << "Enter number of extra baggage (max amount of hand baggage: "
                  << this->maxNumOfBaggage - this->numOfBaggage << "):";

        std::string numberOfBaggage;
        while (std::cin >> numberOfBaggage)
        {
            if (std::all_of(numberOfBaggage.begin(), numberOfBaggage.end(), ::isdigit))
            {
                if (this->numOfBaggage + stoi(numberOfBaggage) <= this->maxNumOfBaggage && stoi(numberOfBaggage) > 0)
                {
                    this->numOfBaggage += stoi(numberOfBaggage);
                    break;
                }
                else
                {
                    std::cout << "Maximum amount of hand baggage is " << this->maxNumOfBaggage << std::endl;
                }
            }
            else
            {
                std::cout << "Number is invalid." << std::endl;
            }
            std::cout << "Enter number of extra baggage:";
        }
    }
    else
    {
        std::cout << "Amount of baggage requested is already maxmimum" << std::endl;
    }
}

void BusinessClass::changeDepartureDate()
{
    std::cout << "Enter changed departure date:";
    std::string date;
    Date previousDate = this->departureDate;

    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            Date departureDate = getDate(date);
            if (!areDatesTheSame(previousDate, departureDate))
            {
                if (isFutureDateValid(departureDate))
                {
                    if (this->validityOfTickets == dateToString(this->departureDate))
                    {
                        this->validityOfTickets = dateToString(departureDate);
                    }
                    this->departureDate = departureDate;
                    break;
                }
            }
            else
            {
                std::cout << "Date can't be the same as the previous one. ";
            }
        }
        std::cout << "Entered date is incorrect." << std::endl;
        std::cout << "Enter changed departure date:";
    }
}

void BusinessClass::setDateOfCarParkingTime()
{
    this->isParkingRequested = true;
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
            if (isFutureDateValid(date) && isPastTheDate(this->dateOfCarDropOff, date))
            {
                this->dateOfCarDropOff = date;
                break;
            }
        }
        std::cout << "Entered date is invalid. "
                     "Date of pickup needs to be an integer and it needs to take place after the drop-off date"
                  << std::endl;
        std::cout << "Enter date of car pick-up:";
        std::cin.clear();
    }
}

void BusinessClass::printTicketInformation()
{
    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
    std::cout << "Requested tickets information." << std::endl;
    std::cout << "Total price: " << this->totalPrice << "PLN" << std::endl;
    std::cout << "Flight from: " << this->flightConnection.departureAirport << std::endl;
    std::cout << "Flight to: " << this->flightConnection.arrivalAirport << std::endl;
    std::cout << "Departure date: " <<
              this->departureDate.day << "-" <<
              this->departureDate.month << "-" <<
              this->departureDate.year << std::endl;

    std::cout << "Number of hand baggage: " << this->numOfHandBaggage << std::endl;
    std::cout << "Number of baggage: " << this->numOfBaggage << std::endl;
    std::cout << "Validity of tickets: " << this->validityOfTickets << std::endl;

    if (this->isParkingRequested)
    {
        std::cout << "Date of car drop-off: "
                  << this->dateOfCarDropOff.day << "-"
                  << this->dateOfCarDropOff.month << "-"
                  << this->dateOfCarDropOff.year << std::endl;
        std::cout << "Date of car pick-up: "
                  << this->dateOfCarPickup.day << "-"
                  << this->dateOfCarPickup.month << "-"
                  << this->dateOfCarPickup.year << std::endl;
    }
    std::cout << std::endl << "------------------------------------------------------------" << std::endl;
    std::cout << "Passengers:" << std::endl;

    for (auto &passenger: this->passengers)
    {
        std::cout << "Name: " << passenger.getName() << std::endl;
        std::cout << "Last name: " << passenger.getLastName() << std::endl;
        std::cout << "Seat number: " << passenger.getSeatNumber() << std::endl;
        std::cout << "Ticket price: " << passenger.getTicketPrice() << "PLN" << std::endl;
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}
