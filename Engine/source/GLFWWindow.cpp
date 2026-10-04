#include <FeedEngine/Window/GLFWWindow.h>
#include <GLFW/glfw3.h>

class fe::GLFWWindow::Impl
{
public:
    GLFWwindow* m_Window = nullptr;
};

fe::GLFWWindow::GLFWWindow() : impl(std::make_unique<Impl>()) { glfwInit();}

fe::GLFWWindow::~GLFWWindow()
    {
    if (impl->m_Window)
        glfwDestroyWindow(impl->m_Window);

        glfwTerminate();
    }

void fe::GLFWWindow::Create(int width, int height, const char* title) {
    impl->m_Window = glfwCreateWindow( width, height, title, nullptr, nullptr);
}

void fe::GLFWWindow::Update() { glfwPollEvents(); }

bool fe::GLFWWindow::ShouldClose() const {return glfwWindowShouldClose(impl->m_Window);}
