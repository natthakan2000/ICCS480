unsigned long previousMillis = 0;
long interval = 2000;
const int ledPin = 3;
const int Buzz = 2;
const int button = 8;
int counter = 0;
int prev = -1;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  digitalWrite(button,HIGH);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(ledPin, LOW);
  unsigned long currentMillis = millis();
  //Serial.println();
  int data = digitalRead(button);
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  //Serial.println(sensorValue);
//  if (counter == 1){
//    currentMillis = millis();
//    previousMillis = currentMillis;
//  }
  if (counter == 2){
     tone(Buzz,100);
     digitalWrite(ledPin, HIGH);
  }
  if (data == LOW){
    noTone(Buzz);
    digitalWrite(ledPin, LOW);
    counter = 0;
  }
  if (sensorValue < 25){
    if (counter == 0){
      counter += 1;
      delay(100);
      previousMillis = currentMillis;
    }
    if (counter == 1){
      if (currentMillis - previousMillis <= interval){
        counter += 1;
        delay(100);
      }else{
        counter = 0;
      }
    }
  }
//  tone(Buzz,100);
//  delay(100);
//  digitalWrite(ledPin, HIGH);
//  if (data == LOW){
//    noTone(Buzz);
//    digitalWrite(ledPin, LOW);
//    delay(100);
//  }
}
