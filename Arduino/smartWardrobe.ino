#include <SPI.h>
#include <RFID.h>
#include <string.h>

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

String id = "rfid:";
String idx = "set:";
String idx2 = "get:";
String p_check = "p:";
bool check = false;
String message = "";
void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
  Serial.print("Oke");
  pinMode(18, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(18), slot1, RISING);
  attachInterrupt(digitalPinToInterrupt(19), slot2, RISING);
  attachInterrupt(digitalPinToInterrupt(20), slot3, RISING);
  attachInterrupt(digitalPinToInterrupt(21), slot4, RISING);
}
void sendRFID(String data){
  Serial.println(data);
  
}
//void readDistance(){
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
//  // Displays the distance on the Serial Monitor
//  if (distance <= 35){
//    String checkpeople = "p:1";
//    sendRFID(checkpeople);
//  }
//  else{
//    String checkpeople = "p:0";
//    sendRFID(checkpeople);
//  }
//}

void slot1(){
  message = "";
  message += idx;
  message += "A_1:";
  readRFID();
}
void slot2(){
  message = "";
  message += idx;
  message += "A_2:";
  readRFID();
}
void slot3(){
  message = "";
  message += idx;
  message += "A_3:";
  readRFID();
}
void slot4(){
  message = "";
  message += idx;
  message += "A_4:";
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
void loop()
{

}
