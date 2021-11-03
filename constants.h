#ifndef AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H
#define AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H

#include <iostream>
#include <utility>
#include <vector>

struct FlightConnection
{
    std::string departureAirport;
    std::string destinationAirport;
    float price;
    int id;
};

// airport connections
const std::vector<FlightConnection> FLIGHT_CONNECTIONS = {
        FlightConnection{.departureAirport = "Paris", .destinationAirport="Warsaw", .price=601.00, .id=1},
        FlightConnection{.departureAirport = "Paris", .destinationAirport="Hong Kong", .price=1622.00, .id=2},
        FlightConnection{.departureAirport = "Paris", .destinationAirport="London", .price=290.00, .id=3},
        FlightConnection{.departureAirport = "Paris", .destinationAirport="New York", .price=1374.00, .id=4},

        FlightConnection{.departureAirport = "Hong Kong", .destinationAirport="London", .price=2240.00, .id=5},
        FlightConnection{.departureAirport = "Hong Kong", .destinationAirport="Warsaw", .price=1727.00, .id=6},
        FlightConnection{.departureAirport = "Hong Kong", .destinationAirport="New York", .price=4303.00, .id=7},
        FlightConnection{.departureAirport = "Hong Kong", .destinationAirport="Paris", .price=1727.00, .id=8},

        FlightConnection{.departureAirport = "London", .destinationAirport="New York", .price=1844.20, .id=9},
        FlightConnection{.departureAirport = "London", .destinationAirport="Paris", .price=471.73, .id=10},
        FlightConnection{.departureAirport = "London", .destinationAirport="Hong Kong", .price=2138.76, .id=11},
        FlightConnection{.departureAirport = "London", .destinationAirport="Warsaw", .price=550.73, .id=12},

        FlightConnection{.departureAirport = "Warsaw", .destinationAirport="Paris", .price=641.91, .id=13},
        FlightConnection{.departureAirport = "Warsaw", .destinationAirport="Hong Kong", .price=2043.75, .id=14},
        FlightConnection{.departureAirport = "Warsaw", .destinationAirport="London", .price=684.71, .id=15},
        FlightConnection{.departureAirport = "Warsaw", .destinationAirport="New York", .price=2265.38, .id=16},

        FlightConnection{.departureAirport = "New York", .destinationAirport="London", .price=1759.91, .id=17},
        FlightConnection{.departureAirport = "New York", .destinationAirport="Paris", .price=1773.01, .id=18},
        FlightConnection{.departureAirport = "New York", .destinationAirport="Hong Kong", .price=3311.47, .id=19},
        FlightConnection{.departureAirport = "New York", .destinationAirport="Warsaw", .price=1719.93, .id=20}};

// flight classes
std::string const REGULAR_CLASS = "REGULAR_CLASS";
std::string const BUSINESS_CLASS = "BUSINESS_CLASS";

// person
std::string const ADULT = "ADULT";
std::string const CHILD = "CHILD";
std::string const TODDLER = "TODDLER";
//std::string

#endif //AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H

