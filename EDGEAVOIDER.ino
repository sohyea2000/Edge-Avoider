
int leftMotorBackward=D1;
int leftMotorForward= D2;
int rightMotorBackward= D4;
int rightMotorForward= D3;
#define echo D7
#define trig D8
int cm;
int duration;

void setup() {
  pinMode(leftMotorForward,OUTPUT);
  pinMode(leftMotorBackward,OUTPUT);
  pinMode(rightMotorForward,OUTPUT);
  pinMode(rightMotorBackward,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(115200);
  
  

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  cm=(duration*0.034)/2;
  Serial.print("Distance=");
  Serial.println(cm);
  if(cm>2)
  {
    go_back();
    delay(1000);
    go_left();
    delay(1000);
    go_straight();
  }
  else
  {
    go_straight();
  }
}
void go_straight()
{
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorBackward,LOW);
  
}
void go_left()
{
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
}
void go_back()
{
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,HIGH);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,HIGH);
  }

  
