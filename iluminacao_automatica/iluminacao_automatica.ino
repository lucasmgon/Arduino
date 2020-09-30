const int ldr = 0;
const int led = 6;

int leitura = 0;
int pwm = 0;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  leitura = analogRead(ldr);
  Serial.print("Valor Lido e: ");
  Serial.println(leitura);
  delay(500);

  if(leitura < 50){
    analogWrite(led, pwm);
    pwm++;
    delay(100);
  }else{
    digitalWrite(led, LOW);
    pwm = 0;
  }

  if(pwm > 255){
    pwm = 255;
  }
}
