
#define LED_R 6
#define LED_G 7
#define LED_B 8

int r = 0;
//0 for white, 1 for red, 2 for green, 3 for blue
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  SerialUSB.begin(0);
}

// the loop function runs over and over again forever
void loop() {
  if (SerialUSB.available()){
    char c = SerialUSB.read();
    switch(c){
      case 'r':
        r = 1;
        break;
      case 'b':
        r = 3;
        break;
      case 'g':
        r = 2;
        break;
      default:
        r = 0;
        SerialUSB.println("Unknown command...");
        SerialUSB.println(c, HEX);
        break; 
      
      }
  }

    switch(r){
      case 0:
        digitalWrite(LED_R, HIGH);   
        digitalWrite(LED_G, HIGH);   
        digitalWrite(LED_B, HIGH);   
        delay(250);                       // wait for a second
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, LOW); 
        delay(250);
        break;  
      case 1:
        digitalWrite(LED_R, HIGH);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, LOW);   
        delay(250);                       // wait for a second
        digitalWrite(LED_R, LOW);   
        delay(250);
        break; 
      case 2:
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, HIGH);   
        digitalWrite(LED_B, LOW);   
        delay(250);                       // wait for a second
        digitalWrite(LED_G, LOW);   
        delay(250);
        break;  
      case 3:
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, HIGH);   
        delay(250);                       // wait for a second
        digitalWrite(LED_B, LOW);   
        delay(250);
        break;  
    }
}
