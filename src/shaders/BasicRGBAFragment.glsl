#version 460 core

in vec4 f_Colour;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
