#include "Passenger.h"

Passenger::Passenger(Date const &dateOfBirth,
                     std::string const &name,
                     std::string const &lastName)
{
    this->name = name;
    this->surname = lastName;

    time_t t = time(nullptr);
    tm *const currentTime = localtime(&t);

    const int currentYear = 1900 + currentTime->tm_year;
    const int currentMonth = currentTime->tm_mon + 1;
    const int currentDay = currentTime->tm_mday;

    const int ageInYears = currentYear - dateOfBirth.year;
    const int ageInMonths = currentMonth - dateOfBirth.month;
    const int ageInDays = currentDay - dateOfBirth.day;

    if (currentYear - dateOfBirth.year > 18)
    {
        this->typeOfPerson = ADULT;
    }
    else if (currentYear - dateOfBirth.year == 18)
    {
        if (currentMonth - dateOfBirth.month > 0)
        {
            this->typeOfPerson = ADULT;
        }
        else if (currentMonth - dateOfBirth.month == 0 && currentDay - dateOfBirth.day >= 0)
        {
            this->typeOfPerson = ADULT;
        }
        else
        {
            this->typeOfPerson = CHILD;
        }
    }
    else if (currentYear - dateOfBirth.year < 18 && currentYear - dateOfBirth.year > 11)
    {
        this->typeOfPerson = CHILD;
    }
    else if (currentYear - dateOfBirth.year == 11)
    {
        if (currentMonth - dateOfBirth.month > 0)
        {
            this->typeOfPerson = CHILD;
        }
        else if (currentMonth - dateOfBirth.month == 0 && currentDay - dateOfBirth.day >= 0)
        {
            this->typeOfPerson = CHILD;
        }
        else
        {
            this->typeOfPerson = TODDLER;
        }
    }
    else if (currentYear - dateOfBirth.year < 11)
    {
        this->typeOfPerson = TODDLER;
    }

    if (typeOfPerson == CHILD)
    {
        this->discountValue = 40;
    }
    else if (typeOfPerson == TODDLER)
    {
        this->discountValue = 100;
    }
    else
    {
        this->discountValue = 0;
    }
}

std::string Passenger::getTypeOfPerson()
{
    return typeOfPerson;
}

std::string Passenger::getName()
{
    return name;
}

std::string Passenger::getLastName()
{
    return surname;
}

int Passenger::getDiscountValue() const
{
    return this->discountValue;
}

void Passenger::setId(int const &id)
{
    this->id = id;
}

int Passenger::getId() const
{
    return this->id;
}

void Passenger::setTicketPrice(float const &basicPrice)
{
    this->ticketPrice = basicPrice - basicPrice * ((float) this->discountValue / 100);
}

float Passenger::getTicketPrice() const
{
    return ticketPrice;
}

std::string Passenger::getSeatNumber()
{
    return this->seat;
}

void Passenger::setSeatNumber(std::string const &seatNumber)
{
    this->seat = seatNumber;
}
