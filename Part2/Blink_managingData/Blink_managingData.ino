#include <FreeRTOS_ARM.h>
#define LED_R 6
#define LED_G 7
#define LED_B 8
#define PD_RED 1
#define PD_GREEN 2
#define PD_BLUE 3
#define PD_YELLOW 4
#define PD_PURPLE 5
#define PD_TIEL 6
#define PD_WHITE 7
#define PD_OFF 8

#define pd_rgb_led_init() { \
  pinMode(LED_R, OUTPUT); \
  pinMode(LED_G, OUTPUT); \
  pinMode(LED_B, OUTPUT); \
  digitalWrite(LED_R, LOW); \
  digitalWrite(LED_G, LOW); \
  digitalWrite(LED_B, LOW); \
}

#define pd_rgb_led(color) { \
  if(color == PD_RED || color == PD_YELLOW || color == PD_PURPLE || color == PD_WHITE){ \
    digitalWrite(LED_R, HIGH); \
  }else{ \
    digitalWrite(LED_R, LOW); \
  } \
  if(color == PD_GREEN || color == PD_YELLOW || color == PD_TIEL || color == PD_WHITE){ \
    digitalWrite(LED_G, HIGH); \
  }else{ \
    digitalWrite(LED_G, LOW); \
  } \
  if(color == PD_BLUE || color == PD_PURPLE || color == PD_TIEL || color == PD_WHITE){ \
    digitalWrite(LED_B, HIGH); \
  }else{ \
    digitalWrite(LED_B, LOW); \
  } \
}

SemaphoreHandle_t sem;
char pcColorSeq[20]; //Max length of the color sequence is 20
pcColorSeq="0";

void setup() {
  pd_rgb_led_init();

  SerialUSB.begin(9600);
  while(!SerialUSB);

  SerialUSB.println(pcColorSeq);

  sem = xSemaphoreCreateBinary();
  xSemaphoreGive(sem);

  portBASE_TYPE s1 = xTaskCreate(LEDBlink, NULL, configMINIMAL_STACK_SIZE, (void*)pcColorSeq, 2, NULL);
  portBASE_TYPE s2 = xTaskCreate(ReadInput, NULL, configMINIMAL_STACK_SIZE, (void*)pcColorSeq, 1, NULL);

  
  // check for creation errors
  if ( sem==NULL || s1 != pdPASS || s2 != pdPASS  ) {
    SerialUSB.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();
  SerialUSB.println("Insufficient RAM");
  while(1);

}

static void ReadInput(void* arg){
  char *pcCol = (char*) arg;

  while(1){
            SerialUSB.println("Reading");

    xSemaphoreTake(sem, portMAX_DELAY);
    byte i = 0;
    if (SerialUSB.available()<20 && SerialUSB.available()>0){
      SerialUSB.println(i);
      *(pcCol+i) = SerialUSB.read();
      if (*(pcCol+i)!='\n' && *(pcCol+i)!='\r') 
        i++;
    }
    *(pcCol+i)='\0';
    xSemaphoreGive(sem);
    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

  }
    
    
}

static void LEDBlink(void* arg){
  char *pcCol = (char*) arg;
  while(1){
            SerialUSB.println("Blinking");

    xSemaphoreTake(sem, portMAX_DELAY);
    int i;
    for (i=0; i<strlen(pcCol); i++){
      switch(*(pcCol+i)){
        case 'R':
        SerialUSB.println("Turning the Red LED on");
        pd_rgb_led(PD_RED);
        break;

        case 'B':
        SerialUSB.println("Turning the Blue LED on");
        pd_rgb_led(PD_BLUE);
        break;
 
        case 'G':
        SerialUSB.println("Turning the Green LED on");
        pd_rgb_led(PD_GREEN);
        break;
        
        case 'P':
        SerialUSB.println("Turning the Purple LED on");
        pd_rgb_led(PD_PURPLE);
        break;

        case 'Y':
        SerialUSB.println("Turning the Yellow LED on");
        pd_rgb_led(PD_YELLOW);
        break;
 
        case 'T':
        SerialUSB.println("Turning the Tiel LED on");
        pd_rgb_led(PD_TIEL);
        break;


        case 'W':
        SerialUSB.println("Turning the White LED on");
        pd_rgb_led(PD_WHITE);
        break;

        default:
        SerialUSB.println("Unknown color");
      }
      xSemaphoreGive(sem);
      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
      
      xSemaphoreTake(sem, portMAX_DELAY);
      SerialUSB.println("Turning the LED off");
      pd_rgb_led(PD_OFF);
      xSemaphoreGive(sem);

      vTaskDelay((500L*configTICK_RATE_HZ)/1000L);
 
      
    }
    SerialUSB.println("Done");
  }
}





void loop() {

}
