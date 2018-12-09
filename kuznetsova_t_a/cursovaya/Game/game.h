#ifndef GAME_H
#define GAME_H

#include "canvas.h"

class Game
{
private:
    Canvas canvas;
    long int score;
public:
    Game();
    void StartGame();
    void StopTurn();
    void FinishGame();
    void ShowScore();
    void CountScore(int countBalls);
};

#endif // GAME_H
