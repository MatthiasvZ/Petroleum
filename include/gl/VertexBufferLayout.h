#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <vector>
#include "GL/glew.h"


struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalised;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_INT:            return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
    private:
        std::vector<VertexBufferElement> elements;
        unsigned int stride;

    public:
        VertexBufferLayout()
            : elements(), stride(0) {}

        void push(unsigned int attribType, unsigned int count)
        {
            elements.push_back({attribType, count, GL_FALSE});
            stride += count * VertexBufferElement::getSizeOfType(attribType);
        }

        inline const std::vector<VertexBufferElement>& getElements() const {return elements;}
        inline unsigned int getStride() const {return stride;}
    protected:
};

#endif // VERTEXBUFFERLAYOUT_H
