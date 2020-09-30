//Projeto 12 - Tocador de melodias

#define NOTA_C3  131
#define NOTA_CS3 139
#define NOTA_D3  147
#define NOTA_DS3 156
#define NOTA_E3  165
#define NOTA_F3  175
#define NOTA_FS3 185
#define NOTA_G3  196
#define NOTA_GS3 208
#define NOTA_A3  220
#define NOTA_AS3 233
#define NOTA_B3  247
#define NOTA_C4  262
#define NOTA_CS4 277
#define NOTA_D4  294
#define NOTA_DS4 311
#define NOTA_E4  330
#define NOTA_F4  349
#define NOTA_FS4 370
#define NOTA_G4  392
#define NOTA_GS4 415
#define NOTA_A4  440
#define NOTA_AS4 466
#define NOTA_B4  494

#define todo 1
#define meio 0.5
#define quarto 0.25
#define oitavo 0.125
#define decimo_sexto 0.0625

int afinacao[] = { NOTA_C4,
               NOTA_C4,
               NOTA_C4,
               NOTA_C4,
               NOTA_C4,
               NOTA_B3,
               NOTA_G3,
               NOTA_A3,
               NOTA_C4,
               NOTA_C4,
               NOTA_G3,
               NOTA_G3,
               NOTA_F3,
               NOTA_F3,
               NOTA_G3,
               NOTA_F3,
               NOTA_E3,
               NOTA_G3,
               NOTA_C4,
               NOTA_C4,
               NOTA_C4,
               NOTA_C4,
               NOTA_A3,
               NOTA_B3,
               NOTA_C4,
               NOTA_D4 };
              
float duracao[] = { oitavo, quarto+oitavo, decimo_sexto, quarto, quarto, meio, meio,
                    meio, quarto, quarto, meio+quarto, quarto, quarto, quarto, quarto+oitavo, oitavo,
                    quarto, quarto, quarto, oitavo, oitavo, quarto, quarto, quarto, quarto, meio+quarto    
                   };
int tamanho;
int buzzer = 8;

void setup(){
  pinMode(buzzer, OUTPUT);
  tamanho = sizeof(afinacao) / sizeof(afinacao[0]);
}

void loop(){
  for(int x=0; x < tamanho; x++){
    tone(buzzer, afinacao[x]);
    delay(1500 * duracao[x]);
    noTone(buzzer);
  }
  //delay(1);
}
