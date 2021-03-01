#ifndef DEFAULTSHADERS_H
#define DEFAULTSHADERS_H

constexpr std::string_view vertSources[]
{

// vertXY
R"glsl(
#version 150 core

in vec2 position;

void main()
{
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYUV
R"glsl(
#version 150 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

void main()
{
    f_TexCoords = texCoords;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYA
R"glsl(
#version 150 core

in vec2 position;
in float alpha;

out float f_Alpha;

void main()
{
    f_Alpha = alpha;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYAUV
R"glsl(
#version 150 core

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

// vertXYB
R"glsl(
#version 150 core

in vec2 position;
in float brightness;

out float f_Brightness;

void main()
{
    f_Brightness = brightness;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYBUV
R"glsl(
#version 150 core

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

// vertXYRGB
R"glsl(
#version 150 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYRGBUV
R"glsl(
#version 150 core

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

// vertXYRGBA
R"glsl(
#version 150 core

in vec2 position;
in vec4 colour;

out vec4 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYRGBAUV
R"glsl(
#version 150 core

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

// vertXY_M
R"glsl(
#version 150 core

in vec2 position;

uniform mat4 u_Mat;

void main()
{
    gl_Position = u_Mat * vec4(position.x, position.y, 0.0f, 1.0f);
}
)glsl",

// vertXYUV_M
R"glsl(
#version 150 core

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

// vertXYA_M
R"glsl(
#version 150 core

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

// vertXYAUV_M
R"glsl(
#version 150 core

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

// vertXYB_M
R"glsl(
#version 150 core

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

// vertXYBUV_M
R"glsl(
#version 150 core

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

// vertXYRGB_M
R"glsl(
#version 150 core

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

// vertXYRGBUV_M
R"glsl(
#version 150 core

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

// vertXYRGBA_M
R"glsl(
#version 150 core

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

// vertXYRGBAUV_M
R"glsl(
#version 150 core

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
)glsl"

// vertXYZ_M
R"glsl(
#version 150 core

in vec3 position;

uniform mat4 u_Mat;

void main()
{
    gl_Position = u_Mat * vec4(position.x, position.y, position.z, 1.0f);
}
)glsl",

// vertXYZUV_M
R"glsl(
#version 150 core

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

// vertXYZA_M
R"glsl(
#version 150 core

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

// vertXYZAUV_M
R"glsl(
#version 150 core

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

// vertXYZB_M
R"glsl(
#version 150 core

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

// vertXYZBUV_M
R"glsl(
#version 150 core

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

// vertXYZRGB_M
R"glsl(
#version 150 core

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

// vertXYZRGBUV_M
R"glsl(
#version 150 core

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

// vertXYZRGBA_M
R"glsl(
#version 150 core

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

// vertXYZRGBAUV_M
R"glsl(
#version 150 core

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


std::vector<std::string> fragSources
{

// fragWHITE
R"glsl(
#version 150 core

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
)glsl",

// fragUV
R"glsl(
#version 150 core

in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords);
}
)glsl",

// fragA
R"glsl(
#version 150 core

in float f_Alpha;

out vec4 outColour;

void main()
{
    outColour = vec4(1.0f, 1.0f, 1.0f, f_Alpha);
}
)glsl",

// fragAUV
R"glsl(
#version 150 core

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

// fragB
R"glsl(
#version 150 core

in float f_Brightness;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// fragBUV
R"glsl(
#version 150 core

in float f_Brightness;
in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords)
    * vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
)glsl",

// fragRGB
R"glsl(
#version 150 core

in vec3 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, 1.0f);
}
)glsl",

// fragRGBUV
R"glsl(
#version 150 core

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

// fragRGBA
R"glsl(
#version 150 core

in vec4 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
)glsl",

// fragRGBAUV
R"glsl(
#version 150 core

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

#endif // DEFAULTSHADERS_H
