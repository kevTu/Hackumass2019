#ifndef PLAYER
#define PLAYER

#include <Arduino.h>

/*#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>*/

class Player {
  public:
    Player();
    byte *getPlayer();
    void moveLeft();
    void moveRight();
    int getCursorPos();
    //void reset();
    
  private:
    byte *arr;
    int cursorPosition;
    int count;
    
};

#endif
