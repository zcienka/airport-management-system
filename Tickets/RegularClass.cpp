#include "RegularClass.h"

std::vector<std::string> generateRandomSeatsWithoutDuplicates(unsigned int numberOfSeats)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<std::string> characters = {"A", "B", "C", "D", "E", "F"};

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
    std::shuffle(characters.begin(), characters.end(), std::default_random_engine(seed));
    std::vector<std::string> randomSeats;

    // number of seats will never be more than 15 because there won't be more than 10 passengers at a time
    for (int i = 0; i < numberOfSeats; ++i)
    {
        randomSeats.push_back(characters[i % characters.size()] + std::to_string(numbers[i]));
    }
    return randomSeats;
}

RegularClass::RegularClass(Date const &departureDate,
                           int numOfHandBaggage,
                           std::vector<Passenger> passengers,
                           FlightConnection const &flightConnection,
                           int maxNumOfHandBaggage)
{
    this->departureDate = departureDate;
    this->numOfHandBaggage = numOfHandBaggage;
    this->basicPrice = flightConnection.price;
    this->totalPrice = 0;
    this->validityOfTickets = dateToString(departureDate);
    this->flightConnection = flightConnection;
    this->isFlightCancelled = false;
    this->maxNumberOfHandBaggage = maxNumOfHandBaggage;

    std::vector<std::string> seats = generateRandomSeatsWithoutDuplicates(passengers.size());
    int id = 1;
    for (auto &passenger: passengers)
    {
        passenger.setId(id);
        passenger.setSeatNumber(seats[id - 1]);
        ++id;
        passenger.setTicketPrice(this->basicPrice - this->basicPrice * ((float) passenger.getDiscountValue() / 100));
        this->totalPrice += passenger.getTicketPrice();
    }
    this->passengers = passengers;
}

void RegularClass::addExtraHandBaggage()
{
    if (this->maxNumberOfHandBaggage - this->numOfHandBaggage != 0)
    {
        std::cout << "Enter number of extra hand baggage (max amount of hand baggage " <<
                  this->maxNumberOfHandBaggage - this->numOfHandBaggage << "):";

        std::string numberOfHandBaggage;
        while (std::cin >> numberOfHandBaggage)
        {
            if (std::all_of(numberOfHandBaggage.begin(), numberOfHandBaggage.end(), ::isdigit))
            {
                if ((this->numOfHandBaggage + stoi(numberOfHandBaggage)) <= this->maxNumberOfHandBaggage &&
                    stoi(numberOfHandBaggage) > 0)
                {
                    this->numOfHandBaggage += stoi(numberOfHandBaggage);
                    break;
                }
                else
                {
                    std::cout << "Maximum amount of hand baggage is " << this->maxNumberOfHandBaggage << std::endl;
                }
            }
            else
            {
                std::cout << "Number is invalid." << std::endl;
            }
            std::cout << "Enter number of extra hand baggage:";
        }
    }
    else
    {
        std::cout << "Maximum amount of hand baggage requested is already maximum." << std::endl;
    }
}

void RegularClass::cancelFlight()
{
    std::cout << "[a] Cancel all tickets." << std::endl;
    if (this->passengers.size() != 1)
    {
        std::cout << "[b] Cancel one ticket." << std::endl;
    }

    std::string option;

    bool isFlightCancelled = false;
    std::cout << "Choose your option:";
    while (std::cin >> option)
    {
        if (option == "a")
        {
            this->totalPrice /= 2;
            this->passengers.clear();
            std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "BILL:" << std::endl;
            std::cout << "Total price: " << std::endl;
            std::cout << "Flight cancellation: " << this->totalPrice << "PLN" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            break;
        }
        else if (option == "b")
        {
            std::cout << "Choose tickets to cancel" << std::endl;
            for (auto &passenger: passengers)
            {
                std::cout << "************************************************************" << std::endl;
                std::cout << "[" << passenger.getId() << "] " <<
                          "Name: " << passenger.getName() << " " <<
                          "Last name: " << passenger.getLastName() << std::endl;
                std::cout << "Ticket from: " << this->flightConnection.departureAirport <<
                          " to: " << this->flightConnection.arrivalAirport << std::endl;
                std::cout << "Price: " << passenger.getTicketPrice() << "PLN" << std::endl;
                std::cout << "************************************************************" << std::endl;
            }
            std::cout << "Choose an id to cancel:";
            std::string idToCancel;

            while (std::cin >> idToCancel)
            {
                if (std::all_of(idToCancel.begin(), idToCancel.end(), ::isdigit))
                {
                    if (stoi(idToCancel) >= 1 && stoi(idToCancel) <= this->passengers.size())
                    {
                        this->passengers.erase(remove_if(this->passengers.begin(), this->passengers.end(),
                                                         [&idToCancel](Passenger const &passenger)
                                                         {
                                                             return passenger.getId() == stoi(idToCancel);
                                                         }));
                        isFlightCancelled = true;
                        break;
                    }
                }
                std::cout << "Chosen id is invalid" << std::endl;
                std::cout << "Choose an id to cancel:";
            }
        }
        if (isFlightCancelled)
        {
            break;
        }
        std::cout << "Chosen option is invalid." << std::endl;
        std::cout << "[a] Cancel all tickets." << std::endl;
        if (this->passengers.size() != 1)
        {
            std::cout << "[b] Cancel one ticket." << std::endl;
        }
        std::cout << "Choose your option:";
    }
    if (this->passengers.empty())
    {
        this->isFlightCancelled = true;
    }
}

void RegularClass::changeDepartureDate()
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
                    this->totalPrice += 250;
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

void RegularClass::changeSeat()
{
    std::cout << "Choose seat to change" << std::endl;
    for (auto &passenger: passengers)
    {
        std::cout << "[" << passenger.getId() << "] " <<
                  "Name: " << passenger.getName() << ", last name: " << passenger.getLastName() <<
                  ", seat number: " << passenger.getSeatNumber() << std::endl;
    }

    std::string passengerId;
    std::cout << "Choose passenger id:";
    while (std::cin >> passengerId)
    {
        if (passengerId.length() == 1)
        {
            if (std::all_of(passengerId.begin(), passengerId.end(), ::isdigit))
            {
                if (passengerId >= "1" && passengerId <= std::to_string(passengers.size()))
                {
                    break;
                }
            }
        }
        std::cout << "Passenger id is incorrect" << std::endl;
        std::cout << "Choose passenger id:";
    }

    auto passengerIndex = std::find_if(this->passengers.begin(), this->passengers.end(),
                                       [&passengerId](Passenger const &passenger)
                                       {
                                           return passenger.getId() == std::stoi(passengerId);
                                       }) - this->passengers.begin();

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
                    bool isSeatTaken = std::find_if(this->passengers.begin(), this->passengers.end(),
                                                    [&seat](Passenger passenger)
                                                    {
                                                        return passenger.getSeatNumber() == seat;
                                                    }) == this->passengers.end();
                    if (isSeatTaken)
                    {
                        if (seat.length() == 3)
                        {
                            if (std::isdigit(seat[1]) && std::isdigit(seat[2]))
                            {
                                if (seat[2] <= '5' && seat[1] == '1')
                                {
                                    {
                                        this->passengers[passengerIndex].setSeatNumber(seat);
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (std::isdigit(seat[1]))
                            {
                                this->passengers[passengerIndex].setSeatNumber(seat);
                                break;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "The seat is already taken. ";
                    }
                }
            }
        }
        std::cout << "Seat number is invalid." << std::endl;
        std::cout << "Enter seat number [A-F][1-15]:";
    }
}

void RegularClass::printTicketInformation()
{

    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
    std::cout << "Requested tickets information." << std::endl;
    std::cout << "Total price: " << this->totalPrice << "PLN" << std::endl;
    std::cout << "Flight from: " << this->flightConnection.departureAirport << std::endl;
    std::cout << "Flight to: " << this->flightConnection.arrivalAirport << std::endl;
    std::cout << "Departure date: " <<
              this->departureDate.day << "-" <<
              this->departureDate.month << "-"
              << this->departureDate.year << std::endl;

    std::cout << "Number of hand baggage: " << this->numOfHandBaggage << std::endl;
    std::cout << "Validity of tickets: " << this->validityOfTickets << std::endl << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl << std::endl;

    std::cout << "Passengers:" << std::endl;

    for (auto &passenger: this->passengers)
    {
        std::cout << "Name: " << passenger.getName() << std::endl;
        std::cout << "Last name: " << passenger.getLastName() << std::endl;
        std::cout << "Seat number: " << passenger.getSeatNumber() << std::endl;
        std::cout << "Ticket price: " << passenger.getTicketPrice() << "PLN" << std::endl;
    }
    std::cout << std::endl << "------------------------------------------------------------" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void RegularClass::extendValidityOfTicket()
{
    std::cout << "Enter wanted validity of ticket:";
    std::string date;
    std::string previousValidity = this->validityOfTickets;
    while (std::cin >> date)
    {
        if (isDateValid(date))
        {
            Date validityOfTicket = getDate(date);
            if (!areDatesTheSame(validityOfTicket, getDate(previousValidity)))
            {
                if (isFutureDateValid(validityOfTicket))
                {
                    this->validityOfTickets = date;
                    break;
                }
                else
                {
                    std::cout << "Entered date is incorrect." << std::endl;
                }
            }
            else
            {
                std::cout << "Entered date is the same as the previous date" << std::endl;
            }
        }
        else
        {
            std::cout << "Entered date is incorrect." << std::endl;
        }
        std::cout << "Enter wanted validity of ticket:";
    }

}

// checks if flight is cancelled for all passengers
bool RegularClass::flightIsCancelled() const
{
    return this->isFlightCancelled;
}
