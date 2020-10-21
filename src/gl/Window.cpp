#include "gl/Window.h"

#include "other/Common.h"

#include <cstdio>
#include <ctime>
#include <string>
#include <GL/glew.h>


void errorCallback(int error, const char* description)
{
    fprintf(stderr, "Error (%d): %s\n", error, description);
}

Input input; // GLFW SUCKS!
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    static bool fullscreen;
    static int windowPosX, windowPosY;
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:  glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        case GLFW_KEY_LEFT_CONTROL: input.ctrlHeld = true;    break;
        case GLFW_KEY_SPACE:      input.spaceHeld = true;     break;
        case GLFW_KEY_LEFT_SHIFT: input.shiftHeld = true;     break;
        case GLFW_KEY_W:            input.wHeld   = true;     break;
        case GLFW_KEY_A:            input.aHeld   = true;     break;
        case GLFW_KEY_S:            input.sHeld   = true;     break;
        case GLFW_KEY_D:            input.dHeld   = true;     break;
        case GLFW_KEY_DOWN:        input.downHeld = true;     break;
        case GLFW_KEY_LEFT:        input.leftHeld = true;     break;
        case GLFW_KEY_RIGHT:      input.rightHeld = true;     break;
        case GLFW_KEY_UP:           input.upHeld  = true;     break;
        case GLFW_KEY_KP_2:         input.kp2Held = true;     break;
        case GLFW_KEY_KP_4:         input.kp4Held = true;     break;
        case GLFW_KEY_KP_5:         input.kp5Held = true;     break;
        case GLFW_KEY_KP_6:         input.kp6Held = true;     break;
        case GLFW_KEY_KP_8:         input.kp8Held = true;     break;
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
    if (action == GLFW_RELEASE)
    {
        switch (key)
        {
        case GLFW_KEY_LEFT_CONTROL: input.ctrlHeld = false;   break;
        case GLFW_KEY_SPACE:      input.spaceHeld = false;    break;
        case GLFW_KEY_LEFT_SHIFT: input.shiftHeld = false;    break;
        case GLFW_KEY_W:            input.wHeld   = false;    break;
        case GLFW_KEY_A:            input.aHeld   = false;    break;
        case GLFW_KEY_S:            input.sHeld   = false;    break;
        case GLFW_KEY_D:            input.dHeld   = false;    break;
        case GLFW_KEY_DOWN:        input.downHeld = false;    break;
        case GLFW_KEY_LEFT:        input.leftHeld = false;    break;
        case GLFW_KEY_RIGHT:      input.rightHeld = false;    break;
        case GLFW_KEY_UP:           input.upHeld  = false;    break;
        case GLFW_KEY_KP_2:         input.kp2Held = false;    break;
        case GLFW_KEY_KP_4:         input.kp4Held = false;    break;
        case GLFW_KEY_KP_5:         input.kp5Held = false;    break;
        case GLFW_KEY_KP_6:         input.kp6Held = false;    break;
        case GLFW_KEY_KP_8:         input.kp8Held = false;    break;
        }
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
    }
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


Window::Window()
    : fps{0}, seconds{0}, avg_fps{0}, tn{time(0)}, ta{tn}
{
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: Problem initialising GLFW!\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    #if PT_MSAA
        glfwWindowHint(GLFW_SAMPLES, PT_MSAA);
    #endif // PT_MSAA

    window = glfwCreateWindow(800, 800, "OpenGL FPS = 0", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        fprintf(stderr, "ERROR: Couldn't create window!\n");
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    glfwSwapInterval(PT_V_SYNC); // 1 = v-sync 0 = off
}

bool Window::shouldRun() const
{
    if (glfwWindowShouldClose(window))
        return false;
    return true;
}

const Input& Window::getInputs() const
{
    return input;
}


void Window::update()
{
    if (time(&tn) != ta)
    {
        ta++;
        changeTitle(("OpenGL FPS = " + std::to_string(fps)).c_str());
        avg_fps += fps;
        seconds++;
        fps = 0;
    }
    fps++;

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::changeTitle(const char* newTitle) const
{
    glfwSetWindowTitle(window, newTitle);
}


Window::~Window()
{
    glfwTerminate();
}
