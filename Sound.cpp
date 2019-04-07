#include <iostream>

#include "Sound.h"
#include "fmodException.h"

Sound::~Sound()
{
    try {
        if(m_sound != nullptr){
            result = m_sound -> release();
            if(result != FMOD_OK)
              	throw fmodException("Sound::release(): ", result);
            m_sound = nullptr;
        }
    }
    catch(const fmodException& e){
        std::cerr << e.what() << "\n";
    }
}
