//Projeto 15 - Controle de um motor simpoles

int potPin = 0;
int transistorPin = 9;
int potValue = 0;

void setup(){
  pinMode(transistorPin, OUTPUT);
}

void loop(){
  potValue = analogRead(potPin) / 4;
  analogWrite(transistorPin, potValue);
}
