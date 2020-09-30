const int sensor = 0;

float temperatura = 0;
int leitura = 0;

void setup(){
  Serial.begin(9600);     //ira coletar ou escrever no arduino usando um porta serial, o numero 
                          //é a taxa dados que a placa ira se comunicar
  analogReference(INTERNAL);  
}

void loop(){
  leitura = analogRead(sensor);
  temperatura = leitura * 0.1075268817;
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(1000);
}

