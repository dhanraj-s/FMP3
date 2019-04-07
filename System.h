#ifndef SYSTEM
#define SYSTEM

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <string>

#include "Sound.h"
#include "Channel.h"

class System
{
    FMOD::System *m_system {nullptr};
    void cleanUpSystem();

    FMOD_RESULT result;
public:
    System(const System&) = delete;
    System(System&&) = delete;

    void loadMusic(const std::string& songName, Sound& sound);
    void playMusic(const Sound& sound, Channel& channel);

    System();
    ~System();
};

#endif //SYSTEM