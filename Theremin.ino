
#include <toneAC.h>
#include <Ultrasonic.h>

#define speaker 10
int distancia;

Ultrasonic ultrasonic(12, 13);

void setup() {
  Serial.begin(9600);

}

void loop() 
{
  delay(30);                    
  distancia = ultrasonic.read(); 
  if(distancia < 120 )             
  {
    int freq= 1500-distancia*10;   
    toneAC(freq, speaker);    
    
    Serial.println(distancia);     
  }
  else
  {
   noToneAC();   
  }

}
