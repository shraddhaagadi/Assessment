#define LED_PIN1      7
#define LED_PIN2      8
//#define BLINK_SPEED  1000

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN1, HIGH);
  delay(1000);
  digitalWrite(LED_PIN1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(LED_PIN2, HIGH);
  delay(1000);
  digitalWrite(LED_PIN2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
