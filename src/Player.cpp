#include "Player.h"

Player::Player() {
  //initialize starting postion
  arr = new byte[8];
  arr[0] = B01100;
  arr[1] = B01110;
  arr[2] = B01100;
  arr[3] = B00000;
  arr[4] = B00000;
  arr[5] = B00000;
  arr[6] = B00000;
  arr[7] = B00000;

  cursorPosition = 0;
  count = 0;
}

void Player::moveLeft() {
  if (cursorPosition == 1 && arr[0] != B01100) {
    for (int k = 0; k < 8; k++) {
      if (k == 7)
      {
        arr[k] = B00000; 
        break;
      }
      arr[k] = arr[k + 1];
    }
    count=0;
  }
  else {
    cursorPosition = 0;
    if (count == 0) {
      arr[0] = B00000;
      arr[1] = B00000;
      arr[2] = B00000;
      arr[3] = B00000;
      arr[4] = B00000;
      arr[5] = B01100;
      arr[6] = B01110;
      arr[7] = B01100;
    }

    if (cursorPosition == 0 && arr[0] != B01100) {
      for (int k = 0; k < 8; k++) {
      if (k == 7)
      {
        arr[k] = B00000; 
        break;
      }
      arr[k] = arr[k + 1];
    }
      count = 1;
    }
  }
}

void Player::moveRight() {
  if (cursorPosition == 0 && arr[7] != B01100) {
    for (int k = 7; k >= 0; k--) {
      arr[k] = arr[k - 1];
    }
    count=1;
  }
  else {
    cursorPosition = 1;
    if (count == 1) {
      arr[0] = B01100;
      arr[1] = B01110;
      arr[2] = B01100;
      arr[3] = B00000;
      arr[4] = B00000;
      arr[5] = B00000;
      arr[6] = B00000;
      arr[7] = B00000;
    }

    if (cursorPosition == 1 && arr[7] != B01100) {
      for (int k = 7; k >= 0; k--) {
        arr[k] = arr[k - 1];
      }
      count = 0;
    }
  }
}

byte *Player::getPlayer() {
  return arr;
}

int Player::getCursorPos() {
  return cursorPosition;
}

/*void Player::reset(){
  arr[0] = B01100;
  arr[1] = B01110;
  arr[2] = B01100;
  arr[3] = B00000;
  arr[4] = B00000;
  arr[5] = B00000;
  arr[6] = B00000;
  arr[7] = B00000;
  }*/
