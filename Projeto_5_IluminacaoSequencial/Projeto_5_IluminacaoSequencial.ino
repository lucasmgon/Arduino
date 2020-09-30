// Projeto 5 - Efeito de iluminaço sequencial com LEDS

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  //array para os pinos dos LEDS
int ledDelay(65); //intervalo de variacoes
int direcao = 1;
int correnteLed = 0;
unsigned long mudancaDeTempo;

void setup(){
  
  for(int x = 0; x < 10;x++){  //define todos os pinos como saida
    pinMode(ledPin[x], OUTPUT);
  }
  
  mudancaDeTempo = millis();
}

void loop(){
 if((millis() - mudancaDeTempo) > ledDelay){
   
   mudancaDeLed();  //Funcao MudancaDeTempo
   
   mudancaDeTempo = millis();
 }
}

void mudancaDeLed(){
  
  for(int x = 0; x < 10; x++){  //apaga todos os LEDS
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
