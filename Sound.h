#ifndef SOUND
#define SOUND

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>

struct Sound
{
private:
    FMOD_RESULT result;
public:        
    FMOD::Sound *m_sound {nullptr};

    ~Sound();
};

#endif //SOUND