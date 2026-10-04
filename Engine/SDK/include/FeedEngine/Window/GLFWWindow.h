#pragma once

#include "Window.h"
#include <memory>

namespace fe
{

class GLFWWindow : public Window
{
private:
    class Impl;
    std::unique_ptr<Impl> impl;

public:
    GLFWWindow();

    ~GLFWWindow();

    void Create(
        int width,
        int height,
        const char* title
    ) override;

    void Update() override;

    bool ShouldClose() const override;
};
}