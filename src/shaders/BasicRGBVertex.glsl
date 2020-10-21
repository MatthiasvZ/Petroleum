#version 460 core

in vec2 position;
in vec3 colour;

out vec3 f_Colour;

void main()
{
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
