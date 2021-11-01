#include <string>
#include "Date.h"
#include <iostream>
#include <ctime>
#include "constants.h"

#ifndef AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H
#define AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H

class Person
{
    std::string name;
    std::string surname;
    std::string typeOfPerson;
public:
    Person(Date const &dateOfBirth,
           std::string const &name,
           std::string const &lastName);

    std::string getTypeOfPerson();
};


#endif //AIRLINETICKETMANAGEMENTSYSTEM_PERSON_H
