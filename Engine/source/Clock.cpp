#include <FeedEngine/Core/Clock.h>

fe::Clock::Clock()
{
    start = std::chrono::high_resolution_clock::now();
}

fe::Time fe::Clock::Restart()
{
    auto now = std::chrono::high_resolution_clock::now();

    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(
            now - start
        );


    start = now;

    return Time(elapsed);
}

fe::Time fe::Clock::GetElapsedTime() const
{
    auto now = std::chrono::high_resolution_clock::now();


    return Time(
        std::chrono::duration_cast<std::chrono::microseconds>(
            now - start
        )
    );
}