#include "../../Petroleum.h"
#include "../../include/dr_wav.h"
#include "../../include/dr_flac.h"
#include <AL/al.h>
#include <cstring>

namespace PT
{
std::string fileEnding(std::string file)
{
    unsigned long i;
    for (i = file.length() - 1; i >= 0; --i)
        if (file[i] == '.')
            break;
    std::string result;
    for (; i < file.length(); ++i)
        result += file[i];
    return result;
}
Audio::Audio(const char* file)
{
    std::string fileType = fileEnding(file);
    if (fileType == ".wav")
    {
        int16_t* pSampleData = drwav_open_file_and_read_pcm_frames_s16(file, &channels, &sampleRate, &totalPCMFrameCount, nullptr);
        data.resize(totalPCMFrameCount * channels);
        std::memcpy(data.data(), pSampleData, data.size() * sizeof(int16_t));
        drwav_free(pSampleData, NULL);
    }
    else if (fileType == ".flac")
    {
        int16_t* pSampleData = drflac_open_file_and_read_pcm_frames_s16(file, &channels, &sampleRate, &totalPCMFrameCount, nullptr);
        data.resize(totalPCMFrameCount * channels);
        std::memcpy(data.data(), pSampleData, data.size() * sizeof(int16_t));
        drflac_free(pSampleData, NULL);
    }
    else
        fprintf(stderr, "(Petroleum) ERROR: Unsupported container '%s', must be either '.wav', or '.flac'\n", fileType.c_str());

    if (data.empty())
    {
        fprintf(stderr, "(Petroleum) ERROR: Couldn't load audio file '%s'!\n", file);
        return;
    }


    PTALEC(alGenBuffers(1, &soundBuffer));
    PTALEC(alBufferData(soundBuffer, channels > 1 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, data.data(), data.size() * sizeof(int16_t), sampleRate));

    PTALEC(alGenSources(1, &soundSource));
    PTALEC(alSource3f(soundSource, AL_POSITION, 0.0f, 0.0f, 0.0f));
    PTALEC(alSource3f(soundSource, AL_VELOCITY, 0.0f, 0.0f, 0.0f));
    PTALEC(alSourcef(soundSource, AL_PITCH, 1.0f));
    PTALEC(alSourcef(soundSource, AL_GAIN, 1.0f));
    PTALEC(alSourcei(soundSource, AL_LOOPING, AL_FALSE));
    PTALEC(alSourcei(soundSource, AL_BUFFER, soundBuffer));
}

void Audio::play()
{
    PTALEC(alSourcePlay(soundSource));
}

void Audio::stop()
{
    PTALEC(alSourceStop(soundSource));
}

void Audio::setPos(float x, float y, float z)
{
    if (channels > 1)
        fprintf(stderr, "(Petroleum) WARNING: Trying to set the position of a stereo audio source. This has no effect!\n");
    PTALEC(alSource3f(soundSource, AL_POSITION, x, y, z));
}

bool Audio::isPlaying()
{
    int sourceState;
    PTALEC(alGetSourcei(soundSource, AL_SOURCE_STATE, &sourceState));
    return sourceState == AL_PLAYING;
}

Audio::~Audio()
{
    PTALEC(alDeleteSources(1, &soundSource));
    PTALEC(alDeleteBuffers(1, &soundBuffer));
}

}
