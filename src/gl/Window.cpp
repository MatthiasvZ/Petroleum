#include "../../Petroleum.h"

namespace PT
{

void errorCallback(int error, const char* description)
{
    fprintf(stderr, "(Petroleum) GLFW Error (%d): %s\n", error, description);
}

bool fullscreen;
int windowPosX, windowPosY;
int focused {0};
bool mouseLocked {1};
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:  glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        case GLFW_KEY_TAB:
                if (mouseLocked)
                    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                if (!mouseLocked)
                    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                mouseLocked = !mouseLocked;
                break;
        case GLFW_KEY_F11:
            if (!fullscreen)
            {
                glfwGetWindowPos(window, &windowPosX, &windowPosY);
                glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, GLFW_DONT_CARE);
                fullscreen = true;
            }
            else
            {
                glfwSetWindowMonitor(window, nullptr, windowPosX, windowPosY, 800, 800, GLFW_DONT_CARE);
                fullscreen = false;
            }
        }
    }
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void focusCallback(GLFWwindow* window, int _focused)
{
    focused = _focused;
}

Window::Window()
    : fps{0}, seconds{0}, avg_fps{0}, last_fps{0}, tn{time(0)}, ta{tn}, title{"OpenGL"}
{
    if (!glfwInit())
    {
        fprintf(stderr, "(Petroleum) ERROR: Problem initialising GLFW!\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_SAMPLES, 4);

    this->init();

    glfwSwapInterval(0); // 1 = v-sync 0 = off
}

Window::Window(Config cfg)
    : fps{0}, seconds{0}, avg_fps{0}, last_fps{0}, tn{time(0)}, ta{tn}, title{"OpenGL"}
{
    if (!glfwInit())
    {
        fprintf(stderr, "(Petroleum) ERROR: Problem initialising GLFW!\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, cfg.opengl_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, cfg.opengl_minor);
    if (cfg.msaa)
        glfwWindowHint(GLFW_SAMPLES, cfg.msaa);

    if (!cfg.window_resizable)
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->init();

    if (cfg.capture_mouse)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        if (glfwRawMouseMotionSupported())
            glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }

    glfwSwapInterval(cfg.vsync); // 1 = v-sync 0 = off

    if (cfg.fullscreen)
    {
        glfwGetWindowPos(window, &windowPosX, &windowPosY);
        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, GLFW_DONT_CARE);
        fullscreen = true;
    }
}

void Window::init()
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    window = glfwCreateWindow(800, 800, (title + " FPS = 0").c_str(), nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        fprintf(stderr, "(Petroleum) ERROR: Couldn't create window!\n");
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetErrorCallback(errorCallback);
}

bool Window::shouldRun() const
{
    if (glfwWindowShouldClose(window))
        return false;
    return true;
}

bool Window::getKey(int glfwKey) const
{
    return glfwGetKey(window, glfwKey);
}

bool Window::getMouseButton(int glfwButton) const
{
    return glfwGetMouseButton(window, glfwButton);
}

int Window::focused() const
{
    return PT::focused;
}

bool Window::mouseLocked() const
{
    return PT::mouseLocked;
}

void Window::getCursorPos(double* p_X, double* p_Y) const
{
    glfwGetCursorPos(window, p_X, p_Y);
}

void Window::update()
{
    if (time(&tn) != ta)
    {
        ta++;
        glfwSetWindowTitle(window, (title + " FPS = " + std::to_string(fps)).c_str());
        avg_fps += fps;
        seconds++;
        last_fps = fps;
        fps = 0;
    }
    fps++;
    glfwSwapBuffers(window);
}

void Window::changeTitle(const std::string newTitle)
{
    title = newTitle;
    glfwSetWindowTitle(window, (title + " FPS = " + std::to_string(last_fps)).c_str());
}

void Window::makeContextCurrent()
{
    glfwMakeContextCurrent(window);
}

Window::~Window()
{
    printf("avg. fps = %f\n", static_cast<float>(avg_fps) / seconds);
    glfwTerminate();
}

}
