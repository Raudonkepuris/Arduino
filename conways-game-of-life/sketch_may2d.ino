#include "LedControl.h"

#define right A5
#define down A2
#define left A0
#define up A3
#define addreset A1

LedControl matrix = LedControl(11, 13, 10, 4);

unsigned long delayt = 100;

int displaygen[16][16] = {0};
int generation[16][16] = {0};

int x = 0, y = 0, dev = 3;

bool playing = false;

bool displayed = false;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  int devices = matrix.getDeviceCount();
  //we have to init all devices in a loop
  for (int address = 0; address < devices; address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    matrix.shutdown(address, false);
    /* Set the brightness to a medium values */
    matrix.setIntensity(address, 8);
    /* and clear the display */
    matrix.clearDisplay(address);
  }

}

void loop() {
  int devices = matrix.getDeviceCount();

  if (playing == false) {
    matrix.setLed(dev, y, x, true);
    delay(delayt);

    if (analogRead(right) > 100) {
      matrix.setLed(dev, y, x, false);
      if (x >= 7 && dev == 3) {
        dev = 2;
        x = 0;
      } else if (x >= 7 && dev == 1) {
        dev = 0;
        x = 0;
      } else if (x == 7 && (dev == 2 || dev == 0)) {} else x++;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();

    } else if (analogRead(down) > 100) {
      matrix.setLed(dev, y, x, false);
      if (y >= 7 && dev == 3) {
        dev = 1;
        y = 0;
      } else if (y >= 7 && dev == 2) {
        dev = 0;
        y = 0;
      } else if (y == 7 && (dev == 1 || dev == 0)) {} else y++;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();

    } else if (analogRead(up) > 100) {
      matrix.setLed(dev, y, x, false);
      if (y <= 0 && dev == 1) {
        dev = 3;
        y = 7;
      } else if (y <= 0 && dev == 0) {
        dev = 2;
        y = 7;
      } else if (y == 0 && (dev == 3 || dev == 2)) {} else y--;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();

    } else if (analogRead(left) > 100) {
      matrix.setLed(dev, y, x, false);
      if (x <= 0 && dev == 0) {
        dev = 1;
        x = 7;
      } else if (x <= 0 && dev == 2) {
        dev = 3;
        x = 7;
      } else if (x == 0 && (dev == 1 || dev == 3)) {} else x--;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();
    
    } else if (analogRead(addreset) > 100) {
      if(dev == 3){
        displaygen[y][x] = 1;
        Serial.println(displaygen[y][x]);
      }else if(dev == 2){
        displaygen[y][x+8] = 1;
        Serial.println(displaygen[y][x+8]);
      }else if(dev == 1){
        displaygen[y+8][x] = 1;
        Serial.println(displaygen[y+8][x]);
      }else if (dev == 0) {
        displaygen[y+8][x+8] = 1;
        Serial.println(displaygen[y+8][x+8]);
      }
      displayed = false;
    }
  }

  if(displayed == false){
    for(int i = 0; i < 16; i++){
      for(int j = 0; j < 16; j++){
        if(displaygen[i][j] == 1){
          if(i <= 7){
            if(j <= 7){
              matrix.setLed(3, i, j, true);
            }else if(j >= 8){
              matrix.setLed(2, i, j-8, true);
            }
          }else if(i >= 8){
            if(j <= 7){
              matrix.setLed(1, i - 8, j, true);
            }else if(j >= 8){
              matrix.setLed(0, i-8, j-8, true);
            }
          }
        }
      }
    }
    displayed = true;
  }
}