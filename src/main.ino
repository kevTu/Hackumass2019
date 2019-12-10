#include <LiquidCrystal.h>
#include "Player.h"

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;

Player *p = new Player();

/*byte bullet[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01000,
  B00000,
  B00000,
  B00000  
};*/

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.createChar(0, p->getPlayer());
  lcd.home();
  lcd.setCursor(1, p->getCursorPos());
  lcd.write(byte(0));
}

void loop() {
  /*put your main code here, to run repeatedly:
    lcd.print("Hello, world");*/
  /*Serial.print("Switch: ");
    Serial.print(digitalRead(SW_pin));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.print(analogRead(Y_pin));
    Serial.print("\n\n");
    delay(500);*/

  if (analogRead(Y_pin) == 0) {
    lcd.begin(16, 2);
    lcd.createChar(0, p->getPlayer());
    lcd.home();
    lcd.setCursor(1, p->getCursorPos());
    lcd.write(byte(0));
    p->moveRight();
    delay(150);
  }

  if (analogRead(Y_pin) == 1023) {
    lcd.begin(16, 2);
    lcd.createChar(0, p->getPlayer());
    lcd.home();
    lcd.setCursor(1, p->getCursorPos());
    lcd.write(byte(0));
    p->moveLeft();
    delay(150);
  }

  /*if (digitalRead(SW_pin) == LOW) {
    int r = rand() % 15;
    lcd.begin(16, 2);
    lcd.createChar(0, p->getPlayer());
    lcd.createChar(0, bullet);
    lcd.home();
    lcd.setCursor(r, p->getCursorPos());
    lcd.write(byte(0));
    delay(150);
  }*/
}
