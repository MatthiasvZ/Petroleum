# Petroleum
Petroleum is a library with the intent of making it faster to create games or other graphical programs using bare-bones OpenGL+C++. It takes care of code and classes which would have to be written for every such program.

**It should however, right now that is, NOT be used by anyone that isn't me. It's at its very early stages, bug-prone and absolutely not user-friendly or even properly documented.**

The code **should** be cross-platform, but since I don't have access to Windows, there is no way for me to check that. Therefore, the only officially supported platform is Linux.
## Building
### Prerequisites
Recent versions of GLEW and GLFW need to be available for linking.
```
$ sudo apt-get install libglew-dev libglfw3-dev
$ sudo pacman -S glew glfw-x11
$ sudo emerge -av media-libs/glew media-libs/glfw
```
### Building the library
The project may be build using either *make* or *Code::Blocks*.

```$ make release```

Alternatively, there are already compiled Linux versions in this repository's release section.
### Building a program using Petroleum (Linux)
Programs using this library need to #include the *Petroleum.h* and link the *libPetroleum.a*, GLEW and GLFW as follows:

```g++ main.cpp /path/to/libPetroleum.a $(pkg-config --libs glfw3 glew) -o prog```
## Features
- Quickly initialising GLFW and GLEW with proper settings
- Config system
- Classes for creating and using vertex- and index buffers, vertex arrays and shaders
  - There are some basic default shaders available
- A class for importing and using textures
## Credits
The following open-source libraries are used:
- **GLFW** for creating the window and context
- **GLEW** for accessing the OpenGL functions
- **stb-image** for reading in images such as textures
## Examples
### Drawing a coloured rectangle
```
#include "Petroleum.h"
#include <cstring>

int main()
{
    PT::setDataDir(strcat(std::getenv("HOME"), "/.local/share/petroleum"));
    PT::Config cfg {PT::parseConfig()};
    
    PT::Window window(cfg);
    PT::initGL(cfg);
    window.changeTitle("Sandbox");

    PT::Shader shader(PT_SHADER_XYRGB);

    std::vector<float> vertices =
    {
        -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f
    };

    std::vector<unsigned char> indices =
    {
        0, 1, 2,
        0, 2, 3
    };

    PT::VertexArray vao;
    PT::VertexBuffer vbo(vertices);
    PT::IndexBuffer ibo(indices);
    vao.addBuffer(vbo, shader.getLayout());

    glDisable(GL_DEPTH_BUFFER);
    while (window.shouldRun())
    {
        PT::clearScreen();
        PT::drawVA(vao, ibo, shader);
        window.update();

        PT::doEvents();
    }

    return 0;
}
```
## Licence
This program is available under the Unlicense. The same applies for stb-image.h.

**Note that GLFW and GLEW have their own licences, causing this program's compiled use when linked with GLFW and GLEW to be partially restricted by the following open-source licences: zlib/libpng, BSD, MIT.**
