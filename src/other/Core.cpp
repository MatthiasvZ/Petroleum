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

    PTGLEC(glFrontFace(GL_CW));
}

void initGL()
{
    initCommon();

    PTGLEC(glEnable(GL_DEPTH_TEST));
    PTGLEC(glEnable(GL_BLEND));
    PTGLEC(glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA));

    PTGLEC(glEnable(GL_MULTISAMPLE));
}

void initGL(Config cfg)
{
    initCommon();

    // Background colours
    switch (cfg.clear_colour)
    {
        case PT_BLACK:
            PTGLEC(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));     break;
        case PT_WHITE:
            PTGLEC(glClearColor(1.0f, 1.0f, 1.0f, 1.0f));     break;
        case PT_SKY_BLUE:
            PTGLEC(glClearColor(0.53f, 0.81f, 0.92f, 1.0f));  break;
        case PT_PETROL:
            PTGLEC(glClearColor(0.0f, 0.12f, 0.16f, 1.0f));   break;
        case PT_LIGHT_GREY:
            PTGLEC(glClearColor(0.7f, 0.7f, 0.7f, 1.0f));     break;
        case PT_GREY:
            PTGLEC(glClearColor(0.5f, 0.5f, 0.5f, 1.0f));     break;
        case PT_DARK_GREY:
            PTGLEC(glClearColor(0.3f, 0.3f, 0.3f, 1.0f));     break;
    }

    if (cfg.enable_blending)
    {
        PTGLEC(glEnable(GL_BLEND));
        PTGLEC(glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA));
    }

    if (cfg.msaa)
    {
        PTGLEC(glEnable(GL_MULTISAMPLE));
    }

    PTGLEC(glEnable(GL_DEPTH_TEST));

    if (cfg.print_status)
    {
        fprintf(stdout, "(Petroleum) Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
        fprintf(stdout, "(Petroleum) Status: Using OpenGL %s\n", glGetString(GL_VERSION));
    }
}

void doEvents()
{
    glfwPollEvents();
}

void printVersion()
{
    printf("(Petroleum) Status: Running version " PT_VERSION_S);
}

}
