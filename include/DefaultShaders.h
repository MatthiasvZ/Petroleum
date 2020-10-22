#ifndef DEFAULTSHADERS_H
#define DEFAULTSHADERS_H

#include <string>
#include <vector>

#ifdef PT_3D
#error "3D isn't yet implemented"
#else

std::vector<std::string> vertSources
{

// vertXY
R"glsl(
#version 400 core

in vec2 position;

void main()
{
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYUV
R"glsl(
#version 400 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYA
R"glsl(
#version 400 core

in vec2 position;
in float alpha;

out float f_Alpha;

void main()
{
    f_Alpha = alpha;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYAUV
R"glsl(
#version 400 core

in vec2 position;
in float alpha;
in vec2 texCoords;

out float f_Alpha;
out vec2 f_TexCoords;

void main()
{
    f_Alpha = alpha;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYB
R"glsl(
#version 400 core

in vec2 position;
in float brightness;

out float f_Brightness;

void main()
{
    f_Brightness = brightness;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYBUV
R"glsl(
#version 400 core

in vec2 position;
in float brightness;
in vec2 texCoords;

out float f_Brightness;
out vec2 f_TexCoords;

void main()
{
    f_Brightness = brightness;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGB
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBUV
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;
in vec2 texCoords;

out vec3 f_Colour;
out vec2 f_TexCoords;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBA
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;

out vec4 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBAUV
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;
in vec2 texCoords;

out vec4 f_Colour;
out vec2 f_TexCoords;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl"

};


std::vector<std::string> fragSources
{

// vertXY
R"glsl(
#version 400 core

in vec2 position;

void main()
{
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYUV
R"glsl(
#version 400 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYA
R"glsl(
#version 400 core

in vec2 position;
in float alpha;

out float f_Alpha;

void main()
{
    f_Alpha = alpha;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYAUV
R"glsl(
#version 400 core

in vec2 position;
in float alpha;
in vec2 texCoords;

out float f_Alpha;
out vec2 f_TexCoords;

void main()
{
    f_Alpha = alpha;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYB
R"glsl(
#version 400 core

in vec2 position;
in float brightness;

out float f_Brightness;

void main()
{
    f_Brightness = brightness;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYBUV
R"glsl(
#version 400 core

in vec2 position;
in float brightness;
in vec2 texCoords;

out float f_Brightness;
out vec2 f_TexCoords;

void main()
{
    f_Brightness = brightness;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGB
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBUV
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;
in vec2 texCoords;

out vec3 f_Colour;
out vec2 f_TexCoords;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBA
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;

out vec4 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl",

// vertXYRGBAUV
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;
in vec2 texCoords;

out vec4 f_Colour;
out vec2 f_TexCoords;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
)glsl"

};


#endif // PT_3D

#endif // DEFAULTSHADERS_H
