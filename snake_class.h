#include <iostream>

class Snake {
private:
    int length;
    int x, y; // Position of the snake's head
    char direction; // 'U' for up, 'D' for down, 'L' for left, 'R' for right
    int size; // Snake grid will be size x size demension
    char board[size][size]

public:
    // Constructor
    Snake(int startX, int startY, int grid_dimension) : length(1), x(startX), y(startY), direction('R'), size(grid_dimension) {}

    // Getter for length
    int getLength() const {
        return length;
    }

    // Move the snake in the current direction
    void move() {
        switch (direction) {
            case 'U': y--; break;
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
};

int main() {
    Snake snake(0, 0);

    snake.display();
    snake.move();
    snake.changeDirection('D');
    snake.move();

    snake.display();

    return 0;
}
