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

// fragXY
R"glsl(
#version 400 core

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
)glsl",

// fragXYUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords);
}
)glsl",

// fragXYA
R"glsl(
#version 400 core

in float f_Alpha;

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, f_Alpha);
}
)glsl",

// fragXYAUV
R"glsl(
#version 400 core

in float f_Alpha;
in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords) *
    vec4(1.0f, 1.0f, 1.0f, f_Alpha);
}
)glsl",

// fragXYB
R"glsl(
#version 400 core

in float f_Brightness;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// fragXYBUV
R"glsl(
#version 400 core

in float f_Brightness;
in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords) *
    vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// fragXYRGB
R"glsl(
#version 400 core

in vec3 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, 1.0f);
}
)glsl",

// fragXYRGBUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;
in vec3 f_Colour;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords) *
    vec4(f_Colour.r, f_Colour.g, f_Colour.b, 1.0f);
}
)glsl",

// fragXYRGBA
R"glsl(
#version 400 core

in vec4 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
)glsl",

// fragXYRGBAUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;
in vec4 f_Colour;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords) *
    vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
)glsl"

};


#endif // PT_3D

#endif // DEFAULTSHADERS_H
