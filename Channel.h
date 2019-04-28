#ifndef CHANNEL
#define CHANNEL

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

struct Channel
{
private:
    mutable FMOD_RESULT result;
    bool isPlaying();
    bool isPaused();
public:
    FMOD::Channel *m_channel {nullptr};

    static constexpr float INVALID_VOLUME = -1;
    
    void stopChannel();
    void switchPause();
    float getVolume() const;
    void setVolume(float vol);

    Channel(const Channel&) = delete;
    Channel(Channel&&) = delete;
    Channel& operator = (const Channel&) = delete;
    Channel& operator = (Channel&&) = delete;
};

#endif //CHANNEL