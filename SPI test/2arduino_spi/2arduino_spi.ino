#include <SPI.h>
int swi=0;
void setup()
{
   digitalWrite(SS, HIGH); 
     SPI.begin ();
     SPI.setClockDivider(SPI_CLOCK_DIV8);

}  // end of setup


void loop (void)
{

  char c;

  // enable Slave Select
  digitalWrite(SS, LOW); 

  if(swi==0)
  {
    for (const char * p = "Hello, world!\n" ; c = *p; p++)
    SPI.transfer (c);
  }
  else
  {
    for (const char * p = "byebye, world!\n" ; c = *p; p++)
    SPI.transfer (c);
    }

  digitalWrite(SS, HIGH);
  swi=1-swi;

  delay(1000);
  
  }
     
