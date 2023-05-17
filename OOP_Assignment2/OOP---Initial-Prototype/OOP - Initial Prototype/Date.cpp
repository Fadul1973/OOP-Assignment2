#include "Date.h"
#include <iostream>
#include <time.h>
#include <string>


Date::Date()
{
    time_t rawtime = time(&rawtime);
    struct tm timeinfo;

    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    d = timeinfo.tm_mday;
    m = timeinfo.tm_mon + 1;
    y = timeinfo.tm_year + 1900;
     
}

Date::Date(const int d, const int m, const int y )
    : d(d), m(m), y(y)
{
    
}

Date::~Date()
{

}

int Date::GetDay() const
{
    return d;

}

int Date::GetMonth() const
{
    return m;
}

int Date::GetYear() const
{
    return y;
}

std::string Date::getFullDate() const
{
    if (GetMonth() <= 9 && GetDay() <=9)
    {
        std::string fullDate = "0"+ std::to_string(GetDay()) + "-" + "0" + std::to_string(GetMonth()) + "-" + std::to_string(GetYear());
        return fullDate;

    }
    else if (GetMonth() <= 9)
    {
        std::string fullDate = std::to_string(GetDay()) + "-" + "0" + std::to_string(GetMonth()) + "-" + std::to_string(GetYear());
        return fullDate;

    }
    else if (GetDay() <= 9)
    {
        std::string fullDate = "0" + std::to_string(GetDay()) + "-" + std::to_string(GetMonth()) + "-" + std::to_string(GetYear());
        return fullDate;

    }
    else
    {
        std::string fullDate = std::to_string(GetDay()) + "-" + std::to_string(GetMonth()) + "-" + std::to_string(GetYear());
        return fullDate;

    }

}
