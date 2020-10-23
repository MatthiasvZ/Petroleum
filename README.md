# Petroleum
Petroleum is a library with the intent of making it faster to create games or other graphical programs using bare-bones OpenGL+C++.

**It should however, right now that is, NOT be used by anyone that isn't me. It's at its very early stages, bug-prone and absolutely not user-friendly or even properly documented.**

The code **should** be cross-platform, but since I don't have Windows, there is no way for me to check that.
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

Alternatively, there are already compiled versions in this repository's release section. You will, however, need the Petroleum.h, GLEW and GLFW anyway.
### Building a program using Petroleum
Programs using it must include the *Petroleum.h* and link the *libPetroleum.a*. 3D-applications should include the Petroleum3D.h instead. All above header files as well as stb-image.h must in the same folder.
## Features
- Quickly initialising GLFW and GLEW with proper settings
- Config system
- Classes for creating and using vertex- and index buffers as well as vertex arrays 
- A class for creating and using shaders
  - There are some basic default shaders available
- A class for importing and using textures
## Credits
The following open-source libraries are used:
- **GLFW** for creating window and gl-context
- **GLEW** for accessing the OpenGL functions
- **stb-image** for reading in images such as textures
## Examples
### Drawing a coloured rectangle
```
#include "Petroleum.h"

int main()
{
    PT::setDataDir(strcat(std::getenv("HOME"), "/.local/share/petroleum"));

    PT::Config cfg {PT::parseConfig()};
    PT::Window window(cfg);
    PT::init();
    window.changeTitle("PetrolSandbox");

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
    PT::VertexBufferLayout layout;
    layout.push(GL_FLOAT, 2);
    layout.push(GL_FLOAT, 3);
    vao.addBuffer(vbo, layout);


    PT::Renderer renderer;
    while (window.shouldRun())
    {
        renderer.clear();
        renderer.drawVA(vao, ibo, shader);
        window.update();
    }


    return 0;
}
```
## Licence
This program is available under the Unlicense. The same applies for stb-image.h.

**Note that GLFW and GLEW have their own licences, causing this program's compiled use when linked with GLFW and GLEW to be restricted by the following open-source licences: zlib/libpng, BSD, MIT. These licences will not be included in this repository, since the respective programs aren't either.**
