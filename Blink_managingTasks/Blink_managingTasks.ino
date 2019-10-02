#include <FreeRTOS_ARM.h>
#include <PowerDue.h>
#define LED_R 6
#define LED_G 7
#define LED_B 8
//
//#define PD_RED 1
//#define PD_GREEN 2
//#define PD_BLUE 3
//#define PD_YELLOW 4
//#define PD_PURPLE 5
//#define PD_TIEL 6
//#define PD_WHITE 7
//#define PD_OFF 8

void setup() {
  pd_rgb_led_init();

  SerialUSB.begin(9600);
  while(!SerialUSB);
  

  portBASE_TYPE s1 = xTaskCreate(BlinkRed, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s2 = xTaskCreate(BlinkGreen, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s3 = xTaskCreate(BlinkBlue, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s4 = xTaskCreate(BlinkYellow, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s5 = xTaskCreate(BlinkPurple, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s6 = xTaskCreate(BlinkTiel, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  portBASE_TYPE s7 = xTaskCreate(BlinkWhite, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);


  // check for creation errors
  if ( s1 != pdPASS || s2 != pdPASS || s3 != pdPASS || s4 != pdPASS || s5 != pdPASS || s6 != pdPASS || s7 != pdPASS ) {
    SerialUSB.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();
  SerialUSB.println("Insufficient RAM");
  while(1);

}

static void BlinkRed(void* arg){
  while(1){
    SerialUSB.println("Turning the Red LED on");
    pd_rgb_led(PD_RED);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Red LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkGreen(void* arg){
  while(1){
    SerialUSB.println("Turning the Green LED on");
    pd_rgb_led(PD_GREEN);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Green LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkBlue(void* arg){
  while(1){
    SerialUSB.println("Turning the Blue LED on");
    pd_rgb_led(PD_BLUE);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Blue LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkYellow(void* arg){
  while(1){
    SerialUSB.println("Turning the Yellow LED on");
    pd_rgb_led(PD_YELLOW);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Yellow LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkPurple(void* arg){
  while(1){
    SerialUSB.println("Turning the Purple LED on");
    pd_rgb_led(PD_PURPLE);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Purple LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkTiel(void* arg){
  while(1){
    SerialUSB.println("Turning the Tiel LED on");
    pd_rgb_led(PD_TIEL);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the Tiel LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}

static void BlinkWhite(void* arg){
  while(1){
    SerialUSB.println("Turning the White LED on");
    pd_rgb_led(PD_WHITE);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Turning the White LED off");
    pd_rgb_led(PD_OFF);

    vTaskDelay((500L*configTICK_RATE_HZ)/1000L);

    SerialUSB.println("Done");
  }
}




void loop() {

}
