#include "../../Petroleum.h"
#include <AL/al.h>
#include <iostream>

namespace PT
{

void clearGlErrors()
{
    while (glGetError());
}

void getGlErrors(DebugInfo* dbi)
{
    while (GLenum error = glGetError())
    {
        std::cerr << "[OpenGL Error] (" << error << " / ";
        switch (error)
        {
        case 0x0500:
            std::cerr << "GL_INVALID_ENUM";
            break;
        case 0x0501:
            std::cerr << "GL_INVALID_VALUE";
            break;
        case 0x0502:
            std::cerr << "GL_INVALID_OPERATION";
            break;
        case 0x0503:
            std::cerr << "GL_STACK_OVERFLOW";
            break;
        case 0x0504:
            std::cerr << "GL_STACK_UNDERFLOW";
            break;
        case 0x0505:
            std::cerr << "GL_OUT_OF_MEMORY";
            break;
        default:
            std::cerr << "UNKNOWN";
            break;
        }
        if (dbi == nullptr)
            std::cerr << ')' << std::endl;
        else if (dbi->line)
            std::cerr << ") after the call of " << dbi->call << " on line " << dbi->line << " of file " << dbi->file << " (" << dbi->func << "())" << std::endl;
        else
            std::cerr << ") after the call of " << dbi->call << " inside Petroleum (PT::" << dbi->func << "())" << std::endl;
    }
}

void clearAlErrors()
{
    while (alGetError());
}

void getAlErrors(DebugInfo* dbi)
{
    while (ALenum error = alGetError())
    {
        std::cerr << "[OpenAL Error] (" << error;
        if (dbi == nullptr)
            std::cerr << ')' << std::endl;
        else if (dbi->line)
            std::cerr << ") after the call of " << dbi->call << " on line " << dbi->line << " of file " << dbi->file << " (" << dbi->func << "())" << std::endl;
        else
            std::cerr << ") after the call of " << dbi->call << " inside Petroleum (PT::" << dbi->func << "())" << std::endl;
    }
}

}
