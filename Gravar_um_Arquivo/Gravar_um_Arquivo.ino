#include <SdFat.h>
#include <SD.h>

// Projeto 42

Sd2Card card;
SdVolume volume;
SdFile root;
SdFile file;

//armazena strings de erro em memoria flash, para economizar RAM
#define error(s) error_P(PSTR(s))

void error_P(const char* str){
  PgmPrint("Error: ");
  Serial.println_P(str);
  if(card.errorCode()){
    PgmPrint("SD error: ");
    Serial.print(card.errorCode(), HEX);
    Serial.print(',');
    Serial.println(card.errorData(), HEX);
  }
  while(1);
}

//Escreve um retorno de carro (CR) e uma alimentação de linha (LF) no arquivo
void writeCRLF(SdFile& f){
  f.write((uint8_t*)"\r\n",2);
}

//Escreve um numero não sinalizado no arquivo
void escreveNumero(SdFile& f, uint32_t n){
  uint8_t buf[10];
  uint8_t i = 0;
  do{
    i++;
    buf[sizeof(buf) - i] = n%10 +'0';
    n /= 10;
  }while(n);
  f.write(&buf[sizeof(buf)-i], i);
}

//Escreve uma string no arquivo
void escreveSring(SdFile& f, char *str){
  uint8_t n;
  for(n = 0; str[n]; n++);
    f.write((uint8_t *)str, n);
}

void setup(){
  Serial.begin(9300);
  Serial.println();
  Serial.println("Iniciando qualquer tipo de caracter...");
  while(!Serial.available());

  /*Inicializa o cartão SD em SPI_HALF_SPEED, para evitar erros de barramento com
    as protoboards.
    Utilize SPI_FULL_SPEED para um melhor desempelho, caso ocartao suporte essa opcao
  */
  if (!card.init(SPI_HALF_SPEED)) error("card.init falhou");

  //Inicializa um volume FAT
  if(!volume.init(&card)) error("volume.init falhou");

  //Abre o diretorio Raiz
  if(!root.openRoot(&volume)) error("openRoot falhou");

  //Cria um novo arquivo
  char nome[] = "TesteArduino.txt";

  file.open(&root, nome, 0_CREAT | O_EXCL | 0_WRITE);

  //Coloca a data e a hora atual
  file.timestamp(31, 12, 2017, 14, 10, 20, 36);

  //Escreve 10 linhas no arquivo
  for(uint8_t x = 0; x <10; x++){
    escreveString(file, "Linha: ");
    escreveNumero(file, x);
    escreveString(file, "Teste de Escrita");
    writeCRLF(file);
  }

  //Fecha o arquivo e força uma operação de escrita de todos os dados para o cartão SD
  file.close;
  Serial.println("Arquivo Criado");

  //Abre um arquivo
  if(file.open(&root, nome, O_READ)){
   Serial.println(nome); 
  
  }else{
    error("file.open Falhou");
  }
  Serial.print();

  int16_t caracter;

  while((caracter =file.read()) > 0) Serial.print((char)caracter);

  Serial.print("\nFeito");
}

void (){
}

