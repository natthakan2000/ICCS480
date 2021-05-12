int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float known = 1000;
float unknown = 0;
float buffer = 0;
void setup(){
Serial.begin(9600);
}

void loop(){
  raw = analogRead(analogPin);
  if(raw){
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    unknown= known * buffer;
//    Serial.print("Vout: ");
//    Serial.println(Vout);
    Serial.print("resistance = ");
    Serial.println(unknown);
    delay(1000);
  }
}
