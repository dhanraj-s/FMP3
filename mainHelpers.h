#ifndef MAIN_HELPERS
#define MAIN_HELPERS

#include "musicPlayer.h"

constexpr int INVALID_VALUE {-1};
constexpr auto volumePrompt {"Enter volume: "};

void reportVolume(const musicPlayer& player);
void takeInput(int& value);
void handleInput(musicPlayer& p, int choice);

#endif //MAIN_HELPERS