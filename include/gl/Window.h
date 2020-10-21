#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <gl/Input.h>

class Window
{
    public:
        Window();
        bool shouldRun() const;
        const Input& getInputs() const;
        void update();
        void changeTitle(const char* newTitle) const;

        ~Window();

    protected:

    private:
        GLFWwindow* window;

        int fps, seconds, avg_fps;
        long int tn, ta;
};

#endif // WINDOW_H
