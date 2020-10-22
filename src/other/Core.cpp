#include "../../Petroleum.h"

namespace PT
{
void init()
{
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "(Petroleum) ERROR: There was an error initilising GLEW! code %d\n", glewInit());
        if (glewInit() == 1)
            fprintf(stderr, "(Petroleum) INFO: PT::init() must be run AFTER at least one PT::Window was created!!\n");
    }
}
}
