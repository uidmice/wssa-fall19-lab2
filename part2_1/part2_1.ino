#include <FreeRTOS_ARM.h>
#define LED_R 6
#define LED_G 7
#define LED_B 8
void setup() {
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  SerialUSB.begin(9600);
  while(!SerialUSB);

  //Print the minimal stack size in words
  SerialUSB.println(configMINIMAL_STACK_SIZE);  //130 words

  //Print the tick rate
  SerialUSB.println(configTICK_RATE_HZ);  //1000Hz
  

  portBASE_TYPE s = xTaskCreate(Blink, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  // check for creation errors
  if ( s != pdPASS ) {
    SerialUSB.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();
  SerialUSB.println("Insufficient RAM");
  while(1);

}

static void Blink(void* arg){
  while(1){
  digitalWrite(LED_R, HIGH);   
  digitalWrite(LED_G, HIGH);   
  digitalWrite(LED_B, HIGH);   

  vTaskDelay((500L*configTICK_RATE_HZ)/1000L);  
  digitalWrite(LED_R, LOW);   
  digitalWrite(LED_G, LOW);   
  digitalWrite(LED_B, LOW); 
  vTaskDelay((500L*configTICK_RATE_HZ)/1000L);  }
}

void loop() {

}
