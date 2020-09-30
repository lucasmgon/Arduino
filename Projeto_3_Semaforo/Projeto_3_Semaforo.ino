// Projeto 3 - Semaforo

int ledDelay = 10000; // espera entre as alteraçoes
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

    //Pinos de Saida
void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
  digitalWrite(redPin, HIGH);  //acende LED vermelho
  delay(ledDelay);  //espera 5 segundos
  
  digitalWrite(yellowPin, HIGH);  //acende LED amarelo
  delay(2000);  //espera 2 segundos
  
  digitalWrite(greenPin, HIGH);   //acende LED verde
  digitalWrite(redPin, LOW);      //apaga LED vermelho
  digitalWrite(yellowPin, LOW);   //apaga LED amarelo
  delay(ledDelay);  //espera 5 segundos

  digitalWrite(yellowPin, HIGH);  //acende LED amarelo
  digitalWrite(greenPin, LOW);  //apaga LED verde
  delay(2000);  //espera 2 segundos
  
  digitalWrite(yellowPin, LOW);  //acende LED amarelo
}
