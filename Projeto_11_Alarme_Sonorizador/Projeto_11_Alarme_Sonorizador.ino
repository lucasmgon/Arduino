// Projeto 11- Alarme com sonorizador buzzer

int buzzerPin = 8;
float sinVal;
int toneVal;

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  for(int x = 0;x < 180;x++){
    //converte graus em radianos, e depois obtem o valor do seno
    sinVal = (sin(x*(3.1416/180)));
    //gera uma frequencia a partir do valor do seno
    toneVal = 2000+(int(sinVal*1000));
    tone(buzzerPin, toneVal);
    delay(2);
  }
}

