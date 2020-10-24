#include "../../Petroleum.h"

namespace PT
{

void clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawVA(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader)
{
    shader.bindShader();
    vao.bindArray();
    ibo.bindBuffer();

    glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr);

    #ifdef DEBUG
        shader.unbindShader();
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

void drawTexture(const VertexArray& vao, const IndexBuffer& ibo, Shader& shader, int texSlot)
{
    shader.bindShader();
    vao.bindArray();
    ibo.bindBuffer();

    shader.setUniform1i("texSlot", texSlot);
    glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr);
    #ifdef DEBUG
        shader.unbindShader();
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

}
