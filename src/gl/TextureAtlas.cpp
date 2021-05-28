#include "../../Petroleum.h"

namespace PT
{

TextureAtlas::TextureAtlas(const std::string& path, const unsigned int& slot, unsigned int minFilter, unsigned int magFilter)
    : Texture(path, slot, minFilter, magFilter), indexSize(1.0f)
{

}

TextureAtlas::TextureAtlas(unsigned long int bufferLength, const unsigned char* imageBuffer, const unsigned int& slot, unsigned int minFilter, unsigned int magFilter)
    : Texture(bufferLength, imageBuffer, slot, minFilter, magFilter), indexSize(1.0f)
{

}

}
