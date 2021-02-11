#include <SPI.h>

byte ssPin = 10;
byte incomingByte;
byte addressToRead = 0x02;

 
void setup()
{
  Serial.begin(9600);
  pinMode (ssPin, OUTPUT);
  digitalWrite (ssPin, HIGH); 
  SPI.begin(); 
  }

void loop()
{
  digitalWrite (ssPin, LOW); // select  device
  SPI.transfer (addressToRead); 
  incomingByte = SPI.transfer(0); // read a byte from the slave 
  digitalWrite (ssPin, HIGH); // deselect the device
  Serial.println(addressToRead);
  Serial.println(incomingByte); 
  delay(500); 
}
