#include "../../Petroleum.h"

namespace PT
{

Texture::Texture(const std::string& path, const unsigned int& slot, unsigned int minFilter, unsigned int magFilter)
    : texID(slot), filePath(path), localBuffer(nullptr),
    width(0), height(0), bPP(0)
{
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load(path.c_str(), &width, &height, &bPP, 4);

    glActiveTexture(GL_TEXTURE0 + texID);
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
    if (minFilter == GL_NEAREST_MIPMAP_NEAREST || minFilter == GL_NEAREST_MIPMAP_LINEAR ||
        minFilter == GL_LINEAR_MIPMAP_NEAREST  || minFilter == GL_LINEAR_MIPMAP_LINEAR)
        glGenerateMipmap(GL_TEXTURE_2D);

    if (localBuffer)
        stbi_image_free(localBuffer);
}

void Texture::bindTexture(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texID);
}

void Texture::unbindTexture() const
{

}

Texture::~Texture()
{
    glDeleteTextures(1, &texID);
}
}
