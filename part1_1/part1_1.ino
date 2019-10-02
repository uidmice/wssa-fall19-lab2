
#define LED_R 6
#define LED_G 7
#define LED_B 8
void setup() {
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

 /*---------toggle Red-------------*/
  digitalWrite(LED_G, LOW);   
  digitalWrite(LED_B, LOW); 

 /*---------toggle Green-------------*/
  //digitalWrite(LED_R, LOW);   
  //digitalWrite(LED_B, LOW); 

 /*---------toggle Blue-------------*/
  //digitalWrite(LED_R, LOW);   
  //digitalWrite(LED_G, LOW); 
}

int redValue = 150;
int greenValue = 200;
int blueValue = 50;

void loop() {
 /*---------toggle Red-------------*/
  digitalWrite(LED_R, HIGH);    
  delay(250);                       
  digitalWrite(LED_R, LOW);   
  delay(250);     
 /*---------toggle Green-------------*/
//  digitalWrite(LED_G, HIGH);    
//  delay(250);                       
//  digitalWrite(LED_G, LOW);   
//  delay(250);     
//
 /*---------toggle Blue-------------*/
//  digitalWrite(LED_B, HIGH);    
//  delay(250);                       
//  digitalWrite(LED_B, LOW);   
//  delay(250);     

 /*---------toggle white-------------*/
//  digitalWrite(LED_R, HIGH);   
//  digitalWrite(LED_G, HIGH);   
//  digitalWrite(LED_B, HIGH);   
//  delay(250);                      
//  digitalWrite(LED_R, LOW);   
//  digitalWrite(LED_G, LOW);   
//  digitalWrite(LED_B, LOW); 
//  delay(250);      
 /*---------toggle colors-------------*/
//  analogWrite(LED_R, redValue);   
//  analogWrite(LED_G, greenValue);   
//  analogWrite(LED_B, blueValue);   
//  delay(250);                      
//  analogWrite(LED_R, LOW);   
//  analogWrite(LED_G, LOW);   
//  analogWrite(LED_B, LOW); 
//  delay(250);                   
}
