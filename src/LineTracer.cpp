#include <Arduino.h>

#define motorlf 6
#define motorlb 7
#define motorls 5
#define motorrf 10
#define motorrb 11
#define motorrs 9

#define sensorL 12
#define sensorR 13
#define sensorC 8

// int sensorvalue = 0;

void setup() {
  pinMode(motorlf, OUTPUT);
  pinMode(motorlb, OUTPUT);
  pinMode(motorrf, OUTPUT);
  pinMode(motorrb, OUTPUT);
  pinMode(sensorL, INPUT);
  pinMode(sensorR, INPUT);
  pinMode(sensorC, INPUT);
  Serial.begin(9600);
}

/*void loop(){
  analogWrite(motorls, 50);
  digitalWrite(motorlf, HIGH);
  digitalWrite(motorlb, LOW);
  //digitalRead(sensorL);
  sensorvalue = digitalRead(sensorL);
  Serial.print(" value : ");
  Serial.println(sensorvalue);
  delay(200);
}*/
void motor_control(char L, char R, int m1_speed, int m2_speed){
  if(L == 1){
    digitalWrite(motorlf, HIGH);
    digitalWrite(motorlb, LOW);
    analogWrite(motorls, m1_speed);
  }
  else if(L == 0){
    digitalWrite(motorlf, LOW);
    digitalWrite(motorlb, HIGH);
    analogWrite(motorls, m1_speed);
  }
  if(R == 1){
    digitalWrite(motorrf, LOW);
    digitalWrite(motorrb, HIGH);
    analogWrite(motorrs, m2_speed);
  }
  else if(R == 0){
    digitalWrite(motorrf, HIGH);
    digitalWrite(motorrb, LOW);
    analogWrite(motorrs, m2_speed);
  }
}

int infraRed_value = 0;

int sensor_read(int i){
  infraRed_value = digitalRead(i);
  return infraRed_value;
}


//char LL;
//char RR;
//char F;
int way = 0;
void way_go(int n){
  if(n == 4){
    motor_control(0, 1, 0, 60);
    Serial.println(n);
  }
  else if(n == 6){
    motor_control(1, 0, 60, 0);
    Serial.println(n);
  }
}

void loop() {
  // forward
  if((sensor_read(sensorL)) && (sensor_read(sensorR))){
    if(sensor_read(sensorC) == 0){
      motor_control(1, 1, 60, 60);
      Serial.print("  Forward ");
      Serial.println(digitalRead(sensorC));
    }
    else{
      way_go(way);   
      Serial.println(digitalRead(sensorC));
      Serial.print(" way go "); 
    }
  }
  // if((sensor_read(sensorL)) && (sensor_read(sensorR))){
  //   if(sensor_read(sensorC)){
  //     way_go(way);   
  //     Serial.println(digitalRead(sensorC));
  //     Serial.print(" way go ");   
  //   }
  // }
  
  // right
  if(sensor_read(sensorL) && sensor_read(sensorR) == 0){
    /*if(sensor_read(sensorC == 0)){
      motor_control(1, 1, 200, 0);
      way = 6;
    }
    else if(sensor_read(sensorC == 1)){
      motor_control(1, 1, 200, 0);
      way = 6;
    }*/
    motor_control(1, 1, 60, 20);
    way = 6;
  }
  //left
  if(sensor_read(sensorR) && sensor_read(sensorL) == 0){
    /*if(sensor_read(sensorC == 0)){
      motor_control(1, 1, 0, 200);
      way = 4;
    }
    else if(sensor_read(sensorC == 1)){
      motor_control(1, 1, 0, 200);
      way = 4;      
    }*/
    motor_control(1, 1, 20, 60);
    way = 4;
  }
  /*else if({
    motor_control(1, 1, 150, 150);
  }*/
}