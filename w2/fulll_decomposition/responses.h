//
// Created by Aleksei Kozharin on 17.11.2020.
//

#ifndef DECOMP_STARTER_RESPONSES_H
#define DECOMP_STARTER_RESPONSES_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

struct BusesForStopResponse
{
    std::vector<std::string> buses;
};;
std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);
struct StopsForBusResponse
{
    std::string bus;
    std::vector<std::string> stops;
    std::map<std::string, std::vector<std::string>> stops_to_buses;
};;
std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);
struct AllBusesResponse
{
    std::map<std::string, std::vector<std::string>> buses_to_stops;
};
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);

#endif //DECOMP_STARTER_RESPONSES_H
