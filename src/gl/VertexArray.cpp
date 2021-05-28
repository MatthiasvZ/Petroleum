#include "../../Petroleum.h"

namespace PT
{

VertexArray::VertexArray()
    : vbCount(0)
{
    PTGLEC(glGenVertexArrays(1, &vaoID));
}

void VertexArray::addBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout)
{
    PTGLEC(glBindVertexArray(vaoID));
    vbo.bindBuffer();
    const auto& elements = layout.getElements();
    unsigned long offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        PTGLEC(glEnableVertexAttribArray(i));
        PTGLEC(glVertexAttribPointer(i, element.count, element.type, \
                element.normalised, layout.getStride(), (const void*)offset));
        offset += element.count*VertexBufferElement::getSizeOfType(element.type);
    }
    ++vbCount;
    #ifdef DEBUG
    unbindArray();
    #endif // DEBUG
}

void VertexArray::bindArray() const
{
    PTGLEC(glBindVertexArray(vaoID));
}

void VertexArray::unbindArray() const
{
    PTGLEC(glBindVertexArray(0));
}

void VertexArray::remove()
{
    PTGLEC(glDeleteVertexArrays(1, &vaoID));
}

VertexArray::~VertexArray()
{

}
}
