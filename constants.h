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

//const std::vector FLIGHT_NETWORKS = {{{"Paris",     "Warsaw"},   601.00},
//                                     {{"Hong Kong", "London"},   2240.00},
//                                     {{"London",    "New York"}, 1844.20},
//                                     {{"Warsaw",    "Paris"},    641.91},
//                                     {{"New York",  "London"},   1872.02}};


// airport connections
const std::vector<FlightConnection> FLIGHT_CONNECTIONS = {
        FlightConnection{.departureAirport = "Paris", .destinationAirport="Warsaw", .price=601.00, .id=1},
        FlightConnection{.departureAirport = "Hong Kong", .destinationAirport="London", .price=2240.00, .id=2},
        FlightConnection{.departureAirport = "London", .destinationAirport="New York", .price=1844.20, .id=3},
        FlightConnection{.departureAirport = "Warsaw", .destinationAirport="Paris", .price=641.91, .id=4},
        FlightConnection{.departureAirport = "New York", .destinationAirport="London", .price=1872.02, .id=5}};

// flight classes
std::string const REGULAR_CLASS = "REGULAR_CLASS";
std::string const BUSINESS_CLASS = "BUSINESS_CLASS";

// person
std::string const ADULT = "ADULT";
std::string const CHILD = "CHILD";
std::string const TODDLER = "TODDLER";
//std::string

#endif //AIRLINETICKETMANAGEMENTSYSTEM_CONSTANTS_H

