#include <iostream>
#include "musicPlayer.h"

int main()
{
    musicPlayer p{"music.mp3"};
    std::cout << "load success\n";
    p.play();
    std::cin.get();
    //p.pause();
    std::cin.get();
    //p.pause();
    std::cin.get();
    //p.resume();
    std::cin.get();
    //p.resume();
    std::cin.get();
    p.play();
    p.stop();
    p.stop();
}