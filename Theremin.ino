
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
