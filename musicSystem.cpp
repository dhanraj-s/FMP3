#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <iostream>
#include <string>

#include "fmodException.h"
#include "System.h"
#include "Sound.h"
#include "Channel.h"

int main()
{
    try{
        System sys;
        Sound music;
        Channel ch;
        sys.loadMusic("music.mp3", music);
        std::cout << "TEST\n";
        int choice {0};
        bool paused {false};
        bool playing {false};
        while(choice != 6){
            float volume = ch.getVolume();
            if(volume == INVALID_VOLUME)
                std::cout << "VOL : Channel not playing\n";
            else
                std::cout << "VOL : " << volume * 100 << "\n";

            std::cout << "1.Play\n2.Stop\n3.Pause\n4.Resume\n5.Change Volume\n6.Quit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch(choice){
                case 1:
                    sys.playMusic(music, ch);
                    playing = true;
                    paused = (paused)? !paused : paused; //keep playing and paused in sync
                    break;
                case 2:
                    ch.stopChannel();
                    playing = false;
                    paused = (paused)? !paused : paused; //keep playing and paused in sync
                    break;
                case 3:
                    if(paused == false && playing == true){
                        ch.switchPause();
                        paused = true;
                    }
                    break;
                case 4:
                    if(paused == true && playing == true){
                        ch.switchPause();
                        paused = false;
                    }
                    break;
                case 5:
                {
                    float v{0};
                    std::cout << "Enter volume: ";
                    std::cin >> v;
                    ch.setVolume(v/100);
                }
                default:
                    break;
            }
        }
    }
    catch(const fmodExceptionCritical& e){
        std::cerr << "CRITICAL FAILURE: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    catch(const fmodException& e){
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
}
