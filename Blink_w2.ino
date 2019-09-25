
#define LED_R 6
#define LED_G 7
#define LED_B 8
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_R, HIGH);   
  digitalWrite(LED_G, HIGH);   
  digitalWrite(LED_B, HIGH);   
  // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(LED_R, LOW);   
  digitalWrite(LED_G, LOW);   
  digitalWrite(LED_B, LOW); 
  delay(250);                       // wait for a second
}
