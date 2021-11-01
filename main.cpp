#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <cstring>
#include "constants.h"
#include "Tickets/BusinessClass.h"

int numberOfDaysInMonth(int const &month, int const &year)
{
    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

bool isDateValid(std::string date)
{
    std::string day, month, year;
    std::vector<std::string> dateArray;
    std::string reducedDate;
    unsigned int hyphenIndex;

    while (true)
    {
        hyphenIndex = date.find('-');
        if (hyphenIndex != std::string::npos)
        {
            reducedDate = date.substr(0, hyphenIndex);
            date = date.erase(0, reducedDate.length() + 1);
            dateArray.push_back(reducedDate);
            if (date.length() == 0)
                break;
        }
        else
        {
            dateArray.push_back(date);
            break;
        }
    }

    if (dateArray.size() != 3)
        return false;

    day = dateArray[0];
    month = dateArray[1];
    year = dateArray[2];

    if (std::all_of(day.begin(), day.end(), ::isdigit) &&
        std::all_of(month.begin(), month.end(), ::isdigit) &&
        std::all_of(year.begin(), year.end(), ::isdigit))
    {
        const int departureDay = std::stoi(day);
        const int departureMonth = std::stoi(month);
        const int departureYear = std::stoi(year);

        const int daysInMonth = numberOfDaysInMonth(departureMonth, departureYear);
        const int numberOfMonths = 12;

        if (daysInMonth >= departureDay && departureDay >= 1)
        {
            if (numberOfMonths >= departureMonth && departureMonth >= 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool isDepartureDateValid(Date date)
{
    const int departureDay = date.day;
    const int departureMonth = date.month;
    const int departureYear = date.year;

    time_t t = time(nullptr);
    tm *const currentTime = localtime(&t);

    const int currentYear = 1900 + currentTime->tm_year;
    const int currentDay = currentTime->tm_mday;
    const int currentMonth = currentTime->tm_mon + 1;

    if (departureYear > currentYear)
    {
        return true;
    }
    else if (departureYear == currentYear)
    {
        if (departureMonth == currentMonth)
        {
            if (departureDay > currentDay)
            {
                return true;
            }
        }
        else if (departureMonth > currentMonth)
        {
            return true;
        }
    }
    return false;
}

bool isBirthdayDateValid(Date date)
{
    std::time_t t = std::time(nullptr);
    std::tm *const currentTime = std::localtime(&t);

    const int currentYear = 1900 + currentTime->tm_year;
    const int currentDay = currentTime->tm_mday;
    const int currentMonth = currentTime->tm_mon + 1;

    const int birthdayDay = date.day;
    const int birthdayMonth = date.month;
    const int birthdayYear = date.year;

    if (birthdayYear < currentYear)
    {
        return true;
    }
    else if (birthdayYear == currentYear)
    {
        if (birthdayMonth < currentMonth)
        {
            return true;
        }
        else if (birthdayMonth == currentMonth)
        {
            if (birthdayDay < currentDay)
            {
                return true;
            }
        }
    }
    return false;
}

Date getDate(std::string date)
{
    unsigned int hyphenIndex;
    std::string reducedDate;
    std::vector<int> dateArray;

    while (true)
    {
        hyphenIndex = date.find('-');
        if (hyphenIndex != std::string::npos)
        {
            reducedDate = date.substr(0, hyphenIndex);
            date = date.erase(0, reducedDate.length() + 1);
            dateArray.push_back(std::stoi(reducedDate));
            if (date.length() == 0)
                break;
        }
        else
        {
            dateArray.push_back(std::stoi(date));
            break;
        }
    }

    Date dateInfo{.day=dateArray[0], .month=dateArray[1], .year=dateArray[2]};
    return dateInfo;
}

struct TicketInfo
{
    std::string departureAirport;
    std::string arrivalAirport;
    Date date;
    int numberOfBaggage;
    std::vector<Person> people;
//    int numberOfPassengers;
    std::string preferredClass;
};

Person setPassengerInfo(int const &personNum)
{
    std::string date, lastName, name, phoneNumber;

    std::cout << "Enter name of person #" << personNum << ":";
    while (std::cin >> name)
    {
        if (std::all_of(name.begin(), name.end(), ::isalpha))
        {
            break;
        }
        else
        {
            std::cout << "Name is invalid" << std::endl;
            std::cout << "Enter name of person #" << personNum << ":";
        }
    }

    std::cout << "Enter last name of person #" << personNum << ":";
    while (std::cin >> lastName)
    {
        if (std::all_of(lastName.begin(), lastName.end(), ::isalpha))
        {
            break;
        }
        else
        {
            std::cout << "Last name is invalid." << std::endl;
            std::cout << "Enter last name of person #" << personNum << ":";
        }
    }

    std::cout << "Enter date of birth of person #" << personNum << ":";

    Date dateOfBirth;
    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            dateOfBirth = getDate(date);
            if (isBirthdayDateValid(dateOfBirth))
            {
                break;
            }
        }
        std::cout << "Date of birth is invalid" << std::endl;
        std::cout << "Enter date of birth of person #" << personNum << ":";
    }

    Person person = Person(dateOfBirth, name, lastName);
    return person;
}

TicketInfo setTicketInfo()
{
    std::string departureAirport, arrivalAirport, departureDate, preferredClass;
    std::string numberOfPassengers;

    std::cout << "Enter your departure airport:";
    std::cin >> departureAirport;
    std::cout << "Enter your arrival airport:";
    std::cin >> arrivalAirport;

    std::cout << "Enter your preferred class" << std::endl;
    std::cout << "[a] Regular class" << std::endl;
    std::cout << "[b] Business class" << std::endl;

    while (std::cin >> preferredClass)
    {
        if (preferredClass == "a" || preferredClass == "b")
        {
            if (preferredClass == "a")
            {
                preferredClass = REGULAR_CLASS;
            }
            else
            {
                preferredClass = BUSINESS_CLASS;
            }
            break;
        }
        else
        {
            std::cout << "Chosen class is invalid." << std::endl;
            std::cout << "Enter your preferred class" << std::endl;
            std::cout << "[a] Regular class" << std::endl;
            std::cout << "[b] Business class" << std::endl;
        }
    }

    std::cout << "Enter number of passengers:";
    while (std::cin >> numberOfPassengers)
    {
        if (std::all_of(numberOfPassengers.begin(), numberOfPassengers.end(), ::isdigit))
        {
            if (std::stoi(numberOfPassengers) >= 1 && std::stoi(numberOfPassengers) <= 10)
            {
                break;
            }
            else
            {
                std::cout << "Number of passengers needs to be higher than zero and smaller than 11" << std::endl;
            }
        }
        else
        {
            std::cout << "Number of passengers is invalid." << std::endl;
            std::cout << "Enter number of passengers:";
        }
    }

    std::vector<Person> people;
    people.reserve(std::stoi(numberOfPassengers));

    for (int i = 0; i < std::stoi(numberOfPassengers); ++i)
    {
        people.push_back(setPassengerInfo(i + 1));
    }

    std::cout << "Enter departure date (day-month-year):";
    Date date;
    while (std::cin >> departureDate)
    {
        if (isDateValid(departureDate))
        {
            date = getDate(departureDate);
            if (isDepartureDateValid(date))
            {
                break;
            }
        }
        std::cout << "Date is invalid." << std::endl;
        std::cout << "Enter departure date (day-month-year):";
    }

    std::string numberOfBaggage;
    std::cout << "Enter number of baggage:";
    while (std::cin >> numberOfBaggage)
    {
        if (std::all_of(numberOfBaggage.begin(), numberOfBaggage.end(), ::isdigit))
        {
            if (std::stoi(numberOfBaggage) > 0 && std::stoi(numberOfBaggage) < 10)
            {
                break;
            }
            else
            {
                std::cout << "Number of baggage needs to be greater than zero and smaller than 10" << std::endl;
            }
        }
        else
        {
            std::cout << "Number of baggage is invalid" << std::endl;
            std::cout << "Enter number of baggage:";
        }
    }

    TicketInfo ticketInfo{.departureAirport=departureAirport,
            .arrivalAirport=arrivalAirport,
            .date=date,
            .numberOfBaggage=std::stoi(numberOfBaggage),
            .people=people,
            .preferredClass=preferredClass};
    return ticketInfo;
}

void printAvailableConnections()
{
    std::cout << "Choose your flight connection" << std::endl;
    std::cout.precision(2);
    for (auto const &connection: FLIGHT_CONNECTIONS)
    {
        std::cout << "[" << connection.id << "]" << " Flight from " << connection.departureAirport <<
                  " to: " << connection.destinationAirport <<
                  ". Price of flight: " << std::fixed << connection.price << " PLN." << std::endl;
    }
}

FlightConnection setFlightConnection()
{
    printAvailableConnections();

    std::string connectionId;

    while (std::cin >> connectionId)
    {
        if (std::all_of(connectionId.begin(), connectionId.end(), ::isdigit))
        {
            if (std::stoi(connectionId) >= 1 && std::stoi(connectionId) <= FLIGHT_CONNECTIONS.size())
            {
                break;
            }
        }
        std::cout << "Chosen connection is invalid." << std::endl;
        printAvailableConnections();
    }

    return FLIGHT_CONNECTIONS[std::stoi(connectionId) - 1];
}

void flightOptionsMenu()
{
    std::cout << "[a] Cancel your flight." << std::endl;
    std::cout << "[b] Change ";
    std::cout << "[c] Change departure date." << std::endl;
    std::cout << "[d] Add extra hand baggage." << std::endl;
}

int main()
{
    FlightConnection flightConnection = setFlightConnection();
    TicketInfo ticketInfo = setTicketInfo();
    std::string command;
    char ticketCommand;

    if (ticketInfo.preferredClass == BUSINESS_CLASS)
    {
        BusinessClass ticketBusinessClass = BusinessClass(ticketInfo.departureAirport,
                                                          ticketInfo.arrivalAirport,
                                                          ticketInfo.date,
                                                          ticketInfo.numberOfBaggage,
                                                          ticketInfo.people);
        std::cout << "Set your flight details" << std::endl;
        flightOptionsMenu();
        while (std::cin >> command && command != "q")
        {
            if (command.length() == 1)
            {
                strcpy(&ticketCommand, command.c_str());
                switch (ticketCommand)
                {
                    case 'a':
                        std::cout << "xd";
                        break;
                    case 'b':
                        std::cout << "abc";
                    default:
                        break;
                }
            }
            else
            {
                std::cout << "Inserted option is incorrect." << std::endl;
            }
        }
    }
    else
    {
        RegularClass ticketRegularClass = RegularClass(ticketInfo.departureAirport,
                                                       ticketInfo.arrivalAirport,
                                                       ticketInfo.date,
                                                       ticketInfo.numberOfBaggage,
                                                       ticketInfo.people);
    }


}