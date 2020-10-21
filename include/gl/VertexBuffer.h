#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <vector>


class VertexBuffer
{
    public:
        VertexBuffer(const std::vector<float>& data);
        VertexBuffer(const float data[], unsigned int size);
        void bindBuffer() const;
        void unbindBuffer() const;
        inline unsigned int getVboID() const { return vboID; }
        ~VertexBuffer();

    protected:

    private:
        unsigned int vboID;
};

#endif // VERTEXBUFFER_H
