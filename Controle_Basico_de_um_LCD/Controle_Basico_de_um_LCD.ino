// Projeto 23

#include <LiquidCrystal.h>

//Inicializa a biblioteca com os numeros dos pinos da interface
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);   //Cria um objeto LCD e atribui os pinos

void setup(){
  lcd.begin(16, 2); //Define o display com 16 colunas e 2 linhas
}

void loop(){
  //executa as funções de demonstração
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createG1yphDemo();
}

void basicPrintDemo(){
  lcd.clear();    //Limpa o display
  
  lcd.print("Basic Print"); //Imprime algum texto
  delay(2000);
}

void displayOnOffDemo(){
  lcd.clear();
  
  lcd.print("Display On/Off");
  for(int x =0; x < 3; x++){
    lcd.noDisplay();  //Apaga o Display
    delay(1000);
    lcd.display();  //Acende o Display
    delay(1000);
  }
}

void setCursorDemo(){
  lcd.clear();
  lcd.print("SetCursor demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5, 0);    //Cursor na coluna 5, linha 0
  lcd.print("5,0");
  delay(2000);
  lcd.setCursor(10, 1);   //cursor na coluna 5, linha 1
  lcd.print("10,1");
  delay(2000);
  lcd.setCursor(3, 1);  //cursor na coluna 3, linha 1
  lcd.print("3,1");
  delay(2000);
}

void scrollLeftDemo(){
  lcd.clear();
  lcd.print("Scroll Left Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("Iniciando");
  lcd.setCursor(9, 1);
  lcd.print("Arduino");
  delay(1000);
  
  for(int x = 0; x < 16; x++){
    lcd.scrollDisplayLeft();    //Rola o display 16 vezes para a esquerda
    delay(250);
  }
}

void scrollRightDemo(){
  lcd.clear();
  lcd.print("Scroll Right");
  lcd.setCursor(0, 1);
  lcd.print("Demonstracao");
  delay(1000);
  lcd.clear();
  lcd.print("Iniciando");
  lcd.setCursor(0, 1);;
  lcd.print("Arduino");
  delay(1000);
  
  for(int x= 0; x < 16; x++){
    lcd.scrollDisplayRight();   //Rola o Display 16  vezes para a direita
    delay(250);
  }
}

void cursorDemo(){
  lcd.clear();
  lcd.cursor(); //Cursor Visivel
  lcd.print("Cursor Ligado");
  delay(2000);
  lcd.clear();
  lcd.noCursor(); //Cursor Invisivel
  lcd.print("Cursor Desligado");
  delay(2000);
  lcd.clear();
  lcd.cursor();   //Cursor Visivel
  lcd.blink();    //Cursor Piscando
  lcd.print("Cursor Piscando");
  delay(3000);
  lcd.noCursor(); //Cursor Invisivel
  lcd.noBlink();  //Cursor não Piscando
}


void createG1yphDemo(){
  lcd.clear();
  
  byte alegre[8] = {  //Cria um array de bytes com uma cara feliz
    B00000,
    B00000,
    B10001,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
  };
  
  byte triste[8] ={ //Cria um array de bytes com uma cara triste
    B00000,
    B00000,
    B10001,
    B00000,
    B01110,
    B10001,
    B00000,
    B00000
  };
  
  lcd.createChar(0, alegre);  //Cria o caractere personalizado 0
  lcd.createChar(1, triste);  //Cria o caractere personalizado 1
  
  for(int x = 0; x < 5; x++){
    lcd.setCursor(8, 0);
    lcd.write((byte)0);   //Escreve o caractere personalizado 0
    delay(1000);
    lcd.setCursor(8, 0);
    lcd.write((byte)1); //Escreve o caractere personalizado 1
    delay(1000);
  }
}
