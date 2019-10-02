
#define LED_R 6
#define LED_G 7
#define LED_B 8

int r = 0; //0 for white, 1 for red, 2 for green, 3 for blue
int t = 250; //time interval
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  SerialUSB.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  while (SerialUSB.available()){
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
      case '1':
        t = 750;
        break;
      case '0':
        t = 250;
        break;
      case '2':
        t = 1750;
        break;
      case '3':
        t = 2750;
        break;
      case '4':
        t = 3750;
        break;
      case ' ':
      case '\n':
      case '\r':
        break;
      default:
        r = 0;
        SerialUSB.print("Unknown command...");
        SerialUSB.println(c, HEX);
        break; 
      
      }
  }

    switch(r){
      case 0:
        digitalWrite(LED_R, HIGH);   
        digitalWrite(LED_G, HIGH);   
        digitalWrite(LED_B, HIGH);   
        delay(250);                       
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, LOW); 
        delay(t);
        break;  
      case 1:
        digitalWrite(LED_R, HIGH);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, LOW);   
        delay(250);                       
        digitalWrite(LED_R, LOW);   
        delay(t);
        break; 
      case 2:
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, HIGH);   
        digitalWrite(LED_B, LOW);   
        delay(250);                       
        digitalWrite(LED_G, LOW);   
        delay(t);
        break;  
      case 3:
        digitalWrite(LED_R, LOW);   
        digitalWrite(LED_G, LOW);   
        digitalWrite(LED_B, HIGH);   
        delay(250);                       
        digitalWrite(LED_B, LOW);   
        delay(t);
        break;  
    }
}
