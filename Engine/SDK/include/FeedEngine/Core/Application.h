#pragma once

#include "Export.h"

#include <iostream>
#include <memory>
#include <type_traits>

#include "../Scripting/Script.h"
#include "Time.h"

namespace fe
{

class FE_API Application
{
public:

    Application();
    virtual ~Application();

    void Run();

    void AddScript(std::shared_ptr<Script> script);

protected:

    void CreateWindow();

    virtual void Init() {}
    virtual void InitWindows() {}
    virtual void Update() {}

private:
    class Impl;

    std::unique_ptr<Impl> impl;
};
}