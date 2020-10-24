#ifndef PETROLEUM_H
#define PETROLEUM_H


#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <glm/glm.hpp>



#define PT_VSYNC 0
#define PT_MSAA 8

#define PT_SHADER_XY 0
#define PT_SHADER_XYUV 1
#define PT_SHADER_XYA 2
#define PT_SHADER_XYAUV 3
#define PT_SHADER_XYB 4
#define PT_SHADER_XYBUV 5
#define PT_SHADER_XYRGB 6
#define PT_SHADER_XYRGBUV 7
#define PT_SHADER_XYRGBA 8
#define PT_SHADER_XYRGBAUV 9

#define PT_BLACK 0
#define PT_WHITE 1
#define PT_SKY_BLUE 2
#define PT_PETROL 3
#define PT_LIGHT_GREY 4
#define PT_GREY 5
#define PT_DARK_GREY 6

namespace PT
{

// FILE MANAGEMENT
void setDataDir(const char* directory);
void createDataFolder(const char* directory);
void createFolder(const char* directory);
struct Config
{
    unsigned int opengl_major;
    unsigned int opengl_minor;
    bool vsync;
    unsigned int msaa;
    bool fullscreen;
    unsigned int clear_colour;
    bool enable_blending;
};
Config parseConfig();


// CORE
void initGL();
void initGL(Config cfg);
void doEvents();


// ERROR HANDLING
void clearGlErrors();
void getGlErrors();


struct Input
{
        bool ctrlHeld {false};
        bool spaceHeld {false};
        bool shiftHeld {false};
        bool wHeld {false};
        bool aHeld {false};
        bool sHeld {false};
        bool dHeld {false};
        bool downHeld {false};
        bool leftHeld {false};
        bool rightHeld {false};
        bool upHeld {false};
        bool kp2Held {false};
        bool kp4Held {false};
        bool kp5Held {false};
        bool kp6Held {false};
        bool kp8Held {false};
};


class Window
{
    public:
        Window();
        Window(Config cfg);
        bool shouldRun() const;
        const Input& getInputs() const;
        void update();
        void changeTitle(const std::string newTitle);
        void makeContextCurrent();
        inline GLFWwindow* getGLFWWindow() { return window; }

        virtual ~Window();

    protected:

    private:
        GLFWwindow* window;
        void init();

        int fps, seconds, avg_fps, last_fps;
        long int tn, ta;
        std::string title;
};


class IndexBuffer
{
    public:
        IndexBuffer(const std::vector<unsigned int>& data);
        IndexBuffer(const std::vector<unsigned short>& data);
        IndexBuffer(const std::vector<unsigned char>& data);
        IndexBuffer(const unsigned int data[], unsigned int size);
        IndexBuffer(const unsigned short data[], unsigned int size);
        IndexBuffer(const unsigned char data[], unsigned int size);
        void bindBuffer() const;
        void unbindBuffer() const;
        inline unsigned int getIboID() const { return iboID; }
        inline unsigned int getCount() const { return count; }
        inline unsigned int getDataType() const { return dataType; }
        ~IndexBuffer();

    protected:

    private:
        unsigned int iboID;
        unsigned int dataType;
        long unsigned int count;
};


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


struct SourcePackage
{
    std::string vertex;
    std::string fragment;
};



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


class Shader
{
    public:
        static std::string readFromFile(const char* filePath);

        Shader(unsigned int shaderName);
        Shader(SourcePackage srcpkg);
        ~Shader();

        void bindShader() const;
        void unbindShader() const;

        void setUniform1i(const std::string& name, int v0);
        void setUniform2i(const std::string& name, int v0, int v1);
        void setUniform3i(const std::string& name, int v0, int v1, int v2);
        void setUniform4i(const std::string& name, int v0, int v1, int v2, int v3);
        void setUniform1f(const std::string& name, float v0);
        void setUniform2f(const std::string& name, float v0, float v1);
        void setUniform3f(const std::string& name, float v0, float v1, float v2);
        void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
        void setUniformMat2f(const std::string& name, const glm::mat2& mat);
        void setUniformMat3f(const std::string& name, const glm::mat3& mat);
        void setUniformMat4f(const std::string& name, const glm::mat4& mat);

        inline VertexBufferLayout getLayout() { return layout; }


    protected:

    private:
        unsigned int programID;
        VertexBufferLayout layout;
        VertexBufferLayout createLayout(std::string vertexSource);
        std::unordered_map<std::string, int> uniformLocationCache;
        unsigned int compileShader(const char* src, unsigned int type);
        int getUniformLocation(const std::string& name);
};

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


class Texture
{
    public:
        Texture(const std::string& path, const unsigned int& slot, unsigned int minFilter = GL_NEAREST_MIPMAP_NEAREST, unsigned int magFilter = GL_NEAREST);
        ~Texture();

        void bindTexture(unsigned int slot = 0) const;
        void unbindTexture() const;

        inline int getWidth() const {return width;}
        inline int getHeight() const {return height;}
        inline int getBPP() const {return bPP;}

    protected:

    private:
        unsigned int texID;
        std::string filePath;
        unsigned char* localBuffer;
        int width, height, bPP;
};


// RENDERER
void clearScreen();
void drawVA(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader);
void drawTexture(const VertexArray& vao, const IndexBuffer& ibo, Shader& shader, int texSlot);


// Template vertices
inline std::vector<float> tVertsEquilateralXY(float posX, float posY, float size, bool centred = true)
{
    if (centred)
        return std::vector<float>() =
        {
            posX - size / 2,    posY - (float)sqrt(size*size - size*size/4) / 2,
            posX,               posY + (float)sqrt(size*size - size*size/4) / 2,
            posX + size / 2,    posY - (float)sqrt(size*size - size*size/4) / 2
        };
    return std::vector<float>() =
    {
        posX,               posY,
        posX + size / 2,    posY + (float)sqrt(size*size - size*size/4),
        posX + size,        posY
    };
}

inline std::vector<float> tVertsEquilateralXYUV(float posX, float posY, float size, bool centred = true)
{
    if (centred)
        return std::vector<float>() =
        {
            posX - size / 2,    posY - (float)sqrt(size*size - size*size/4) / 2, 0.0f, 0.0f,
            posX,               posY + (float)sqrt(size*size - size*size/4) / 2, 0.5f, 1.0f,
            posX + size / 2,    posY - (float)sqrt(size*size - size*size/4) / 2, 1.0f, 0.0f
        };
    return std::vector<float>() =
    {
        posX,               posY,                                           0.0f, 0.0f,
        posX + size / 2,    posY + (float)sqrt(size*size - size*size/4),    0.5f, 1.0f,
        posX + size,        posY,                                           1.0f, 0.0f
    };
}

inline std::vector<float> tVertsSquareXY(float posX, float posY, float size, bool centred = false)
{
    if (centred)
        return std::vector<float>() =
        {
            posX - size/2, posY - size/2,
            posX - size/2, posY + size/2,
            posX + size/2, posY + size/2,
            posX + size/2, posY - size/2
        };
    return std::vector<float>() =
    {
        posX,           posY - size,
        posX,           posY,
        posX + size,    posY,
        posX + size,    posY - size
    };
}

inline std::vector<float> tVertsSquareXYUV(float posX, float posY, float size, bool centred = false)
{
    if (centred)
        return std::vector<float>() =
        {
            posX - size/2, posY - size/2, 0.0f, 0.0f,
            posX - size/2, posY + size/2, 0.0f, 1.0f,
            posX + size/2, posY + size/2, 1.0f, 1.0f,
            posX + size/2, posY - size/2, 1.0f, 0.0f
        };
    return std::vector<float>() =
    {
        posX,           posY - size, 0.0f, 0.0f,
        posX,           posY,        0.0f, 1.0f,
        posX + size,    posY,        1.0f, 1.0f,
        posX + size,    posY - size, 1.0f, 0.0f
    };
}

template <typename T>
inline std::vector<T> tIndsTriangles(T count)
{
    std::vector<T> result(3 * count);
    for (int i {0}; i < count; ++i)
    {
        result.push_back(0 + 3*i);
        result.push_back(1 + 3*i);
        result.push_back(2 + 3*i);
    }
    return result;
}

template <typename T>
inline std::vector<T> tIndsSquares(T count)
{
    std::vector<T> result(6 * count);
    for (int i {0}; i < count; ++i)
    {
        result.push_back(0 + 4*i);
        result.push_back(1 + 4*i);
        result.push_back(2 + 4*i);

        result.push_back(0 + 4*i);
        result.push_back(2 + 4*i);
        result.push_back(3 + 4*i);
    }
    return result;
}
}


#endif // PETROLEUM_H
