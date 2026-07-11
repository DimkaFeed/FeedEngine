#include <FeedEngine/Core/Application.h>

#include <vector>

#include <FeedEngine/Core/Clock.h>
#include <FeedEngine/Core/Window.h>

class fe::Application::Impl
{
public:

    float TickRate = 60;

    fe::Time tickTime = fe::Seconds(1.f / TickRate);

    fe::Time accumulator;

    fe::Clock clock;

    std::vector<std::shared_ptr<fe::Script>> scripts;

    std::vector<fe::Window> windows;

};

fe::Application::Application()
{
    impl = std::make_unique<Impl>();
}

fe::Application::~Application() = default;

void fe::Application::AddScript(
    std::shared_ptr<Script> script
)
{
    impl->scripts.push_back(script);
}

void fe::Application::Run()
{
    std::cout << "1\n";

    InitWindows();

    std::cout << "2\n";

    Init();

    std::cout << "3\n";

    std::cout 
        << "Scripts count: "
        << impl->scripts.size()
        << "\n";

    for (auto& s : impl->scripts)
    {
        if (s)
        {
            std::cout 
                << "Calling OnStart\n";


            s->OnStart();


            std::cout 
                << "OnStart done\n";
        }
    }

    std::cout << "4\n";

    while(true)
    {
        Update();

        for(auto& s : impl->scripts)
        {
            if(s)
                s->OnUpdate();
        }

        impl->accumulator += 
            impl->clock.Restart();

        while(impl->accumulator >= impl->tickTime)
        {
            for(auto& s : impl->scripts)
            {
                if(s)
                    s->OnTickUpdate();
            }

            impl->accumulator -= 
                impl->tickTime;
        }

    }

}