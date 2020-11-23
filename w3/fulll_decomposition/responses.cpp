//
// Created by Aleksei Kozharin on 17.11.2020.
//

#include "responses.h"
#include <map>

std::ostream &operator << (std::ostream &os, const BusesForStopResponse &r)
{
    if (r.buses.empty())
        os << "No stop" << std::endl;
    else
    {
        for (const std::string &bus : r.buses)
            os << bus << " ";
        os << std::endl;
    }
    return os;
}

std::ostream &operator << (std::ostream &os, const StopsForBusResponse &r)
{
    if (r.stops.empty())
        os << "No bus" << std::endl;
    else
        for (const std::string &stop : r.stops)
        {
            std::cout << "Stop " << stop << ": ";
            if (r.stops_to_buses.at(stop).size() == 1)
                std::cout << "no interchange";
            else
                for (const std::string &other_bus : r.stops_to_buses.at(stop))
                    if (r.bus != other_bus)
                        std::cout << other_bus << " ";
            std::cout << std::endl;
        }
    return os;
}

std::ostream &operator << (std::ostream &os, const AllBusesResponse &r)
{
    if (r.buses_to_stops.empty())
        os << "No buses" << std::endl;
    else
        for (const auto &bus_item : r.buses_to_stops)
        {
            os << "Bus " << bus_item.first << ": ";
            for (const std::string &stop : bus_item.second)
                os << stop << " ";
            os << std::endl;
        }
    return os;
}
