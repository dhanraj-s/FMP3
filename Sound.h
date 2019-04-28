#ifndef SOUND
#define SOUND

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

struct Sound
//Instantiate only after System object is created.
{
private:
    FMOD_RESULT result;
public:        
    FMOD::Sound *m_sound {nullptr};
    ~Sound();

    Sound(const Sound&) = delete;
    Sound& operator = (const Sound&) = delete;
    Sound(Sound&&) = delete;
    Sound& operator = (Sound&&) = delete;
};

#endif //SOUND