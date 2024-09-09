#include "../include/Flight.hpp"

// constructor for flight class

Flight::Flight(const std::string& airlineName, const std::string& flightSource, const std::string& flightDestination, int flightPrice) {
    airline = airlineName;
    source = flightSource;
    destination = flightDestination;
    price = flightPrice;
}

std::string Flight::getAirline() const{
    return airline;
}

std::string Flight::getSource() const{
    return source;
}

std::string Flight::getDestination() const{
    return destination;
}

int Flight::getPrice() const{
    return price;
}