#pragma once

#include "Export.h"

#include <chrono>

namespace fe
{
    class FE_API Time
    {
    public:
        Time();

        explicit Time(std::chrono::microseconds value);

        float AsSeconds() const;
        long long AsMilliseconds() const;
        long long AsMicroseconds() const;

        Time operator+(const Time& other) const;
        Time operator-(const Time& other) const;

        Time& operator+=(const Time& other);
        Time& operator-=(const Time& other);

        bool operator>=(const Time& other) const;
        bool operator<=(const Time& other) const;
        bool operator>(const Time& other) const;
        bool operator<(const Time& other) const;

    private:
        std::chrono::microseconds microseconds;
    };

    Time Seconds(float value);
    Time Milliseconds(long long value);
    Time Microseconds(long long value);

    Time Minutes(float value);
    Time Hours(float value);
    Time Days(float value);
}