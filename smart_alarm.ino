#include "BluetoothSerial.h"
const int trigPin = 12;
const int echoPin = 13;

int hh=0;

int check = 0;
int thre=0; 

BluetoothSerial SerialBT;
byte BTData;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   pinMode(27, OUTPUT);
  digitalWrite(27,LOW);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  float duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  float distanceCm = (duration/2) * 0.034;
  
  // Convert to inches
 float distanceInch = distanceCm / 2.5;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  if(dcm>50 && hh == 0){
    digitalWrite(27,HIGH);
  }


  if(dcm<=50 && dcm>=10 && hh == 0){
    digitalWrite(27,LOW);
    delay(5000);
    digitalWrite(27,HIGH);
    
  }
  

  if(dcm<10){
    digitalWrite(27,LOW);
    hh = 1;
    
  }

  
  delay(1000);
}
