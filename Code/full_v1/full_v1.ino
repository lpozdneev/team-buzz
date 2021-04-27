#include <ILI9341_t3.h>
#include <font_Arial.h> // from ILI9341_t3
#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define CS_PIN  8
#define TFT_DC  9
#define TFT_CS 10
// MOSI=11, MISO=12, SCK=13

XPT2046_Touchscreen ts(CS_PIN);
#define TIRQ_PIN  2
//XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);


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

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  ts.begin();
  ts.setRotation(1);
  while (!Serial && (millis() <= 1000));
  
  Serial.println("Setup Complete");
  Serial.println("Entering Main...");
}

void loop() {

  if (current_state == S_IDLE){
    Serial.println("Entering S_IDLE...");
    // Home page
  }
  
  if (current_state == S_CHARGE_SETUP){
    Serial.println("Entering S_CHARGE_SETUP...");
    // charge setup page with options
  }
  if (current_state == S_CHARGING){
    Serial.println("Entering S_CHARGING...");
    // charging page
  }
  if (current_state == S_CHARGE_COMPLETE){
    Serial.println("Entering S_CHARGE_COMPLETE...");
    // charging complete page
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
