int sensorPin = A2;         // The analog pin the LM35's Vout is connected to

/*
Initialize serial connection with the computer
*/

void setup()
{
  Serial.begin(9600);       //Begin serial connection with computer
  pinMode(sensorPin, INPUT);
}

void loop()
{
int reading = analogRead(sensorPin);   //read data from LM35 using A0 pin
float voltage = reading *5.0;     //convert sensor data to voltage
voltage /= 1024.0;
Serial.print(voltage);
Serial.println("volts");  //print voltage on serial monitor

float temperatureC=(voltage-0.5)*100;    // convert voltage to temp
Serial.print(temperatureC);Serial.println("degrees C"); //print temp to serial monitor

// if(temperatureC >XXXX){
//    digitalWrite(ledPin, HIGH);
//    delay(1000);
//    digitalWrite(ledpin, LOW);
//    delay(1000);
// }
// else{
//    digitalWrite(ledPin, Low);
// }

delay(1000);          // print every second



}
