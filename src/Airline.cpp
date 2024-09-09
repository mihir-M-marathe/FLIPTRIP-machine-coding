#include "../include/Airline.hpp"
#include "../include/Exception.hpp"

// constructor
// Airline::Airline(const std::string& airlineName) : name(airlineName) {}

// Default constructor implementation
Airline::Airline() : name("") {} // Initialize name to an empty string

Airline::Airline(const std::string& airlineName) {
    name = airlineName;
}

void Airline::addFlight(const std::string& source, const std::string& destination, int price) {
    if (price <= 0) {
        throw CustomException("Price Must be positive");
    }
    flights.emplace_back(name, source, destination, price);
}

const std::vector<Flight>& Airline::getFlights() const {
    return flights;
}

std::string Airline::getName() const {
    return name;
}