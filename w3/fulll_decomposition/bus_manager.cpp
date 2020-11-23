//
// Created by Aleksei Kozharin on 17.11.2020.
//

#include "bus_manager.h"
#include <vector>

void BusManager::AddBus(const std::string &bus, const std::vector<std::string> &stops) {
    buses_to_stops[bus] = stops;
    for (const std::string &stop : stops)
        stops_to_buses[stop].push_back(bus);
}
BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const {
    std::vector<std::string> result;
    try
    {
        result = stops_to_buses.at(stop);
    }
    catch (...) {}

    return {result};
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string &bus) const {
    std::vector<std::string> result;
    try
    {
        result = buses_to_stops.at(bus);
    }
    catch (...) {}

    return {bus, result, stops_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_to_stops};
}