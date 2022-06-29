#include <SPI.h>
#include <RFID.h>
#include <string.h>
 
const int trigPin = 23;
const int echoPin = 25;
/* Ket noi chan (Arduino Mega)
 *  Reset     5
 *  SPI SDA   53
 *  SPI MOSI  51
 *  SPI MISO  50
 *  SPI SCK   52
 */

#define SDA_DIO 53
#define RESET_DIO 5

RFID RC522(SDA_DIO, RESET_DIO);
long duration;
int distance;
String id = "rfid:";
String idx = "set:";
String idx2 = "get:";
String p_check = "p:";
bool check = false;
String message = "";
int checkcount1 = 0;
int checkcount2 = 0;
bool isperson = false;
void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
//  Serial.print("Oke");
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  attachInterrupt(digitalPinToInterrupt(18), slot1, RISING);
  attachInterrupt(digitalPinToInterrupt(19), slot2, RISING);
  attachInterrupt(digitalPinToInterrupt(20), slot3, RISING);
  attachInterrupt(digitalPinToInterrupt(21), slot4, RISING);
  pinMode(15,OUTPUT);
}
void sendRFID(String data){
  Serial.println(data);
  
}
void readDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.println(distance);

  if (distance <= 35  && !isperson){
    if (checkcount1 <= 20) {
      checkcount1++; 
    }
    else {
      isperson = true;
      checkcount1 = 0;
      Serial.println("p:1");
    }
  }
  else if (distance >=  35  && isperson){
    if (checkcount2 <= 20) {
      checkcount2++;
    }
    else {
      isperson = false;
      checkcount2 = 0;
      Serial.println("p:0");
    }
  }
  
  
}
void openDoor(){
  digitalWrite(15,LOW);
  delay(1000);
}

void slot1(){
  message = "";
  message += idx;
  message += "A_1:";
  Serial.print("Slot 1");
  readRFID();
}
void slot2(){
  message = "";
  message += idx;
  message += "A_2:";
  Serial.print("Slot 2");
  readRFID();
}
void slot3(){
  message = "";
  message += idx;
  message += "A_3:";
  Serial.print("Slot 3");
  readRFID();
}
void slot4(){
  message = "";
  message += idx;
  message += "A_4:";
  Serial.print("Slot 4");
  readRFID();
}
void readRFID(){
  bool state = true;
  while (state){
    if (RC522.isCard()){
      RC522.readCardSerial();
      String b = "";
      for(int i = 0 ; i < 5; i++){
        b+= String(RC522.serNum[i]);
      }
      message += b;
      sendRFID(message);
      state = false;
    }
  }
}
void loop(){
  readDistance();
}
