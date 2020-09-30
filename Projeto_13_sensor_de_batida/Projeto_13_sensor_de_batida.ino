//Projeto 13 - Sensor de Batida

int ledPin = 9;
int buzzerPin = 5;
int limite = 1000;
int sensorValue = 0;
float ledValue = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
  delay(150);
}

void loop(){
  sensorValue = analogRead(buzzerPin);
  if(sensorValue >= limite){
    ledValue = 255;
  }
  
  analogWrite(ledPin, int(ledValue));
  ledValue = ledValue - 0.05;
  
  if(ledValue <= 0){
    ledValue = 0;
  }
}
