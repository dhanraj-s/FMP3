#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <string>
#include <iostream>

#include "System.h"
#include "fmodException.h"

void System::loadMusic(const std::string& songName, Sound& sound)
{
    result = m_system -> createSound(
        songName.c_str(),
        FMOD_CREATESTREAM | FMOD_LOOP_OFF,
        nullptr,
        &sound.m_sound
        );
    if(result != FMOD_OK)
        throw fmodException("System::createSound(): " , result);

}

void System::playMusic(const Sound& sound, Channel& channel)
{
    result = m_system -> playSound(sound.m_sound, nullptr, false, &channel.m_channel);
    if(result != FMOD_OK)
        throw fmodException("System::playSound(): ", result);
}

 System::System()
{
    if((result = FMOD::System_Create(&m_system)) != FMOD_OK)
        throw fmodException("FMOD::System_Create(): ", result);

    if((result = m_system -> init(32, FMOD_INIT_NORMAL, nullptr)) != FMOD_OK){
        cleanUpSystem();
        throw fmodException("System::init(): ", result);
    }

}

void System::cleanUpSystem()
{
    result = m_system -> release();
    if(result != FMOD_OK){
        throw fmodExceptionCritical("System::release():  ", result);
    }
}

System::~System()
{
    try {
        result = m_system -> release();
        if(result != FMOD_OK){
            throw fmodExceptionCritical("System::release(): ", result);
        }
        m_system = nullptr;
    }
    catch(const fmodExceptionCritical& e){
        std::cerr << "CRITICAL FAILURE: " << e.what() << "\n";
    }
}
