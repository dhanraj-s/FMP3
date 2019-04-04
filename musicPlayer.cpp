#include "musicPlayer.h"

inline FMOD_RESULT musicPlayer::loadMusic(const std::string& name)
{
    return m_system -> createSound(name.c_str(), FMOD_CREATESTREAM | FMOD_LOOP_OFF, nullptr, &m_sound);
}

inline FMOD_RESULT musicPlayer::createSystem()
{
    return FMOD::System_Create(&m_system);
}

inline FMOD_RESULT musicPlayer::initSystem()
{
    return m_system -> init(32, FMOD_INIT_NORMAL, nullptr);
}

musicPlayer::musicPlayer(const std::string& name)
{
    errorHandle("createSystem() Error:", createSystem());

    errorHandle("initSystem() Error:", initSystem());

    errorHandle("loadMusic() Error:", loadMusic(name));
}

void musicPlayer::cleanUp()
{
    freeSound();
    freeSystem();
}

void musicPlayer::freeSystem()
{
    if(m_system == nullptr)
        return;
    
    FMOD_RESULT result = m_system -> release();
    if(result != FMOD_OK){
        std::cerr << "freeSystem() Error: " << FMOD_ErrorString(result) << "\n";
        return;
    }
    else 
        m_system = nullptr;
}

void musicPlayer::freeSound()
{
    if(m_sound == nullptr)
        return;
    
    FMOD_RESULT result = m_sound -> release();
    if(result != FMOD_OK){
        std::cerr << "freeSound() Error: " << FMOD_ErrorString(result) << "\n";
        return;
    }
    else
        m_sound = nullptr;
}

musicPlayer::~musicPlayer()
{
    cleanUp();

    m_channel = nullptr;
}

void musicPlayer::errorHandle(const std::string& message, FMOD_RESULT eCode)
{
    if(eCode != FMOD_OK){
        std::cerr << message << " " << FMOD_ErrorString(eCode) << "\n";
        cleanUp();
        exit(EXIT_FAILURE);
    }
    else 
        return;
}

void musicPlayer::play()
{
    detectPlaying();
    if(m_playing == false){
        FMOD_RESULT result = m_system -> playSound(m_sound, nullptr, m_paused, &m_channel); 
        errorHandle("play() Error: ", result);
        m_playing = true;
    }
    else {
        std::cerr << "Audio already playing!\n";
        return;
    }
}

void musicPlayer::stop()
{
    detectPlaying();
    if(m_playing == true){
        FMOD_RESULT result = m_channel -> stop();
        m_channel = nullptr; //because channel handle is made invalid as soon as sound ends
        errorHandle("stop() Error: ", result);
        m_playing = false;
    }
    else {
        std::cerr << "Audio not playing!\n";
        return;
    }
}

void musicPlayer::detectPlaying()
{
    FMOD_RESULT result = m_channel -> isPlaying(&m_playing);
    if(result == FMOD_ERR_INVALID_HANDLE || result == FMOD_OK)
        return;
    else
        errorHandle("Playing() Error: ", result);    
}

/*void musicPlayer::pause()
{
    FMOD_RESULT result = m_channel -> getPaused(&m_paused);
    errorHandle("pause() Error: ", result);
    if(m_paused == false){
        result = m_channel -> setPaused(true);
        errorHandle("pause() Error: ", result);
        m_paused = true;
    }
    else {
        std::cerr << "Audio already paused!\n";
        return; 
    }
}

void musicPlayer::resume()
{
    FMOD_RESULT result = m_channel -> getPaused(&m_paused);
    errorHandle("resume() Error: ", result);
    if(m_paused == true){
        result = m_channel -> setPaused(false);
        errorHandle("resume() Error: ", result);
        m_paused = false;
    }
    else {
        std::cerr << "Audio not paused!\n";
        return; 
    }
}*/


