/* Transmitter */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN Pins
const uint64_t address = 0xF0F0F0F0E1LL;

String data;
char karakter;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() 
{
  while (Serial.available()>0){
    
    karakter = Serial.read();
    //data.concat(karakter);
  }
  
  radio.write(&karakter, sizeof(karakter));
  
}
