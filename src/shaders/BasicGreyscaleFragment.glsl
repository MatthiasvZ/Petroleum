#version 460 core

in float f_Brightness;

out vec4 outColour;

void main()
{
    outColour = vec4(f_Brightness, f_Brightness, f_Brightness, 1.0f);
}
