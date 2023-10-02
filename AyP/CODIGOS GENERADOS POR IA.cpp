/* PROMPT: escribe un código en c++ para encontrar todos los números primos 
hasta un número ingresado*/
#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    cout << "Prime numbers up to " << n << " are:" << endl;
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}


/* PROMPT: escribe un código en c++ para encontrar todos los números primos 
hasta un número ingresado*/
#include <iostream>
using namespace std;

bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limite;
    
    cout << "Ingresa un número límite: ";
    cin >> limite;
    
    cout << "Números primos hasta " << limite << ": ";
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}

/* BINGAI: write the entire code for pong in c++*/

class GameObject {
  protected:
    int x; // x coordinate
    int y; // y coordinate
    int w; // width
    int h; // height
    SDL_Texture* texture; // image
  public:
    GameObject(int x, int y, int w, int h, SDL_Texture* texture); // constructor
    virtual ~GameObject(); // destructor
    virtual void update() = 0; // update position and state
    virtual void render(SDL_Renderer* renderer) = 0; // draw on screen
};

class Ball : public GameObject {
  private:
    int dx; // horizontal speed
    int dy; // vertical speed
  public:
    Ball(int x, int y, int w, int h, SDL_Texture* texture); // constructor
    ~Ball(); // destructor
    void update() override; // bounce off walls and paddles
    void render(SDL_Renderer* renderer) override; // draw on screen
};

class Paddle : public GameObject {
  private:
    int speed; // vertical speed
  public:
    Paddle(int x, int y, int w, int h, SDL_Texture* texture); // constructor
    ~Paddle(); // destructor
    void update() override; // move up or down according to input
    void render(SDL_Renderer* renderer) override; // draw on screen
};

class Score : public GameObject {
  private:
    int value; // score value
    TTF_Font* font; // font
    SDL_Color color; // color
  public:
    Score(int x, int y, int w, int h, TTF_Font* font, SDL_Color color); // constructor
    ~Score(); // destructor
    void update() override; // increase or reset value
    void render(SDL_Renderer* renderer) override; // draw on screen
};

class GameManager {
  private:
    SDL_Window* window; // window
    SDL_Renderer* renderer; // renderer
    SDL_Event event; // event handler
    bool running; // game state
    Ball* ball; // ball object
    Paddle* paddle1; // paddle1 object
    Paddle* paddle2; // paddle2 object
    Score* score1; // score1 object
    Score* score2; // score2 object
  public:
    GameManager(); // constructor
    ~GameManager(); // destructor
    void init(); // initialize game components
    void loadMedia(); // load images and fonts
    void handleEvents(); // handle user input and window events
    void update(); // update game logic and objects
    void render(); // render game objects on screen
    void clean(); // free memory and quit SDL subsystems 
};

/* CHATGPT3.5: write the entire code for pong in c++*/

# include <iostream>
# include <conio.h>
# include <windows.h>

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

/* BARD: write the entire code for pong in c++*/

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

