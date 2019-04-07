#ifndef CHANNEL
#define CHANNEL

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

constexpr float INVALID_VOLUME = -1;

struct Channel
{
private:
    FMOD_RESULT result;
public:
    FMOD::Channel *m_channel {nullptr};

    bool isPlaying();
    void stopChannel();
    bool isPaused();
    void switchPause();
    float getVolume();
    void setVolume(float vol);
};

#endif //CHANNEL