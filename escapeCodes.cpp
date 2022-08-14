
#include "escapeCodes.h"

void moveUp(int move)
{
    std::cout << "\033[" + std::to_string(move) + "A";
}
void moveDown(int move)
{
    std::cout << "\033[" + std::to_string(move) + "B";
}
void moveRight(int move)
{
    std::cout << "\033[" + std::to_string(move) + "C";
}
void moveLeft(int move)
{
    std::cout << "\033[" + std::to_string(move) + "D";
}