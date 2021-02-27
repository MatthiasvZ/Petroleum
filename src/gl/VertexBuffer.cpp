#include "../../Petroleum.h"

namespace PT
{

VertexBuffer::VertexBuffer(const std::vector<float>& data, unsigned int drawType)
    : drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &vboID));
    PTGLEC(glBindBuffer(GL_ARRAY_BUFFER, vboID));
    PTGLEC(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GL_FLOAT), data.data(), drawType));
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

VertexBuffer::VertexBuffer(const float data[], unsigned int size, unsigned int drawType)
    : drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &vboID));
    PTGLEC(glBindBuffer(GL_ARRAY_BUFFER, vboID));
    PTGLEC(glBufferData(GL_ARRAY_BUFFER, size, data, drawType));
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

void VertexBuffer::bindBuffer() const
{
    PTGLEC(glBindBuffer(GL_ARRAY_BUFFER, vboID));
}

void VertexBuffer::unbindBuffer() const
{
    PTGLEC(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::updateData(const std::vector<float>& data)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GL_FLOAT), data.data(), drawType));
}

void VertexBuffer::updateData(const float data[], unsigned int size)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ARRAY_BUFFER, size, data, drawType));
}

void VertexBuffer::remove()
{
    PTGLEC(glDeleteBuffers(1, &vboID));
}

VertexBuffer::~VertexBuffer()
{

}
}
