#include <iostream>
#include <SDL.h>
#include <stdio.h>

using namespace std;

const int display_height = 600;
const int display_width = 700;

enum Direction
{
    STOP = 0,
    Up,
    Down,
    Left,
    Right
};

class Snake
{
private:
    int x, y;
    Direction dir;
    bool continueRunning;

public:
    Snake()
    {
        x = 0;
        y = 0;
        dir = Direction::STOP;
        continueRunning = true;
    }

    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setDir(Direction dir) { this->dir = dir; }

    void move()
    {
        switch (dir)
        {
        case Direction::Up:
            y--;
            break;
        case Direction::Down:
            y++;
            break;
        case Direction::Left:
            x--;
            break;
        case Direction::Right:
            x++;
            break;
        default:
            break;
        }

        // Check if the snake has hit the wall or its own tail.
        if (x < 0 || x >= display_width || y < 0 || y >= display_height || isCollidingWithTail())
        {
            // Game over.
            continueRunning = false;
        }
    }

    bool isCollidingWithTail()
    {
        // TODO: Implement this method to check if the snake is colliding with its own tail.
        return false;
    }

    bool isRunning() { return continueRunning; }
};

void GameInit()
{
    // TODO: Initialize the game state here.
}

void input(Snake& snake)
{
    // TODO: Handle keyboard input here.
    // For example, you could use the following code to handle the arrow keys:
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
        case 72: // Up arrow key
            snake.setDir(Direction::Up);
            break;
        case 80: // Down arrow key
            snake.setDir(Direction::Down);
            break;
        case 75: // Left arrow key
            snake.setDir(Direction::Left);
            break;
        case 77: // Right arrow key
            snake.setDir(Direction::Right);
            break;
        default:
            break;
        }
    }
}

void updateGame(Snake& snake)
{
    // TODO: Update the game state here.
    snake.move();
}

int main()
{
    cout << "\n\nProject Name: Snake game: Write a classic Snake game in C++.\n\n";

    Snake snake;
    GameInit();

    while (snake.isRunning()) {
        input(snake);
        updateGame(snake);
    }

    return 0;
}
