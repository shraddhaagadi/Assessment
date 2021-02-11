int sensorPin = A2;         



void setup()
{
  Serial.begin(9600);       
  pinMode(sensorPin, INPUT);
}

void loop()
{
int reading = analogRead(sensorPin);   
float voltage = reading *5.0;     //convert sensor data to voltage
voltage /= 1024.0;
Serial.print(voltage);
Serial.println("volts");  //print voltage on serial monitor

float temperatureC=(voltage-0.5)*100;    // convert voltage to temp
Serial.print(temperatureC);
Serial.println("degrees C"); //print temp to serial monitor

// if(temperatureC >XXXX){
//    digitalWrite(ledPin, HIGH);
//    delay(1000);
//    digitalWrite(ledpin, LOW);
//    delay(1000);
// }
// else{
//    digitalWrite(ledPin, Low);
// }

delay(1000);         



}
