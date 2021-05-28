#include "../../Petroleum.h"

namespace PT
{

void clearScreen()
{
    PTGLEC(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void drawVA(const VertexArray& vao, const IndexBuffer& ibo)
{
    vao.bindArray();
    ibo.bindBuffer();

    PTGLEC(glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr));

    #ifdef DEBUG
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

void drawVA(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader)
{
    shader.bindShader();
    vao.bindArray();
    ibo.bindBuffer();

    PTGLEC(glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr));

    #ifdef DEBUG
        shader.unbindShader();
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

void drawMultiVA(const VertexArray& vao, const IndexBuffer* const* ibo)
{
    vao.bindArray();
    ibo[0]->bindBuffer();

    GLsizei counts[vao.getVBCount()];
    const GLvoid* indices [vao.getVBCount()];
    for (unsigned int i = 0; i < vao.getVBCount(); ++i)
    {
        counts[i] = ibo[i]->getCount();
        indices[i] = ibo[i]->getDataPointer();
    }

    PTGLEC(glMultiDrawElements(GL_TRIANGLES, counts, ibo[0]->getDataType(), indices, vao.getVBCount()));

    #ifdef DEBUG
        vao.unbindArray();
        ibo[0]->unbindBuffer();
    #endif // DEBUG
}

void drawMultiVA(const VertexArray& vao, const IndexBuffer* const* ibo, const Shader& shader)
{
    shader.bindShader();
    vao.bindArray();
    ibo[0]->bindBuffer();

    GLsizei counts[vao.getVBCount()];
    const GLvoid* indices [vao.getVBCount()];
    for (unsigned int i = 0; i < vao.getVBCount(); ++i)
    {
        counts[i] = ibo[i]->getCount();
        indices[i] = ibo[i]->getDataPointer();
    }

    fprintf(stderr, "right before drawcall\n");
    PTGLEC(glMultiDrawElements(GL_TRIANGLES, counts, ibo[0]->getDataType(), indices, vao.getVBCount()));

    #ifdef DEBUG
        shader.unbindShader();
        vao.unbindArray();
        ibo[0]->unbindBuffer();
    #endif // DEBUG
}

}
