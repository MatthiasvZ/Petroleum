#ifndef RENDERER_H
#define RENDERER_H

#include "gl/VertexArray.h"
#include "gl/IndexBuffer.h"
#include "gl/Shader.h"

class Renderer
{
    public:
        Renderer();
        void clear() const;
        void drawVA(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const;
        void drawTexture(const VertexArray& vao, const IndexBuffer& ibo, Shader& shader, int texSlot);
        ~Renderer();

    protected:

    private:
};

#endif // RENDERER_H
