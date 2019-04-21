#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <iostream>
#include <string>

#include "fmodException.h"
#include "musicPlayer.h"

/* This is only to test everything out */

int main()
{
    try{
        musicPlayer p("music.mp3");
        int choice {0};
        while(choice != 6) {
            float volume = p.getVolume();
            if(volume == musicPlayer::INVALID_VOLUME)
                std::cout << "VOL : Channel not playing\n";
            else
                std::cout << "VOL : " << volume << "\n";

            std::cout << "1.Play\n2.Stop\n3.Pause\n4.Resume\n5.Change Volume\n6.Quit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch(choice) {
                case 1:
                    p.play();
                    break;
                case 2:
                    p.stop();
                    break;
                case 3:
                    p.pause();
                    break;
                case 4:
                    p.resume();
                    break;
                case 5:
                {
                    float v{0};
                    std::cout << "Enter volume: ";
                    std::cin >> v;
                    p.setVolume(v);
                }
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
