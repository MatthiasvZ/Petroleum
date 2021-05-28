#ifndef DEFAULTSHADERS_H
#define DEFAULTSHADERS_H

std::array<std::string, 30> vertSources
{

// 0 vertXY
R"glsl(
#version 400 core

in vec2 position;

void main()
{
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 1 vertXYUV
R"glsl(
#version 400 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 2 vertXYA
R"glsl(
#version 400 core

in vec2 position;
in float alpha;

out float f_Alpha;

void main()
{
    f_Alpha = alpha;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 3 vertXYAUV
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
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 4 vertXYB
R"glsl(
#version 400 core

in vec2 position;
in float brightness;

out float f_Brightness;

void main()
{
    f_Brightness = brightness;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 5 vertXYBUV
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
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 6 vertXYRGB
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 7 vertXYRGBUV
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
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 8 vertXYRGBA
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;

out vec4 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 9 vertXYRGBAUV
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
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 10 vertXY_M
R"glsl(
#version 400 core

in vec2 position;

uniform mat4 u_Mat;

void main()
{
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 11 vertXYUV_M
R"glsl(
#version 400 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 12 vertXYA_M
R"glsl(
#version 400 core

in vec2 position;
in float alpha;

out float f_Alpha;

uniform mat4 u_Mat;

void main()
{
    f_Alpha = alpha;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 13 vertXYAUV_M
R"glsl(
#version 400 core

in vec2 position;
in float alpha;
in vec2 texCoords;

out float f_Alpha;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Alpha = alpha;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 14 vertXYB_M
R"glsl(
#version 400 core

in vec2 position;
in float brightness;

out float f_Brightness;

uniform mat4 u_Mat;

void main()
{
    f_Brightness = brightness;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 15 vertXYBUV_M
R"glsl(
#version 400 core

in vec2 position;
in float brightness;
in vec2 texCoords;

out float f_Brightness;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Brightness = brightness;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 16 vertXYRGB_M
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 17 vertXYRGBUV_M
R"glsl(
#version 400 core

in vec2 position;
in vec3 colour;
in vec2 texCoords;

out vec3 f_Colour;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 18 vertXYRGBA_M
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;

out vec4 f_Colour;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 19 vertXYRGBAUV_M
R"glsl(
#version 400 core

in vec2 position;
in vec4 colour;
in vec2 texCoords;

out vec4 f_Colour;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// 20 vertXYZ_M
R"glsl(
#version 400 core

in vec3 position;

uniform mat4 u_Mat;

void main()
{
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 21 vertXYZUV_M
R"glsl(
#version 400 core

in vec3 position;
in vec2 texCoords;

out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 22 vertXYZA_M
R"glsl(
#version 400 core

in vec3 position;
in float alpha;

out float f_Alpha;

uniform mat4 u_Mat;

void main()
{
    f_Alpha = alpha;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 23 vertXYZAUV_M
R"glsl(
#version 400 core

in vec3 position;
in float alpha;
in vec2 texCoords;

out float f_Alpha;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Alpha = alpha;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 24 vertXYZB_M
R"glsl(
#version 400 core

in vec3 position;
in float brightness;

out float f_Brightness;

uniform mat4 u_Mat;

void main()
{
    f_Brightness = brightness;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 25 vertXYZBUV_M
R"glsl(
#version 400 core

in vec3 position;
in float brightness;
in vec2 texCoords;

out float f_Brightness;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Brightness = brightness;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 26 vertXYZRGB_M
R"glsl(
#version 400 core

in vec3 position;
in vec3 colour;

out vec3 f_Colour;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 27 vertXYZRGBUV_M
R"glsl(
#version 400 core

in vec3 position;
in vec3 colour;
in vec2 texCoords;

out vec3 f_Colour;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 28 vertXYZRGBA_M
R"glsl(
#version 400 core

in vec3 position;
in vec4 colour;

out vec4 f_Colour;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// 29 vertXYZRGBAUV_M
R"glsl(
#version 400 core

in vec3 position;
in vec4 colour;
in vec2 texCoords;

out vec4 f_Colour;
out vec2 f_TexCoords;

uniform mat4 u_Mat;

void main()
{
    f_Colour = colour;
    f_TexCoords = texCoords;
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl"

};


std::array<std::string, 10> fragSources
{

// *0 fragWHITE
R"glsl(
#version 400 core

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
)glsl",

// *1 fragUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D u_TexSlot;

void main()
{
    outColour = texture(u_TexSlot, f_TexCoords);
}
)glsl",

// *2 fragA
R"glsl(
#version 400 core

in float f_Alpha;

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, f_Alpha);
}
)glsl",

// *3 fragAUV
R"glsl(
#version 400 core

in float f_Alpha;
in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D u_TexSlot;

void main()
{
    outColour = texture(u_TexSlot, f_TexCoords) *
    vec4(1.0f, 1.0f, 1.0f, f_Alpha);
}
)glsl",

// *4 fragB
R"glsl(
#version 400 core

in float f_Brightness;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// *5 fragBUV
R"glsl(
#version 400 core

in float f_Brightness;
in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D u_TexSlot;

void main()
{
    outColour = texture(u_TexSlot, f_TexCoords) *
    vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// *6 fragRGB
R"glsl(
#version 400 core

in vec3 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, 1.0f);
}
)glsl",

// *7 fragRGBUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;
in vec3 f_Colour;

out vec4 outColour;

uniform sampler2D u_TexSlot;

void main()
{
    outColour = texture(u_TexSlot, f_TexCoords) *
    vec4(f_Colour.r, f_Colour.g, f_Colour.b, 1.0f);
}
)glsl",

// *8 fragRGBA
R"glsl(
#version 400 core

in vec4 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
)glsl",

// *9 fragRGBAUV
R"glsl(
#version 400 core

in vec2 f_TexCoords;
in vec4 f_Colour;

out vec4 outColour;

uniform sampler2D u_TexSlot;

void main()
{
    outColour = texture(u_TexSlot, f_TexCoords) *
    vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
)glsl"

};

#endif // DEFAULTSHADERS_H
