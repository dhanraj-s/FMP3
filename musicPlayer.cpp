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
