// Projeto 1 - LED piscando

int ledPin = 10; //Pino 10 do Arduino

void setup(){  //Funçao Obrigatoria
  pinMode(ledPin, OUTPUT); //Define o modo do Pino como Saida
}

void loop(){  //Funcao Obrigatoria
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
