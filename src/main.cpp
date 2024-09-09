#include <iostream>
#include "../include/FlightManager.hpp"
#include "../include/Exception.hpp"

int main() {
    try {
        FlightManager flightManager;
        flightManager.registerFlight("JetAir", "DEL", "BLR", 500);
        flightManager.registerFlight("Delta", "DEL", "LON", 2000);
        flightManager.registerFlight("IndiGo", "LON", "NYC", 2500);
        flightManager.registerFlight("Delta", "LON", "NYC", 2000);

        flightManager.searchFlight("DEL", "NYC", true);


        // adding these for testing not included in the submitted code
        flightManager.registerFlight("JetAir", "DEL", "BLR", 500);
        
        
        // Test case for not a direct path
        flightManager.searchFlight("DEL", "NYC", true);

        // Test case for no path found
        flightManager.searchFlight("BLR", "NYC", true);

    } catch (const CustomException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}