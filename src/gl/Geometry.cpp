#include "../../Petroleum.h"

namespace PT
{

std::vector<float> tVertsEquilateralXY(float posX, float posY, float size, bool centred)
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

std::vector<float> tVertsEquilateralXYUV(float posX, float posY, float size, bool centred)
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

std::vector<float> tVertsSquareXY(float posX, float posY, float size, bool centred)
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

std::vector<float> tVertsSquareXYUV(float posX, float posY, float size, bool centred)
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

std::vector<float> tVertsCubeXYZ(float posX, float posY, float posZ, float size, bool centred, bool shortened)
{
    if (shortened)
    {
        if (centred)
            return std::vector<float>() =
            {
                posX - size/2, posY - size/2, posZ - size/2,
                posX - size/2, posY - size/2, posZ + size/2,
                posX - size/2, posY + size/2, posZ - size/2,
                posX - size/2, posY + size/2, posZ + size/2,
                posX + size/2, posY - size/2, posZ - size/2,
                posX + size/2, posY - size/2, posZ + size/2,
                posX + size/2, posY + size/2, posZ - size/2,
                posX + size/2, posY + size/2, posZ + size/2,
            };
        return std::vector<float>() =
        {
            posX,        posY - size, posZ - size,
            posX,        posY - size, posZ,
            posX,        posY,        posZ - size,
            posX,        posY,        posZ,
            posX + size, posY - size, posZ - size,
            posX + size, posY - size, posZ,
            posX + size, posY,        posZ - size,
            posX + size, posY,        posZ
        };
    }
    if (centred)
    {
        return std::vector<float>() =
        {
            posX - size/2, posY - size/2, posZ - size/2,
            posX - size/2, posY + size/2, posZ - size/2,
            posX + size/2, posY + size/2, posZ - size/2,
            posX + size/2, posY - size/2, posZ - size/2,

            posX - size/2, posY - size/2, posZ + size/2,
            posX - size/2, posY + size/2, posZ + size/2,
            posX - size/2, posY + size/2, posZ - size/2,
            posX - size/2, posY - size/2, posZ - size/2,

            posX + size/2, posY - size/2, posZ + size/2,
            posX + size/2, posY + size/2, posZ + size/2,
            posX - size/2, posY + size/2, posZ + size/2,
            posX - size/2, posY - size/2, posZ + size/2,

            posX + size/2, posY - size/2, posZ - size/2,
            posX + size/2, posY + size/2, posZ - size/2,
            posX + size/2, posY + size/2, posZ + size/2,
            posX + size/2, posY - size/2, posZ + size/2,

            posX - size/2, posY + size/2, posZ - size/2,
            posX - size/2, posY + size/2, posZ + size/2,
            posX + size/2, posY + size/2, posZ + size/2,
            posX + size/2, posY + size/2, posZ - size/2,

            posX - size/2, posY - size/2, posZ + size/2,
            posX - size/2, posY - size/2, posZ - size/2,
            posX + size/2, posY - size/2, posZ - size/2,
            posX + size/2, posY - size/2, posZ + size/2
        };
    }
    return std::vector<float>() =
    {
        posX, posY - size, posZ - size,
        posX, posY, posZ - size,
        posX + size, posY, posZ - size,
        posX + size, posY - size, posZ - size,

        posX, posY - size, posZ,
        posX, posY, posZ,
        posX, posY, posZ - size,
        posX, posY - size, posZ - size,

        posX + size, posY - size, posZ,
        posX + size, posY, posZ,
        posX, posY, posZ,
        posX, posY - size, posZ,

        posX + size, posY - size, posZ - size,
        posX + size, posY, posZ - size,
        posX + size, posY, posZ,
        posX + size, posY - size, posZ,

        posX, posY, posZ - size,
        posX, posY, posZ,
        posX + size, posY, posZ,
        posX + size, posY, posZ - size,

        posX, posY - size, posZ,
        posX, posY - size, posZ - size,
        posX + size, posY - size, posZ - size,
        posX + size, posY - size, posZ
    };
}

std::vector<float> tVertsCubeXYZUV(float posX, float posY, float posZ, float size, bool centred, bool shortened)
{
    if (shortened)
    {
        if (centred)
            return std::vector<float>() =
            {
                posX - size/2, posY - size/2, posZ - size/2, 1.0f, 0.0f,
                posX - size/2, posY - size/2, posZ + size/2, 0.0f, 0.0f,
                posX - size/2, posY + size/2, posZ - size/2, 1.0f, 1.0f,
                posX - size/2, posY + size/2, posZ + size/2, 0.0f, 1.0f,
                posX + size/2, posY - size/2, posZ - size/2, 0.0f, 0.0f,
                posX + size/2, posY - size/2, posZ + size/2, 1.0f, 0.0f,
                posX + size/2, posY + size/2, posZ - size/2, 0.0f, 1.0f,
                posX + size/2, posY + size/2, posZ + size/2, 1.0f, 1.0f,

                posX - size/2, posY - size/2, posZ - size/2, 0.0f, 1.0f,
                posX + size/2, posY - size/2, posZ - size/2, 1.0f, 1.0f,
                posX - size/2, posY + size/2, posZ - size/2, 0.0f, 0.0f,
                posX + size/2, posY + size/2, posZ - size/2, 1.0f, 0.0f
            };
        return std::vector<float>() =
        {
            posX,        posY - size, posZ - size,  1.0f, 0.0f,
            posX,        posY - size, posZ,         0.0f, 0.0f,
            posX,        posY,        posZ - size,  1.0f, 1.0f,
            posX,        posY,        posZ,         0.0f, 1.0f,
            posX + size, posY - size, posZ - size,  0.0f, 0.0f,
            posX + size, posY - size, posZ,         1.0f, 0.0f,
            posX + size, posY,        posZ - size,  0.0f, 1.0f,
            posX + size, posY,        posZ,         1.0f, 1.0f,

            posX,        posY - size, posZ - size,  0.0f, 1.0f,
            posX + size, posY - size, posZ - size,  1.0f, 1.0f,
            posX,        posY,        posZ - size,  0.0f, 0.0f,
            posX + size, posY,        posZ - size,  1.0f, 0.0f
        };
    }
    if (centred)
    {
        return std::vector<float>() =
        {
            posX - size/2, posY - size/2, posZ - size/2, 0.0f, 0.0f,
            posX - size/2, posY + size/2, posZ - size/2, 0.0f, 1.0f,
            posX + size/2, posY + size/2, posZ - size/2, 1.0f, 1.0f,
            posX + size/2, posY - size/2, posZ - size/2, 1.0f, 0.0f,

            posX - size/2, posY - size/2, posZ + size/2, 0.0f, 0.0f,
            posX - size/2, posY + size/2, posZ + size/2, 0.0f, 1.0f,
            posX - size/2, posY + size/2, posZ - size/2, 1.0f, 1.0f,
            posX - size/2, posY - size/2, posZ - size/2, 1.0f, 0.0f,

            posX + size/2, posY - size/2, posZ + size/2, 0.0f, 0.0f,
            posX + size/2, posY + size/2, posZ + size/2, 0.0f, 1.0f,
            posX - size/2, posY + size/2, posZ + size/2, 1.0f, 1.0f,
            posX - size/2, posY - size/2, posZ + size/2, 1.0f, 0.0f,

            posX + size/2, posY - size/2, posZ - size/2, 0.0f, 0.0f,
            posX + size/2, posY + size/2, posZ - size/2, 0.0f, 1.0f,
            posX + size/2, posY + size/2, posZ + size/2, 1.0f, 1.0f,
            posX + size/2, posY - size/2, posZ + size/2, 1.0f, 0.0f,

            posX - size/2, posY + size/2, posZ - size/2, 0.0f, 0.0f,
            posX - size/2, posY + size/2, posZ + size/2, 0.0f, 1.0f,
            posX + size/2, posY + size/2, posZ + size/2, 1.0f, 1.0f,
            posX + size/2, posY + size/2, posZ - size/2, 1.0f, 0.0f,

            posX - size/2, posY - size/2, posZ + size/2, 0.0f, 0.0f,
            posX - size/2, posY - size/2, posZ - size/2, 0.0f, 1.0f,
            posX + size/2, posY - size/2, posZ - size/2, 1.0f, 1.0f,
            posX + size/2, posY - size/2, posZ + size/2, 1.0f, 0.0f
        };
    }
    return std::vector<float>() =
    {
        posX, posY - size, posZ - size, 0.0f, 0.0f,
        posX, posY, posZ - size, 0.0f, 1.0f,
        posX + size, posY, posZ - size, 1.0f, 1.0f,
        posX + size, posY - size, posZ - size, 1.0f, 0.0f,

        posX, posY - size, posZ, 0.0f, 0.0f,
        posX, posY, posZ, 0.0f, 1.0f,
        posX, posY, posZ - size, 1.0f, 1.0f,
        posX, posY - size, posZ - size, 1.0f, 0.0f,

        posX + size, posY - size, posZ, 0.0f, 0.0f,
        posX + size, posY, posZ, 0.0f, 1.0f,
        posX, posY, posZ, 1.0f, 1.0f,
        posX, posY - size, posZ, 1.0f, 0.0f,

        posX + size, posY - size, posZ - size, 0.0f, 0.0f,
        posX + size, posY, posZ - size, 0.0f, 1.0f,
        posX + size, posY, posZ, 1.0f, 1.0f,
        posX + size, posY - size, posZ, 1.0f, 0.0f,

        posX, posY, posZ - size, 0.0f, 0.0f,
        posX, posY, posZ, 0.0f, 1.0f,
        posX + size, posY, posZ, 1.0f, 1.0f,
        posX + size, posY, posZ - size, 1.0f, 0.0f,

        posX, posY - size, posZ, 0.0f, 0.0f,
        posX, posY - size, posZ - size, 0.0f, 1.0f,
        posX + size, posY - size, posZ - size, 1.0f, 1.0f,
        posX + size, posY - size, posZ, 1.0f, 0.0f
    };
}

std::vector<float> xyToXyz(const std::vector<float>& vertices2d, unsigned int vertexSize, float z)
{
    std::vector<float> result {vertices2d};
    for (unsigned long i {2}; i < vertices2d.size() + vertices2d.size() / vertexSize; i += vertexSize + 1)
    {
        result.insert(result.begin() + i, z);
    }
    return result;
}

}
