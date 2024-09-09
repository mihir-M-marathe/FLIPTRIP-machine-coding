#ifndef AIRLINE_HPP
#define AIRLINE_HPP

#include <string>
#include <vector>
#include "Flight.hpp"

class Airline {

private:
    std::string name;
    std::vector<Flight> flights;

public:

    Airline();
    Airline(const std::string& name);

    void addFlight(const std::string& source, const std::string& destination, int price);
    const std::vector<Flight>& getFlights() const;
    std::string getName() const;

};


#endif