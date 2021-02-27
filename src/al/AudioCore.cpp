#include "../../Petroleum.h"
#include "AL/al.h"
#include "AL/alc.h"

/* Credit goes to "enigma tutorials" on YouTube, as his tutorial was a great help with adding sound support to PT.
    https://www.youtube.com/watch?v=WvND0djMcfE */

namespace PT
{

void initAL()
{
    const char* defaultDeviceString = alcGetString(nullptr, ALC_DEFAULT_DEVICE_SPECIFIER);
    ALCdevice* device = alcOpenDevice(defaultDeviceString);
    if (!device)
        fprintf(stderr, "(Petroleum) ERROR: Failed to get the default device for OpenAL!\n");

    ALCcontext* context = alcCreateContext(device, nullptr);
    if (!alcMakeContextCurrent(context))
        fprintf(stderr, "(Petroleum) ERROR: Failed to make the OpenAL context current!\n");
    getAlErrors();
}

}
