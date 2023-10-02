#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool quit = false;
const int width = 20;
const int height = 10;
int ballX, ballY, playerX, playerY, enemyX, enemyY, score;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction ballDir;

void Setup() {
    quit = false;
    ballX = width / 2;
    ballY = height / 2;
    playerX = width / 2;
    playerY = height - 1;
    enemyX = width / 2;
    enemyY = 0;
    score = 0;
    ballDir = STOP;
}

void Draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == ballY && j == ballX)
                cout << "O";
            else if (i == playerY && j == playerX)
                cout << "P";
            else if (i == enemyY && j == enemyX)
                cout << "E";
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            ballDir = LEFT;
            break;
        case 'd':
            ballDir = RIGHT;
            break;
        case 'w':
            ballDir = UP;
            break;
        case 's':
            ballDir = DOWN;
            break;
        case 'x':
            quit = true;
            break;
        }
    }
}

void Logic() {
    switch (ballDir) {
    case LEFT:
        ballX--;
        break;
    case RIGHT:
        ballX++;
        break;
    case UP:
        ballY--;
        break;
    case DOWN:
        ballY++;
        break;
    }

    if (ballX < 0 || ballX >= width || ballY < 0 || ballY >= height) {
        quit = true;
    }

    if (ballX == playerX && ballY == playerY) {
        ballDir = UP;
        score++;
    }

    if (ballX == enemyX && ballY == enemyY) {
        ballDir = DOWN;
    }
}

int main() {
    Setup();

    while (!quit) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // Sleep for a short duration to control the game speed
    }

    return 0;
}
