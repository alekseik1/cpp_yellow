//
// Created by Aleksei Kozharin on 17.11.2020.
//

#include "phone_number.h"
#include <sstream>


PhoneNumber::PhoneNumber(const string &international_number) {
    std::istringstream ss(international_number);

    if (ss.get() != '+') throw invalid_argument("wrong number format");

    std::getline(ss, country_code_, '-');
    std::getline(ss, city_code_, '-');
    std::getline(ss, local_number_);

    if (country_code_.empty() || city_code_.empty() || local_number_.empty())
        throw invalid_argument("wrong number format 1");
}

std::string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

std::string PhoneNumber::GetCityCode() const
{
    return city_code_;
}

std::string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const
{
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
