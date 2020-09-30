const int r = 9;
const int g = 10;
const int b = 11;

int valorRed = 255;
int valorGreen = 0;
int valorBlue = 0;

void setup(){
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  analogWrite(r, valorRed);
  analogWrite(g, valorGreen);
  analogWrite(b, valorBlue);
}

void loop(){
  for(valorGreen = 0; valorGreen < 255; valorGreen +=5){
    analogWrite(g, valorGreen);
    delay(50);
  }
  for(valorRed = 255; valorRed > 0; valorRed -=5){
    analogWrite(r, valorRed);
    delay(50);
  }
  for(valorBlue = 0; valorBlue < 255; valorBlue +=5 ){
    analogWrite(b, valorBlue);
    delay(50);
  }
  for(valorGreen = 255; valorGreen > 0; valorGreen -=5){
    analogWrite(g, valorGreen);
    delay(50);
  }
  for(valorRed = 0; valorRed < 255; valorRed +=5){
    analogWrite(r, valorRed);
    delay(50);
  }
  for(valorBlue = 255; valorBlue > 0; valorBlue -=5){
    analogWrite(b, valorBlue);
    delay(50);
  }
}
