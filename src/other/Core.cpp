#include "../../Petroleum.h"

namespace PT
{

void initCommon()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "(Petroleum) ERROR: There was an error initilising GLEW! code %d\n", glewInit());
        if (glewInit() == 1)
            fprintf(stderr, "(Petroleum) INFO: PT::initGL() must be run AFTER at least one PT::Window was created!!\n");
    }

    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using OpenGL %s\n", glGetString(GL_VERSION));

    glFrontFace(GL_CW);
}

void initGL()
{
    initCommon();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_MULTISAMPLE);
}

void initGL(Config cfg)
{
    initCommon();

    // Background colours
    if (cfg.clear_colour == PT_BLACK)
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    if (cfg.clear_colour == PT_WHITE)
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    if (cfg.clear_colour == PT_SKY_BLUE)
        glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    if (cfg.clear_colour == PT_PETROL)
        glClearColor(0.0f, 0.12f, 0.16f, 1.0f);
    if (cfg.clear_colour == PT_LIGHT_GREY)
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    if (cfg.clear_colour == PT_GREY)
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    if (cfg.clear_colour == PT_DARK_GREY)
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);


    if (cfg.enable_blending)
    {
        glEnable(GL_BLEND);
        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    }

    if (cfg.msaa)
        glEnable(GL_MULTISAMPLE);

    glEnable(GL_DEPTH_TEST);
}



void doEvents()
{
    glfwPollEvents();
}

}
