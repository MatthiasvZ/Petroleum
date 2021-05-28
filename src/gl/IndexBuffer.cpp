#include "../../Petroleum.h"

namespace PT
{

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& data, unsigned int drawType)
    : dataType {GL_UNSIGNED_INT}, count {data.size()}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_INT), data.data(), drawType));
    this->data = data.data();
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const std::vector<unsigned short>& data, unsigned int drawType)
    : dataType {GL_UNSIGNED_SHORT}, count {data.size()}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_SHORT), data.data(), drawType));
    this->data = data.data();
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const std::vector<unsigned char>& data, unsigned int drawType)
    : dataType {GL_UNSIGNED_BYTE}, count {data.size()}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_BYTE), data.data(), drawType));
    this->data = data.data();
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned int data[], unsigned int size, unsigned int drawType)
    : dataType {GL_UNSIGNED_INT}, count {size / sizeof(GL_UNSIGNED_INT)}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned short data[], unsigned int size, unsigned int drawType)
    : dataType {GL_UNSIGNED_SHORT}, count {size / sizeof(GL_UNSIGNED_SHORT)}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

IndexBuffer::IndexBuffer(const unsigned char data[], unsigned int size, unsigned int drawType)
    : dataType {GL_UNSIGNED_BYTE}, count {size / sizeof(GL_UNSIGNED_BYTE)}, drawType(drawType)
{
    PTGLEC(glGenBuffers(1, &iboID));
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
    #ifdef DEBUG
    unbindBuffer();
    #endif // DEBUG
}

void IndexBuffer::bindBuffer() const
{
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID));
}

void IndexBuffer::unbindBuffer() const
{
    PTGLEC(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::updateData(const std::vector<unsigned int>& data)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_INT), data.data(), drawType));
    this->data = data.data();
}

void IndexBuffer::updateData(const std::vector<unsigned short>& data)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_SHORT), data.data(), drawType));
    this->data = data.data();
}

void IndexBuffer::updateData(const std::vector<unsigned char>& data)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_UNSIGNED_BYTE), data.data(), drawType));
    this->data = data.data();
}

void IndexBuffer::updateData(const unsigned int data[], unsigned int size)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
}

void IndexBuffer::updateData(const unsigned short data[], unsigned int size)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
}

void IndexBuffer::updateData(const unsigned char data[], unsigned int size)
{
    bindBuffer();
    PTGLEC(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType));
    this->data = data;
}


void IndexBuffer::remove()
{
    PTGLEC(glDeleteBuffers(1, &iboID));
}

IndexBuffer::~IndexBuffer()
{

}
}
