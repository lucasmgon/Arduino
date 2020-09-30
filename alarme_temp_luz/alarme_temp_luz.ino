const int sensorL = A0;
const int sensorT = A1;
const int buzzer = 2;
const int led[] = {5,6,7,8,9,10,11};

int leituraL = 0;
int leituraT = 0;
float temperatura = 0;

void setup(){
  Serial.begin(9600);
  for(int x = 0; x < 7; x++){
    pinMode(led[x], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop(){
  analogRead(sensorL);
  delay(5);
  leituraL = analogRead(sensorL);
  analogRead(sensorT);
  delay(5);
  leituraT = analogRead(sensorT);
  temperatura = leituraT * 0.4887585532;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  delay(500);

  if(temperatura > 25.00){
    digitalWrite(led[0], HIGH);
  }else{
    digitalWrite(led[0], LOW);
  }

  if(temperatura > 28.00){
    digitalWrite(led[1], HIGH);
  }else{
    digitalWrite(led[1], LOW);
  }

  if(temperatura > 30.00){
    digitalWrite(led[2], HIGH);
  }else{
    digitalWrite(led[2], LOW);
  }
  
//-----------------------------------------
  if(leituraL < 422){
    digitalWrite(led[3], HIGH);
  }else{
    digitalWrite(led[3], LOW);
  }

  if(leituraL < 100){
    digitalWrite(led[4], HIGH);
  }else{
    digitalWrite(led[4], LOW);
  }

  if(leituraL < 70){
    digitalWrite(led[5], HIGH);
  }else{
    digitalWrite(led[5], LOW);
  }

  if(temperatura > 32 && leituraL <= 40){
    digitalWrite(led[6], HIGH);
    tone(buzzer, 2000);
  }else{
    digitalWrite(led[6], LOW);
    noTone(buzzer);
  }
}
