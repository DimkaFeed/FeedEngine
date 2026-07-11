#include <FeedEngine/Core/Time.h>

fe::Time::Time()
    :
    microseconds(0)
{}

fe::Time::Time(std::chrono::microseconds value)
    :
    microseconds(value){}

float fe::Time::AsSeconds() const
{
    return microseconds.count() / 1000000.f;
}

long long fe::Time::AsMilliseconds() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        microseconds
    ).count();
}

long long fe::Time::AsMicroseconds() const
{
    return microseconds.count();
}

fe::Time fe::Time::operator+(const Time& other) const
{
    return Time(microseconds + other.microseconds);
}

fe::Time fe::Time::operator-(const Time& other) const
{
    return Time(microseconds - other.microseconds);
}

fe::Time& fe::Time::operator+=(const Time& other)
{
    microseconds += other.microseconds;
    return *this;
}


fe::Time& fe::Time::operator-=(const Time& other)
{
    microseconds -= other.microseconds;
    return *this;
}

bool fe::Time::operator>=(const Time& other) const
{
    return microseconds >= other.microseconds;
}

bool fe::Time::operator<=(const Time& other) const
{
    return microseconds <= other.microseconds;
}

bool fe::Time::operator>(const Time& other) const
{
    return microseconds > other.microseconds;
}

bool fe::Time::operator<(const Time& other) const
{
    return microseconds < other.microseconds;
}

fe::Time fe::Seconds(float value)
{
    return Time(
        std::chrono::microseconds(
            static_cast<long long>(value * 1000000)
        )
    );
}

fe::Time fe::Milliseconds(long long value)
{
    return Time(
        std::chrono::milliseconds(value)
    );
}

fe::Time fe::Microseconds(long long value)
{
    return Time(
        std::chrono::microseconds(value)
    );
}

fe::Time fe::Minutes(float value)
{
    return Seconds(value * 60);
}

fe::Time fe::Hours(float value)
{
    return Minutes(value * 60);
}

fe::Time fe::Days(float value)
{
    return Hours(value * 24);
}