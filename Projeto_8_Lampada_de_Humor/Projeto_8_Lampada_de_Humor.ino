//Projeto 8 - Lampada de Humor

float rgb1[3];
float rgb2[3];
float inc[3];
int redPin = 11;
int greenPin = 10;
int yellowPin = 9;
int red, green, yellow;

void setup(){
  randomSeed(analogRead(0));
  
  rgb1[0] = 0;
  rgb1[1] = 0;
  rgb1[2] = 0;
  
  rgb2[0] = random(256);
  rgb2[1] = random(256);
  rgb2[2] = random(256);
}

void loop(){
  randomSeed(analogRead(0));
  
  for(int x = 0; x < 3; x++){
    inc[x] = (rgb1[x] - rgb2[x]) / 256;
  }
  
  for(int x = 0; x < 256; x++){
    red = int(rgb1[0]);
    green = int(rgb1[1]);
    yellow = int (rgb1[2]);
    
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(yellowPin, yellow);
    delay(10);
    
    rgb1[0] -= inc[0];
    rgb1[1] -= inc[1];
    rgb1[2] -= inc[2];
  }
  
  for(int x = 0; x < 3; x++){
    rgb2[x] = random(556) - 300;
    rgb2[x] = constrain(rgb2[x], 0, 255);
    delay(1000);
  }
}
