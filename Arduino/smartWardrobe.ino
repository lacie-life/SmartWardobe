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
}
void sendRFID(String data){
  Serial.println(data);
  
}
void slot1(){
  message = "";
  message += idx;
  message += "A_1:";
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
