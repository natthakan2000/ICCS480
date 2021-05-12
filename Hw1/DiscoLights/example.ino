////// These variables store the flash pattern
////// and the current state of the LED
////
////int ledPin1 =  2;      // the number of the LED pin
////int ledState1 = LOW;             // ledState used to set the LED
////unsigned long previousMillis1 = 0;        // will store last time LED was updated
////long OnTime1 = 200;           // milliseconds of on-time
////long OffTime1 = 500;          // milliseconds of off-time
////
////int ledPin2 =  3;      // the number of the LED pin
////int ledState2 = LOW;             // ledState used to set the LED
////unsigned long previousMillis2 = 0;        // will store last time LED was updated
////long OnTime2 = 300;           // milliseconds of on-time
////long OffTime2 = 600;          // milliseconds of off-time
////
////int ledPin3 =  4;      // the number of the LED pin
////int ledState3 = LOW;             // ledState used to set the LED
////unsigned long previousMillis3 = 0;        // will store last time LED was updated
////long OnTime3 = 400;           // milliseconds of on-time
////long OffTime3 = 700;          // milliseconds of off-time
////
////void setup() 
////{
////  // set the digital pin as output:
////  pinMode(ledPin1, OUTPUT);      
////  pinMode(ledPin2, OUTPUT);   
////  pinMode(ledPin3, OUTPUT);    
////}
////
////void loop()
////{
////  // check to see if it's time to change the state of the LED
////  unsigned long currentMillis = millis();
//// 
////  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
////  {
////    ledState1 = LOW;  // Turn it off
////    previousMillis1 = currentMillis;  // Remember the time
////    digitalWrite(ledPin1, ledState1);  // Update the actual LED
////  }
////  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
////  {
////    ledState1 = HIGH;  // turn it on
////    previousMillis1 = currentMillis;   // Remember the time
////    digitalWrite(ledPin1, ledState1);    // Update the actual LED
////  }
////  
////  if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
////  {
////    ledState2 = LOW;  // Turn it off
////    previousMillis2 = currentMillis;  // Remember the time
////    digitalWrite(ledPin2, ledState2);  // Update the actual LED
////  }
////  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
////  {
////    ledState2 = HIGH;  // turn it on
////    previousMillis2 = currentMillis;   // Remember the time
////    digitalWrite(ledPin2, ledState2);   // Update the actual LED
////  }
////  if((ledState3 == HIGH) && (currentMillis - previousMillis3 >= OnTime3))
////  {
////    ledState3 = LOW;  // Turn it off
////    previousMillis3 = currentMillis;  // Remember the time
////    digitalWrite(ledPin3, ledState3);  // Update the actual LED
////  }
////  else if ((ledState3 == LOW) && (currentMillis - previousMillis3 >= OffTime3))
////  {
////    ledState3 = HIGH;  // turn it on
////    previousMillis3 = currentMillis;   // Remember the time
////    digitalWrite(ledPin3, ledState3);   // Update the actual LED
////  }
////}
//
////#define led1 2   //
////#define led2 3  //pin for each led
////#define led3 4
////
////unsigned long previousMillis[3]; //[x] = number of leds
////
////void setup() { 
////  pinMode(led1, OUTPUT);   
////  pinMode(led2, OUTPUT);
////  pinMode(led3, OUTPUT);
////}
////void loop() {
//// BlinkLed(led1, 100, 0);   //BlinkLed( which led, interval, one of the stored prevMillis
//// BlinkLed(led2, 400, 1);//last parameters must be different for each led
//// BlinkLed(led3, 700, 2);
////}
////
////void BlinkLed (int led, int interval, int array){   
////  
////  //(long) can be omitted if you dont plan to blink led for very long time I think
////   if (((long)millis() - previousMillis[array]) >= interval){ 
////   
////    previousMillis[array]= millis(); //stores the millis value in the selected array
////   
////    digitalWrite(led, !digitalRead(led)); //changes led state
////  }
//// }
//
////int red = 2;
////int intervalRed = 1000; //how long to delay in millis
////unsigned long previousRed = 0;
////int redState = LOW;
////
////int blue = 3;
////int intervalBlue = 2000; //how long to delay in millis
////unsigned long previousBlue = 0;
////int blueState = LOW;
////
////int green = 4;
////int intervalGreen = 3000; //how long to delay in millis
////unsigned long previousGreen = 0;
////int greenState = LOW;
////
////void setup() {
////  Serial.begin(9600);
////  pinMode(red, OUTPUT);
////  pinMode(blue, OUTPUT);
////  pinMode(green, OUTPUT);
////}
////
////void checkRed() {
////  unsigned long currentMillis = millis();
////
////  if (currentMillis - previousRed >= intervalRed && currentMillis - previousGreen < intervalGreen && currentMillis - previousBlue < intervalBlue) {
////    //save this reading!
////    previousRed = currentMillis;
////
////    //figure out if you should turn the LED on or off
////    if (redState == LOW) {
////      redState = HIGH;
////      greenState = LOW;
////      blueState = LOW;
////    } else {
////      redState = LOW;
////    }
////    digitalWrite(red, redState);
////  }
////}
////
////void checkGreen() {
////  unsigned long currentMillis = millis();
////
////  if (currentMillis - previousGreen >= intervalGreen && currentMillis - previousBlue >= intervalBlue && currentMillis - previousRed < intervalRed) {
////    //save this reading!
////    previousGreen = currentMillis;
////
////    //figure out if you should turn the LED on or off
////    if (greenState == LOW) {
////      greenState = HIGH;
////    } else {
////      greenState = LOW;
////    }
////    digitalWrite(green, greenState);
////  }
////}
////
////void checkBlue() {
////  unsigned long currentMillis = millis();
////
////  if (currentMillis - previousBlue >= intervalBlue && currentMillis - previousRed < intervalRed && currentMillis - previousGreen < intervalGreen) {
////    //save this reading!
////    previousBlue = currentMillis;
////
////    //figure out if you should turn the LED on or off
////    if (blueState == LOW) {
////      blueState = HIGH;
////    } else {
////      blueState = LOW;
////    }
////    digitalWrite(blue, blueState);
////  }
////}
////
////
////void loop() {
////  checkRed();
////  checkGreen();
////  checkBlue();
////}
//
////#include <ezOutput.h> // ezOutput library
////
////ezOutput led1(2);  // create ezOutput object that attach to pin 7;
////ezOutput led2(3);  // create ezOutput object that attach to pin 8;
////ezOutput led3(4);  // create ezOutput object that attach to pin 9;
////
////void setup() {
////  led1.blink(500, 250); // 500 milliseconds ON, 250 milliseconds OFF
////  led2.blink(250, 250); // 250 milliseconds ON, 250 milliseconds OFF
////  led2.blink(100, 100); // 100 milliseconds ON, 100 milliseconds OFF
////}
////
////void loop() {
////  led1.loop(); // MUST call the led1.loop() function in loop()
////  led2.loop(); // MUST call the led2.loop() function in loop()
////  led3.loop(); // MUST call the led3.loop() function in loop()
////}
////#include <Servo.h> 
////class Flasher
////{
////  // Class Member Variables
////  // These are initialized at startup
////  int ledPin;      // the number of the LED pin
////  long OnTime;     // milliseconds of on-time
////  long OffTime;    // milliseconds of off-time
////
////  // These maintain the current state
////  int ledState;                 // ledState used to set the LED
////  unsigned long previousMillis;   // will store last time LED was updated
////
////  // Constructor - creates a Flasher 
////  // and initializes the member variables and state
////  public:
////  Flasher(int pin, long on, long off)
////  {
////  ledPin = pin;
////  pinMode(ledPin, OUTPUT);     
////    
////  OnTime = on;
////  OffTime = off;
////  
////  ledState = LOW; 
////  previousMillis = 0;
////  }
////
////  void Update()
////  {
////    // check to see if it's time to change the state of the LED
////    unsigned long currentMillis = millis();
////     
////    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
////    {
////      ledState = LOW;  // Turn it off
////      previousMillis = currentMillis;  // Remember the time
////      digitalWrite(ledPin, ledState);  // Update the actual LED
////    }
////    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
////    {
////      ledState = HIGH;  // turn it on
////      previousMillis = currentMillis;   // Remember the time
////      digitalWrite(ledPin, ledState);   // Update the actual LED
////    }
////  }
////};
////
////class Sweeper
////{
////  Servo servo;              // the servo
////  int pos;              // current servo position 
////  int increment;        // increment to move for each interval
////  int  updateInterval;      // interval between updates
////  unsigned long lastUpdate; // last update of position
////
////public: 
////  Sweeper(int interval)
////  {
////    updateInterval = interval;
////    increment = 1;
////  }
////  
////  void Attach(int pin)
////  {
////    servo.attach(pin);
////  }
////  
////  void Detach()
////  {
////    servo.detach();
////  }
////  
////  void Update()
////  {
////    if((millis() - lastUpdate) > updateInterval)  // time to update
////    {
////      lastUpdate = millis();
////      pos += increment;
////      servo.write(pos);
////      Serial.println(pos);
////      if ((pos >= 180) || (pos <= 0)) // end of sweep
////      {
////        // reverse direction
////        increment = -increment;
////      }
////    }
////  }
////};
//// 
//// 
////Flasher led1(3, 100, 400);
////Flasher led2(4, 300, 350);
////Flasher led3(5, 200, 250);
////
////Sweeper sweeper1(15);
////Sweeper sweeper2(25);
//// 
////void setup() 
////{ 
////  Serial.begin(9600);
////  pinMode(2, INPUT_PULLUP); 
////  sweeper1.Attach(9);
////  sweeper2.Attach(10);
////} 
//// 
//// 
////void loop() 
////{ 
////  sweeper1.Update();
////  
////  if(digitalRead(2) == HIGH)
////  {
////     sweeper2.Update();
////     led1.Update();
////  }
////  
////  led2.Update();
////  led3.Update();
////}
//unsigned long previousMillis = 0;        
//long OnTime = 250;
//int myPins[] = {HIGH, LOW, LOW, LOW, LOW, LOW, LOW};
//int discoDirection = 0; 
//class Flasher
//{
////  long OnTime;     =
////  int pinIdx = 0;
////  int toRight = true;
////  // These maintain the current state
////  unsigned long previousMillis;
//  public:
////  Flasher(int pin, long on, long off)
////  {
////  ledPin = pin;
////  pinMode(ledPin, OUTPUT);     
////    
////  OnTime = on;
////  OffTime = off;
////  
////  ledState = LOW; 
////  previousMillis = 0;
////  }
//// 
////  void Update()
////  {
////    // check to see if it's time to change the state of the LED
////    unsigned long currentMillis = millis();
////     
////    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
////    {
////      ledState = LOW;  // Turn it off
////      previousMillis = currentMillis;  // Remember the time
////      digitalWrite(ledPin, ledState);  // Update the actual LED
////    }
////    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
////    {
////      ledState = HIGH;  // turn it on
////      previousMillis = currentMillis;   // Remember the time
////      digitalWrite(ledPin, ledState);   // Update the actual LED
////    }
////  }
//  Flashers(long on)
//    {
//      OnTime = on;
//      previousMillis = 0;
//    }
//
//    void changeTime(int on)
//    {
//      if ( on <= 10 ) {
//        OnTime = 10;
//      } else {
//
//        OnTime = on;
//      }
//    }
//    void setToRight(int isRight) {
//      toRight = isRight;
//    }
//    void updateLight()
//    {
//      // check to see if it's time to change the state of the LED
//      unsigned long currentMillis = millis();
//
//      if ((currentMillis - previousMillis >= OnTime) && toRight)
//      {
//        previousMillis = currentMillis;  // Remember the time
//        lightUp(pinIdx + 1); // Update the actual LED
//        goRight();
//      } else if ((currentMillis - previousMillis >= OnTime) && !toRight)
//      {
//        previousMillis = currentMillis;  // Remember the time
//        lightUp(pinIdx + 1); // Update the actual LED
//        goLeft();
//      }
//    }
//
//    void goLeft() {
//      if ( pinIdx == 0 ) {
//        pinIdx = 7;
//      } else {
//        pinIdx--;
//      }
//    }
//    void goRight() {
//      if ( pinIdx == 7 ) {
//        pinIdx = 0;
//      } else {
//        pinIdx++;
//      }
//    }
//    void lightUp(int idx) {
//      for (byte i = 1; i < 9; i = i + 1) {
//        digitalWrite(i, LOW);  // Update the actual LED
//      }
//      digitalWrite(idx, HIGH);  // Update the actual LED
//    }
//};
// 
// 
////Flasher led1(2, 100, 3700);
////Flasher led2(3, 400, 3400);
////Flasher led3(4, 700, 3100);
////Flasher led4(5, 1000, 2800);
////Flasher led5(6, 1300, 2500);
////Flasher led6(7, 1600, 2200);
////Flasher led1(2, 100, 700);
////Flasher led2(3, 100, 700);
//// 
//Flashers led(OnTime);
//void setup()
//{
//  pinMode(2, OUTPUT);
//  pinMode(3, OUTPUT);
//  pinMode(4, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(7, OUTPUT);
//  pinMode(8, OUTPUT);
//  Serial.begin(9600);
//}
// 
//void loop()
//{
////  //int myPins[] = {2,3};
////  for (int i = 0; i < 2; i++) {
////    if (i == 0){
////      led1.Update();
////      //digitalWrite(3, LOW);
////    }
////    if (i == 1){
////      led2.Update();
////      //digitalWrite(2, LOW);
////    }
////  }
//  discoDirection = analogRead(A0);
//  Serial.println(discoDirection);
//  if (discoDirection <= 512) {
//    led.setToRight(true);
//    led.changeTime(discoDirection);
//    led.updateLight();
//  } else {
//    led.setToRight(false);
//    led.changeTime(1024 - discoDirection);
//    led.updateLight();
//  }discoDirection = analogRead(A0);
//  Serial.println(discoDirection);
//  if (discoDirection <= 512) {
//    led.setToRight(true);
//    led.changeTime(discoDirection);
//    led.updateLight();
//  } else {
//    led.setToRight(false);
//    led.changeTime(1024 - discoDirection);
//    led.updateLight();
//  }
////  led1.Update();
////  led2.Update();
////  led3.Update();
////  led4.Update();
////  led5.Update();
////  led6.Update();
//}

unsigned long previousMillis = 0;        // will store last time LED was updated
long OnTime = 250;           // milliseconds of on-time
int discoDirection = 0;             // ledState used to set the LED
int myPins[] = {HIGH, LOW, LOW, LOW, LOW, LOW, LOW};  // ledState used to set the LED

class Flashers
{
    // Class Member Variables
    // These are initialized at startup
    long OnTime;     // milliseconds of on-time
    int pinIdx = 0;
    int toRight = true;
    // These maintain the current state
    unsigned long previousMillis;   // will store last time LED was updated

    // Constructor - creates a Flasher
    // and initializes the member variables and state
  public:
    Flashers(long on)
    {
      OnTime = on;
      previousMillis = 0;
    }

    void changeTime(int on)
    {
      if ( on <= 10 ) {
        OnTime = 10;
      } else {

        OnTime = on;
      }
    }
    void setToRight(int isRight) {
      toRight = isRight;
    }
    void updateLight()
    {
      // check to see if it's time to change the state of the LED
      unsigned long currentMillis = millis();

      if ((currentMillis - previousMillis >= OnTime) && toRight)
      {
        previousMillis = currentMillis;  // Remember the time
        lightUp(pinIdx + 1); // Update the actual LED
        goRight();
      } else if ((currentMillis - previousMillis >= OnTime) && !toRight)
      {
        previousMillis = currentMillis;  // Remember the time
        lightUp(pinIdx + 1); // Update the actual LED
        goLeft();
      }
    }

    void goLeft() {
      if ( pinIdx == 0 ) {
        pinIdx = 7;
      } else {
        pinIdx--;
      }
    }
    void goRight() {
      if ( pinIdx == 7 ) {
        pinIdx = 0;
      } else {
        pinIdx++;
      }
    }
    void lightUp(int idx) {
      for (byte i = 1; i < 9; i = i + 1) {
        digitalWrite(i, LOW);  // Update the actual LED
      }
      digitalWrite(idx, HIGH);  // Update the actual LED
    }
};

Flashers led(OnTime);

void setup() {
  // put your setup code here, to run once:
  // make a port that detect the coin
  // initialize serial communication at 9600 bits per second:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  discoDirection = analogRead(A0);
  Serial.println(discoDirection);
  if (discoDirection <= 512) {
    led.setToRight(true);
    led.changeTime(discoDirection);
    led.updateLight();
  } else {
    led.setToRight(false);
    led.changeTime(1024 - discoDirection);
    led.updateLight();
  }mkdi
}
