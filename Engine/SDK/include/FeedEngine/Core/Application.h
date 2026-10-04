#pragma once

#include "Export.h"

#include <iostream>
#include <memory>
#include <type_traits>

#include "Time.h"
#include "Clock.h"

#include "../Scripting/Script.h"
#include "../Window/Window.h"

namespace fe
{
class FE_API Application
{
public:
    Application();
    virtual ~Application();

    void Run();

    void AddScript(std::shared_ptr<Script> script);
    void AddWindow(std::shared_ptr<Window> window);

protected:
    virtual void Init() {}
    virtual void InitWindows() {}
    virtual void Update() {}

private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}