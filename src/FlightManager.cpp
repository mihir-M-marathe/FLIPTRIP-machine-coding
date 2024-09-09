#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
#include <chrono>
#include "../include/FlightManager.hpp"
#include "../include/Exception.hpp"
#include <limits>
#include <algorithm>

struct flightPath {
    std::vector<Flight> flights;
    //can be kept double
    int totalCost;
    int totalHops;

    flightPath() : totalCost(0), totalHops(0) {}
};

bool compareByCost(const flightPath& a, const flightPath& b) {
    return a.totalCost < b.totalCost || (a.totalCost == b.totalCost && a.totalHops < b.totalHops);
}

void FlightManager::registerFlight(const std::string& airlineName, const std::string& source, const std::string& destination, const int price) {
    if (airlines.find(airlineName) == airlines.end()) {
        airlines.emplace(airlineName, Airline(airlineName));
    }
    airlines[airlineName].addFlight(source, destination, price);
    // print out according to given example
    std::cout << airlineName << " " << source << " " << destination << " " << "flight registered" << std::endl;
}

void FlightManager::searchFlight(const std::string& source, const std::string& destination, const bool isMealRequired) const {
    //isMealRequired
    if (source.empty() || destination.empty() || source == destination) {
        // we can also check iod spource is invalid or destination
        throw CustomException("Invalid source or destination");
    }
    std::unordered_map<std::string, std::vector<Flight>> graph;
    for (const auto& airline : airlines) {
        for (const auto& flight : airline.second.getFlights()) {
            graph[flight.getSource()].push_back(flight);
        }
    }

    // we can do BFS for min hops like we do in graph questions
    std::queue<flightPath> q;
    std::set<std::string> visited;
    flightPath initialPath;
    // insert source
    visited.insert(source);
    q.push(initialPath);

    std::vector<flightPath> validPaths;

    while(!q.empty()) {
        flightPath currentPath = q.front();
        q.pop();

        //checking last flight in curr path

        std::string currentCity = currentPath.flights.empty() ? source : currentPath.flights.back().getDestination();

        if (currentCity == destination) {
            validPaths.push_back(currentPath);
            continue;
        }

        for (const auto& flight : graph[currentCity]) {
            if (visited.find(flight.getDestination()) == visited.end()) {
                flightPath newPath = currentPath;
                newPath.flights.push_back(flight);
                newPath.totalCost += flight.getPrice();
                newPath.totalHops++;

                // Mark the destination as visited
                visited.insert(flight.getDestination());
                q.push(newPath);
            }
        }
    }

    // Handle no flights found
    if (validPaths.empty()) {
        std::cout << "No flights found from " << source << " to " << destination << "." << std::endl;
        return;
    }

    const flightPath& minCost = validPaths.front();
    std::cout << minCost.totalCost << " " << minCost.totalHops << std::endl;

    // Sort valid paths by cost and hops
    std::sort(validPaths.begin(), validPaths.end(), compareByCost);

    // Output the minimum hops path
    const flightPath& minHopsPath = validPaths.front();
    std::cout << "Route with Minimum Hops:" << std::endl;
    for (const auto& flight : minHopsPath.flights) {
        std::cout << flight.getSource() << " to " << flight.getDestination() << " via " 
                  << flight.getAirline() << " for " << flight.getPrice() << std::endl;
    }
    std::cout << "Total Flights = " << minHopsPath.totalHops << std::endl;
    std::cout << "Total Cost = " << minHopsPath.totalCost << std::endl;

    // If mealRequired, filter paths that meet this requirement
    if (isMealRequired) {
        std::cout << "Filtering for flights with meal service:" << std::endl;
        for (const auto& flight : validPaths) {
            if (flight.flights.front().getAirline() == "IndiGo") { // Assuming IndiGo serves meals
                std::cout << "Route with meals:" << std::endl;
                for (const auto& f : flight.flights) {
                    std::cout << f.getSource() << " to " << f.getDestination() << " via " 
                              << f.getAirline() << " for " << f.getPrice() << std::endl;
                }
                std::cout << "Total Flights = " << flight.totalHops << std::endl;
                std::cout << "Total Cost = " << flight.totalCost << std::endl;
                break; // Only show the first valid path with meal service
            }
        }
    }
}
