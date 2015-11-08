const byte rtMotorPin1 = 4;
const byte rtMotorPin2 = 5;  //pwm
const byte ltMotorPin2 = 6;  //pwm
const byte ltMotorPin1 = 7;
const byte rtLight = 12;
const byte ltLight = 13;
const byte rtLightSensor = A5;
const byte ltLightSensor = A4;

int rtTurn = 0;
int ltTurn = 0;
int RPM = 255;


void setup()
{
  //Serial.begin(9600);
  pinMode(rtMotorPin1, OUTPUT);
  pinMode(rtMotorPin2, OUTPUT);
  pinMode(ltMotorPin1, OUTPUT);
  pinMode(ltMotorPin2, OUTPUT);
  pinMode (rtLight, OUTPUT);
  pinMode (ltLight,OUTPUT);
  digitalWrite(rtLight, HIGH);
  digitalWrite(ltLight, HIGH);
}

void loop()
{
    readRtLightSensor();
    readLtLightSensor();
    //delay(100);
    //Serial.print(rtTurn);
    //Serial.print(", ");
    //Serial.println(ltTurn);
    if (rtTurn == 0 && ltTurn == 0) {
      analogWrite(rtMotorPin2, RPM);
      digitalWrite(rtMotorPin1, LOW);
      analogWrite(ltMotorPin2, RPM);
      digitalWrite(ltMotorPin1, LOW);
    }
    else if (rtTurn == 0 && ltTurn == 1) {
      analogWrite(rtMotorPin2, RPM);
      digitalWrite(rtMotorPin1, LOW);
      analogWrite(ltMotorPin2, RPM/2);
      digitalWrite(ltMotorPin1, HIGH);
    }
    else if (rtTurn == 1 && ltTurn == 0) {
      analogWrite(rtMotorPin2, RPM/2);
      digitalWrite(rtMotorPin1, HIGH);
      analogWrite(ltMotorPin2, RPM);
      digitalWrite(ltMotorPin1, LOW);
    }
    else {
      digitalWrite(rtMotorPin2, LOW);
      digitalWrite(rtMotorPin1, LOW);
      digitalWrite(ltMotorPin2, LOW);
      digitalWrite(ltMotorPin1, LOW);
    }
}

int readRtLightSensor()
{
  int rtSignal;
  rtSignal = analogRead(rtLightSensor);
  //Serial.println(rtSignal);
  if (rtSignal >= 550)
  {
    rtTurn = 1;
  }
  else 
  {
    rtTurn = 0;
  }
  return rtTurn;
}

int readLtLightSensor()
{
  int ltSignal;
  ltSignal = analogRead(ltLightSensor);
  //Serial.println(ltSignal);
  if (ltSignal >= 550)
  {
    ltTurn = 1;
  }
  else
  {
    ltTurn = 0;
  }
  return ltTurn;
  
}

