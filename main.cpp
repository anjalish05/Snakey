#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
// variables for map dimensions
const int width = 20; // in blocks (dimensions)
const int height = 20;
//variables for head positions
int x, y; 
// variables for fruit position, and a score variable 
int fruitX, fruitY, score;

// Suppose 'a' is the key, which on pressing moves the snake to left, but it makes the snake move continuously towards left, rather than making us click 'a' multiple times
// So, we need to track the directions, when we press a key, it needs to change the direction
// this is enumeration
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir; // variable for direction


void Setup() {
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width; // fruit placed randomly somewhere in the map 
    fruitY = rand()%height;
    score = 0;
}

void Draw() {
    system("cls"); // To clear the screen or conole window
    for(int i = 0; i < width; i++){
        cout << "#"; // map wall
    }
    cout << endl;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(j == 0) { // first field
                cout << "#";
            }
            if(i == y && j == x) {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            else {
                cout << " ";
            }
            if(j == width-1) {
                cout << "#";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < width; i++){
        cout << "#"; // map wall
    }
    cout << endl;
    cout << "Score: " << score << endl;

}

void Input() {
    // We'll be using two asynchronous functions from the library conio.h
    // Function to get a character from the console window
    if(_kbhit()) {
        // kbhit: is used when a character from the keyboard is pressed 
        // returns positive number if key is pressed 
        switch(_getch()) {
            // getch: returns ASCII value of the character pressed 
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    switch(dir) {
        // As we go left, 'x' coordinates are decreased and so on and so forth 
        // with other keys

        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // below is the snippet for when head touches the walls, the game is going to end

    if (x > width || x < 0 || y > height || y < 0) {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        // to randomly allocate the fruit again after being hit by it
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main() {

    Setup();

    while(!gameOver) {
        Draw();
        Input();
        Logic();
        // Sleep(); sleep(10): it slows our game!
    }


    return 0;
}