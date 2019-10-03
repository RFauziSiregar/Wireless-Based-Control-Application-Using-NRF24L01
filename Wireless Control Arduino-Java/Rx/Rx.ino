/* Receiver */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN Pins
const uint64_t address = 0xF0F0F0F0E1LL;

const int Led1 = 2;
const int Led2 = 3;
const int Led3 = 4;
const int Led4 = 5;

String data;
char recvData;


void setup() 
{
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() 
{
  if (radio.available()) {
    data.concat(recvData);
    
    if(data.equals("A") == true){
      digitalWrite(Led1, HIGH);
    }
    else if(data.equals("B") == true){
      digitalWrite(Led1, LOW);
    }
    else if(data.equals("C") == true){
      digitalWrite(Led2, HIGH);
    }
    else if(data.equals("D") == true){
      digitalWrite(Led2, LOW);
    }
    else if(data.equals("E") == true){
      digitalWrite(Led3, HIGH);
    }
    else if(data.equals("F") == true){
      digitalWrite(Led3, LOW);
    }
    else if(data.equals("G") == true){
      digitalWrite(Led4, HIGH);
    }
    else if(data.equals("H") == true){
      digitalWrite(Led4, LOW);
    }
    data="";
    radio.read(&recvData, sizeof(recvData));
    Serial.println(recvData);
  }
}
