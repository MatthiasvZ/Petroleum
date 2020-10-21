#version 460 core

in vec2 f_TexCoords;
in vec4 f_Colour;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords) * vec4(f_Colour.r, f_Colour.g, f_Colour.b, f_Colour.a);
}
