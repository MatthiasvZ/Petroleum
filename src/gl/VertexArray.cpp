#include "../../Petroleum.h"

namespace PT
{

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &vaoID);
}

void VertexArray::addBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout)
{
    glBindVertexArray(vaoID);
    vbo.bindBuffer();
    const auto& elements = layout.getElements();
    unsigned long offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, \
                element.normalised, layout.getStride(), (const void*)offset);
        offset += element.count*VertexBufferElement::getSizeOfType(element.type);
    }
    #ifdef DEBUG
    glBindVertexArray(0);
    #endif // DEBUG
}

void VertexArray::bindArray() const
{
    glBindVertexArray(vaoID);
}

void VertexArray::unbindArray() const
{
    glBindVertexArray(0);
}

void VertexArray::remove()
{
    glDeleteVertexArrays(1, &vaoID);
}

VertexArray::~VertexArray()
{
    //glDeleteVertexArrays(1, &vaoID);
}
}
