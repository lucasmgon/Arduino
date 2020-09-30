const int sensor = 0;
const int buzzer = 12;

float temperatura = 0;
int leitura = 0;

void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  leitura = analogRead(sensor);
  temperatura = leitura * 0.1075268817204301;

  Serial.print("Temperatura : ");
  Serial.print(temperatura);
  Serial.println(" *C");
  
  if(temperatura > 32){
    delay(1000);
    leitura = analogRead(sensor);
    temperatura = leitura * 0.1075268817204301;

    if(temperatura > 32){
      tone(buzzer, 2000);
    
    }
  }else{
      noTone(buzzer);
    }
  delay(1000);
}

