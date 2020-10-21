#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <vector>


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

#endif // INDEXBUFFER_H
