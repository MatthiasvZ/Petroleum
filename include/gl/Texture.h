#ifndef TEXTURE_H
#define TEXTURE_H

#include "Renderer.h"
#include <string>

class Texture
{
    public:
        Texture(const std::string& path, const unsigned int& slot);
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

#endif // TEXTURE_H
