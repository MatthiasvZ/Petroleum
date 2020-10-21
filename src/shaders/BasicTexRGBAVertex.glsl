#version 460 core

in vec2 position;
in vec2 texCoords;
in vec4 colour;

out vec2 f_TexCoords;
out vec4 f_Colour;

void main()
{
    f_TexCoords = texCoords;
    f_Colour = colour;
    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
