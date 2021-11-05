#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
#include "constants.h"
#include "Tickets/BusinessClass.h"

struct TicketInfo
{
    Date date;
    int numberOfHandBaggage;
    int maxNumberOfHandBaggage;
    std::vector<Passenger> passengers;
    std::string preferredClass;
    int maxNumberOfBaggage;
    int numberOfBaggage;
};

Passenger setPassengerInfo(int personNum)
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

    std::cout << "Enter date of birth of person #" << personNum << " (day-month-year)" << ":";

    Date dateOfBirth;
    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            dateOfBirth = getDate(date);
            if (isPastDateValid(dateOfBirth))
            {
                break;
            }
        }
        std::cout << "Date of birth is invalid" << std::endl;
        std::cout << "Enter date of birth of person #" << personNum << " (day-month-year)" << ":";
    }

    Passenger person = Passenger(dateOfBirth, name, lastName);
    return person;
}

TicketInfo setTicketInfo()
{
    std::string departureAirport, arrivalAirport, departureDate, preferredClass;
    std::string numberOfPassengers;

    std::cout << "Enter your preferred class" << std::endl;
    std::cout << "[a] Regular class" << std::endl;
    std::cout << "[b] Business class" << std::endl;
    std::cout << "Preferred class:";

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
            std::cout << "Preferred class:";
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

    std::vector<Passenger> people;
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
            if (isFutureDateValid(date))
            {
                break;
            }
        }
        std::cout << "Date is invalid." << std::endl;
        std::cout << "Enter departure date (day-month-year):";
    }

    std::string numberOfBaggage;

    int maxNumberOfBaggage, maxNumberOfHandBaggage;
    bool isBaggageRequested = true;
    if (preferredClass == REGULAR_CLASS)
    {
        maxNumberOfHandBaggage = 3 * std::stoi(numberOfPassengers);
        isBaggageRequested = false;
    }
    else
    {
        maxNumberOfHandBaggage = 5 * std::stoi(numberOfPassengers);
        maxNumberOfBaggage = 10 * std::stoi(numberOfPassengers);
    }

    if (isBaggageRequested)
    {
        std::cout << "Enter number of baggage for all passengers:";
        while (std::cin >> numberOfBaggage)
        {
            if (std::all_of(numberOfBaggage.begin(), numberOfBaggage.end(), ::isdigit))
            {
                if (std::stoi(numberOfBaggage) > 0 && std::stoi(numberOfBaggage) <= maxNumberOfBaggage)
                {
                    break;
                }
                else
                {
                    std::cout << "Number of baggage needs to be greater than zero and smaller than "
                              << maxNumberOfBaggage + 1
                              << std::endl;
                }
            }
            else
            {
                std::cout << "Number of baggage is invalid" << std::endl;
            }
            std::cout << "Enter number of baggage for all passengers:";
        }
    }

    std::string numberOfHandBaggage;
    std::cout << "Enter number of hand baggage for all passengers:";
    while (std::cin >> numberOfHandBaggage)
    {
        if (std::all_of(numberOfHandBaggage.begin(), numberOfHandBaggage.end(), ::isdigit))
        {
            if (std::stoi(numberOfHandBaggage) > 0 && std::stoi(numberOfHandBaggage) <= maxNumberOfHandBaggage)
            {
                break;
            }
            else
            {
                std::cout << "Number of hand baggage needs to be greater than zero and smaller than "
                          << maxNumberOfHandBaggage + 1
                          << std::endl;
            }
        }
        else
        {
            std::cout << "Number of hand baggage is invalid" << std::endl;
        }
        std::cout << "Enter number of hand baggage for all passengers:";

    }
    if (!isBaggageRequested)
    {
        TicketInfo ticketInfo{.date=date,
                .numberOfHandBaggage=std::stoi(numberOfHandBaggage),
                .maxNumberOfHandBaggage=maxNumberOfHandBaggage,
                .passengers=people,
                .preferredClass=preferredClass};
        return ticketInfo;
    }
    else
    {
        TicketInfo ticketInfo{.date=date,
                .numberOfHandBaggage=std::stoi(numberOfHandBaggage),
                .maxNumberOfHandBaggage=maxNumberOfHandBaggage,
                .passengers=people,
                .preferredClass=preferredClass,
                .maxNumberOfBaggage=maxNumberOfBaggage,
                .numberOfBaggage=std::stoi(numberOfBaggage)};
        return ticketInfo;
    }
}

void printAvailableConnections()
{
    std::cout << "Available connections:" << std::endl;
    std::cout.precision(2);
    for (auto const &connection: FLIGHT_CONNECTIONS)
    {
        std::cout << "[" << connection.id << "]" <<
                  " Flight from " << connection.departureAirport <<
                  " to: " << connection.arrivalAirport <<
                  ". Price of flight: " << std::fixed << connection.price << " PLN." << std::endl;
    }
}

FlightConnection setFlightConnection()
{
    printAvailableConnections();
    std::string connectionId;
    std::cout << "Choose your flight connection:";

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
        std::cout << "Choose your flight connection:";
    }

    return FLIGHT_CONNECTIONS[std::stoi(connectionId) - 1];
}

void displayMenuBusinessClass()
{
    std::cout << "############################################################" << std::endl;
    std::cout << "[a] Cancel your flight." << std::endl;
    std::cout << "[b] Extend validity of your ticket." << std::endl;
    std::cout << "[c] Change departure date." << std::endl;
    std::cout << "[d] Add extra hand baggage." << std::endl;
    std::cout << "[e] Add extra baggage." << std::endl;
    std::cout << "[f] Change your seat." << std::endl;
    std::cout << "[g] Set your parking time." << std::endl;
    std::cout << "[h] Print ticket information" << std::endl;
    std::cout << "[q] Quit" << std::endl;
    std::cout << "############################################################" << std::endl;
}

void flightOptionsBusinessClass(BusinessClass ticketBusinessClass)
{
    char charCommand;
    bool endProgram = false;
    std::string command;

    displayMenuBusinessClass();
    std::cout << "Choose an option:";

    while (true)
    {
        std::cin >> command;
        if (command.length() == 1)
        {
            strcpy(&charCommand, command.c_str());
            switch (charCommand)
            {
                case 'a':
                {
                    ticketBusinessClass.cancelFlight();
                    break;
                    case 'b':
                    {
                        ticketBusinessClass.extendValidityOfTicket();
                        break;
                    }
                    case 'c':
                    {
                        ticketBusinessClass.changeDepartureDate();
                        break;
                    }
                    case 'd':
                    {
                        ticketBusinessClass.addExtraHandBaggage();
                        break;
                    }
                    case 'e':
                    {
                        ticketBusinessClass.addExtraBaggage();
                        break;
                    }
                    case 'f':
                    {
                        ticketBusinessClass.changeSeat();
                        break;
                    }
                    case 'g':
                    {
                        ticketBusinessClass.setDateOfCarParkingTime();
                        break;
                    }
                    case 'h':
                    {
                        ticketBusinessClass.printTicketInformation();
                        break;
                    }
                    case 'q':
                    {
                        endProgram = true;
                        ticketBusinessClass.printTicketInformation();
                        break;
                    }
                    default:
                        std::cout << "Inserted option is incorrect." << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Inserted option is incorrect." << std::endl;
        }
        std::cin.clear();
        if (endProgram || ticketBusinessClass.flightIsCancelled())
        {
            break;
        }
        displayMenuBusinessClass();
        std::cout << "Choose an option:";
    }
}

void displayMenuRegularClass()
{
    std::cout << "############################################################" << std::endl;
    std::cout << "[a] Cancel your flight." << std::endl;
    std::cout << "[b] Add hand baggage." << std::endl;
    std::cout << "[c] Change departure date." << std::endl;
    std::cout << "[d] Print tickets information" << std::endl;
    std::cout << "[e] Change seat number" << std::endl;
    std::cout << "[q] Quit" << std::endl;
    std::cout << "############################################################" << std::endl;
}

void flightOptionsRegularClass(RegularClass ticketRegularClass)
{
    displayMenuRegularClass();
    std::cout << "Choose an option:";
    char charCommand;
    bool leaveTheMenu = false;
    std::string command;

    while (true)
    {
        std::cin >> command;
        if (command.length() == 1)
        {
            strcpy(&charCommand, command.c_str());
            switch (charCommand)
            {
                case 'a':
                {
                    ticketRegularClass.cancelFlight();
                    break;
                }
                case 'b':
                {
                    ticketRegularClass.addExtraHandBaggage();
                    break;
                }
                case 'c':
                {
                    ticketRegularClass.changeDepartureDate();
                    break;
                }
                case 'd':
                {
                    ticketRegularClass.printTicketInformation();
                    break;
                }
                case 'e':
                {
                    ticketRegularClass.changeSeat();
                }
                case 'q':
                {
                    ticketRegularClass.printTicketInformation();
                    leaveTheMenu = true;
                    break;
                }
                default:
                    std::cout << "Inserted option is incorrect." << std::endl;
            }
        }
        else
        {
            std::cout << "Inserted option is incorrect." << std::endl;
        }
        std::cin.clear();
        if (leaveTheMenu || ticketRegularClass.flightIsCancelled())
        {
            break;
        }
        displayMenuRegularClass();
        std::cout << "Choose an option:";
    }
}

int main()
{
    FlightConnection flightConnection = setFlightConnection();
    TicketInfo ticketInfo = setTicketInfo();
    std::string command;

    if (ticketInfo.preferredClass == BUSINESS_CLASS)
    {
        BusinessClass ticketBusinessClass = BusinessClass(ticketInfo.date,
                                                          ticketInfo.numberOfHandBaggage,
                                                          ticketInfo.passengers,
                                                          flightConnection,
                                                          ticketInfo.numberOfBaggage,
                                                          ticketInfo.maxNumberOfHandBaggage,
                                                          ticketInfo.maxNumberOfBaggage);
        std::cout << "Set your flight details" << std::endl;
        flightOptionsBusinessClass(ticketBusinessClass);
    }
    else
    {
        RegularClass ticketRegularClass = RegularClass(ticketInfo.date,
                                                       ticketInfo.numberOfHandBaggage,
                                                       ticketInfo.passengers,
                                                       flightConnection,
                                                       ticketInfo.maxNumberOfHandBaggage);
        std::cout << "Set your flight details" << std::endl;
        flightOptionsRegularClass(ticketRegularClass);
    }
}
