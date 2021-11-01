#include "Person.h"

Person::Person(Date const &dateOfBirth,
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

}

std::string Person::getTypeOfPerson()
{
    return typeOfPerson;
}


