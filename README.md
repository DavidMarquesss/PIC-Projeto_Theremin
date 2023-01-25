# PIC-Projeto_Theremin
## O que é o Projeto?

<p>Projeto que consiste em um instrumento theremin usando um sensor ultrassônico, no qual um auto-falante emite frequências sonoras diferentes em relação a proximidade com o sensor ultrassônico utilizado num raio de 120 cm e controle do volume do alto-falante feito por um potenciômetro.</p>

<p>Por meio da biblioteca Ultrasonic.h é usada a função que por meio dos pinos de trigger e echo conectados ao circuito, é retornado uma distancia em centímetros.Esse distancia é utilizada para calcular uma frequencia por meio da fórmula <b>Frequência = 1500 - (distância * 10)</b>. Esse valor de frequência calculado em seguida, usando a biblioteca toneAC, é passado a frequência a ser aplicada e escutada pelo speaker. O controle de volume é realizado por um potenciômetro conectado ao positivo do speaker.</p>

<p>Pensando em um compartimento para armazenar os componentes e fios do projeto, planejamos a construção de uma caixa. Utilizando a Matemateca do Departamento de Matemática da UFES, que consiste em um laboratório de pesquisas na área de marcenaria e eletrônica, conseguimos planejar melhor um esquema da caixa e utilizando o maquinário do laboratório conseguimos realizar sua construção e melhoramento da estética proposta inicialmente.</p>


## Componentes
- 1x Sensor Ultrassônico
- 1x Potenciômetro
- Jumpers
- Arduino UNO
- 1x Speaker 0.5w 8Ω
- Protoboard
- Alimentação (Usado no projeto uma bateria 9V)

### Esquemático
![a](https://github.com/DavidMarquesss/PIC-Projeto_Theremin/blob/main/Amazing%20Tumelo.png)
<p>Obs.: No esquemático a seguir foi utilizado um Buzzer para demostrar o speaker, possuindo a mesma pinagem</p>

## Código
```
  #include <toneAC.h>
  #include <Ultrasonic.h>

  #define speaker 10
  int distancia;

  Ultrasonic ultrasonic(12, 13); //define os pinos 12 - Trigger e 13 - Echo para o sensor ultrassonico

  void setup() {
    Serial.begin(9600);

  }

  void loop() 
  {
    delay(30);                    
    distancia = ultrasonic.read(); //Pega a leitura de distancia em centímetros do sensor ultrassonico (limite de 120 cm)
    if(distancia < 120 )             
    {
      int freq= 1500-distancia*10;  //calculo para a frequencia que sera em seguida escutada pelo speaker 
      toneAC(freq, speaker);    

      Serial.println(distancia); //mostra a distancia no serial monitor para checagens    
    }
    else
    {
     noToneAC();   //caso esteja fora do alcance nada eh tocado
    }

  } 
  ```



