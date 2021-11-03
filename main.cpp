#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
#include "constants.h"
#include "Tickets/BusinessClass.h"

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
            if (isPastDateValid(dateOfBirth))
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
            if (isFutureDateValid(date))
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
        std::cout << "[" << connection.id << "]" <<
                  " Flight from " << connection.departureAirport <<
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

void flightOptionsBusinessClass(BusinessClass ticketBusinessClass)
{
    std::cout << "[a] Cancel your flight." << std::endl;
    std::cout << "[b] Extend validity of your ticket." << std::endl;
    std::cout << "[c] Change departure date." << std::endl;
    std::cout << "[d] Add extra hand baggage." << std::endl;
    std::cout << "[e] Add extra baggage." << std::endl;
    std::cout << "[f] Change your seat." << std::endl;
    std::cout << "[g] Set your parking time." << std::endl;
    std::cout << "[h] Change your departure airport." << std::endl;
    std::cout << "[i] Change your arrival airport." << std::endl;
    std::cout << "[q] Quit" << std::endl;

    std::string command;
    char charCommand;
    bool isFlightCancelled = false;
    bool endProgram = false;
    while (std::cin >> command && command != "q")
    {
        if (command.length() == 1)
        {
            strcpy(&charCommand, command.c_str());
            switch (charCommand)
            {
                case 'a':
                {
                    std::string option;
                    std::cout << "Do you want to cancel the flight? [y/n]" << std::endl;
                    while (std::cin >> option)
                    {

                        if (option == "y")
                        {
                            isFlightCancelled = true;
                            ticketBusinessClass.cancelFlight();
                            break;
                        }
                        else if (option != "n")
                        {
                            std::cout << "Chosen option is incorrect" << std::endl;
                            std::cout << "Do you want to cancel the flight? [y/n]" << std::endl;
                        }
                    }
                    break;
                }
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
                case 'q':
                {
                    endProgram = true;
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
        if (endProgram)
        {
            break;
        }
    }
}

void flightOptionsRegularClass(RegularClass ticketRegularClass)
{
    std::cout << "[a] Cancel your flight." << std::endl;
    std::cout << "[b] Add hand baggage." << std::endl;
    std::cout << "[c] Change departure airport" << std::endl;
    std::cout << "[d] Change arrival airport" << std::endl;
    std::cout << "[e] Change departure date." << std::endl;
    std::cout << "[q] Quit" << std::endl;

    std::string command;
    char charCommand;
    while (std::cin >> command && command != "q")
    {
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
                    ticketRegularClass.changeDepartureAirport();
                    break;
                }
                case 'd':
                {
                    ticketRegularClass.changeArrivalAirport();
                    break;
                }
                case 'e':
                {
                    ticketRegularClass.changeDepartureDate();
                    break;
                }
                case 'q':
                {
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
    }
}

int main()
{
    FlightConnection flightConnection = setFlightConnection();
    TicketInfo ticketInfo = setTicketInfo();
    std::string command;
    char charCommand;

    //    TODO: tu trzeba jeszcze dać wartkość biletu bo potem są procenty
    if (ticketInfo.preferredClass == BUSINESS_CLASS)
    {
        BusinessClass ticketBusinessClass = BusinessClass(ticketInfo.departureAirport,
                                                          ticketInfo.arrivalAirport,
                                                          ticketInfo.date,
                                                          ticketInfo.numberOfBaggage,
                                                          ticketInfo.people);
        std::cout << "Set your flight details" << std::endl;
        flightOptionsBusinessClass(ticketBusinessClass);
    }
    else
    {
        RegularClass ticketRegularClass = RegularClass(ticketInfo.date,
                                                       ticketInfo.numberOfBaggage,
                                                       ticketInfo.people);
        flightOptionsRegularClass(ticketRegularClass);
    }
}
