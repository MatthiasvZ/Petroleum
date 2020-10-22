#include "../../Petroleum.h"

namespace PT
{

Renderer::Renderer()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
        fprintf(stderr, "Error during glewInit(), %d\n", glewInit());
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Status: Using OpenGL %s\n", glGetString(GL_VERSION));

    glFrontFace(GL_CW);

    // Background colours
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black
    // glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White
    // glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // Sky blue
    // glClearColor(0.0f, 0.12f, 0.16f, 1.0f); // Petrol blue


    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    #if GRAPHICS_MSAA
    glEnable(GL_MULTISAMPLE);
    #endif // GRAPHICS_MSAA
}

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawVA(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
    shader.bindShader();
    vao.bindArray();
    ibo.bindBuffer();

    glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr);
    #ifdef DEBUG
        //shader.unbindShader();
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

void Renderer::drawTexture(const VertexArray& vao, const IndexBuffer& ibo, Shader& shader, int texSlot)
{
    shader.bindShader();
    vao.bindArray();
    ibo.bindBuffer();

    shader.setUniform1i("texSlot", texSlot);
    glDrawElements(GL_TRIANGLES, ibo.getCount(), ibo.getDataType(), nullptr);
    #ifdef DEBUG
        //shader.unbindShader();
        vao.unbindArray();
        ibo.unbindBuffer();
    #endif // DEBUG
}

Renderer::~Renderer()
{
    //dtor
}
}
