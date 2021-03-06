# Petroleum
Petroleum is a library with the intent of making it faster to create games or other graphical programs using bare-bones OpenGL+C++. It takes care of code and classes which would have to be written for every such program.

**It should however, right now that is, NOT be used by anyone that isn't me. It's at its very early stages, bug-prone and absolutely not user-friendly or even properly documented.**

The code *might* be cross-platform, but since I don't have access to Windows, there is no way for me to check that. Therefore, the only officially supported platform is Linux.
## Building
### Prerequisites
Recent versions of GLFW, GLEW and OpenAL-Soft need to be available for linking.
```
$ sudo apt-get install libglew-dev libglfw3-dev libopenal-dev
$ sudo pacman -S glew glfw-x11 openal
$ sudo emerge -av media-libs/glew media-libs/glfw media-libs/openal
```
### Building the library
The project may be build using either *make* or *Code::Blocks*.

```$ make release```

Alternatively, there are already compiled Linux versions in this repository's release section.
### Building a program using Petroleum (Linux)
Programs using this library need to #include the *Petroleum.h*, and link the *libPetroleum.a*, GLEW, GLFW and OpenAL as follows:
```g++ main.cpp /path/to/libPetroleum.a $(pkg-config --libs openal glfw3 glew) -ldl -lpthread -o prog```
## Features
- Quickly loading GLFW and GLEW with proper settings
- Config system
- Classes for creating and using vertex- and index buffers, vertex arrays and shaders
  - There are some basic default shaders available
- A class for importing and using textures
## Credits
The following open-source libraries are used:
- **GLFW** for creating the window and context
- **GLEW** for accessing the OpenGL functions
- **stb_image** for reading in images such as textures
- **dr_wav** and **dr_flac** for reading in audio files
## Examples
### Drawing a coloured rectangle
```
#include "Petroleum.h"
#include <string>

int main()
{
    PT::setDataDir((std::getenv("HOME") + (std::string)"/.local/share/pt-sandbox").c_str());
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
This program is available under the Unlicense. The same applies for stb-image.h, dr_wav.h and dr_flac.h.

*Note that GLFW and GLEW have other licences, causing programs linked with GLFW and GLEW to be restricted by the following open-source licences: zlib/libpng, BSD, MIT.*
