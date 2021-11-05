#ifndef AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H

#include <iostream>
#include <utility>
#include <vector>

struct FlightConnection
{
    std::string departureAirport;
    std::string arrivalAirport;
    float price;
    int id;
};

// airport connections
const std::vector<FlightConnection> FLIGHT_CONNECTIONS = {
        FlightConnection{.departureAirport = "Paris", .arrivalAirport="Warsaw", .price=601.00, .id=1},
        FlightConnection{.departureAirport = "Paris", .arrivalAirport="Hong Kong", .price=1622.00, .id=2},
        FlightConnection{.departureAirport = "Paris", .arrivalAirport="London", .price=290.00, .id=3},
        FlightConnection{.departureAirport = "Paris", .arrivalAirport="New York", .price=1374.00, .id=4},

        FlightConnection{.departureAirport = "Hong Kong", .arrivalAirport="London", .price=2240.00, .id=5},
        FlightConnection{.departureAirport = "Hong Kong", .arrivalAirport="Warsaw", .price=1727.00, .id=6},
        FlightConnection{.departureAirport = "Hong Kong", .arrivalAirport="New York", .price=4303.00, .id=7},
        FlightConnection{.departureAirport = "Hong Kong", .arrivalAirport="Paris", .price=1727.00, .id=8},

        FlightConnection{.departureAirport = "London", .arrivalAirport="New York", .price=1844.20, .id=9},
        FlightConnection{.departureAirport = "London", .arrivalAirport="Paris", .price=471.73, .id=10},
        FlightConnection{.departureAirport = "London", .arrivalAirport="Hong Kong", .price=2138.76, .id=11},
        FlightConnection{.departureAirport = "London", .arrivalAirport="Warsaw", .price=550.73, .id=12},

        FlightConnection{.departureAirport = "Warsaw", .arrivalAirport="Paris", .price=641.91, .id=13},
        FlightConnection{.departureAirport = "Warsaw", .arrivalAirport="Hong Kong", .price=2043.75, .id=14},
        FlightConnection{.departureAirport = "Warsaw", .arrivalAirport="London", .price=684.71, .id=15},
        FlightConnection{.departureAirport = "Warsaw", .arrivalAirport="New York", .price=2265.38, .id=16},

        FlightConnection{.departureAirport = "New York", .arrivalAirport="London", .price=1759.91, .id=17},
        FlightConnection{.departureAirport = "New York", .arrivalAirport="Paris", .price=1773.01, .id=18},
        FlightConnection{.departureAirport = "New York", .arrivalAirport="Hong Kong", .price=3311.47, .id=19},
        FlightConnection{.departureAirport = "New York", .arrivalAirport="Warsaw", .price=1719.93, .id=20}};

// flight classes
std::string const REGULAR_CLASS = "REGULAR_CLASS";
std::string const BUSINESS_CLASS = "BUSINESS_CLASS";

// person
std::string const ADULT = "ADULT";
std::string const CHILD = "CHILD";
std::string const TODDLER = "TODDLER";

#endif //AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H

