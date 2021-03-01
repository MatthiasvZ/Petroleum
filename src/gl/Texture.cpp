#include "../../Petroleum.h"
#include "../../include/stb_image.h"
#include <cstring>

namespace PT
{

Texture::Texture(const std::string& path, const unsigned int& slot, unsigned int minFilter, unsigned int magFilter)
    : texID(slot), filePath(path), localBuffer(nullptr),
    width(0), height(0), bPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load(path.c_str(), &width, &height, &bPP, 4);

    PTGLEC(glActiveTexture(GL_TEXTURE0 + texID));
    PTGLEC(glGenTextures(1, &texID));
    PTGLEC(glBindTexture(GL_TEXTURE_2D, texID));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    PTGLEC(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
    if (minFilter == GL_NEAREST_MIPMAP_NEAREST || minFilter == GL_NEAREST_MIPMAP_LINEAR ||
        minFilter == GL_LINEAR_MIPMAP_NEAREST  || minFilter == GL_LINEAR_MIPMAP_LINEAR)
        PTGLEC(glGenerateMipmap(GL_TEXTURE_2D));

    if (localBuffer)
        stbi_image_free(localBuffer);
}

Texture::Texture(unsigned long int length, const unsigned char* image, const unsigned int& slot, unsigned int minFilter, unsigned int magFilter)
    : texID(slot), localBuffer(nullptr), width(0), height(0), bPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load_from_memory(image, length, &width, &height, &bPP, 4);

    PTGLEC(glActiveTexture(GL_TEXTURE0 + texID));
    PTGLEC(glGenTextures(1, &texID));
    PTGLEC(glBindTexture(GL_TEXTURE_2D, texID));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    PTGLEC(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    PTGLEC(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
    if (minFilter == GL_NEAREST_MIPMAP_NEAREST || minFilter == GL_NEAREST_MIPMAP_LINEAR ||
        minFilter == GL_LINEAR_MIPMAP_NEAREST  || minFilter == GL_LINEAR_MIPMAP_LINEAR)
        PTGLEC(glGenerateMipmap(GL_TEXTURE_2D));

    if (localBuffer)
        stbi_image_free(localBuffer);
}

void Texture::bindTexture(unsigned int slot) const
{
    PTGLEC(glActiveTexture(GL_TEXTURE0 + slot));
    PTGLEC(glBindTexture(GL_TEXTURE_2D, texID));
}

void Texture::unbindTexture() const
{
    PTGLEC(glActiveTexture(GL_TEXTURE0));
}

Texture::~Texture()
{
    PTGLEC(glDeleteTextures(1, &texID));
}
}
