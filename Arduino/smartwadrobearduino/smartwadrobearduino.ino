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
bool checkgetslot = false;
bool checkinterupt = false;
void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
//  Serial.print("Oke");
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  attachInterrupt(digitalPinToInterrupt(18), slot1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(19), slot2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(20), slot3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(21), slot4, CHANGE);
  pinMode(15,OUTPUT);
  digitalWrite(15,HIGH);
}
void sendRFID(String data){
  Serial.print(data);
  
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
      Serial.print("p:1");
    }
  }
  else if (distance >=  35  && isperson){
    if (checkcount2 <= 20) {
      checkcount2++;
    }
    else {
      isperson = false;
      checkcount2 = 0;
      Serial.print("p:0");
    }
  }
  
  
}
void openDoor(){
  digitalWrite(15,LOW);
  delay(1000);
}

void slot1(){
  if (digitalRead(18) == HIGH){
  message = "";
  message += idx;
  message += "A_1:";
  readRFID();
  }
}
void slot2(){
  if (digitalRead(19) == HIGH){
  message = "";
  message += idx;
  message += "A_2:";
 
  readRFID();
  }
}
void slot3(){
  if (digitalRead(20) == HIGH){
  message = "";
  message += idx;
  message += "A_3:";
 
  readRFID();
  }
}
void slot4(){
  if (digitalRead(21) == HIGH){
  message = "";
  message += idx;
  message += "A_4:";
  readRFID();
  }
}
void readRFID(){
  bool state = true;
  if (checkinterupt){
    if (!checkgetslot){
    
    
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
  }
}
void readSerialString(){
  String incomingString;
  if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();
    checkgetslot = true;
    Serial.print(incomingString);
  }
  else{
    checkgetslot = false;
  }
  char opendoor = "";
  char slot = "";
  if (incomingString.length() == 3){
    opendoor = incomingString.charAt(0);  
  }
  else {
    opendoor = incomingString.charAt(0);
    slot = incomingString.charAt(5);  
  }
  
  
  bool getcheck= true;
  switch (slot){
    case '1':
      digitalWrite(8,HIGH); //8
      while(getcheck){
      if (digitalRead(18)){
        digitalWrite(6,LOW);
        Serial.print("checkdone1");
        getcheck = false;
      }
      }
      break;
    case '2':
      digitalWrite(6,HIGH);//
      while(getcheck){
      if (digitalRead(19)){
        digitalWrite(7,LOW);
        getcheck = false;
        Serial.print("checkdone2");
      }
      }
      break;
      case '3':
      digitalWrite(7,HIGH); //7
      while(getcheck){
      if (digitalRead(20)){
        digitalWrite(8,LOW);
        getcheck = false;
        Serial.print(slot);
        Serial.print("checkdone3");
      }
      }
      break;
      
      case '4':
      digitalWrite(10,HIGH);
      while(getcheck){
      if (digitalRead(21)){
        digitalWrite(10,LOW);
        getcheck = false;
        Serial.print("checkdone4");
      }
      }
      break;
  }
  if(opendoor == 'd'){
    checkinterupt = false;
    digitalWrite(15,LOW);
    delay(3000);
    digitalWrite(15,HIGH); 
    Serial.print("opendone");
  }
  else if (opendoor == 'o'){
    checkinterupt = true;
  }
  else if (opendoor == 'A'){
    checkinterupt = true;
  }
}
void loop(){
  readDistance();
  readSerialString();
}
