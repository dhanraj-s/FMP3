#include <limits>
#include "mainHelpers.h"

void reportVolume(const musicPlayer& player)
{
    float volume = player.getVolume();
    if(volume == musicPlayer::INVALID_VOLUME)
        std::cout << "VOL : Channel not playing\n";
    else
        std::cout << "VOL : " << volume << "\n";
}

void takeInput(int& value)
{
    std::cin >> value;
    if(std::cin.fail()) {
        std::cin.clear();
        value = INVALID_VALUE;
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    return;
}

void handleInput(musicPlayer& p, int choice)
{
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
            int newVolume{0};
            std::cout << volumePrompt;
            takeInput(newVolume);
            p.setVolume(newVolume);
            break;
        }
        case 6:
            break;

        default:
            std::cout << "Invalid input. Try Again.\n";
    }

}