#include <SPI.h>

/* SPI Pins used:
  MISO = 12
  SCK = 13
  SS = 10
  */

const int adcCS = 10; // Control  slave device

int adcValue=0;//value in  ADC output register
byte dummyByte;// allows the conversion cycle to complete.
byte upperByte;//Most significant BIT
byte lowerByte;//Least significant BIT


void setup(){
 SPI.begin();
 SPI.setDataMode(SPI_MODE1);
 pinMode(adcCS, OUTPUT);
 Serial.begin(9600);

 
// Initializethe chip  
digitalWrite (adcCS, LOW);
dummyByte = SPI.transfer(0); // Initialization/Reset clocks
digitalWrite (adcCS,  HIGH);
 
}
 
 void loop(){
  Serial.println("\n"); 
  digitalWrite (adcCS, LOW); //Enable SPI
  upperByte = SPI.transfer(0);  
  Serial.println(upperByte);
  lowerByte = SPI.transfer(0);  
  Serial.println(lowerByte);
  dummyByte = SPI.transfer(0); 
  digitalWrite (adcCS,  HIGH); //Disable SPI
  adcValue = (upperByte<<8) + lowerByte; // Move upperByte to left, then add the lowerByte.
   
  Serial.println(upperByte<<8);
    
  Serial.println((upperByte<<8)+ lowerByte);
   
  Serial.println(adcValue, DEC);//Prints the ADC Value to Serial port.
                                 //Converts from binary to decimal.

  Serial.println("\n"); 
  delay(250);
}
 
