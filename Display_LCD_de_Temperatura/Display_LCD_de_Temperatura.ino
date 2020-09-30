//Projeto 24
#include <LiquidCrystal.h>

//Inicia a biblioteca com os numeros dos pinos de interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //Cria um objeto lcd e atribui os pinos

int maxC = 0, minC = 100, maxF = 0, minF = 212;
int escala = 1;
int button = 8;

void setup(){
  lcd.begin(16, 2); //Define o cursor na posição de inicio
  analogReference(INTERNAL);
  pinMode(button, INPUT);
  lcd.clear();
}

void loop(){
  lcd.setCursor(0, 0);    //Define a posicao inicial do cursor
  int sensor = analogRead(0); //Le a temperatura do sensor
  int estadoBotao = digitalRead(button);  //Verifica se o botao foi precionado
  
  switch(estadoBotao){
    case HIGH:
      escala =-escala;   //Inverte a escala
      lcd.clear();
  }
  delay(250);

  switch(escala){
    case 1:
      celsius(sensor);
    break;
    case -1:
      fahrenheit(sensor); 
    break;
  }
}

void celsius(int sensor){
  lcd.setCursor(0,0);
  int temp = sensor * 0.9765625;
  lcd.print(temp);
  lcd.write(B11011111);   //Simbolo do Grau
  lcd.print("C ");

  if(temp > maxC){
    maxC = temp;
  }
  if(temp < minC){
    minC = temp;
  }
  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.print(maxC);
  lcd.write(B11011111);
  lcd.print("C L=");
  lcd.print(minC);
  lcd.write(B11011111);
  lcd.print("C ");
}

void fahrenheit(int sensor){
  lcd.setCursor(0,0);
  float temp = ((sensor * 0.09765625) * 1.8)+32;
  lcd.print(int(temp));
  lcd.write(B11011111);
  lcd.print("F ");
 
  if(temp > maxF){
    maxF = temp;
  }
  if(temp < minF){
    minF = temp;
  }
  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.print(maxF);
  lcd.write(B11011111);
  lcd.print("F L=");
  lcd.print(minF);
  lcd.write(B11011111);
  lcd.print("F ");
}

