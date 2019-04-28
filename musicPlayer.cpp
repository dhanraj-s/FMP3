#include "musicPlayer.h"

void musicPlayer::play()
{
    m_sys.playMusic(m_music, m_ch);
    playing = true;
    paused = (paused)? !paused : paused; //keep 'playing' and 'paused' in sync
}

void musicPlayer::stop()
{
    m_ch.stopChannel();
    playing = false;
    paused = (paused)? !paused : paused; //keep 'playing' and 'paused' in sync
}

void musicPlayer::pause()
{
    if(paused == false && playing == true){
        m_ch.switchPause();
        paused = true;
    }
}

void musicPlayer::resume()
{
    if(paused == true && playing == true){
        m_ch.switchPause();
        paused = false;
    }
}

void musicPlayer::setVolume(float v)
{
    if(v < 0 || v > 100) {
        std::cerr << "Invalid volume. Enter a value between 0 and 100 (inclusive)\n";
        return;
    }
    m_ch.setVolume(v / 100);
}