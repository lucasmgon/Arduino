const int PinPotenciometro = A0;
const int led = 11;

int valor = 0;
int pwm = 0;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  valor = analogRead(PinPotenciometro);
  pwm = map(valor, 0 , 1023, 0, 255);
// Variável Recebedora = map(Valor Lido, Mínimo do Potenciômetro, Máximo do Potenciômetro, 
//Novo Mínimo definido por você, Novo Máximo definido por você)
  analogWrite(led, pwm);
}

