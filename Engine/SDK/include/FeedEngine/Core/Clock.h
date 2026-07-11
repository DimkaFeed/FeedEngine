#pragma once

#include "Export.h"

#include "Time.h"

#include <chrono>

namespace fe
{
    class FE_API Clock
    {
    public:
        Clock();

        Time Restart();
        Time GetElapsedTime() const;

    private:
        std::chrono::high_resolution_clock::time_point start;
    };
}