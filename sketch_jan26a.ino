#include "Frequencias.h"
#define MIN_DISTANCIA 50



int echo = 13;     // Pin para echo                          
int trigger = 12; // Pin para trigger                               
int speaker = 10; // Pin para o speaker
unsigned long tempoResposta;
unsigned long distancia;
int limiteInferior = 5;
int limiteSuperior = 80;
int quantidadeNotas = 12;

int notas[]={NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4,NOTE_C5}; //Escala cromatica

void setup() {
  pinMode(speaker, OUTPUT);                  
  pinMode(trigger, OUTPUT);                     
  pinMode(echo, INPUT);   
  Serial.begin(9600);                 
 } 

void loop() {
  digitalWrite(trigger, HIGH);            // Enviando pulso de 10 microsegundos
  delayMicroseconds(10);                        
  digitalWrite(trigger, LOW);                   
  tempoResposta = pulseIn(echo, HIGH);  // esperamos retorno do pulso
  distancia = tempoResposta/58;         // Cálculo de distancia em cm
  
  if (distancia >= limiteInferior && distancia <= limiteSuperior) {
    int x=map(distancia,limiteInferior,limiteSuperior,0,((quantidadeNotas-1)*10));
    tone(speaker, notas[x/10]);
    delay(100);
  
  }  
  else{
    noTone(speaker);
  }
   
}
