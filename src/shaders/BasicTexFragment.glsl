#version 460 core

in vec2 f_TexCoords;

out vec4 outColour;

uniform sampler2D texSlot;

void main()
{
    outColour = texture(texSlot, f_TexCoords);
}
