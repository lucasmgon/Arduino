//Projeto 14 - Sensor de Luz

int buzzerPin = 8;
int ldrPin = 0;
int valor = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop(){
  valor = analogRead(ldrPin);
  Serial.print("Luz: ");
  Serial.println(valor);
  
  tone(buzzerPin, 1000);
  delay(25);
  noTone(buzzerPin);
  delay(valor);
}
