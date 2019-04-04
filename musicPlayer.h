#ifndef MUSICPLAYER
#define MUSICPLAYER

#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <iostream>
#include <string>

class musicPlayer
{
private:
    FMOD::System *m_system = nullptr;
    FMOD::Sound *m_sound = nullptr;
    FMOD::Channel *m_channel = nullptr;
    bool m_paused {false};
    bool m_playing {false};

    void errorHandle(const std::string& message, FMOD_RESULT eCode);

    FMOD_RESULT createSystem();
    FMOD_RESULT initSystem();
    
    void cleanUp();
    void freeSystem();
    void freeSound();

    void detectPlaying();
    //void detectPaused(); May very well be the next thing to do

public:
    musicPlayer(const std::string& name);
    musicPlayer(const musicPlayer&) = delete; //copy constructor deleted
    ~musicPlayer();

    FMOD_RESULT loadMusic(const std::string& name);

    void play();
    void stop();

    //void pause();
    //void resume(); //deal with interaction with play()/stop() later
};

#endif //MUSICPLAYER