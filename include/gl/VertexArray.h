#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "gl/VertexBuffer.h"
#include "gl/VertexBufferLayout.h"


class VertexArray
{
    public:
        VertexArray();
        void addBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout);
        void bindArray() const;
        void unbindArray() const;
        ~VertexArray();

    protected:

    private:
        unsigned int vaoID;
};

#endif // VERTEXARRAY_H
