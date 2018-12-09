#include "game.h"

Game::Game()
{


}

void Game::StartGame()
{
    //Canvas  canvas();
    //this->canvas = canvas;
    //генерируем шарики
    //показываем шарики

}

void Game::CountScore(int countBalls)
{
    score += 600 + (countBalls - 5) * 100;
}
