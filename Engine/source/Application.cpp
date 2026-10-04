#include <FeedEngine/Core/Application.h>

#include <vector>

class fe::Application::Impl
{
public:
    float TickRate = 60;

    fe::Time tickTime = fe::Seconds(1.f / TickRate);
    fe::Time accumulator;
    fe::Clock clock;

    std::vector<std::shared_ptr<fe::Script>> scripts;
    std::vector<std::shared_ptr<fe::Window>> windows;

};

fe::Application::Application()
{
    impl = std::make_unique<Impl>();
}

fe::Application::~Application() = default;

void fe::Application::AddScript( std::shared_ptr<Script> script)
{
    impl->scripts.push_back(script);
}
void fe::Application::AddWindow( std::shared_ptr<Window> window)
{
    impl->windows.push_back(window);
}

void fe::Application::Run()
{
    InitWindows();

    Init();

    std::cout 
        << "Scripts count: "
        << impl->scripts.size()
        << "\n";

    for (auto& s : impl->scripts)
    {
        if (s)
        {
            s->OnStart();
        }
    }

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