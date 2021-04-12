#include <font_Arial.h>
#include <font_ArialBold.h>
#include <ILI9341_t3.h>


// Define States
#define S_IDLE 10

#define S_CHARGE_SETUP  20
#define S_CHARGING  21
#define S_CHARGE_COMPLETE  22

#define S_SELECT_STATISTICS  30
#define S_COMPUTE_STATISTICS  31
#define S_VIEW_STATISTICS  32

#define S_UPLOAD_SETUP  40
#define S_UPLOADING  41
#define S_UPLOAD_COMPLETE  42


volatile int current_state = S_IDLE;


void setup() {
  Serial.begin(9600);
  Serial.println("Setup Starting...");
  
  // Setup pins and devices
  
  Serial.println("Setup Complete");
  Serial.println("Entering Main");
}

void loop() {

  if (current_state == S_IDLE){
    Serial.println("Entering S_IDLE...");
  }
  
  if (current_state == S_CHARGE_SETUP){
    Serial.println("Entering S_CHARGE_SETUP...");
  }
  if (current_state == S_CHARGING){
    Serial.println("Entering S_CHARGING...");
  }
  if (current_state == S_CHARGE_COMPLETE){
    Serial.println("Entering S_CHARGE_COMPLETE...");
  }


  if (current_state == S_SELECT_STATISTICS){
    Serial.println("Entering S_SELECT_STATISTICS...");
  }
  if (current_state == S_COMPUTE_STATISTICS){
    Serial.println("Entering S_COMPUTE_STATISTICS...");
  }
  if (current_state == S_VIEW_STATISTICS){
    Serial.println("Entering S_VIEW_STATISTICS...");
  }


  if (current_state == S_UPLOAD_SETUP){
    Serial.println("Entering S_UPLOAD_SETUP...");
  }
  if (current_state == S_UPLOADING){
    Serial.println("Entering S_UPLOADING...");
  }
  if (current_state == S_UPLOAD_COMPLETE){
    Serial.println("Entering S_UPLOAD_COMPLETE...");
  }
  
}
