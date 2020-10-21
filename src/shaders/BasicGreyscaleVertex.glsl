#version 460 core

in vec2 position;
in float brightness;

out float f_Brightness;

void main()
{
    f_Brightness = brightness;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
