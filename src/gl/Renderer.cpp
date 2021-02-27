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

}
