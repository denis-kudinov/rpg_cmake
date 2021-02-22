#include "mylib/stdafx.hpp"
#include "mylib/Game.hpp"
#include <Windows.h>

int main()
{
    /*sf::Music music;
    if (!music.openFromFile("Resources/Music/song.wav"))
        std::cout << "ERROR main(): could not load music\n";
    music.setLoop(true);
    music.setVolume(20.f);
    music.play();*/

    Game game;
    game.run();
    return 0;
}