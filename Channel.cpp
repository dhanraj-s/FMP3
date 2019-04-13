#include <iostream>

#include "Channel.h"
#include "fmodException.h"

/* NOTE: Channel functions return FMOD_ERR_INVALID_HANDLE if audio is not playing. Checking for
this error code checks whether audio is playing or not. Please refer to the FMOD Core API docs 
for more information. */

float Channel::getVolume()
{
    float volume {INVALID_VOLUME};
    result = m_channel -> getVolume(&volume);
    if(result != FMOD_OK && result != FMOD_ERR_INVALID_HANDLE)
        throw fmodException("ChannelControl::getVolume(): ", result);

    return volume;
}

void Channel::setVolume(float vol)
{
    result = m_channel -> setVolume(vol);
    if(result != FMOD_OK && result != FMOD_ERR_INVALID_HANDLE)
        throw fmodException("ChannelControl::setVolume(): ", result);

    else if(result == FMOD_ERR_INVALID_HANDLE){
        std::cerr << "No audio playing!\n";
        return;
    }
}

bool Channel::isPlaying()
{
    bool playing {false};
    result = m_channel -> isPlaying(&playing);
    if(result != FMOD_OK && result != FMOD_ERR_INVALID_HANDLE)
        throw fmodException("ChannelControl::isPlaying(): ", result);
    return playing;
}

void Channel::stopChannel()
{
    result = m_channel -> stop();
    if(result != FMOD_OK && result != FMOD_ERR_INVALID_HANDLE)
        throw fmodException("ChannelControl::stop(): ", result);

    else if(result == FMOD_ERR_INVALID_HANDLE){
        std::cerr << "Channel already stopped!\n";
        return;
    }
}

bool Channel::isPaused()
{
    bool paused {false};
    result = m_channel -> getPaused(&paused);
    if(result != FMOD_OK && result != FMOD_ERR_INVALID_HANDLE)
        throw fmodException("ChannelControl::getPaused(): ", result);
    return paused;
}

void Channel::switchPause()
{
    if(isPlaying())
        result = m_channel -> setPaused(!isPaused());
    else
        return;

    if(result != FMOD_OK)
        throw fmodException("ChannelControl::setPaused(): ", result);
}
