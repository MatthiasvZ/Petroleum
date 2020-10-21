#include "gl/IndexBuffer.h"

#include <GL/glew.h>


IndexBuffer::IndexBuffer(const std::vector<unsigned int>& data)
    : dataType {GL_UNSIGNED_INT}, count {data.size()}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_INT), data.data(), GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const std::vector<unsigned short>& data)
    : dataType {GL_UNSIGNED_SHORT}, count {data.size()}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_SHORT), data.data(), GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const std::vector<unsigned char>& data)
    : dataType {GL_UNSIGNED_BYTE}, count {data.size()}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_BYTE), data.data(), GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned int data[], unsigned int size)
    : dataType {GL_UNSIGNED_INT}, count {size / sizeof(GL_UNSIGNED_INT)}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned short data[], unsigned int size)
    : dataType {GL_UNSIGNED_SHORT}, count {size / sizeof(GL_UNSIGNED_SHORT)}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned char data[], unsigned int size)
    : dataType {GL_UNSIGNED_BYTE}, count {size / sizeof(GL_UNSIGNED_BYTE)}
{
    glGenBuffers(1, &iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    #ifdef DEBUG
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #endif // DEBUG
}

void IndexBuffer::bindBuffer() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
}

void IndexBuffer::unbindBuffer() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &iboID);
}

