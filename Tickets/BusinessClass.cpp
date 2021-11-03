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
                                                                        people) {}

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
                this->price += 230 * std::stoi(numOfBaggage);
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

void BusinessClass::cancelFlight()
{
    this->price = price * 0.25;
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

void BusinessClass::changeSeat()
{
    std::string seat;
    std::cout << "Enter seat number [A-F][1-15]:";

    while (std::cin >> seat)
    {
        if (seat.length() >= 2)
        {
            if (std::isalpha(seat[0]))
            {
                if (seat[0] >= 'A' && seat[0] <= 'F')
                {
                    if (seat.length() == 3)
                    {

                        if (std::isdigit(seat[1]) && std::isdigit(seat[2]))
                        {
                            if (seat[2] < '2' && seat[1] == '1')
                            {
                                this->seat = seat;
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (std::isdigit(seat[1]))
                        {
                            this->seat = seat;
                            break;
                        }
                    }
                }
            }
        }
        std::cout << "Seat number is invalid." << std::endl;
        std::cout << "Enter seat number [A-F][1-15]:";
    }
}

void BusinessClass::extendValidityOfTicket()
{
    std::cout << "Enter wanted validity of ticket:";
    std::string date;

    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            Date validityOfTicket = getDate(date);
            if (isFutureDateValid(validityOfTicket))
            {
                this->validityOfTicket = date;
                break;
            }
            std::cout << "Entered date is incorrect." << std::endl;
            std::cout << "Enter wanted validity of ticket:";
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
            if (isFutureDateValid(date) && isAfterTheDate(dateOfCarPickup, dateOfCarDropOff))
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
