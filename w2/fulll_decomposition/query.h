//
// Created by Aleksei Kozharin on 17.11.2020.
//

#ifndef DECOMP_STARTER_QUERY_H
#define DECOMP_STARTER_QUERY_H
#include <iostream>
#include <string>
#include <vector>

enum class QueryType
{
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};
struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q);

#endif //DECOMP_STARTER_QUERY_H
