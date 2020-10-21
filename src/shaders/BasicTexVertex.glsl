#version 460 core

in vec2 position;
in vec2 texCoords;

out vec2 f_TexCoords;

void main()
{
    f_TexCoords = texCoords;

    gl_Position = vec4(position.x, position.y, 1.0f, 1.0f);
}
