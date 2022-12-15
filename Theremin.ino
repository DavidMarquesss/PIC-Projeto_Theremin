//#include <pitches.h>
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
  delay(30);                    // Wait 30ms between pings (about 33 pings/sec). 29ms should be the shortest delay between pings.
  distancia = ultrasonic.read(); //reads the distance from the sensor
  if(distancia < 120 )             //range is about 120 cm
  {
    int freq= 1500-distancia*10;   //calculates a corresponding freqeuncy
    toneAC(freq, speaker);    //plays the sound!(output through speaker- pin10)
    
    Serial.println(distancia);     //just for monitoring if required
  }
  else
  {
   noToneAC();  //out of range 
  }

}
