#ifndef MUSICPLAYER
#define MUSICPLAYER

#include "System.h"
#include "Sound.h"
#include "Channel.h"
#include "fmodException.h"

#include <string>
#include <iostream>

class musicPlayer
{
    //IMPORTANT : Members must be declared in this order only!
    System m_sys;
    Sound m_music;
    Channel m_ch;

    bool paused {false};
    bool playing {false};
public:
    musicPlayer(const std::string& file) {m_sys.loadMusic(file, m_music);}

    void play();
    void stop();

    void pause();
    void resume();

    //Volume is on a scale of 1 to 100
    float getVolume() {return 100 * m_ch.getVolume();}
    void setVolume(float v) {m_ch.setVolume(v / 100);}

    musicPlayer(const musicPlayer&) = delete;
    musicPlayer(musicPlayer&&) = delete;

    static constexpr float INVALID_VOLUME = 100 * Channel::INVALID_VOLUME;
};

#endif //MUSICPLAYER