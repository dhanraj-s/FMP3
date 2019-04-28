#include <FMOD/fmod.hpp>
#include <FMOD/fmod_errors.h>
#include <iostream>
#include <string>
#include <cstdlib>

#include "fmodException.h"
#include "musicPlayer.h"
#include "mainHelpers.h"

constexpr auto menu
{
    "1.Play\n2.Stop\n3.Pause\n4.Resume\n5.Change Volume\n6.Quit\n"
    "Enter your choice: "
};

int main(int argc, char *argv[])
{
    if(argc != 2) {
        std::cerr << "Usage: ./fmp3 <filename>\n";
        return EXIT_FAILURE;
    }
    const std::string fileName {argv[1]};
    try{
        musicPlayer p {fileName};
        int choice {0};
        
        while(choice != 6) {
            reportVolume(p);
            std::cout << menu;
            takeInput(choice);
            handleInput(p, choice);
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
