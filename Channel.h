#ifndef CHANNEL
#define CHANNEL

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

struct Channel
{
private:
    FMOD_RESULT result;
    bool isPlaying();
    bool isPaused();
public:
    FMOD::Channel *m_channel {nullptr};

    static constexpr float INVALID_VOLUME = -1;
    
    void stopChannel();
    void switchPause();
    float getVolume();
    void setVolume(float vol);
};

#endif //CHANNEL