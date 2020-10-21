#include "gl/VertexBuffer.h"

#include <GL/glew.h>


VertexBuffer::VertexBuffer(const std::vector<float>& data)
{
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GL_FLOAT), data.data(), GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

VertexBuffer::VertexBuffer(const float data[], unsigned int size)
{
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

void VertexBuffer::bindBuffer() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

void VertexBuffer::unbindBuffer() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &vboID);
}
