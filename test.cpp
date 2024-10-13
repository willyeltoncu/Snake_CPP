#include <iostream>
#include <string>
#include <random>
using namespace std;
class Snake {
private:
    int length;
    int x, y; // Position of the snake's head
    char direction; // 'U' for up, 'D' for down, 'L' for left, 'R' for right
    const int size; // Snake grid will be size x size demension
    int** board;

public:
    // Constructor
    Snake(int startX, int startY, int grid_dimension) : length(1), x(startX), y(startY), direction('R'), size(grid_dimension) {
        board = new int*[size];
        for(int i = 0; i < size; ++i) {
            board[i] = new int[size];
        }
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                board[j][k] = 0;
            }
        }
        cout << "Board initialized. (Filled with zeros).... "<< endl; 
     
    }
    ~Snake(){ //Destruction
        delete[] board;
    }

    // Getter for length
    int getLength() const {
        return length;
    }

    // Move the snake in the current direction
    void move() {
        switch (direction) {
            case 'U': board[x][y] = 0; y--;board[x][y] = 1; break;
            case 'D': y++; break;
            case 'L': x--; break;
            case 'R': x++; break;
        }
    }

    // Change the direction of the snake
    void changeDirection(char newDirection) {
        direction = newDirection;
    }

    // Display the snake's current position
    void display() const {
        std::cout << "Snake Position: (" << x << ", " << y << ")" << std::endl;
    }

    void print_board(){
        string placeholder = "";
        for(int i = 0; i < size; i++){
            for(int k = 0; k < size; k++){
                placeholder = to_string(board[i][k]);
                cout << " " + placeholder + " " ;
            }
            cout << endl;
        }

    }
};

int main() {
    int x_position = rand() % 8;
    int y_position = rand() % 8;
    cout << "Snake head randomly placed at : (" + to_string(x_position) + "," + to_string(y_position) + ")."<< endl; 
        // board[x_position][y_position] = 1;
    Snake snake = Snake(x_position, y_position, 8);

    snake.display();
    snake.move();
    snake.print_board();
    snake.changeDirection('U');
    snake.move();

    snake.display();
    snake.print_board();
    return 0;
}
