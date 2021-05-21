#include "DHT.h"
#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
//#include "PinDefinitionsAndMore.h"
#include <IRremote.h>
#define DHTTYPE DHT11
#define DHTPIN 3
#define MODE_DATE 1
#define MODE_TEMP 2
#define MODE_DAY 3
LiquidCrystal_I2C lcd(0x27, 16, 2);
DS1302 rtc(8, 9, 10);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.init();
  Serial.begin(9600);  
  IrReceiver.begin(2, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  rtc.setDOW(THURSDAY);        // Set Day-of-Week to FRIDAY
//  rtc.setTime(20, 18, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(5, 19, 2021);   // Set the date to August 6th, 2010
  dht.begin();
  lcd.backlight();
}
void hourIncrementor(){
  Time t = rtc.getTime();
  if (t.hour == 23){
    rtc.setTime(0, t.min, t.sec);
  }else{
    rtc.setTime(t.hour + 1, t.min, t.sec); 
  }
}
void hourDecrementor(){
  Time t = rtc.getTime();
  if (t.hour == 0){
    rtc.setTime(23, t.min, t.sec);
  }else{
    rtc.setTime(t.hour - 1, t.min, t.sec);
  }
}
void minuteIncrementor(){
  Time t = rtc.getTime();
  if (t.min == 59 && t.hour != 23){
    rtc.setTime(t.hour + 1, 0, t.sec);
  }else if(t.min == 59 && t.hour == 23){
    rtc.setTime(0, 0, t.sec);
  }else{
    rtc.setTime(t.hour, t.min + 1, t.sec);
  }
}
void minuteDecrementor(){
  Time t = rtc.getTime();
  if (t.min == 0 && t.hour != 0){
    rtc.setTime(t.hour - 1, 59, t.sec);
  }else if(t.min == 0 && t.hour == 0){
    rtc.setTime(23, 59, t.sec);
  }else{
    rtc.setTime(t.hour, t.min - 1, t.sec);
  }
}
void timeDisplay(){
//  lcd.setCursor(0, 0);
//  lcd.print(rtc.getDateStr());
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  //delay(100);
}
void tempDisplay(){
  delay(100);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Humidity:");
  lcd.setCursor(2, 0);
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  lcd.print(t);
  lcd.print(" ");
  lcd.print((char)0xDF);
  lcd.print("C");
}
void dateDisplay(){
  lcd.setCursor(0, 0);
  lcd.print("Today is ");
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDOWStr());
}
int state = MODE_DATE;
int gotCommand = false;
void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {

        // Print a short summary of received data
        IrReceiver.printIRResultShort(&Serial);
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            // We have an unknown protocol here, print more info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
        }
        //Serial.println();

        /*
         * !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.resume(); // Enable receiving of the next value

        /*
         * Finally, check the received data and perform actions according to the received command
         */
    if (IrReceiver.decodedIRData.command == 0xC) {
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x18) {
      state = MODE_TEMP;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x5E) {
      state = MODE_DAY;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x15) {
      minuteIncrementor();
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x7) {
      minuteDecrementor();
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x40) {
      hourIncrementor();
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    } else if (IrReceiver.decodedIRData.command == 0x44) {
      hourDecrementor();
      state = MODE_DATE;
      lcd.clear();
      gotCommand = !gotCommand;
    }
  }
  if (state == MODE_TEMP) {
    tempDisplay();
  } else if (state == MODE_DATE) {
    timeDisplay();
  } else if (state == MODE_DAY) {
    dateDisplay();
  }
}
