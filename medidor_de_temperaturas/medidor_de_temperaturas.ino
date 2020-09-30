//Projeto 36

#define sensorPin 0

float celsis, fahrenheit, kelvin;
int sensorValor;

void setup(){
  Serial.begin(9600);
  Serial.print("Iniciando...");
}

void loop(){
  temperatura();
  Serial.print("Celsius: ");
  Serial.println(celsius);
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
  Serial.print("Kelvin: ");
  Serial.println(kelvin);
  delay(2000);
}

void temperatura(){
  sensorValor = analogRead(sensorPin);
  kelvin = (((float(sensorValue) / 1023) * 5) * 100);
  celsius = kelvin - 273.15;
  fahrenheit = (celsius * 1.8) +32;
}

