#ifndef ESCAPECODES_H
#define ESCAPECODES_H
#include <iostream>
#include <iomanip>

#define CLEAR   "\e[2J\e[3J\e[H"
#define BLACK   "\x1B[30;1m"
#define RED     "\x1B[31;1m"
#define GREEN   "\x1B[32;1m"
#define YELLOW  "\x1B[33;1m"
#define BLUE    "\x1B[34;1m"
#define MAGENTA "\x1B[35;1m"
#define CYAN    "\x1B[36;1m"
#define WHITE   "\x1B[37;1m"
#define RESET   "\x1B[0m"


#define B_BLACK    "\x1B[40;1m"
#define B_RED      "\x1B[41;1m"
#define B_GREEN    "\x1B[42;1m"
#define B_YELLOW   "\x1B[43;1m"
#define B_BLUE     "\x1B[44;1m"
#define B_MAGENTA  "\x1B[45;1m"
#define B_CYAN     "\x1B[46;1m"
#define B_WHITE    "\x1B[47;1m"


#define BLACKL_ENGTH    sizeof(BLACK)/sizeof(char)
#define RED_LENGTH      sizeof(RED)/sizeof(char)
#define GREEN_LENGTH    sizeof(GREEN)/sizeof(char)
#define YELLOW_LENGTH   sizeof(YELLOW)/sizeof(char)
#define BLUE_LENGTH     sizeof(BLUE)/sizeof(char)
#define MAGENTA_LENGTH  sizeof(MAGENTA)/sizeof(char)
#define CYAN_LENGTH     sizeof(CYAN)/sizeof(char)
#define WHITE_LENGTH    sizeof(WHITE)/sizeof(char)

void moveUp(int);
void moveDown(int);
void moveRight(int);
void moveLeft(int);

#endif