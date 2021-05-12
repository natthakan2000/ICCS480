#define T_C 262
#define T_D 294
#define T_E 330
#define T_G 392

const int C = 8;
const int D = 9;
const int E = 10;
const int G = 11;

const int Buzz = 2;
const int LED = 13;

void setup()
{
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
}

void loop()
{
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
  }
  noTone(Buzz);
  digitalWrite(LED,LOW);

}
