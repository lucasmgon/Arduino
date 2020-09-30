//Projeto 10 - Lampada Humor com controle Serial

char buffer[18];  //array que vai armazenar as strings
int red, green, yellow;
int redPin = 11;
int greenPin = 10;
int yellowPin = 9;

void setup(){
  Serial.begin(9600);  //Inicia a comunicaçao Seriais
  Serial.flush();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    int indice = 0;
    delay(100);    //deixe o buffer cheio
    int numChar = Serial.available();
    if(numChar > 15){
      numChar = 15;
    }
    while(numChar--){
      buffer[indice++] = Serial.read();
    }
    dividindoString(buffer);
  }
}

void dividindoString(char* data){
  Serial.print("Data Entrou: ");
  Serial.println(data);
  char* parametro;
  parametro = strtok (data, " ,");
  
  while(parametro != NULL){
    conjuntoLED(parametro);
    parametro = strtok(NULL, " ,");
  }
  
  //Limpa o texto e os buffers seriais
  for(int x=0; x < 16; x++){
    buffer[x] = '\0';
  }
  Serial.flush();
}

void conjuntoLED(char* data){
  if((data[0] == 'r') || (data[0] == 'R')){
    int anos = strtol(data+1, NULL, 10);
    anos = constrain(anos, 0, 255);
    analogWrite(redPin, anos);
    Serial.print("Vermelho esta definido para: ");
    Serial.println(anos);
  }
  
  if((data[0] == 'g') || (data[0] == 'G')){
    int anos = strtol(data+1, NULL, 10);
    anos = constrain(anos, 0, 255);
    analogWrite(greenPin, anos);
    Serial.print("Verde esta definido para: ");
    Serial.println(anos);
  }
  
  if((data[0] == 'y') || (data[0] == 'Y')){
    int anos = strtol(data+1,NULL, 10);
    anos = constrain(anos, 0, 255);
    analogWrite(yellowPin, anos);
    Serial.print("Amarelo esta definido para: ");
    Serial.println(anos);
  }
}
