//flight.hpp
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>

class Flight {

private:

    std::string airline;
    std::string source;
    std::string destination;
    //do we need to keep this double?
    int price;
    // we can add source and dest time here for the bonus question

public:
// need to add meal also - bool isMealOffered - false
    Flight(const std::string& airline, const std::string& source, const std::string& destination, int price);

    //methods here
    std::string getAirline() const;
    std::string getSource() const;
    std::string getDestination() const;
    int getPrice() const; 

};


#endif