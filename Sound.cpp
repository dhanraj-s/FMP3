#include <iostream>

#include "Sound.h"
#include "fmodException.h"

Sound::~Sound()
{
    try {
        if(m_sound != nullptr){
            result = m_sound -> release();
            if(result != FMOD_OK)
              	throw fmodExceptionCritical("Sound::release(): ", result);
            m_sound = nullptr;
        }
    }
    catch(const fmodExceptionCritical& e){
        std::cerr << "CRITICAL FAILURE: " << e.what() << "\n";
    }
}
