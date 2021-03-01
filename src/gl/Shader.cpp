#include "../../Petroleum.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <string_view>

namespace PT
{

std::string readFromFile(const char* filePath)
{
    std::ifstream in(filePath, std::ios::in | std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    fprintf(stderr, "(Petroleum) ERROR: Couldn't read in shader file '%s'\n", filePath);
    return "";
}

VertexBufferLayout Shader::createLayout(std::string vertexSource)
{
    VertexBufferLayout result;
    std::istringstream stream(vertexSource);
    std::string line;
    while (getline(stream, line))
    {
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
        if (line[0] == 'i' && line[1] == 'n')
        {
            if (line[2] == 'f' && line[3] == 'l' && line[4] == 'o' && line[5] == 'a' && line[6] == 't')
                result.push(GL_FLOAT, 1);

            if (line[2] == 'v' && line[3] == 'e' && line[4] == 'c')
            {
                switch (line[5])
                {
                case '2':
                    result.push(GL_FLOAT, 2);
                    break;
                case '3':
                    result.push(GL_FLOAT, 3);
                    break;
                case '4':
                    result.push(GL_FLOAT, 4);
                    break;
                }
            }
        }
    }

    return result;
}

Shader::Shader(unsigned int shaderName)
{
    #include "../../include/DefaultShaders.h"
    layout = createLayout(static_cast<std::string>(vertSources[shaderName]));
    programID = glCreateProgram();
    unsigned int vertexShader = compileShader(static_cast<std::string>(vertSources[shaderName]).c_str(), GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(static_cast<std::string>(fragSources[shaderName % 10]).c_str(), GL_FRAGMENT_SHADER);

    PTGLEC(glAttachShader(programID, vertexShader));
    PTGLEC(glAttachShader(programID, fragmentShader));

    PTGLEC(glBindFragDataLocation(programID, 0, "outColour"));

    PTGLEC(glLinkProgram(programID));
    PTGLEC(glValidateProgram(programID));

    PTGLEC(glDeleteShader(vertexShader));
    PTGLEC(glDeleteShader(fragmentShader));
}

Shader::Shader(SourcePackage srcpkg)
{
    layout = createLayout(srcpkg.vertex);
    programID = glCreateProgram();
    unsigned int vertexShader = compileShader(srcpkg.vertex.c_str(), GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(srcpkg.fragment.c_str(), GL_FRAGMENT_SHADER);

    PTGLEC(glAttachShader(programID, vertexShader));
    PTGLEC(glAttachShader(programID, fragmentShader));

    PTGLEC(glBindFragDataLocation(programID, 0, "outColour"));

    PTGLEC(glLinkProgram(programID));
    PTGLEC(glValidateProgram(programID));

    PTGLEC(glDeleteShader(vertexShader));
    PTGLEC(glDeleteShader(fragmentShader));
}

unsigned int Shader::compileShader(const char* src, unsigned int type)
{
    unsigned int id = PTGLEC(glCreateShader(type));
    PTGLEC(glShaderSource(id, 1, &src, nullptr));
    PTGLEC(glCompileShader(id);

    int status;
    PTGLEC(glGetShaderiv(id, GL_COMPILE_STATUS, &status));
    if (status != GL_TRUE)
    {
        std::cerr << "(Petroleum) ERROR: Couldn't compile " << \
                (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << \
                "Shader!\n";
        char buffer[1024];
        PTGLEC(glGetShaderInfoLog(id, 1024, NULL, buffer));
        printf("%s", buffer);
    }
    return id;
}

void Shader::bindShader() const
{
    PTGLEC(glUseProgram(programID));
}

void Shader::unbindShader() const
{
    PTGLEC(glUseProgram(GL_FALSE));
}


void Shader::setUniform1i(const std::string& name, int v0)
{
    bindShader();
    PTGLEC(glUniform1i(getUniformLocation(name), v0)));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform2i(const std::string& name, int v0, int v1)
{
    bindShader();
    PTGLEC(glUniform2i(getUniformLocation(name), v0, v1));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform3i(const std::string& name, int v0, int v1, int v2)
{
    bindShader();
    PTGLEC(glUniform3i(getUniformLocation(name), v0, v1, v2));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform4i(const std::string& name, int v0, int v1, int v2, int v3)
{
    bindShader();
    PTGLEC(glUniform4i(getUniformLocation(name), v0, v1, v2, v3));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform1f(const std::string& name, float v0)
{
    bindShader();
    PTGLEC(glUniform1f(getUniformLocation(name), v0));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform2f(const std::string& name, float v0, float v1)
{
    bindShader();
    PTGLEC(glUniform2f(getUniformLocation(name), v0, v1));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform3f(const std::string& name, float v0, float v1, float v2)
{
    bindShader();
    PTGLEC(glUniform3f(getUniformLocation(name), v0, v1, v2));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    bindShader();
    PTGLEC(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniformMat2f(const std::string& name, const glm::mat2& mat)
{
    bindShader();
    PTGLEC(glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat)));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniformMat3f(const std::string& name, const glm::mat3& mat)
{
    bindShader();
    PTGLEC(glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat)));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

void Shader::setUniformMat4f(const std::string& name, const glm::mat4& mat)
{
    bindShader();
    PTGLEC(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat)));
    #ifdef DEBUG
        unbindShader();
    #endif // DEBUG
}

int Shader::getUniformLocation(const std::string& name)
{
    if (uniformLocationCache.find(name) != uniformLocationCache.end())
        return uniformLocationCache[name];

    int location = PTGLEC(glGetUniformLocation(programID, name.c_str()));
    #ifdef DEBUG
    if (location == -1)
        std::cerr << "Warning: uniform '" << name << "' does not exist or got removed due to being unused inside of the shader!" << std::endl;
    #endif
    uniformLocationCache[name] = location;
    return location;
}

Shader::~Shader()
{
    PTGLEC(glDeleteProgram(programID));
}

}
