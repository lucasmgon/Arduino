//Projeto 7 - Lampada Pulsante

int ledPin = 11;
int ledVal;        //valor armazenado que vai ser mandado para o pino PWM 11
float sinVal;      //onda senoidal  (para entender o que e: https://pt.wikipedia.org/wiki/Forma_de_onda)

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  for(int x = 0; x < 180; x++){

    sinVal = (sin(x*(3.1416/180)));           // a funcao sin calcula o seno do angulo, 
    ledVal = int(sinVal*255);                 // onde o grau esta em radianos.
    analogWrite(ledPin, ledVal);              // A funcao X*(3.1416/180) converte o grau para radianos.
    delay(25);                                // Resultando em -1 e 1 que  multiplicado por 255,obtera o brilho do led.
  }                                           // Esse valor  passado para o pino PWM 11, que realiza a conversao digital para analogica*/
}
