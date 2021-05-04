#include <Arduino.h>
#include <OneButton.h>
#include "LedControl.h"

LedControl matrix = LedControl(11, 13, 10, 4);

unsigned long delayt = 100;

int displaygen[16][16] = {0};
int generation[16][16] = {0};

int x = 0, y = 0, dev = 3;

bool playing = false;

bool displayed = false;

bool presetMenu = false;

int devices;

/*int presetNum = 0;

int presets[][16][16] = {
  {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  },
  {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  },
  {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  },
};*/

OneButton addresetBtn(A1, true);
OneButton upBtn(A3, true);
OneButton downBtn(A2, true);
OneButton leftBtn(A0, true);
OneButton rightBtn(A5, true);
OneButton startBtn(A4, true);

void addresetClicked();
void addresetLongPressed();

void up();
void down();
void left();
void right();
void start();

void display();
int checkLive(int y, int x);
void genGeneration();

void loadPreset(int& presetNum);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  devices = matrix.getDeviceCount();
  //we have to init all devices in a loop
  for (int address = 0; address < devices; address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    matrix.shutdown(address, false);
    /* Set the brightness to a medium values */
    matrix.setIntensity(address, 8);
    /* and clear the display */
    matrix.clearDisplay(address);
  }

  addresetBtn.attachClick(addresetClicked);
  addresetBtn.attachLongPressStop(addresetLongPressed);

  upBtn.attachClick(up);
  downBtn.attachClick(down);
  leftBtn.attachClick(left);
  rightBtn.attachClick(right);
  startBtn.attachClick(start);
}

void loop() {
  addresetBtn.tick();

  upBtn.tick();
  downBtn.tick();
  leftBtn.tick();
  rightBtn.tick();
  startBtn.tick();
  
  if(playing == false){
    matrix.setLed(dev, y, x, true);
  }
  else if(playing == true){
    delay(1000);

    genGeneration();

    displayed = false;
  }

  if(displayed == false){
    display();
  }
}

void up(){
  Serial.println("up");

  if(playing == false && presetMenu == false){
    matrix.setLed(dev, y, x, false);
      if (y <= 0 && dev == 1) {
        dev = 3;
        y = 7;
      } 
      else if (y <= 0 && dev == 0) {
        dev = 2;
        y = 7;
      } 
      else if (y == 0 && (dev == 3 || dev == 2)) {} 
      else y--;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();
      displayed = false;
  }
}

void down(){
  Serial.println("down");

  if(playing == false && presetMenu == false){
    matrix.setLed(dev, y, x, false);
      if (y >= 7 && dev == 3) {
        dev = 1;
        y = 0;
      } 
      else if (y >= 7 && dev == 2) {
        dev = 0;
        y = 0;
      } 
      else if (y == 7 && (dev == 1 || dev == 0)) {} 
      else y++;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();
      displayed = false;
  }
}

void left(){
  Serial.println("left");

  if(playing == false && presetMenu == false){
    matrix.setLed(dev, y, x, false);
      if (x <= 0 && dev == 0) {
        dev = 1;
        x = 7;
      } 
      else if (x <= 0 && dev == 2) {
        dev = 3;
        x = 7;
      } 
      else if (x == 0 && (dev == 1 || dev == 3)) {} 
      else x--;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();
      displayed = false;
  }
  /*else if(playing == false && presetMenu == true){
    presetNum--;
    loadPreset();
  }*/
}

void right(){
 Serial.println("right"); 

 if(playing == false){
   matrix.setLed(dev, y, x, false);
      if (x >= 7 && dev == 3) {
        dev = 2;
        x = 0;
      } 
      else if (x >= 7 && dev == 1) {
        dev = 0;
        x = 0;
      } 
      else if (x == 7 && (dev == 2 || dev == 0)) {} 
      else x++;
      Serial.print("x: ");
      Serial.print(x);
      Serial.print(" y: ");
      Serial.print(y);
      Serial.println();
      displayed = false;
 } 
  /*else if(playing == false && presetMenu == true){
    presetNum++;
    loadPreset();
  }*/ 
}

void start(){
  Serial.println("start");

  if(playing == false){
    playing = true;
  }
}

void addresetClicked(){
  Serial.println("addreset clicked");

  if(playing == false){
    if(dev == 3){
        if(checkLive(y, x) == 0) displaygen[y][x] = 1;
        else displaygen[y][x] = 0;
        Serial.println(displaygen[y][x]);
      }
      else if(dev == 2){
        if(checkLive(y, x+8) == 0) displaygen[y][x+8] = 1;
        else displaygen[y][x+8] = 0;
        Serial.println(displaygen[y][x+8]);
      }
      else if(dev == 1){
        if(checkLive(y+8, x) == 0) displaygen[y+8][x] = 1;
        else displaygen[y+8][x] = 0;
        Serial.println(displaygen[y+8][x]);
      }
      else if (dev == 0) {
        if(checkLive(y+8, x+8) == 0) displaygen[y+8][x+8] = 1;
        else displaygen[y+8][x+8] = 0;
        Serial.println(displaygen[y+8][x+8]);
      }
      displayed = false;
  }
  else if(playing == true){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
          displaygen[i][j] = 0;
          generation[i][j] = 0;
        }
      }
      x = 0, y = 0, dev = 3;

      playing = false;

      displayed = false;
  }
}

void addresetLongPressed(){
  Serial.println("addreset longpressed");

  if(playing == false){
    //presetMenu = true;
  }
  else if(playing == true){
        for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
          displaygen[i][j] = 0;
          generation[i][j] = 0;
        }
      }
      x = 0, y = 0, dev = 3;

      playing = false;

      displayed = false;
  }
}


void display(){
    for (int address = 0; address < 4; address++) {
    matrix.clearDisplay(address);
  }
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
              matrix.setLed(1, i-8, j, true);
            }else if(j >= 8){
              matrix.setLed(0, i-8, j-8, true);
            }
          }
        }
      }
    }
    displayed = true;
}

int checkLive(int y, int x){
  if(y < 0 || x < 0 || x > 15 || y > 15) return 0;
  else return displaygen[y][x];
}

void genGeneration(){
  int neighbours;
  for(int i = 0; i < 16; i++){
      for(int j = 0; j < 16; j++){
        int neighbours = checkLive(i-1, j-1) + checkLive(i-1, j) + checkLive(i-1, j+1) +
                          checkLive(i, j-1)   +         0         + checkLive(i, j+1) +
                          checkLive(i+1, j-1) + checkLive(i+1, j) + checkLive(i+1, j+1);
        if(checkLive(i, j) == 1){
          if(neighbours == 2 || neighbours == 3) generation[i][j] = 1;
          else generation[i][j] = 0;
        } else{
          if(neighbours == 3) generation[i][j] = 1;
        }
      }
    }
    
    for(int i = 0; i < 16; i++){
      for(int j = 0; j < 16; j++){
        displaygen[i][j] = generation[i][j];
        Serial.print(displaygen[i][j]);
      }
      Serial.println();
    }
  Serial.println();
}

/*void loadPreset(){
  if(presetNum <= 0) presetNum = 0;
  else if(presetNum >= 3) presetNum = 3;

  for(int i = 0; i < 16; i++){
      for(int j = 0; j < 16; j++){
        displaygen[i][j] = presets[presetNum][i][j];
      }
  }
}*/