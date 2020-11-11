#include <Arduino.h>

//const int IRSENSOR = A0;
const int IRSENSOR = 4;
int SensorValue = 0;
void setup()
{
    Serial.begin(9600);
  pinMode(IRSENSOR,INPUT);
}


void loop()
{
    //SensorValue = analogRead(IRSENSOR);
    SensorValue = digitalRead(IRSENSOR);
    Serial.print(" sensor =  ");
    Serial.println(SensorValue);
    delay(200);
}