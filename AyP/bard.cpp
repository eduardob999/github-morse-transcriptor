#include <iostream>
#include <vector>

using namespace std;

class Ball {
public:
  int x, y;
  int dir_x, dir_y;
  int radius;

  Ball() {
    x = 0;
    y = 0;
    dir_x = -1;
    dir_y = 0;
    radius = 10;
  }

  void move() {
    x += dir_x;
    y += dir_y;
  }

  bool collidesWith(Ball other) {
    return (x - other.x)*(x - other.x) + (y - other.y)*(y - other.y) <= radius*radius;
  }
};

class Paddle {
public:
  int x, y;
  int height;
  int width;

  Paddle(int x, int y, int height, int width) {
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
  }

  void moveUp() {
    y -= 10;
  }

  void moveDown() {
    y += 10;
  }
};

int main() {
  int width = 600;
  int height = 400;

  Ball ball;
  Paddle paddle1(100, height / 2, 20, 100);
  Paddle paddle2(width - 100, height / 2, 20, 100);

  while (true) {
    // Clear the screen
    cout << "\033[2J\033[0;0H";

    // Draw the ball
    cout << ball;

    // Draw the paddles
    cout << paddle1;
    cout << paddle2;

    // Move the ball
    ball.move();

    // Check for collisions
    if (ball.collidesWith(paddle1)) {
      ball.dir_x = 1;
    } else if (ball.collidesWith(paddle2)) {
      ball.dir_x = -1;
    }

    // Check if the ball went out of bounds
    if (ball.x < 0 || ball.x > width) {
      // Game over!
      break;
    }

    // Wait for a few milliseconds before the next frame
    Sleep(10);
  }

  return 0;
}