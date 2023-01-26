# PIC-Projeto_Theremin
## O que é o Projeto?

<p>Projeto que consiste em um instrumento theremin usando um sensor ultrassônico, no qual um auto-falante emite frequências sonoras diferentes em relação a proximidade com o sensor ultrassônico utilizado num raio de 120 cm e controle do volume do alto-falante feito por um potenciômetro.</p>

<p>Usando um arquivo ".h" público de frequências para a definição de notas a serem usadas no código principal, é definido primeiramente os os pins de echo e trigger do sensor ultrassônico, em seguido do speaker. Em seguida, é enviado o pulso pelo sensor e captado em seguida. Como foi definido limite minimo de captação da distancia em 5cm e máximo de 80cm, caso seja detectado algo nesse intervalo, é mapeado um valor x, que é dividido por 10 para ser liberado o som no speaker.</p>

<p>Pensando em um compartimento para armazenar os componentes e fios do projeto, planejamos a construção de uma caixa. Utilizando a Matemateca do Departamento de Matemática da UFES, que consiste em um laboratório de pesquisas na área de marcenaria e eletrônica, conseguimos planejar melhor um esquema da caixa e utilizando o maquinário do laboratório conseguimos realizar sua construção e melhoramento da estética proposta inicialmente.</p>


## Componentes
- 1x Sensor Ultrassônico
- 1x Potenciômetro
- Jumpers
- Arduino UNO
- 1x Speaker 0.5w 8Ω
- Alimentação (Usado no projeto uma bateria 9V)

### Esquemático
![a](https://github.com/DavidMarquesss/PIC-Projeto_Theremin/blob/main/Amazing%20Tumelo.png)
<p>Obs.: No esquemático a seguir foi utilizado um Buzzer para demostrar o speaker, possuindo a mesma pinagem</p>

## Código
```
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
  ```



