//Projeto 6 - Iluminacao Sequencial com controle de um Potenciometro

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  //array dos pinos dos leds
int potPin = 2; //pino do Potenciometro

int ledDelay(0); //intervalo entre as alteracoes
int direcao = 1;
int correnteLed = 0;
unsigned long mudancaDeTempo;

void setup(){
  for(int x = 0; x < 10; x++){  //Pinos definidos como Saida
    pinMode(ledPin[x], OUTPUT);
  }
  mudancaDeTempo = millis();
}

void loop(){
  ledDelay = analogRead(potPin);    //Leitura Analogica do Potenciometro
  
  if((millis() - mudancaDeTempo) > ledDelay){  
    mudancaDeLed();
    mudancaDeTempo = millis();
  }
}

void mudancaDeLed(){
  for(int x = 0; x < 10; x++){
    digitalWrite(ledPin[x], LOW);
  }
  
  digitalWrite(ledPin[correnteLed], HIGH);
  correnteLed += direcao;
  
  if(correnteLed == 9){
    direcao = -1;
  }
  
  if(correnteLed == 0){
    direcao = 1;
  }
}
