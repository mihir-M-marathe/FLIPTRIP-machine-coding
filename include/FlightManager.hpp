#ifndef FLIGHTMANAGER_HPP
#define FLIGHTMANAGER_HPP

#include <string>
#include <map>
#include <vector>
#include "Airline.hpp"

// this can also be used, but we need readability
//using namespace std;

class FlightManager {

private:
    std::map<std::string, Airline> airlines;

public:
    // need to registerr and search specific flights as well
    //  e.g. register flight-> JetAir -> DEL -> BLR -> 500
    void registerFlight(const std::string& airlineName, const std::string& source, const std::string& destination, int price);
    // search flight-> DEL -> NYC -> TRUE
    void searchFlight(const std::string& source, const std::string& destination, bool isMealRequired) const;

};

#endif